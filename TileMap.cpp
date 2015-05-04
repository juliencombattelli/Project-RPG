#include "TileMap.hpp"
#include "Global.hpp"


rpg::TileMap::TileMap() : mMapName(""), mTileset(), mTileSize(32), mSize{0,0}
{

}

bool rpg::TileMap::loadFromFile(const std::string& mapName)
{
    utility::ibfstream file( mapFolder + mapName + mapExt );

    if(not file.isOpen())
        return false;

    size_t fileLength = file.getFileLength();
    uint8_t* buffer = new uint8_t[fileLength];
    size_t position = 0;

    file.read(buffer, fileLength);

    mMapName = utility::readString(buffer, 0, 20);
    position += mMapName.size()+1;

    std::string tilesheetName = utility::readString(buffer, position, 20);
    mTileset.loadFromFile(pictureFolder + tilesheetName + pictureExt);
    position += tilesheetName.size()+1;

    mTileSize = utility::read4Byte(buffer, position);
    position += 4;

    mSize.x = utility::read4Byte(buffer, position);
    position += 4;

    mSize.y = utility::read4Byte(buffer, position);
    position += 4;

    mTilesLayer1.resize(mSize.x*mSize.y);
    mTilesLayer1.assign(mSize.x*mSize.y, 0x00);

    std::cout << mTileSize << std::endl
              << mSize.x  << std::endl
              << mSize.y << std::endl;

    delete[] buffer;

    file.close();

    return true;
}

bool rpg::TileMap::loadFromMemory(const void* data, std::size_t size)
{
    return true;
}

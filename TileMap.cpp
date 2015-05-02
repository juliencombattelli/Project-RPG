#include "TileMap.hpp"
#include <fstream>

rpg::TileMap::TileMap() : mMapName(""), mTileset(), mTileSize(32), mSize{0,0}
{

}

bool rpg::TileMap::loadFromFile(const std::string& mapName)
{
    std::ifstream file( "ressource/map/" + mapName + ".mapdata" );

    if(not file.is_open())
        return false;

    file.seekg(std::ios_base::beg);

    //mTileset.loadFromFile()

    file.close();

    return true;
}

bool rpg::TileMap::loadFromMemory(const void* data, std::size_t size)
{
    return true;
}

#ifndef TILEMAP_INCLUDED
#define TILEMAP_INCLUDED

#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace rpg
{

class TileMap
{
public:

    TileMap();

    bool loadFromFile(const std::string& mapName);
    bool loadFromMemory(const void* data, std::size_t size);

    const std::string&          getMapName() const { return mMapName; }
    const sf::Texture&          getTileset() const { return mTileset; }
    const uint32_t&             getTileSize() const { return mTileSize; }
    const sf::Vector2u&         getSize() const { return mSize; }
    const std::vector<uint8_t>& getTilesLayer1() const { return mTilesLayer1; }
    const std::vector<uint8_t>& getTilesLayer2() const { return mTilesLayer2; }
    const std::vector<uint8_t>& getTilesLayer3() const { return mTilesLayer3; }

private:

    std::string             mMapName;
    sf::Texture             mTileset;
    uint32_t                mTileSize;
    sf::Vector2u            mSize;
    std::vector<uint8_t>    mTilesLayer1;
    std::vector<uint8_t>    mTilesLayer2;
    std::vector<uint8_t>    mTilesLayer3;
};

}


#endif //TILEMAP_INCLUDED

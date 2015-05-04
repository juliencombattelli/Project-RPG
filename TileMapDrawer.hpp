#ifndef TILEMAPDRAWER_HPP_INCLUDED
#define TILEMAPDRAWER_HPP_INCLUDED

#include "TileMap.hpp"
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace rpg
{

class TileMapDrawer : public sf::Drawable, public sf::Transformable
{
public:

    TileMapDrawer();
    TileMapDrawer(const TileMapDrawer&) = delete;
    TileMapDrawer& operator=(const TileMapDrawer&)= delete;
    ~TileMapDrawer();

    bool load(const std::string& mapName);

    const std::string&          getMapName() const { return mTileMap.getMapName(); }
    const sf::Texture&          getTileset() const { return mTileMap.getTileset(); }
    const uint32_t&             getTileSize() const { return mTileMap.getTileSize(); }
    const sf::Vector2u&         getSize() const { return mTileMap.getSize(); }
    const std::vector<uint8_t>& getTilesLayer1() const { return mTileMap.getTilesLayer1(); }
    const std::vector<uint8_t>& getTilesLayer2() const { return mTileMap.getTilesLayer2(); }
    const std::vector<uint8_t>& getTilesLayer3() const { return mTileMap.getTilesLayer3(); }

    uint32_t                    getSizeX_pix() const { return mTileMap.getSize().x * mTileMap.getTileSize(); }
    uint32_t                    getSizeY_pix() const { return mTileMap.getSize().y * mTileMap.getTileSize(); }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    TileMap mTileMap;
    sf::VertexArray mVertices;
};

}
#endif // TILEMAPDRAWER_HPP_INCLUDED

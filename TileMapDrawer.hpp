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

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    TileMap mTileMap;
    sf::VertexArray mVertices;
};

}
#endif // TILEMAPDRAWER_HPP_INCLUDED

#include "TileMapDrawer.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

rpg::TileMapDrawer::TileMapDrawer()
{

}

rpg::TileMapDrawer::~TileMapDrawer()
{

}

bool rpg::TileMapDrawer::load(const std::string& mapName)
{
    mTileMap.loadFromFile(mapName);

    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    const std::string& name     = mTileMap.getMapName();
    const sf::Texture& tileset  = mTileMap.getTileset();
    const uint32_t&    tileSize = mTileMap.getTileSize();
    const uint32_t&    width    = mTileMap.getSize().x;
    const uint32_t&    height   = mTileMap.getSize().y;

    const std::vector<uint8_t>& tilesLayer1 = mTileMap.getTilesLayer1();
    const std::vector<uint8_t>& tilesLayer2 = mTileMap.getTilesLayer2();
    const std::vector<uint8_t>& tilesLayer3 = mTileMap.getTilesLayer3();

    mVertices.setPrimitiveType(sf::Quads);
    mVertices.resize(width * height * 4);

    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // on récupère le numéro de tuile courant
            uint32_t tileNumber = static_cast<uint32_t>(tilesLayer1[i + j * width]);

            // on en déduit sa position dans la texture du tileset
            uint32_t tu = tileNumber % width;
            uint32_t tv = tileNumber / width;

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &mVertices[(i + j * width) * 4];

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i * tileSize, j * tileSize);
            quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
            quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
            quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
            quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
        }

    return true;
}

void rpg::TileMapDrawer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    states.texture = &mTileMap.getTileset();

    target.draw(mVertices, states);
}

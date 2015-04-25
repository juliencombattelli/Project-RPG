#ifndef TILE_LOADER_INCLUDED
#define TILE_LOADER_INCLUDED

#include <SFML/Graphics/VertexArray.hpp>
#include <string>

struct MapData
{
    std::string textureName;
    int sizeX,sizeY;
    MapData():sizeX(0),sizeY(0){}
};

class TileLoader
{
protected:
    MapData m_mapdata;
public:
    virtual ~TileLoader(void){};
    virtual void appendTile(int gx,int gy,sf::VertexArray& garr)=0;
    /*
    2.implement this method to append(or skip appending) tiles(4 vertices) to given vertex array,
    you may assume tiles will be requested in row major order:((0,0),(1,0),..,(map_x-1,0),(0,1),..,(map_x-1,map_y-1)),
    this method will be called exactly MapX*MapY times,
    for correct displaying and culling it's assumed your appended tile will be square with side equal to tilesize
    and have it's top left point at (tilesize*gx,tilesize*gy),
    */
    const MapData& getData(void) const {return m_mapdata;}
};

#endif //TILE_LOADER_INCLUDED

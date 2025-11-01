#include <Siv3D.hpp>

#include "MapGrid.h"
using namespace SinGame;

MapGrid::MapGrid(class Game* game, int height, int width, GridTexture gridTex)
	:Actor(game)
{
	mTileGrid = Grid<Tile*>(width, height);

	double Tilenum = width;
	double TileHeightNum = height;
	double TileSize = 1080 / Tilenum;
	double scale = TileSize / 32;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			Tile* tile = new Tile(game);

			tile->SetGridTexture(gridTex.GetGridTextures());
			tile->SetPosition(Vec2(400.0f + i * (float)TileSize, 300.0f + j * (float)TileSize));
			tile->SetScale((float)scale);

			mTileGrid[Point{ i,j }] = tile;
		}
	}


}

void MapGrid::UpdateMapGrid()
{

}

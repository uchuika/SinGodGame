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
	mTileScale = scale;

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

	Grid<int32> map = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			mTileGrid[Point{ i, j }]->SetTileTexture(map[Point{ i,j }]);
		}
	}

	/*
	mTileGrid[Point{ 10, 10 }]->SetTileTexture(25);
	mTileGrid[Point{ 10, 11}]->SetTileTexture(26);
	mTileGrid[Point{ 11, 10 }]->SetTileTexture(37);
	mTileGrid[Point{ 11, 11 }]->SetTileTexture(38);
	*/
}

void MapGrid::UpdateMapGrid(Grid<int32> map)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			mTileGrid[Point{ i, j }]->SetTileTexture(map[Point{ i,j }]);
		}
	}
}

#pragma once

#include <Siv3D.hpp>

#include "../Game.h"
#include "../Actor/Tile.h"
#include "../Actor/Actor.h"
#include "GridTexture.h"

namespace SinGame
{
	class MapGrid : public Actor
	{
	public:
		MapGrid(class Game* game, int height, int width, GridTexture gridTex);

		void UpdateMapGrid();

		Grid<Tile*>& GetTileGrid() { return mTileGrid; }

	private:
		Grid<Tile*> mTileGrid;
	};
}

#pragma once

#include "Actor.h";

namespace SinGame
{
	class Tile : public Actor
	{
	public:
		friend class MapGrid;
		enum TileState
		{
			
		};

		Tile(class Game* game);

		void SetGridTexture(Array<Texture>& textures);
		void SetTileTexture(int texnum);

	private:

		void UpdateTexture();
		class SpriteComponent* mSprite;

		Array<Texture> MakeTile(const Image& baseImage, const int size);

		Array<Texture> mGridTextures;
		bool mSelected;

		int mTextureNum;
	};
}

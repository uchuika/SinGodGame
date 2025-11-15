#include "Tile.h"

#include "../Component/SpriteComponent.h"
#include "../Game.h"

using namespace SinGame;

Tile::Tile(class Game* game)
	:Actor(game)
	,mSelected(false)
	, mTextureNum(0)
{
	mSprite = new SpriteComponent(this, 40);
}

void Tile::SetGridTexture(Array<Texture>& texutres)
{
	mGridTextures = texutres;
	UpdateTexture();
}

void Tile::SetTileTexture(int texnum)
{
	if (texnum < mGridTextures.size()) {
		mTextureNum = texnum;
		UpdateTexture();
	}
}

void Tile::UpdateTexture()
{
	mSprite->SetTexture(mGridTextures[mTextureNum]);
}

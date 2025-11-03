#include "Resident.h"
#include "../Component/CharacterComponent.h"
#include "../Component/SpriteComponent.h"

using namespace SinGame;

Resident::Resident(class Game* game)
	:Actor(game)
	,mTextureNum(0)
	,mFaithLevel(0)
	,HangryLevel(50)
	,TempLevel(15)
	,goalPoint(GetPosition())
{
	mSprite = new SpriteComponent(this);
}

void Resident::UpdateActor(double deltaTime)
{
	accumlatedTime += deltaTime;

	if (interval <= accumlatedTime)
	{
		
		accumlatedTime = 0.0;
	}
	mFaithLevel = 0;
	if (TempLevel >= 20 && TempLevel <= 25)
	{
		mFaithLevel += 5.0;
	}
}

void Resident::SetGridTexture(Array<Texture>& texutres)
{
	mGridTextures = texutres;
	UpdateTexture();
}

void Resident::SetTileTexture(int texnum)
{
	if (texnum < mGridTextures.size()) {
		mTextureNum = texnum;
		UpdateTexture();
	}
}

void Resident::UpdateTexture()
{
	mSprite->SetTexture(mGridTextures[mTextureNum]);
}

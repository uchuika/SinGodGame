#include "Crops.h"
#include "../Component/SpriteComponent.h"

using namespace SinGame;

Crops::Crops(class Game* game)
	:Actor(game)
{
	mSprite = new SpriteComponent(this, 50);
}

void Crops::SetTexture(Texture tex)
{
	mTexture = tex;
	UpdateTexture();
}

void Crops::UpdateActor(double deltaTime)
{
	if (mMaxGrowLevel <= mGrowLevel)
	{
		mGrowLevel = 0;
	}
}

void Crops::UpdateTexture()
{
	mSprite->SetTexture(mTexture);
}

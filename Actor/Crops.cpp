#include "Crops.h"
#include "../Component/SpriteComponent.h"

using namespace SinGame;

Crops::Crops(class Game* game)
	:Actor(game)
	, mCropState(EGrowing)
{
	mSprite = new SpriteComponent(this, 50);
}

void Crops::SetGridTexture(GridTexture gridTex)
{
	mGridTexture = gridTex;
	UpdateTexture();
}

void Crops::SetCropState(CropState cropState)
{

}

void Crops::UpdateActor(double deltaTime)
{

	if (mMaxGrowLevel == mGrowLevel)
	{
		mCropState = ECompleted;
		UpdateTexture();
	}
}

void Crops::UpdateTexture()
{
	switch (mCropState)
	{
	case EGrowing:
		mSprite->SetTexture(mGridTexture.GetGridTextures()[99]);
		break;
	case ECompleted:
		mSprite->SetTexture(mGridTexture.GetGridTextures()[96]);
	}
}

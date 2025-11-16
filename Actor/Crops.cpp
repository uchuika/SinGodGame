#include "Crops.h"
#include "../Component/SpriteComponent.h"


using namespace SinGame;

Crops::Crops(class Game* game)
	:Actor(game)
{
	mSprite = new SpriteComponent(this, 50);
	mCrop = new CropComponent(this);
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(23.2);
}

void Crops::SetGridTexture(GridTexture gridTex)
{
	mGridTexture = gridTex;
	UpdateTexture();
}


void Crops::UpdateActor(double deltaTime)
{
	
}

int Crops::GetGrowLevel()
{
	return mCrop->GetGrowLevel();
}

void Crops::SetGrowLevel(int growLevel)
{
	mCrop->SetGrowLevel(growLevel);
	UpdateTexture();
}

void Crops::UpdateTexture()
{
	CropComponent::CropState mCropState = mCrop->GetCropState();
	switch (mCropState)
	{
	case CropComponent::CropState::EGrowing:
		mSprite->SetTexture(mGridTexture.GetGridTextures()[99]);
		break;
	case CropComponent::CropState::ECompleted:
		mSprite->SetTexture(mGridTexture.GetGridTextures()[96]);
	}
}

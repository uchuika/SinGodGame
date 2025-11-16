#include "CropComponent.h"

using namespace SinGame;

CropComponent::CropComponent(Actor* owner)
	:Component(owner)
	,mCropState(EGrowing)
{

}

CropComponent::~CropComponent()
{

}

void CropComponent::Update(double deltaTime)
{
	if (mMaxGrowLevel == mGrowLevel)
	{
		mCropState = ECompleted;
	}
}

void CropComponent::CollectCrop()
{
	if (mCropState == ECompleted)
	{
		mCropState = EGrowing;
		mGrowLevel = 0;
	}
}



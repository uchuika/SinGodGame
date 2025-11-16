#pragma once

#include <Siv3D.hpp>
#include "Component.h"
#include "../Actor/Actor.h"

namespace SinGame
{
	class CropComponent : public Component
	{
	public:
		enum CropState
		{
			EGrowing,
			ECompleted,
		};

		CropComponent(class Actor* owner);
		~CropComponent();

		void Update(double deltaTime) override;

		//void SetCropState(CropState cropState);
		CropState GetCropState() { return mCropState; }

		void SetGrowLevel(int level) { mGrowLevel = level; }
		int GetGrowLevel() { return mGrowLevel; }

		void SetMaxGrowLevel(int level) { mMaxGrowLevel = level; };

		void CollectCrop();
	private:
		CropState mCropState;
		int mGrowLevel = 0;
		int mMaxGrowLevel = 10;
	};
}

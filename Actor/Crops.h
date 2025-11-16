#pragma once

#include "../Component/SpriteComponent.h"
#include "../Actor/Actor.h"
#include "../Map/GridTexture.h"
#include "../Game.h"

namespace SinGame
{
	class Crops : public Actor
	{
	public:
		enum CropState
		{
			EGrowing,
			ECompleted,
		};

		Crops(class Game* game);

		void SetGridTexture(GridTexture tex);

		void UpdateActor(double deltaTime) override;

		void SetGrowLevel(int level) { mGrowLevel = level; }
		int GetGrowLevel() { return mGrowLevel; }

		void SetMaxGrowLevel(int level) { mMaxGrowLevel = level; };

	private:
		void UpdateTexture();
		class SpriteComponent* mSprite;

		GridTexture mGridTexture;

		CropState mCropState;
		int mGrowLevel = 0;
		int mMaxGrowLevel = 10;
	};
}

#pragma once

#include "../Actor/Actor.h"
#include "../Map/GridTexture.h"
#include "../Component/CropComponent.h"
#include "../Component/CircleComponent.h"
#include "../Component/SpriteComponent.h"
#include "../Game.h"

namespace SinGame
{
	class Crops : public Actor
	{
	public:

		Crops(class Game* game);

		void SetGridTexture(GridTexture tex);

		void UpdateActor(double deltaTime) override;

		class CropComponent* GetCropComponent() { return mCrop; }
		class CircleComponent* GetCircle() { return mCircle; }

		int GetGrowLevel();
		void SetGrowLevel(int growLevel);

	private:
		void UpdateTexture();
		class CircleComponent* mCircle;
		class SpriteComponent* mSprite;
		class CropComponent* mCrop;

		GridTexture mGridTexture;
	};
}

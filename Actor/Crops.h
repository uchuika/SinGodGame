#pragma once

#include "../Component/SpriteComponent.h"
#include "../Actor/Actor.h"
#include "../Game.h"

namespace SinGame
{
	class Crops : public Actor
	{
	public:
		Crops(class Game* game);

		void SetTexture(Texture tex);

		void UpdateActor(double deltaTime) override;

		void SetGrowLevel(int level) { mGrowLevel = level; }
		int GetGrowLevel() { return mGrowLevel; }

		void SetMaxGrowLevel(int level) { mMaxGrowLevel = level; };

	private:
		void UpdateTexture();
		class SpriteComponent* mSprite;

		Texture mTexture;

		int mGrowLevel = 0;
		int mMaxGrowLevel = 10;
	};
}

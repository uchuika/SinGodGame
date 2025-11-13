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

		void UpdateActor(double deltaTime) override;

	private:
		class SpriteComponent* mSprite;

		Texture mTexture;
	};
}

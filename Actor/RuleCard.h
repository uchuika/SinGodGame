#pragma once

#include "../Actor/Actor.h"
#include "../Game.h"

namespace SinGame
{
	class RuleCard : public Actor
	{
	public:
		RuleCard(class Game* game);

		void SetBaseCardTexture(Texture baseTex);

		void UpdateActor(double deltaTime) override;

	private:
		void UpdateTexture();
		class SpriteComponent* mSprite;

		Texture mBaseCardTexture;
	};
}

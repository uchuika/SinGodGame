#pragma once

#include "../Component/UISpriteComponent.h"
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
		class UISpriteComponent* mUISprite;

		Rect collisionRect;

		Texture mBaseCardTexture;
	};
}

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

		bool IsMouseOver();

		bool IsPressed();

		//ルールクラスをセット
		void SetRule(class Rule* rule);

		//ルールを適用
		void ApplyRule();

	private:
		void UpdateTexture();
		class UISpriteComponent* mUISprite;

		RectF collisionRect;

		Texture mBaseCardTexture;

		Rule* mRule;
	};
}

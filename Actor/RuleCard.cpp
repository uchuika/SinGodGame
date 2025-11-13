#include "RuleCard.h"
#include "../Component/SpriteComponent.h"

using namespace SinGame;

RuleCard::RuleCard(class Game* game)
	:Actor(game)
{
	mUISprite = new UISpriteComponent(this);
	collisionRect = RectF{ GetPosition().x, GetPosition().y, 360, 640 };
}

void RuleCard::UpdateActor(double deltaTime)
{
	collisionRect.x = GetPosition().x-180;
	collisionRect.y = GetPosition().y-320;
}

void RuleCard::SetBaseCardTexture(Texture baseTex)
{
	mBaseCardTexture = baseTex;
	UpdateTexture();
}

bool RuleCard::IsMouseOver()
{
	if(collisionRect.mouseOver())
	{
		Print << U"mouseOver";
	}

	return collisionRect.mouseOver();
}

void RuleCard::UpdateTexture()
{
	mUISprite->SetTexture(mBaseCardTexture);
}


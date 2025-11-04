#include "RuleCard.h"
#include "../Component/SpriteComponent.h"

using namespace SinGame;

RuleCard::RuleCard(class Game* game)
	:Actor(game)
{
	mSprite = new SpriteComponent(this);
}

void RuleCard::UpdateActor(double deltaTime)
{
	
}

void RuleCard::SetBaseCardTexture(Texture baseTex)
{
	mBaseCardTexture = baseTex;
	UpdateTexture();
}

void RuleCard::UpdateTexture()
{
	mSprite->SetTexture(mBaseCardTexture);
}


#include "Crops.h"
#include "../Component/SpriteComponent.h"

using namespace SinGame;

Crops::Crops(class Game* game)
	:Actor(game)
{
	mSprite = new SpriteComponent(this);
}

void Crops::UpdateActor(double deltaTime)
{

}

#include "DirtTile.h"
#include "../Game.h"
#include "../Actor/Actor.h"
#include "../Component/SpriteComponent.h"

using namespace SinGame;

DirtTile::DirtTile(class Game* game)
	:Actor(game)
{
	SpriteComponent* sc = new SpriteComponent(this, 150);
	sc->SetTexture(Texture{ U"exmaple/windmill.png" });
}

void DirtTile::UpdateActor(double deltaTime)
{

}

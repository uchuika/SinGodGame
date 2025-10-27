#include "DirtTile.h"
#include "../Game.h"
#include "../Actor/Actor.h"
#include "../Component/SpriteComponent.h"

using namespace SinGame;

DirtTile::DirtTile(class Game* game)
	:Actor(game)
{
	SpriteComponent* sc = new SpriteComponent(this, 150);
	const Texture texture1{ U"example/windmill.png" };
	sc->SetTexture( texture1 );
	Logger << U"DirtTile::Init";
}

void DirtTile::UpdateActor(double deltaTime)
{

}

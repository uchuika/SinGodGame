#include "DirtTile.h"
#include "../Game.h"
#include "../Actor/Actor.h"
#include "../Component/SpriteComponent.h"
#include "../Constants.h"

using namespace SinGame;
using namespace Constants;

DirtTile::DirtTile(class Game* game)
	:Actor(game)
{

	Logger << U"DirtTile::Init";
	//const Texture texture1{ U"example/windmill.png" };
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/DirtTile1.png"));
	
}

void DirtTile::UpdateActor(double deltaTime)
{
}

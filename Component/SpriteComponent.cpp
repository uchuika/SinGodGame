#include "SpriteComponent.h"

using namespace SinGame;

SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
	:Component(owner)
	,mTexture(Texture{ U"リンゴ"_emoji })
	, mDrawOrder(drawOrder)
{
	mOwner -> GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw()
{
	
	if (not mTexture.isEmpty())
	{
		//Logger << U"SpriteComponent::Draw";
		mTexture.drawAt(mOwner->GetPosition());
	}
}

void SpriteComponent::SetTexture(Texture texture)
{
	mTexture = texture;
}



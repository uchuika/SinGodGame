#include "UISpriteComponent.h"

using namespace SinGame;

UISpriteComponent::UISpriteComponent(Actor* owner, int drawOrder)
	:Component(owner)
	,mTexture(Texture{ U"リンゴ"_emoji })
	,mDrawOrder(drawOrder)
{
	mOwner->GetGame()->AddUISprite(this);
}

UISpriteComponent::~UISpriteComponent()
{
	mOwner->GetGame()->RemoveUISprite(this);
}

void UISpriteComponent::Draw()
{
	if (not mTexture.isEmpty() && mOwner->GetState() == Actor::EActive)
	{

		mTexture.scaled(mOwner->GetScale()).drawAt(mOwner->GetPosition());
	}
}

void UISpriteComponent::SetTexture(Texture texture)
{
	mTexture = texture;
}


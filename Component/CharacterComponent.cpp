#include "CharacterComponent.h"

using namespace SinGame;

CharacterComponent::CharacterComponent(Actor* owner, int drawOrder)
	:Component(owner)
	, mCharaTexture(Texture{ U"リンゴ"_emoji })
	, mDrawOrder(drawOrder)
	, direction(0)
	,animationIndex(0)
{
	mOwner->GetGame()->AddCharacter(this);
}

CharacterComponent::~CharacterComponent()
{
	mOwner->GetGame()->RemoveCharacter(this);
}

void CharacterComponent::Draw()
{
	if (not mCharaTexture.isEmpty())
	{
		mCharaTexture((20 * animationIndex), (28 * direction), 20, 28).scaled(mOwner->GetScale()).drawAt(mOwner->GetPosition());
	}
}

void CharacterComponent::SetCharaTexture(Texture texture)
{
	mCharaTexture = texture;
}

void CharacterComponent::SetTexState(int texState)
{
	direction = 6 / texState;
	animationIndex = 6 % texState;
}



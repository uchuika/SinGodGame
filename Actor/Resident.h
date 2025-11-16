#pragma once

#include "../Actor/Actor.h"
#include "../Game.h"

namespace SinGame
{
	class Resident : public Actor
	{
	public:
		Resident(class Game* game);

		void SetGridTexture(Array<Texture>& textures);
		void SetTileTexture(int texnum);

		//void SetFaithLevel(int level) { mFaithLevel = level; }
		int GetFaithLevel() { return mFaithLevel; }

		void SetTempLevel(int templevel) { TempLevel = templevel; }
		int GetTempLevel() { return TempLevel; }

		void SetHangryLevel(int hangryLevel) { HangryLevel = hangryLevel; }
		int GetHangryLevel() { return HangryLevel; }

		void SetWalkProgress(double progress) { mWalkProgress = progress; }
		double GetWalkProgress() { return mWalkProgress; }

		void SetGoalPoint(Vec2 point) { goalPoint = point; }
		Vec2 GetGoalPoint() { return goalPoint; }

		class CircleComponent* GetCircle() { return mCircle; }

		void UpdateActor(double deltaTime) override;

	private:
		void UpdateTexture();
		class SpriteComponent* mSprite;
		class CircleComponent* mCircle;

		Array<Texture> mGridTextures;

		Vec2 goalPoint;
		int mTextureNum;

		const double interval = 2.0;
		double accumlatedTime = 0.0;

		int HangryLevel;
		int TempLevel;
		int mFaithLevel;
		double mWalkProgress = 1.0;
	};
}

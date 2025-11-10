#pragma once

#include "../Game.h"
#include "../Actor/DirtTile.h"
#include "../Actor/Tile.h"
#include "../Actor/Resident.h"
#include "../Actor/RuleCard.h"
#include "../Map/GridTexture.h"
#include "../Map/MapGrid.h"
#include "../Constants.h"
#include "../Component/SpriteComponent.h"
#include "../Component/CharacterComponent.h"
#include "../Component/UISpriteComponent.h"
#include "../Map/World.h"

namespace SinGame
{
	enum GameState
	{
		CardSelecting,
		GameProgress,
	};

	class GameScene : public AbstractScene
	{
	public:

		const static char* ParameterTagStage;	//パラメータのタグ「ステージ」
		const static char* ParameterTagLevel;	//パラメータのタグ「レベル」

		GameScene(IOnSceneChangedListener* impl, const Parameter& parameter, class Game* game);
		virtual ~GameScene() = default;

		void update() override;
		void draw() const override;
		void drawUI() override;
		EScene GetScene() const override;

	private:
		int _level;
		class Game* mGame;
		Array<class SpriteComponent*> sprites;
		Array<class CharacterComponent*> characters;
		Array<class UISpriteComponent*> uiSprites;
		Array<class Resident*> ResidentActors;
		Array<class RuleCard*> RuleCardActors;

		//NPCの行動を更新
		void npcUpdate();

		//世界の状態を更新
		void worldUpdate();

		GameState mGameState;

		MapGrid* grid;
		World* world;

		int mTargetFaithLevel = 0;
		int mTotalFaithLevel = 0;
		double mTempLevel = 15.0;

		Font font{ FontMethod::MSDF, 48 };

		const double interval = 2.0;

		double accumlatedTime = 0.0;

		class Player* mPlayer;	//プレイヤーメンバ変数
	};
}

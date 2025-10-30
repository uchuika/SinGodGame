#pragma once

#include <Siv3D.hpp>
#include "../Game.h"
#include "../Actor/Actor.h" // 追加: Actorクラスの定義をインクルード

namespace SinGame
{
	class GameScene : public AbstractScene
	{
	public:

		const static char* ParameterTagStage;	//パラメータのタグ「ステージ」
		const static char* ParameterTagLevel;	//パラメータのタグ「レベル」

		GameScene(IOnSceneChangedListener* impl, const Parameter& parameter, class Game* game);
		virtual ~GameScene() = default;

		void update() override;
		void draw() const override;
		void drawUI() const override;
		EScene GetScene() const override;

	private:
		int _level;
		class Game* mGame;
		Array<class SpriteComponent*> sprites;
		Array<class CharacterComponent*> characters;
		Array<class Enemy*> enemieseActor;	//EnemyActorを格納するベクターs	

		//カウンタ
		int mCount = 0;	//ゲームループカウンタ

		Font font{ FontMethod::MSDF, 48 };

		class Player* mPlayer;	//プレイヤーメンバ変数
	};
}

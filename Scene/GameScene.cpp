#include <Siv3D.hpp>

#include "GameScene.h"
#include "../GameUIToolKit/GameUIToolKit.h"

using namespace SinGame;
using namespace GameUIToolKit;

const char* GameScene::ParameterTagStage = "ParameterTagStage";	//パラメータのタグ「ステージ」
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";	//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter, class Game* game)
	: AbstractScene(impl, parameter, game)
	, mGame(game)
	, accumlatedTime(0.0)
	, mTargetFaithLevel(30)		//目標とする信仰度を設定
	//, grid(game, 20, 20, GridTexture(Image{ U"Assets/Outside_A2.png" }))
{
	//初期化処理
	//全てのActorを削除
	for (auto e : mGame->GetActors())
	{
		e->SetState(Actor::State::EDead);
	}

	//_level = parameter.get(ParameterTagLevel);

	GridTexture gridTexture = GridTexture(Image{ U"Assets/Outside_A2.png" });
	//マップ生成
	grid = new MapGrid(game, 20, 20, gridTexture);
	world = new World(game);

	//ルールカード表示用Actorを初期化
	for(int i = 0; i < 3; i++)
	{
		RuleCard* card = new RuleCard(mGame);
		card->SetBaseCardTexture(mGame->GetTexture("Assets/BaseCardTexture.png"));
		card->SetPosition(Vec2(320 + i * 640, 540));
		card->SetScale(20);
		card->SetState(Actor::EPaused);

		RuleCardActors.push_back(card);
	}

	//住民のテクスチャマップ
	GridTexture resiGridTex = GridTexture(Image{ U"example/spritesheet/siv3d-kun-16.png" });

	//住人の初期化
	for (int i = 0; i < Random(5, 20); i++) {
		Resident* resi = new Resident(game);
		resi->SetGridTexture(resiGridTex.GetGridTextures());
		resi->SetPosition(Vec2(400 + grid->GetTileScale() * 32 * Random(0, 20), 300 + grid->GetTileScale() * 32 * Random(0, 20)));
		resi->SetScale(grid->GetTileScale());
		resi->SetGoalPoint(resi->GetPosition());

		ResidentActors.push_back(resi);
	}

	//作物の初期化
	for(int i = 0; i < Random(15,20); i++)
	{
		Crops* crop = new Crops(game);
		
		CropsActors.push_back(crop);
	}

	//ゲームを進行状態にする
	mGameState = GameState::GameProgress;
}

void GameScene::update()
{
	sprites = mGame->GetSprites();
	characters = mGame->GetCharacters();
	uiSprites = mGame->GetUISprites();

	npcUpdate();
	worldUpdate();

	switch (mGameState)
	{
		case GameProgress:
			if (mTargetFaithLevel <= mTotalFaithLevel)
			{
				for (auto ruleCard : RuleCardActors)
				{
					ruleCard->SetState(Actor::EActive);
				}

				//ゲームをカード選択状態にする
				mGameState = GameState::CardSelecting;

				mTargetFaithLevel *= 1.5;
			}
			break;
		case CardSelecting:
			bool mouseOver = false;
			
			//マウスが触れているかどうか判定
			for (auto ruleCard : RuleCardActors)
			{
				if(ruleCard->IsPressed())
				{
					mouseOver = true;
				}
			}

			if (mouseOver)
			{
				for (auto ruleCard : RuleCardActors)
				{
					ruleCard->SetState(Actor::EPaused);
				}
				//状態をゲーム進行中にする
				mGameState = GameState::GameProgress;
				mouseOver = false;
			}
			break;
	}

	//シーンチェンジ(タイトル画面に戻る)
	if (KeyEscape.down())
	{
		_implSceneChanged->onSceneChanged(true);
	}
}

void GameScene::draw() const
{
	Camera2D camera = mGame->GetCamera();
	const auto t = camera.createTransformer();

	for(SpriteComponent* sprite : sprites)
	{
		sprite->Draw();
	}

	for (CharacterComponent* chara : characters)
	{
		chara->Draw();
	}
}



void GameScene::npcUpdate()
{
	mTotalFaithLevel = 0;

	for (auto resi : ResidentActors)
	{
		//住人の温度をWorldの温度と同期
		resi->SetTempLevel(world->GetTempLevel());

		//信仰の合計を取得
		mTotalFaithLevel += resi->GetFaithLevel();

		//Todo : 住人の空腹度についての処理

		//住人の移動についての処理
		double walkSpeed = 0.1;
		//移動していない場合かつ確立で
		if (resi->GetGoalPoint() == resi->GetPosition() && Random(1,100) % 100==0)
		{
			Vec2 goalPoint = resi->GetGoalPoint();
			//direcion(0:↓ 1:← 2:→ 3:↑)
			//向きを決定
			int direction = Random(0, 3);

			//↓向き
			if (direction == 0)
			{
				goalPoint.y += 64;
				resi->SetTileTexture(0);
			}
			//→向き
			else if (direction == 1)
			{
				goalPoint.x += 64;
				resi->SetTileTexture(2);
			}
			//←向き
			else if (direction == 2)
			{
				goalPoint.x -= 64;
				resi->SetTileTexture(1);
			}
			//↑向き
			else if (direction == 3)
			{
				goalPoint.y -= 64;
				resi->SetTileTexture(3);
			}

			goalPoint.x = Clamp<double>(goalPoint.x, 400, 400 + 32 * 19 * grid->GetTileScale());
			goalPoint.y = Clamp<double>(goalPoint.y, 300, 300 + 32 * 19 * grid->GetTileScale());

			resi->SetGoalPoint(goalPoint);
			resi->SetWalkProgress(0.0);

		}
		else {
			double progress = resi->GetWalkProgress();
			resi->SetWalkProgress(progress += (Scene::DeltaTime() * walkSpeed));

			Vec2 newPosition = resi->GetPosition().lerp(resi->GetGoalPoint(), progress);
            resi->SetPosition(newPosition);
			if (1.0 <= progress)
			{
				//現在地をgoalPointにして終了
				resi->SetPosition(resi->GetGoalPoint());
			}
		}
	}
}

void GameScene::worldUpdate()
{
	accumlatedTime += Scene::DeltaTime();
	if (interval <= accumlatedTime)
	{
		world->Update();
		accumlatedTime = 0.0;
	}
}

void GameScene::drawUI()
{
	constexpr ColorF barBackgroundColor(0.2, 0.8);

	const Array<std::pair<double, ColorF>> barColors = {
		{ 0.15, ColorF(0.8, 0.2, 0.0) }, // 15 % 未満は赤
		{ 0.5, ColorF(0.8, 0.6, 0.1) }, // 50 % 未満はオレンジ
		{ 1.0, ColorF(0.1, 0.8, 0.2) }, // それ以外は緑
	};

	double TempLevel = world->GetTempLevel();
	font(U"現在の信仰度: {}"_fmt(mTotalFaithLevel)).draw(0, 0);
	font(U"目的の信仰度: {}"_fmt(mTargetFaithLevel)).draw(0, 48);

	SimpleGUI::Slider(U"温度: {:.2f}"_fmt(TempLevel), TempLevel, 0.0, 40.0, Vec2{ 500, 40 });

	world->SetTempLevel(static_cast<int>(TempLevel));

	ProgressBar(Rect(700, 40, 320, 25), barBackgroundColor, barColors)
		.draw(TempLevel, 40);

	for (UISpriteComponent* ui : uiSprites)
	{
		ui->Draw();
	}
}

EScene GameScene::GetScene() const
{
	return EScene::Game;
}

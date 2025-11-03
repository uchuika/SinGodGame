#include <Siv3D.hpp>

#include "GameScene.h"

using namespace SinGame;

const char* GameScene::ParameterTagStage = "ParameterTagStage";	//パラメータのタグ「ステージ」
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";	//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter, class Game* game)
	: AbstractScene(impl, parameter, game)
	, mGame(game)
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

	//住民のテクスチャマップ
	GridTexture resiGridTex = GridTexture(Image{ U"example/spritesheet/siv3d-kun-16.png" });

	for (int i = 0; i < Random(5, 20); i++) {
		Resident* resi = new Resident(game);
		resi->SetGridTexture(resiGridTex.GetGridTextures());
		resi->SetPosition(Vec2(400 + grid->GetTileScale() * 32 * Random(0, 20), 300 + grid->GetTileScale() * 32 * Random(0, 20)));
		resi->SetScale(grid->GetTileScale());
		resi->SetGoalPoint(resi->GetPosition());

		ResidentActors.push_back(resi);
	}	
}

void GameScene::update()
{
	sprites = mGame->GetSprites();
	characters = mGame->GetCharacters();

	npcUpdate();
	worldUpdate();

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
		resi->SetTempLevel(mTempLevel);
		mTotalFaithLevel += resi->GetFaithLevel();

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

            // 修正後:
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

}

void GameScene::drawUI()
{
	font(U"現在の信仰度: {}"_fmt(mTotalFaithLevel)).draw(0, 0);

	SimpleGUI::Slider(U"温度: {:.2f}"_fmt(mTempLevel), mTempLevel, 0.0, 40.0, Vec2{ 500, 40 });


	
}

EScene GameScene::GetScene() const
{
	return EScene::Game;
}

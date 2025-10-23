# include <Siv3D.hpp> // Siv3D v0.6.16
#include "Game.h"
#include "Constants.h"

void Main()
{
	//windowタイトルを決定する
	Window::SetTitle(Constants::GameIdentityTitleName);

	// 背景の色を設定する
	Scene::SetBackground(Constants::Gold);
	Scene::SetResizeMode(ResizeMode::Keep);
	Scene::Resize(1920, 1080);
	Window::Resize(1600, 900);
	System::SetTerminationTriggers(UserAction::CloseButtonClicked);

	class Game game;
	bool succes = game.Inisitalize();
	while (System::Update())
	{
		game.RunLoop();
	}
	game.Shutdown();
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//

#pragma once

class Game
{
public:
	Game();
	bool Inisitalize();
	void RunLoop();
	void Shutdown();

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();
};

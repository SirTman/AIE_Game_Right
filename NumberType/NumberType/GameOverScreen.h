#pragma once
#include <string>
class GameOverScreen
{
public:
	bool m_QuitGame;
	GameOverScreen();
	bool GameOverManGameOver();
	~GameOverScreen();
private:
	bool m_GoingToRestart = true;
	std::string m_OptionTXT;

};


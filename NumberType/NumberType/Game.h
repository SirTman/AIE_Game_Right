#pragma once
#include <string>
class Game
{
public:
	Game();
	bool m_GameOver = false;
	
	void RunningGame(int Min, int Max);
	~Game();
private:
	int m_timer;
	int m_MinNumRange; //The minimual number the computor will guess
	int m_MaxNumRange; //The maximun number the computor will guess
	std::string m_YesNoInput; //Plays Choice text
	int m_RoundNum = 0; //How long the game has gone on for
	int m_Selection = 0; //0 = Higher; 1 = Lower; 3 = Correct

};


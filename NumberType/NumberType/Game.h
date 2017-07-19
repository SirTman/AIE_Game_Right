#pragma once
class Game
{
public:
	Game();
	bool m_GameOver = false;
	
	void RunningGame(int timer);
	~Game();
private:
	int m_currentLife;
	int m_timer;

};


#pragma once
#include <string>
class GameState
{
	friend class GameStateManager;
public:
	GameState() {}
	virtual ~GameState() {}
	bool isActive() const { return m_active; }

protected:

	void enter() { m_active = true; onEnter(); } 
	void exit() { m_active = false; onExit(); } 
	
	virtual void onUpdate(float deltaTime) = 0; 
	virtual void onDraw() = 0;

	// can be overwritten in derived classes that need to behave 
	// in certain ways when activated/deactivated or pushed/popped 
	virtual void onEnter() {} 
	virtual void onExit() {} 
	virtual void onPushed() {} 
	virtual void onPopped() {}

private:
	bool m_active = false;
};

class SplashScreen : public GameState
{
	public:
		SplashScreen();
		virtual void RunningSplash();
		~SplashScreen();
	private:
		std::string m_title = "Char Snap";
		std::string m_flashText = "[Press Enter]";
		int m_counter = 0;
		bool m_ShowFlashText = true;

		bool m_KeyPressed = false;
};

class Game : public GameState 
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

class GameOverScreen : public GameState
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
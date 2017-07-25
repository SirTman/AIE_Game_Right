#pragma once
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime> 
#include <algorithm>
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
		virtual ~SplashScreen();

		virtual void onUpdate(float deltaTime) {}
		virtual void onDraw() 
		{
			m_KeyPressed = false;
			for (int i = 0; true;)
			{
				system("cls");
				std::cout << m_title + "\n";
				if (m_ShowFlashText == true)
				{
					std::cout << m_flashText;
					m_ShowFlashText = false;
				}
				else
				{
					m_ShowFlashText = true;
				}
				//True False Flipper
				Sleep(1000);
				if (GetKeyState(VK_RETURN) & 0x8000) { break; } //Stops the loop changeing it to the start game state
			}
		}

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
		virtual ~Game();

		virtual void onUpdate(float deltaTime) {};
		virtual void onDraw(int Min, int Max)
		{
			std::srand((unsigned)time(0));
			//Count in Timer
			int CountIn = 3;
			for (int i = 0; CountIn >= 0; i++)
			{
				Sleep(1000);
				system("cls");
				std::cout << "I want you to think of a number between 1 & 100; I'll guess it~" << "\n";
				std::cout << CountIn;
				CountIn -= 1;
			};

			//Game
			m_MinNumRange = Min;
			m_MaxNumRange = Max;
			do {
				m_RoundNum++;
				int range = (m_MaxNumRange - m_MinNumRange) + 1;
				system("cls");
				int NumberGuess = m_MinNumRange + int(range*rand() / (RAND_MAX + 1)); //Picks a random number between the (MaxNumRange = 100) and (MinNumRange = 1) 
				do {
					system("cls");
					if (m_Selection == 0)
					{
						m_YesNoInput = "[Higher]   Lower    Correct";
					}
					else if (m_Selection == 1)
					{
						m_YesNoInput = " Higher   [Lower]   Correct";
					}
					else if (m_Selection == 2)
					{
						m_YesNoInput = " Higher    Lower    [Correct]";
					}
					std::cout << "Round #" << m_RoundNum << "\nIs it" << "\n" << NumberGuess << "\nHigher, Lower or Yes?\n";
					std::cout << m_YesNoInput;

					if (GetKeyState(VK_LEFT) & 0x8000) //Left Arrow Key
					{
						m_Selection -= 1;
						Sleep(100);
						continue;
					}
					if (GetKeyState(VK_RIGHT) & 0x8000) //Right Arrow Key
					{
						m_Selection += 1;
						Sleep(100);
						continue;
					}
					if (m_Selection < 0) { m_Selection = 0; };
					if (m_Selection > 3) { m_Selection = 3; };

					if (GetKeyState(VK_RETURN) & 0x8000) //Enter is Pressed
					{
						break;
					}
				} while (true);

				system("cls");
				if (m_Selection == 2) //If the Computor got it right
				{
					std::cout << "\nHa! I win!";

					//Whitty statement based on if the computor guessed in 10 turns or less
					if (m_RoundNum <= 10)
					{
						std::cout << "\n" << m_RoundNum << " rounds isn't bad\n";
					}
					//statement based on if the computor guessed in more than 10 turns
					else if (m_RoundNum > 10)
					{
						std::cout << "\n" << m_RoundNum << " rounds eh I need to do some more work\n";
					}

					while (true) { if (GetKeyState(VK_RETURN) & 0x8000) { break; } } //Wait for input
					break;
				}
				if (m_MaxNumRange == m_MinNumRange) //If the Player is cheating
				{
					std::cout << "Wait no! Your cheating\nI'm not going to play anymore";
					while (true) { if (GetKeyState(VK_RETURN) & 0x8000) { break; } } //Wait for input
					break;

				}
				else if (m_Selection == 0) //Player says the number is higher
				{
					m_MinNumRange = NumberGuess + 1; //Sets the minimal range to the last number guessed
				}
				else if (m_Selection == 1) //Player says the number is lower
				{
					m_MaxNumRange = NumberGuess - 1; //Sets the manimun range to the last number guessed
				}
			} while (true);
		};

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
		virtual void onUpdate(float deltaTime) {};
		virtual void onDraw() 
		{
			system("cls");
			do {
				system("cls");
				if (m_GoingToRestart == true)
				{
					m_OptionTXT = "[Yes]   NO";
				}
				else
				{
					m_OptionTXT = " Yes   [NO]";
				}
				std::cout << "Play Agian?\n";
				std::cout << m_OptionTXT;

				if (GetKeyState(VK_LEFT) & 0x8000) //Left Arrow Key
				{
					m_GoingToRestart = true;
					continue;
				}

				if (GetKeyState(VK_RIGHT) & 0x8000) //Right Arrow Key
				{
					m_GoingToRestart = false;
					continue;
				}

				if (GetKeyState(VK_RETURN) & 0x8000) //Enter is Pressed
				{
					break;
				}

			} while (true);
			//return m_GoingToRestart;
		};

		virtual ~GameOverScreen();
	private:
		bool m_GoingToRestart = true;
		std::string m_OptionTXT;
};
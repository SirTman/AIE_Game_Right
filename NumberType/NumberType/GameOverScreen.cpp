#include "GameOverScreen.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>


GameOverScreen::GameOverScreen(){}

bool GameOverScreen::GameOverManGameOver() 
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
		
	} while(true);
	return m_GoingToRestart;
};

GameOverScreen::~GameOverScreen(){}

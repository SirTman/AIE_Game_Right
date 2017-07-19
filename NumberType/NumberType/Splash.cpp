#include "Splash.h"
#include <Windows.h>
#include <iostream>
#include <stdlib.h>

Splash::Splash()
{
}
void Splash::RunningSplash()
{
	do
	{
		Sleep(500);
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
		if (GetKeyState(VK_RETURN) & 0x8000) { m_KeyPressed = true; } //Stops the loop changeing it to the start game state
	} while (m_KeyPressed == false);

};


Splash::~Splash()
{
}

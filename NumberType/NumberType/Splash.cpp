#include "Splash.h"
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

Splash::Splash()
{
}
void Splash::RunningSplash()
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

};


Splash::~Splash()
{
}

#include "Splash.h"
#include <Windows.h>
#include <iostream>
#include <stdlib.h>

Splash::Splash()
{
}
void Splash::RunningSplash()
{
	m_KeyPressed = false;
	for (int i = 0; true; i++)
	{
		system("cls");
		std::cout << m_title + "\n";
		if (m_ShowFlashText = true)
		{
			std::cout << m_flashText;
		}
		
		//True False Flipper
		if (i%5)
		{
			if (m_ShowFlashText = true){m_ShowFlashText = false;}
			else { m_ShowFlashText = true; }
		}
		if (GetKeyState(VK_RETURN) & 0x8000) { break; } //Stops the loop changeing it to the start game state
	} 

};


Splash::~Splash()
{
}

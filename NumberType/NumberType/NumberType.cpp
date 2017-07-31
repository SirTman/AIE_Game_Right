// NumberType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

#include "GameState.h"
#include "GameStateManager.h"
#include "NumberType.h"

int main()
{
	//Inisalise all the Class flies
	unsigned int NumOfStates = 4;
	int CurrentGameState = 0;
	bool PushNew = false;

	GameStateManager ThisGame(NumOfStates);
	SplashScreen* splash = new SplashScreen;
	Game* theGame = new Game;
	GameOverScreen* GOS = new GameOverScreen;
	
	ThisGame.registerState(0, splash);
	ThisGame.registerState(1, theGame);
	ThisGame.registerState(2, GOS);
	
	ThisGame.pushState(CurrentGameState);
	int A_Number = 1;
	
	while (true) 
	{
		if (PushNew) { ThisGame.pushState(CurrentGameState);}

		ThisGame.update(A_Number);
		ThisGame.draw();
		
		if (GOS->m_QuitGame == true) {}
	}
	system("pause");
	return 0;
}


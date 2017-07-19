// NumberType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

#include "Splash.h"
#include "Game.h"
#include "DiffcultySelect.h"
#include "GameOverScreen.h"

int main()
{
	//Inisalise all the Class flies
	Splash oSplash;
	Game oGame;
	GameOverScreen oGameOverScreen;
	DiffcultySelect oDiffcultySelect;

	//Manages all the states
	bool Restart;
	do {
		oSplash.RunningSplash();//Spash Screen
		oGame.RunningGame(5);//The Game
		Restart = oGameOverScreen.GameOverManGameOver();//Game Over
	} while (Restart == true);
	
	return 0;
}


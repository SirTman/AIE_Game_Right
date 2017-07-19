// NumberType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
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
	oSplash.RunningSplash();
	oGame.RunningGame(5);
	return 0;
}


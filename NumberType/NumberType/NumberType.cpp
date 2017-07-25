// NumberType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

#include "GameState.h"
#include "GameStateManager.h"

int main()
{
	//Inisalise all the Class flies
	
	GameStateManager ThisGame(4);
	SplashScreen* splash = new SplashScreen;
	Game* oGame = new Game;
	GameOverScreen* GOS = new GameOverScreen;
	
	ThisGame.registerState(0, splash);
	ThisGame.registerState(1, oGame);
	ThisGame.registerState(2, GOS);

	//Manages all the states
	bool Restart;
	int MinMax[2];
	oSplash.RunningSplash(); //Spash Screen
	do {
		/* 
		oDiffcultySelect.RangeSet(); Dificulty //DIffculty Select
		oGame.RunningGame(oDiffcultySelect.m_MIN, oDiffcultySelect.m_MAX); //The Game 
		*/
		
		oGame.RunningGame(1, 100); //The Game
		Restart = oGameOverScreen.GameOverManGameOver(); //Game Over
	} while (Restart == true);
	
	return 0;
}


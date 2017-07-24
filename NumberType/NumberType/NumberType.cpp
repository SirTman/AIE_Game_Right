// NumberType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

#include "GameState.h"
#include "GameStateManager.h"

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


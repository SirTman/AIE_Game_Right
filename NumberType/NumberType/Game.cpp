#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime> 


Game::Game()
{
}
void Game::RunningGame(int timer)
{
	std::srand((unsigned)time(0));
	int initalTimer = timer;
	//Count in Timer
	int const CountIn = 3;
	for (int i = 0; timer >= 0; i++) 
	{
		Sleep(1000);
		system("cls");
		std::cout << timer;
		timer -= 1;
	};
	
	//Game
	system("cls");
	char LifeIndicator[5] = { '[','0','0','0',']' };
	char TryingToMatch = 'A' + (rand() % 26) + 1;
	char RndChar = 'A' + (rand() % 26) + 1;
	//Game Timer
	for (int i = 0; timer >= 0; i++)
	{
		Sleep(1000);
		system("cls");
		std::cout << timer;
		timer -= 1;
	};

};

Game::~Game()
{
}

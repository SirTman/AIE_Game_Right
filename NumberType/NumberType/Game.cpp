#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>


Game::Game()
{
}
void Game::RunningGame(int timer)
{
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

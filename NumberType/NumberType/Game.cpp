#include "Game.h"
#include <iostream>


Game::Game()
{
}
void Game::RunningGame(int timer)
{
	for (int i; timer <= 0; i++) 
	{
		std::cout << timer;
		timer - i;
		system("cls");
	};
};

Game::~Game()
{
}

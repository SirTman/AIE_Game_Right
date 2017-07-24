#include "GameStateManager.h"



GameStateManager::GameStateManager(unsigned int stateCount)
{
}

void registerState(int id, GameState* state) {};
void pushState(int id) {};
void popState() {};

void update(float deltaTime) {};

void draw() {};

GameStateManager::~GameStateManager()
{
}

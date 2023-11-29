#include "game.h"
#include "../xenity.h"

#include "../engine/class_registry/class_registry.h"
#include "testerino.h"
//#include "my_class.h"

Game *Game::game = nullptr;

/// <summary>
/// Init game
/// </summary>
void Game::Start()
{
	game = this;
	LoadGameData();

	//ClassRegistry::AddComponentClass<MyClass>("MyClass");
	ClassRegistry::AddComponentClass<Testerino>("Testerino");


	Debug::Print("Game::Start");
}

void Game::LoadGameData()
{
}

/// <summary>
/// Game loop
/// </summary>
void Game::Update()
{
}

GameInterface *CreateGame()
{
	return new Game();
}
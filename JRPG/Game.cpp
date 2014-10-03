#include "Game.h"

Game::Game()
{

};

Game::~Game()
{

}

void Game::SetScene(Scene newScene)
{
	scene = newScene;
}

Scene Game::GetScene()
{
	return scene;
}
#include "Game.h"

Game::Game()
{
	this->actualScene = 0;
};


Game::Game(int i)
{
	this->actualScene = i;
};

Game::~Game()
{

}

Game::Game(const Game& game){
	this->actualScene = game.actualScene;
}
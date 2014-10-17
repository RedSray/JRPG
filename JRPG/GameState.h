#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <boost\math\special_functions\round.hpp>

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Audio\Music.hpp>

#include <memory>

#include "Game.h"

#include "State.h"
#include "ExplorationGameState.h"



class GameState : public State
{
public:
	GameState();
	~GameState();

	virtual void OnEnter(sf::RenderWindow&);
	virtual void OnExit(sf::RenderWindow&);

	virtual StateType Update(sf::RenderWindow&, sf::Time); //return the ID of the new state or -1
	virtual void Render(sf::RenderWindow&);
	void ChangeState(StateType, sf::RenderWindow&);

private:
	std::unique_ptr<State> activeSubState;
	std::vector<sf::Texture> tilesetTextures;
	sf::Texture playerExplorationSpritesheet;

	std::shared_ptr<Game> game;

	sf::Music gameMusic;
	
};

#endif
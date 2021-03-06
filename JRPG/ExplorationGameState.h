#ifndef EXPLORATION_H
#define EXPLORATION_H

#include <SFML\Window\Keyboard.hpp>

#include "GameState.h"

const float movementSpeed = 4.0f;

class ExplorationGameState : public State
{
public:
	ExplorationGameState(std::shared_ptr<Game>);
	~ExplorationGameState();

	virtual void OnEnter(sf::RenderWindow&);
	virtual void OnExit(sf::RenderWindow&);

	virtual StateType Update(sf::RenderWindow&, sf::Time); //return the ID of the new state or -1
	virtual void Render(sf::RenderWindow&);

private:
	sf::Time AnimUpdateTimer;
	std::shared_ptr<Game> game;
};

#endif
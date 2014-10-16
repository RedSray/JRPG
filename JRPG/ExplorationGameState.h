#ifndef EXPLORATION_H
#define EXPLORATION_H

#include <SFML\Window\Keyboard.hpp>

#include "GameState.h"

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
	
	std::shared_ptr<Game> game;
};

#endif
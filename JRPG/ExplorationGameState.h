#ifndef EXPLORATION_H
#define EXPLORATION_H

#include "GameState.h"

class ExplorationGameState : public State
{
public:
	ExplorationGameState();
	~ExplorationGameState();

	virtual void OnEnter(sf::RenderWindow&);
	virtual void OnExit(sf::RenderWindow&);

	virtual StateType Update(sf::RenderWindow&, sf::Time); //return the ID of the new state or -1
	virtual void Render(sf::RenderWindow&);

private:

};

#endif
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <memory>

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
};

#endif
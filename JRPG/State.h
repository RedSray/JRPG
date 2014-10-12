#ifndef STATE_H
#define STATE_H

#include <iostream>

#include <SFML\Graphics\RenderWindow.hpp>

//actually it's the most conveniant place to put  that//
const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
//END//

enum StateType{
	NoState,
	Splash,
	Menu,
	GameScene,
	Exploration,
	IGMenu,
	Paused,
	Battle
};

class State
{
public:
	State();
	virtual ~State();

	virtual void OnEnter(sf::RenderWindow&) = 0;
	virtual void OnExit(sf::RenderWindow&) = 0;

	virtual StateType Update(sf::RenderWindow&, sf::Time) = 0; //return the ID of the new state or -1
	virtual void Render(sf::RenderWindow&) = 0;

private:
	State(const State&);
	State& operator=(const State&);
};

#endif
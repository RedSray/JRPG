#ifndef SPLASHSTATE_H
#define SPLASHSTATE_H

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\View.hpp>
#include <SFML\Graphics\Sprite.hpp>

#include "State.h"

class SplashState : public State
{
public:
	SplashState();
	~SplashState();

	virtual void OnEnter(sf::RenderWindow&);
	virtual void OnExit(sf::RenderWindow&);

	virtual StateType Update(sf::RenderWindow&, sf::Time); //return the ID of the new state or -1
	virtual void Render(sf::RenderWindow&);
	virtual void RenderGUI(sf::RenderWindow&);

private:
	sf::Texture splashTexture;
	sf::Sprite splash;
	sf::Time totalduration;
	float transparency;
};

#endif
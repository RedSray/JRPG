#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <vector>

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Window\Keyboard.hpp>

#include "State.h"

const float selectionAnimationDuration = 0.5f;

class MenuState : public State
{
public:
	MenuState();
	~MenuState();

	virtual void OnEnter(sf::RenderWindow&);
	virtual void OnExit(sf::RenderWindow&);

	virtual StateType Update(sf::RenderWindow&, sf::Time); //return the ID of the new state or -1
	virtual void Render(sf::RenderWindow&);

private:
	std::vector<sf::Text> menuItems;
	sf::Text title;
	sf::Font titleFont;
	sf::Font menuFont;
	int selectedItem;
	bool selectionAnimationInterverted;
	sf::Time selectionAnimationTime;
	sf::Time selectionChangeRepetitionTime;
	
	
};

#endif
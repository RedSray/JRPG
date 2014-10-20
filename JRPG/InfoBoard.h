#ifndef INFOBOARD_H
#define INFOBOARD_H

#include <SFML\Graphics\Text.hpp>

#include "Entity.h"

class InfoBoard : public Entity
{
public:
	InfoBoard();
	virtual ~InfoBoard();

	virtual void ExplorationUpdate(sf::RenderWindow&);
	virtual void InteractionUpdate(sf::RenderWindow&);

	virtual void ExplorationRender(sf::RenderWindow&);
	virtual void InteractionRender(sf::RenderWindow&);

	virtual void ExplorationGUIRender(sf::RenderWindow&);
	virtual void InteractionGUIRender(sf::RenderWindow&);
private:
	sf::Text test;
	sf::Font font;
};

#endif
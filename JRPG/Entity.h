#ifndef ENTITY_H
#define ENTITY_H
#include <memory>

#include <SFML\Graphics\RenderWindow.hpp>

class Entity
{
public:
	virtual ~Entity();

	virtual void ExplorationUpdate(sf::RenderWindow&) = 0;
	virtual void InteractionUpdate(sf::RenderWindow&) = 0;

	virtual void ExplorationRender(sf::RenderWindow&) = 0;
	virtual void InteractionRender(sf::RenderWindow&) = 0;

	virtual void ExplorationGUIRender(sf::RenderWindow&) = 0;
	virtual void InteractionGUIRender(sf::RenderWindow&) = 0;

private:
};

#endif
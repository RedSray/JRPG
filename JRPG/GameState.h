#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Window\Keyboard.hpp>

#include <memory>

#include "State.h"
#include "ExplorationGameState.h"

struct Tile
{
	sf::Vector2i positionInTexture; 
};

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
	sf::Texture tileset;
	std::vector<Tile> tiles;
	std::vector<std::vector<int>> map;
};

#endif
#include <SFML\Graphics.hpp>
#include "Game.h"
#include <SFML\System.hpp>

class RenderManager
{
public:
	RenderManager();
	~RenderManager();

	bool WindowIsOpen();
	void Update(Game);
	void PollEvent();

private:
	sf::RenderWindow* window;
	sf::CircleShape circle;
	sf::View view;
	float i;
	sf::Clock animUpdateClock;
	float animUpdateTime;
};

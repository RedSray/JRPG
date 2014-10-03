#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "Game.h"
#include "ResourcesManager.h"

class RenderManager
{
public:
	RenderManager(ResourcesManager*);
	~RenderManager();

	bool WindowIsOpen();
	void Update(Game);
	void PollEvent();

private:
	sf::RenderWindow* window;
	sf::CircleShape circle;
	sf::View view;

	ResourcesManager* resourcesManager;
};

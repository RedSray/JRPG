#include <SFML\Graphics.hpp>

class RenderManager
{
public:
	RenderManager();
	~RenderManager();

	bool WindowIsOpen();
	void Update();
	void PollEvent();

private:
	sf::RenderWindow* window;
	sf::CircleShape circle;
};

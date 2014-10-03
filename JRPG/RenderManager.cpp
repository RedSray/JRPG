#include "RenderManager.h"


RenderManager::RenderManager()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");
	view = sf::View(sf::Vector2f(0.0f,0.0f), sf::Vector2f(800.0f,600.0f));
	window->setView(view);
}

RenderManager::~RenderManager()
{
	delete window;
}

bool RenderManager::WindowIsOpen()
{
	return window->isOpen();
}

void RenderManager::Update(Game game){

	window->setView(view);
	window->clear();
    window->draw(game.GetScene().GetCircle());
    window->display();
}

void RenderManager::PollEvent(){
	 sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}
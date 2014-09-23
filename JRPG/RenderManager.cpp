#include "RenderManager.h"

RenderManager::RenderManager()
{
	window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
	circle.setRadius(100.0f);
    circle.setFillColor(sf::Color::Green);
}

RenderManager::~RenderManager()
{
	delete window;
}

bool RenderManager::WindowIsOpen()
{
	return window->isOpen();
}

void RenderManager::Update(){
	window->clear();
    window->draw(circle);
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
#include "Scene.h"

Scene::Scene()
{
	circle.setRadius(100.0f);
    circle.setFillColor(sf::Color::Green);
	circle.setOrigin(100,100);
	circle.setPosition(0.0f,0.0f);
}

Scene::~Scene()
{

}

sf::CircleShape Scene::GetCircle()
{
	return circle;
}
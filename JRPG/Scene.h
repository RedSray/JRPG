#ifndef SCENE_H
#define SCENE_H

#include <SFML\Graphics.hpp>

class Scene {
public:
	Scene();
	~Scene();

	sf::CircleShape GetCircle();

private: 
	sf::CircleShape circle;

};

#endif
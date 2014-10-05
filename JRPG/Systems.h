#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <SFML\Graphics.hpp>

#include "Scene.h"

class InputSystem
{
public:
	InputSystem();
	~InputSystem();

	void Init();
	void Update();

private:
};

class BehaviourSystem
{
public:
	BehaviourSystem();
	~BehaviourSystem();

	void Init();
	void Update(Scene*);

private:
};

class MouvementSystem
{
public:
	MouvementSystem();
	~MouvementSystem();

	void Init();
	void Update(Scene*);

private:
};

class AnimationSystem
{
public:
	AnimationSystem();
	~AnimationSystem();

	void Init();
	void Update(Scene*);

private:
};

const int TILESET_TILE_PIXELSIZE = 32;

class RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();

	void Init();

	bool WindowIsOpen();
	void PollEvent();

	void Update(Scene*);

private:
	sf::RenderWindow* window;
	sf::Texture tileset;
	int tilesetSizeX;//in number of tile
};

#endif
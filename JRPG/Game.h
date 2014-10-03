#ifndef GAME_H
#define GAME_H

#include "Scene.h"

class Game{

public:
	Game();
	~Game();

	void SetScene(Scene);
	Scene GetScene();

private:
	Scene scene;

};

#endif


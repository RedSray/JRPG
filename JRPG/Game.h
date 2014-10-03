#ifndef GAME_H
#define GAME_H

#include <string.h>

#include "Scene.h"
#include "ResourcesManager.h"

class Game{

public:
	Game(ResourcesManager*);
	~Game();

	void Init();

private:
	Scene scene;
	ResourcesManager* resourcesManager;
	std::map<std::string, std::string> levelFilesMap;///Scene name => Scene file pair 

	

};

#endif


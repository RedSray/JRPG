#include "RenderManager.h"
#include "Game.h"
#include "ResourcesManager.h"

class App {
public:
	App();
	~App();

	void Run();

private:
	RenderManager* renderManager;
	ResourcesManager* resourcesManager;
	Game* game;
};
#include "RenderManager.h"
#include "Game.h"

class App {
public:
	App();
	~App();

	void Run();

private:
	RenderManager* renderManager;
	Game game;
};
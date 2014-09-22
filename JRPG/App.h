#include "RenderManager.h"

class App {
public:
	App();
	~App();

	void Run();

private:
	RenderManager* renderManager;
};
#include "App.h"

App::App()
{
	renderManager = new RenderManager();
}

App::~App()
{
	delete renderManager;
}

void App::Run()
{
	while(renderManager->WindowIsOpen()){
		renderManager->PollEvent();
		renderManager->Update();
	}
}
#include "App.h"

App::App()
{
	scene = new Scene();

	/*inputSystem = new InputSystem();
	behaviourSystem = new BehaviourSystem();
	mouvementSystem = new MouvementSystem();
	animationSystem = new AnimationSystem();*/
	renderSystem = new RenderSystem();
};

App::~App()
{
	delete renderSystem;
	/*delete animationSystem;
	delete mouvementSystem;
	delete behaviourSystem;
	delete inputSystem;*/

	delete scene;
};

void App::Init()
{
	scene->Init();

	/*inputSystem->Init();
	behaviourSystem->Init();
	mouvementSystem->Init();
	animationSystem->Init();*/
	renderSystem->Init();
};

void App::Run()
{
	while(renderSystem->WindowIsOpen()){
		renderSystem->PollEvent();
		/*inputSystem->Update();
		behaviourSystem->Update(scene);
		mouvementSystem->Update(scene);
		animationSystem->Update(scene);*/
		renderSystem->Update(scene);
	}
};
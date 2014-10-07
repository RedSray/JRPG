#include "App.h"

App::App()
{
	fileManager = new FileManager();

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

	delete fileManager;
};

void App::Init()
{
	fileManager->LoadSceneFile("SceneFile.xml");
	sf::Vector2u size = fileManager->GetMapSize();
	scene->Init(size.x,size.y,fileManager->GetTileData());

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
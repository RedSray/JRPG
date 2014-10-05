#ifndef APP_H
#define APP_H

#include "Scene.h"
#include "Systems.h"

class App
{
public:
	App();
	~App();

	void Init();
	void Run();
	
private:
	App(const App&);
	App& operator= (const App&);

	Scene* scene;

	InputSystem* inputSystem;
	BehaviourSystem* behaviourSystem;
	MouvementSystem* mouvementSystem;
	AnimationSystem* animationSystem;
	RenderSystem* renderSystem;
};

#endif
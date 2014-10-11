#ifndef APP_H
#define APP_H

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include <memory>

#include "State.h"
#include "SplashState.h"
#include "MenuState.h"
#include "GameState.h"

class App
{
public:
	App();
	~App();

	void Init();
	void Run();

	void ChangeState(StateType);
	
private:
	App(const App&);
	App& operator= (const App&);
	sf::RenderWindow window;

	std::unique_ptr<State> activeState;
	sf::Clock clock;
	sf::Time lastFrameDuration;
};

#endif
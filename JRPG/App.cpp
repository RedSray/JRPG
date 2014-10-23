#include "App.h"

App::App()
{
	window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "JRPG",sf::Style::None);
	//window.setFramerateLimit(30);
};

App::~App()
{

};

void App::Init()
{
	ChangeState(StateType::Splash);
	clock.restart();
	lastFrameDuration = sf::Time::Zero;
};

void App::Run()
{
	while(window.isOpen()){
		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		StateType newState = activeState->Update(window, lastFrameDuration);

		window.clear(clearColor);
		activeState->Render(window);
		window.display();

		if(newState != StateType::NoState)  ChangeState(newState);
		lastFrameDuration = clock.restart();
	}
};

void App::ChangeState(StateType newState)
{
	if(activeState.get() != nullptr) activeState->OnExit(window);
	switch(newState)
	{
	case StateType::Splash:
		activeState.reset(new SplashState());
		clearColor = sf::Color::Black;
		break;
	case StateType::Menu:
		activeState.reset(new MenuState());
		clearColor = sf::Color(20,20,20,255);
		break;
	case StateType::GameScene:
		activeState.reset(new GameState());
		clearColor = sf::Color::Black;
		break;
	}
	activeState->OnEnter(window);
}
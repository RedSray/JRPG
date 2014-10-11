#include "App.h"

App::App()
{
	window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "JRPG",sf::Style::None);
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

		window.clear(sf::Color(20,20,20,255));
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
		break;
	case StateType::Menu:
		activeState.reset(new MenuState());
		break;
	case StateType::Game:
		activeState.reset(new GameState());
		break;
	}
	activeState->OnEnter(window);
}
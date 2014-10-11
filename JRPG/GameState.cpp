#include "GameState.h"

GameState::GameState()
{

}

GameState::~GameState()
{

}

void GameState::OnEnter(sf::RenderWindow& window)
{
	ChangeState(StateType::Exploration, window);
}

void GameState::OnExit(sf::RenderWindow& window)
{

}

StateType GameState::Update(sf::RenderWindow& window, sf::Time elapsedTime)
{
	return activeSubState->Update(window, elapsedTime);
}

void GameState::Render(sf::RenderWindow& window)
{
	activeSubState->Render(window);
}

void GameState::ChangeState(StateType newState, sf::RenderWindow& window)
{
	if(activeSubState.get() != nullptr) activeSubState->OnExit(window);
	switch(newState)
	{
	case StateType::Exploration:
		activeSubState.reset(new ExplorationGameState());
		break;
	case StateType::Battle:
		//activeSubState.reset(new MenuState());
		break;
	case StateType::IGMenu:
		//activeSubState.reset(new MenuState());
		break;
	case StateType::Paused:
		//activeSubState.reset(new MenuState());
		break;
	}
	activeSubState->OnEnter(window);
}
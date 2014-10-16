#include "ExplorationGameState.h"

ExplorationGameState::ExplorationGameState(std::shared_ptr<Game> gameFromParent)
{
	game = gameFromParent;
}

ExplorationGameState::~ExplorationGameState()
{

}

void ExplorationGameState::OnEnter(sf::RenderWindow& window)
{
	game->InitPlayerMovement();
}

void ExplorationGameState::OnExit(sf::RenderWindow& window)
{

}

StateType ExplorationGameState::Update(sf::RenderWindow& window, sf::Time lastFrameDuration)
{	

	if(std::abs(game->GetPlayerMoveGoal().x-game->GetPlayerWorldPosition().x) < 0.02f && std::abs(game->GetPlayerMoveGoal().y-game->GetPlayerWorldPosition().y) < 0.02f )
	{
		game->ReinitPlayerMovement();
				

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if(game->GetPlayerMoveGoal().y > 0.0f)
			{ 
				game->MovePlayer(MoveDirection::North);
				if(!game->IsCellWalkable(game->GetPlayerMoveGoal())) game->MovePlayer(MoveDirection::South);
				else game->SetPlayerSpeed('y', -4.0f);
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if(game->GetPlayerMoveGoal().y < game->GetMapSize().y-1.0f)
			{
				game->MovePlayer(MoveDirection::South);
				if(!game->IsCellWalkable(game->GetPlayerMoveGoal())) game->MovePlayer(MoveDirection::North);
				else game->SetPlayerSpeed('y', 4.0f);
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if(game->GetPlayerMoveGoal().x > 0.0f) 
			{
				game->MovePlayer(MoveDirection::West);
				if(!game->IsCellWalkable(game->GetPlayerMoveGoal())) game->MovePlayer(MoveDirection::East);
				else game->SetPlayerSpeed('x', -4.0f);
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if(game->GetPlayerMoveGoal().x < game->GetMapSize().x-1.0f)
			{
				game->MovePlayer(MoveDirection::East);
				if(!game->IsCellWalkable(game->GetPlayerMoveGoal())) game->MovePlayer(MoveDirection::West);
				else game->SetPlayerSpeed('x', 4.0f);
			}
		}
	}
	else
	{
		sf::Vector2f newPosition = game->GetPlayerWorldPosition();
		newPosition.x += game->GetPlayerSpeed().x*lastFrameDuration.asSeconds();
		newPosition.y += game->GetPlayerSpeed().y*lastFrameDuration.asSeconds();
		game->SetPlayerWorldPosition(newPosition);
	}

	

	return StateType::NoState;
}

void ExplorationGameState::Render(sf::RenderWindow& window)
{

}
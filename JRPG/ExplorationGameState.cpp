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
	moveGoal = game->GetPlayerWorldPosition();
	moveGoal.x = (int)moveGoal.x;
	moveGoal.y = (int)moveGoal.y;
	game->SetPlayerWorldPosition(moveGoal);
}

void ExplorationGameState::OnExit(sf::RenderWindow& window)
{

}

StateType ExplorationGameState::Update(sf::RenderWindow& window, sf::Time lastFrameDuration)
{
	if(std::abs(moveGoal.x-game->GetPlayerWorldPosition().x) < 0.01f && std::abs(moveGoal.y-game->GetPlayerWorldPosition().y) < 0.01f )
	{
		//reinit speed to 0
		playerSpeed.x = 0.0f;
		playerSpeed.y = 0.0f;
		//replace properly (try to remove float imprecision)
		moveGoal.x = boost::math::round<float>(moveGoal.x);
		moveGoal.y = boost::math::round<float>(moveGoal.y);
		game->SetPlayerWorldPosition(moveGoal);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if(moveGoal.y > 0.0f)
			{ 
				moveGoal.y -= 1.0f;
				std::cout << "movegoal : " << moveGoal.x << "/" << moveGoal.y << std::endl;
				std::cout << "walkable : " << game->IsCellWalkable(moveGoal) << std::endl;
				if(!game->IsCellWalkable(moveGoal)) moveGoal.y += 1.0f;
				else playerSpeed.y = -4.0f;
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if(moveGoal.y < game->GetMapSize().y-1.0f)
			{
				moveGoal.y += 1.0f;
				if(!game->IsCellWalkable(moveGoal)) moveGoal.y -= 1.0f;
				else playerSpeed.y = 4.0f;
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if(moveGoal.x > 0.0f) 
			{
				moveGoal.x -= 1.0f;
				if(!game->IsCellWalkable(moveGoal)) moveGoal.x += 1.0f;
				else playerSpeed.x = -4.0f;
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if(moveGoal.x < game->GetMapSize().x-1.0f)
			{
				moveGoal.x += 1.0f;
				if(!game->IsCellWalkable(moveGoal)) moveGoal.x -= 1.0f;
				else playerSpeed.x = 4.0f;
			}
		}
	}
	else
	{
		sf::Vector2f newPosition = game->GetPlayerWorldPosition();
		newPosition.x += playerSpeed.x*lastFrameDuration.asSeconds();
		newPosition.y += playerSpeed.y*lastFrameDuration.asSeconds();
		game->SetPlayerWorldPosition(newPosition);
	}

	

	return StateType::NoState;
}

void ExplorationGameState::Render(sf::RenderWindow& window)
{

}
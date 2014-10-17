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
			if(game->GetPlayerActiveAnime() != 0)
			{
				game->SetPlayerActiveAnim(0);
				game->SetPlayerActiveAnimFrame(0);
			}

			if(game->GetPlayerMoveGoal().y > 0.0f)
			{ 
				game->MovePlayer(MoveDirection::North);
				if(!game->IsCellWalkable(game->GetPlayerMoveGoal())) game->MovePlayer(MoveDirection::South);
				else game->SetPlayerSpeed('y', -4.0f);
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if(game->GetPlayerActiveAnime() != 1)
			{
				game->SetPlayerActiveAnim(1);
				game->SetPlayerActiveAnimFrame(0);
			}

			if(game->GetPlayerMoveGoal().y < game->GetMapSize().y-1.0f)
			{
				game->MovePlayer(MoveDirection::South);
				if(!game->IsCellWalkable(game->GetPlayerMoveGoal())) game->MovePlayer(MoveDirection::North);
				else game->SetPlayerSpeed('y', 4.0f);
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if(game->GetPlayerActiveAnime() != 2)
			{
				game->SetPlayerActiveAnim(2);
				game->SetPlayerActiveAnimFrame(0);
			}

			if(game->GetPlayerMoveGoal().x > 0.0f) 
			{
				game->MovePlayer(MoveDirection::West);
				if(!game->IsCellWalkable(game->GetPlayerMoveGoal())) game->MovePlayer(MoveDirection::East);
				else game->SetPlayerSpeed('x', -4.0f);
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if(game->GetPlayerActiveAnime() != 3)
			{
				game->SetPlayerActiveAnim(3);
				game->SetPlayerActiveAnimFrame(0);
			}
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

	if(0 == game->GetPlayerSpeed().x && 0 == game->GetPlayerSpeed().y)
	{
		game->SetPlayerActiveAnimFrame(0);
		AnimUpdateTimer = sf::Time::Zero;
	}
	
	//upate player animation
	
	if(AnimUpdateTimer.asSeconds() >= (1.0/game->GetPlayerActiveAnimFPS()))
	{
		std::cout << "update anim frame : " << AnimUpdateTimer.asSeconds() << "/" << 1.0/game->GetPlayerActiveAnimFPS() << std::endl;
		game->PlayerNextAnimFrame();
		AnimUpdateTimer = sf::Time::Zero;
	}
	else 
	{
		AnimUpdateTimer += lastFrameDuration;
	}

	return StateType::NoState;
}

void ExplorationGameState::Render(sf::RenderWindow& window)
{

}
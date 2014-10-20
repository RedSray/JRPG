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
	//std::abs(game->GetPlayerMoveGoal().x-game->GetPlayerWorldPosition().x) < 0.02f && std::abs(game->GetPlayerMoveGoal().y-game->GetPlayerWorldPosition().y) < 0.02f 
	if((game->GetPlayerSpeed().x > 0.0f && game->GetPlayerWorldPosition().x >= game->GetPlayerMoveGoal().x) || 
		(game->GetPlayerSpeed().x < 0.0f && game->GetPlayerWorldPosition().x <= game->GetPlayerMoveGoal().x) || 
		(game->GetPlayerSpeed().y > 0.0f && game->GetPlayerWorldPosition().y >= game->GetPlayerMoveGoal().y) || 
		(game->GetPlayerSpeed().y < 0.0f && game->GetPlayerWorldPosition().y <= game->GetPlayerMoveGoal().y) || 
		(0 == game->GetPlayerSpeed().x && 0 == game->GetPlayerSpeed().y))
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
				else game->SetPlayerSpeed('y', -movementSpeed);
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
				else game->SetPlayerSpeed('y', movementSpeed);
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
				else game->SetPlayerSpeed('x', -movementSpeed);
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
				else game->SetPlayerSpeed('x', movementSpeed);
			}
		}
	}
	
	sf::Vector2f newPosition = game->GetPlayerWorldPosition();

	newPosition.x += game->GetPlayerSpeed().x*lastFrameDuration.asSeconds();
	if(game->GetPlayerSpeed().x > 0.0 && newPosition.x > game->GetPlayerMoveGoal().x && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) newPosition.x = game->GetPlayerMoveGoal().x;
	if(game->GetPlayerSpeed().x < 0.0 && newPosition.x < game->GetPlayerMoveGoal().x && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) newPosition.x = game->GetPlayerMoveGoal().x;

	newPosition.y += game->GetPlayerSpeed().y*lastFrameDuration.asSeconds();
	if(game->GetPlayerSpeed().y > 0.0 && newPosition.y > game->GetPlayerMoveGoal().y && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) newPosition.y = game->GetPlayerMoveGoal().y;
	if(game->GetPlayerSpeed().y < 0.0 && newPosition.y < game->GetPlayerMoveGoal().y && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) newPosition.y = game->GetPlayerMoveGoal().y;

	game->SetPlayerWorldPosition(newPosition);
	

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

	for(int i =0; i < game->GetNbEntities(); ++i)
	{
		game->GetEntity(i)->ExplorationUpdate(window);
	}

	return StateType::NoState;
}

void ExplorationGameState::Render(sf::RenderWindow& window)
{
	for(int i =0; i < game->GetNbEntities(); ++i)
	{
		game->GetEntity(i)->ExplorationRender(window);
	}
}

void ExplorationGameState::RenderGUI(sf::RenderWindow& window)
{
	for(int i =0; i < game->GetNbEntities(); ++i)
	{
		game->GetEntity(i)->ExplorationGUIRender(window);
	}
}
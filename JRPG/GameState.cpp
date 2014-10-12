#include "GameState.h"

GameState::GameState()
{
	Game* gametemp = new Game();
	game.reset(gametemp);
}

GameState::~GameState()
{

}

void GameState::OnEnter(sf::RenderWindow& window)
{
	
	if(!tileset.loadFromFile("terrain.png"))
	{
		std::cout << "Error loading tileset" << std::endl;
	}

	if(!playerExplorationSpritesheet.loadFromFile("Kakashi.png"))
	{
		std::cout << "Error loading player spritesheet" << std::endl;
	}
	
	Tile tile;
	tile.positionInTexture.x = 0;
	tile.positionInTexture.y = 8;
	game->SetTile(tile);
	tile.positionInTexture.x = 0;
	tile.positionInTexture.y = 9;
	game->SetTile(tile);
	tile.positionInTexture.x = 0;
	tile.positionInTexture.y = 10;
	game->SetTile(tile);
	tile.positionInTexture.x = 1;
	tile.positionInTexture.y = 8;
	game->SetTile(tile);
	tile.positionInTexture.x = 1;
	tile.positionInTexture.y = 9;
	game->SetTile(tile);
	tile.positionInTexture.x = 1;
	tile.positionInTexture.y = 10;
	game->SetTile(tile);
	tile.positionInTexture.x = 2;
	tile.positionInTexture.y = 8;
	game->SetTile(tile);
	tile.positionInTexture.x = 2;
	tile.positionInTexture.y = 9;
	game->SetTile(tile);
	tile.positionInTexture.x = 2;
	tile.positionInTexture.y = 10;
	game->SetTile(tile);

	game->SetMap(40,40);

	game->SetPlayerWorldPosition(sf::Vector2f(19.0f,19.0f));

	sf::View view(sf::Vector2f(20.0f*32.0f,20.0f*32.0f), sf::Vector2f(800.0f,600.0f));
	window.setView(view);
	
	ChangeState(StateType::Exploration, window);
}

void GameState::OnExit(sf::RenderWindow& window)
{

}

StateType GameState::Update(sf::RenderWindow& window, sf::Time elapsedTime)
{
	sf::Vector2f speed(0.0f,0.0f);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) speed.x -= 200.0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) speed.x += 200.0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) speed.y += 200.0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) speed.y -= 200.0;

	sf::Vector2f center = window.getView().getCenter();
	center.x += speed.x*elapsedTime.asSeconds();
	center.y += speed.y*elapsedTime.asSeconds();
	sf::View view(center,sf::Vector2f(800.0f,600.0f));
	window.setView(view);

	return activeSubState->Update(window, elapsedTime);
}

void GameState::Render(sf::RenderWindow& window)
{
	
	sf::Sprite tileToRender;
	tileToRender.setTexture(tileset);
	tileToRender.setOrigin(16.0f,16.0f);

	for(int i = 0; i < game->GetMapSize().x; ++i)
	{
		for(int j = 0; j < game->GetMapSize().y; ++j)
		{
			tileToRender.setTextureRect(sf::IntRect(game->GetTile(game->GetMapCell(i,j)).positionInTexture.x*32,game->GetTile(game->GetMapCell(i,j)).positionInTexture.y*32,32,32));
			tileToRender.setPosition(i*32.0f,j*32.0f);
			window.draw(tileToRender);
		}
	}

	sf::Sprite playerSprite;
	playerSprite.setTexture(playerExplorationSpritesheet);
	playerSprite.setTextureRect(sf::IntRect(0,0,32,32));
	playerSprite.setOrigin(16.0f,16.0f);
	playerSprite.setPosition(game->GetPlayerWorldPosition().x*32.0f,game->GetPlayerWorldPosition().y*32.0f);
	window.draw(playerSprite);
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
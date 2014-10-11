#include "GameState.h"

GameState::GameState()
{

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

	Tile tile;
	tile.positionInTexture.x = 0;
	tile.positionInTexture.y = 8;
	tiles.push_back(tile);
	tile.positionInTexture.x = 0;
	tile.positionInTexture.y = 9;
	tiles.push_back(tile);
	tile.positionInTexture.x = 0;
	tile.positionInTexture.y = 10;
	tiles.push_back(tile);
	tile.positionInTexture.x = 1;
	tile.positionInTexture.y = 8;
	tiles.push_back(tile);
	tile.positionInTexture.x = 1;
	tile.positionInTexture.y = 9;
	tiles.push_back(tile);
	tile.positionInTexture.x = 1;
	tile.positionInTexture.y = 10;
	tiles.push_back(tile);
	tile.positionInTexture.x = 2;
	tile.positionInTexture.y = 8;
	tiles.push_back(tile);
	tile.positionInTexture.x = 2;
	tile.positionInTexture.y = 9;
	tiles.push_back(tile);
	tile.positionInTexture.x = 2;
	tile.positionInTexture.y = 10;
	tiles.push_back(tile);
	
	map.resize(40);
	for(int i=0; i < map.size(); ++i)
	{
		map[i].resize(40);
		for(int j=0; j < map[i].size(); ++j)
		{
			if(i == 0) map[i][j] = 1;
			else if(i == map.size()-1) map[i][j] = 7;
			else if(j == 0) map[i][j] = 3;
			else if(j ==  map[i].size()-1) map[i][j] = 5;
			else map[i][j] = 4;
		}
	}

	map[0][0] = 0;
	map[map.size()-1][map[0].size()-1] = 8;
	map[map.size()-1][0] = 6;
	map[0][map[0].size()-1] = 2;

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

	for(int i = 0; i < map.size(); ++i)
	{
		for(int j = 0; j < map[i].size(); ++j)
		{
			tileToRender.setTextureRect(sf::IntRect(tiles[map[i][j]].positionInTexture.x*32,tiles[map[i][j]].positionInTexture.y*32,32,32));
			tileToRender.setPosition(i*32.0f,j*32.0f);
			window.draw(tileToRender);
		}
	}
	
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
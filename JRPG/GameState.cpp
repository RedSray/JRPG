#include "GameState.h"
#include "pugixml.hpp"

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
	//map init
	std::string source("DemoMap.tmx");
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(source.c_str(), ~pugi::parse_eol);
	if (result)
		std::cout << "XML [" << source << "] parsed without errors.\n\n";
	else
	{
		std::cout << "XML [" << source << "] parsed with errors.\n";
		std::cout << "Error description: " << result.description() << "\n";
//		std::cout << "Error offset: " << result.offset << " (error at [..." << (source + result.offset) << "]\n\n";
	}

	pugi::xml_node mapNode = doc.child("map");

	game->SetMapSize(sf::Vector2i(mapNode.attribute("width").as_int(),mapNode.attribute("height").as_int()));
	game->SetTileSize(sf::Vector2i(mapNode.attribute("tilewidth").as_int(),mapNode.attribute("tileheight").as_int()));

	//loop over tilesets
	int textureID = 0;
	for (pugi::xml_node tilesetNode = mapNode.child("tileset"); tilesetNode; tilesetNode = tilesetNode.next_sibling("tileset"))
	{
		if(!tilesetNode.child("properties").child("property").attribute("value").as_bool())
		{
			sf::Texture newTexture;
			if(!newTexture.loadFromFile(tilesetNode.child("image").attribute("source").as_string()))
			{
				std::cout << "could not load " << tilesetNode.child("image").attribute("source").as_string() << std::endl;
			}
			tilesetTextures.push_back(newTexture);
		
			for(int i = 0; i*32 < tilesetNode.child("image").attribute("height").as_int(); ++i)
			{
				for(int j = 0; j*32 < tilesetNode.child("image").attribute("width").as_int(); ++j)
				{
					Tile tile;
					tile.positionInTexture = sf::Vector2i(j*32,i*32);
					tile.textureID = textureID;
					game->SetTile(tile);
				}
			}

			++textureID;
		}
	}
	//loop over layers
	for (pugi::xml_node layerNode = mapNode.child("layer"); layerNode; layerNode = layerNode.next_sibling("layer"))
	{
		game->SetLayer(layerNode.attribute("name").as_string(), layerNode.child("data").text().as_string());
	}

	//player init
	if(!playerExplorationSpritesheet.loadFromFile("playerExplo.png"))
	{
		std::cout << "Error loading player spritesheet" << std::endl;
	}

	Animation animation;
	animation.fps = 8;
	animation.LoopFrame = 1;
	animation.framesID.resize(3);
	animation.framesID[0] = 10;
	animation.framesID[1] = 11;
	animation.framesID[2] = 9;
	game->AddPlayerAnimation(animation);//haut
	animation.framesID[0] = 1;
	animation.framesID[1] = 2;
	animation.framesID[2] = 0;
	game->AddPlayerAnimation(animation);//bas
	animation.framesID[0] = 4;
	animation.framesID[1] = 5;
	animation.framesID[2] = 3;
	game->AddPlayerAnimation(animation);//gauche
	animation.framesID[0] = 7;
	animation.framesID[1] = 8;
	animation.framesID[2] = 6;
	game->AddPlayerAnimation(animation);//droite

	game->SetPlayerActiveAnim(1);
	game->SetPlayerActiveAnimFrame(0);

	game->SetPlayerWorldPosition(sf::Vector2f(36.0f,10.0f));

	//view init
	sf::View view(sf::Vector2f(20.0f*32.0f,10.0f*32.0f), sf::Vector2f(800.0f,600.0f));
	window.setView(view);

	/*if(!gameMusic.openFromFile("YukiAndTakuGame.wav"))
	{
		std::cout << "cannot open menu music file" << std::endl;
	}
	else
	{
		gameMusic.setLoop(true);
		gameMusic.setVolume(25);
	//	gameMusic.play();
	}*/

	
	//starting the first substate
	ChangeState(StateType::Exploration, window);
}

void GameState::OnExit(sf::RenderWindow& window)
{
//	gameMusic.stop();
}

StateType GameState::Update(sf::RenderWindow& window, sf::Time elapsedTime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return StateType::Menu;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F4) && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
	{
		window.close();
	}
	//view follow the player
	sf::Vector2f center = game->GetPlayerWorldPosition();
	// 400 and 300 are half of the view size and 16 is for the offset apply to tiles through origin
	center.x = boost::math::round<float>(center.x*32.0f);
	if(center.x < 400-16) center.x = 400-16;
	if(center.x > game->GetMapSize().x*32 - (400+16)) center.x = game->GetMapSize().x*32 - (400+16);

	center.y =  boost::math::round<float>(center.y*32.0f);
	if(center.y < 300) center.y = 300;
	if(center.y > game->GetMapSize().y*32 - (300+16)) center.y = game->GetMapSize().y*32 - (300+16);

	sf::View view(center,sf::Vector2f(800,600));

	

	window.setView(view);

	return activeSubState->Update(window, elapsedTime);
}

void GameState::Render(sf::RenderWindow& window)
{
	//prepare the player rendering
	sf::Sprite playerSprite;
	playerSprite.setTexture(playerExplorationSpritesheet);
	int frameID = game->GetPlayerActiveAnimeFrame();
	sf::IntRect spriteRect(32*(frameID%(playerExplorationSpritesheet.getSize().x/32)),32*(frameID/(playerExplorationSpritesheet.getSize().x/32)),32,32);
	playerSprite.setTextureRect(spriteRect);
	playerSprite.setOrigin(16.0f,16.0f);
	playerSprite.setPosition(game->GetPlayerWorldPosition().x*32.0f,game->GetPlayerWorldPosition().y*32.0f);


	sf::Sprite tileSprite;
	tileSprite.setOrigin(game->GetTileSize().x/2,game->GetTileSize().y/2);
	//layers render loop
	for(int l =0; l < game->GetNbLayer();++l)
	{
		if(game->GetLayerName(l) == "Entities")
		{
			window.draw(playerSprite); //render player but not the layer itself (the layer only contain physics data)
		}
		else
		{
			for(int i = 0; i < game->GetMapSize().x; ++i)
			{
				for(int j = 0; j < game->GetMapSize().y; ++j)
				{
					int tileID = game->GetLayerCell(l,i,j);
					if(tileID >= 0)
					{
						Tile tile = game->GetTile(tileID);
						tileSprite.setTexture(tilesetTextures[tile.textureID]);
						tileSprite.setTextureRect(sf::IntRect(tile.positionInTexture.x,tile.positionInTexture.y,game->GetTileSize().x,game->GetTileSize().y));
						tileSprite.setPosition(game->GetTileSize().x*i,game->GetTileSize().y*j);
						window.draw(tileSprite);
					}
				}
			}
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
		activeSubState.reset(new ExplorationGameState(game));
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
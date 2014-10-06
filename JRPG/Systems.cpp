#include "Systems.h"

RenderSystem::RenderSystem()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");
	sf::View view(sf::Vector2f(128.0f,0.0f), sf::Vector2f(800.0,600.0f));
	window->setView(view);
}

RenderSystem::~RenderSystem()
{
	delete window;
}

void RenderSystem::Init()
{
	if(!tileset.loadFromFile("terrain.png")){
		//need an error log system
	}
	tilesetSizeX = tileset.getSize().x/TILESET_TILE_PIXELSIZE;
}

bool RenderSystem::WindowIsOpen() const
{
	return window->isOpen();
}

void RenderSystem::PollEvent(){
	sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void RenderSystem::Update(Scene* scene)
{
	window->clear();
	//Render tile one by one from top to bottom and left to right
	//Will change ...
	for(int i = 0; i < scene->GetMapSize().x; ++i)
	{
		for(int j = 0; j < scene->GetMapSize().y; ++j)
		{
			sf::IntRect rect((scene->GetTileType(i,j)%tilesetSizeX)*TILESET_TILE_PIXELSIZE,(scene->GetTileType(i,j)/tilesetSizeX)*TILESET_TILE_PIXELSIZE,TILESET_TILE_PIXELSIZE,TILESET_TILE_PIXELSIZE);
			sf::Sprite sprite(tileset, rect);
			sprite.setPosition(i*32.0f,j*32.0f);
			window->draw(sprite);
		}
	}

	window->display();
}
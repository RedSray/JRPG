#include "Systems.h"

RenderSystem::RenderSystem()
{
	window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

RenderSystem::~RenderSystem()
{
	delete window;
}

void RenderSystem::Init()
{
	tileset.loadFromFile("tileset.png");
	tilesetSizeX = tileset.getSize().x/TILESET_TILE_PIXELSIZE;
}

bool RenderSystem::WindowIsOpen()
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
	//render tile one by one from top to bottom and left to right
	for(int i = 0; i < scene->GetMapSize().x; ++i)
	{
		for(int j = 0; j < scene->GetMapSize().y; ++j)
		{
			sf::IntRect rect(scene->GetTileType(i,j)%tilesetSizeX,scene->GetTileType(i,j)/tilesetSizeX,TILESET_TILE_PIXELSIZE,TILESET_TILE_PIXELSIZE);
			sf::Sprite sprite(tileset, rect);
			window->draw(sprite);
		}
	}
}
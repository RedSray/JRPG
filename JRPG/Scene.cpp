#include "Scene.h"

Scene::Scene()
{
	map = new Map();
}

Scene::~Scene()
{
	delete map;
}

void Scene::Init()
{
	map->Init();
}

sf::Vector2u Scene::GetMapSize()
{
	return map->GetSize();
}

int Scene::GetTileType(int x, int y)
{
	return map->GetTileType(x,y);
}


Map::Map()
{

}

Map::~Map()
{

}

void Map::Init()
{

}

int Map::GetTileType(int x, int y)
{

}

const sf::Vector2u Map::GetSize()
{
	return size;
}
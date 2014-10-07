#include "Scene.h"

Scene::Scene()
{
	map = new Map();
}

Scene::~Scene()
{
	delete map;
}

void Scene::Init(int mapSizeX, int mapSizeY, std::string mapTileData)
{
	map->Init(mapSizeX, mapSizeY, mapTileData);
}

sf::Vector2u Scene::GetMapSize()
{
	return map->GetSize();
}

int Scene::GetTileType(int x, int y)
{
	return map->GetTileType(x,y);
}


Scene::Map::Map()
{

}

Scene::Map::~Map()
{
	
}

void Scene::Map::Init(int mapSizeX, int mapSizeY, std::string mapTileData)
{
	size.x = mapSizeX;// will be transfer in a file
	size.y = mapSizeY;// will be transfer in a file

	tiles.resize(size.x);
	for(int i = 0; i < size.x; ++i){
		tiles[i].resize(size.y);
	}

	std::vector<std::string> mapRowsList;
	boost::split(mapRowsList, mapTileData, boost::is_any_of(" "),boost::token_compress_on);

	for(int j = 0; j < size.y; ++j){

		std::vector<std::string> mapRowTilesValue;
		boost::split(mapRowTilesValue, mapRowsList[j], boost::is_any_of("*-_"),boost::token_compress_on);

		for(int i = 0; i < size.x; ++i){
			tiles[i][j].SetTilesID(boost::lexical_cast<int>(mapRowTilesValue[i]));
		}
	}
}

int Scene::Map::GetTileType(int x, int y)
{
	return tiles[x][y].GetComponentSprite().GetSpriteID();
}

const sf::Vector2u Scene::Map::GetSize()
{
	return size;
}

Scene::Tile::Tile()
{

}

Scene::Tile::~Tile()
{

}

Scene::Tile::Tile(const Tile& other)
{
	componentSprite = other.GetComponentSprite();
}

Scene::Tile& Scene::Tile::operator=(const Tile& other)
{
	componentSprite = other.GetComponentSprite();
	return *this;
}

ComponentSprite Scene::Tile::GetComponentSprite() const
{
	return componentSprite;
}

void Scene::Tile::SetTilesID(int id)
{
	componentSprite.SetSpriteID(id);
}
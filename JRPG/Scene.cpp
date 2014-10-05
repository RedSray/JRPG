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
	std::string mapString("42*43*43*43*44-63*64*64*64*65-84*85*85*85*86");
	std::vector<std::string> mapRowsList;
	boost::split(mapRowsList,mapString, boost::is_any_of("-"),boost::token_compress_on);

	size.x = 5;
	size.y = 3;
	tiles.resize(size.x);
	for(int i = 0; i < size.x; ++i){
		tiles[i].resize(size.y);
	}

	for(int j = 0; j < size.y; ++j){
		std::vector<std::string> mapRowTilesValue;
		boost::split(mapRowTilesValue, mapRowsList[j], boost::is_any_of("*"),boost::token_compress_on);
		for(int i = 0; i < size.x; ++i){
			tiles[i][j].UseComponentSprite().SetSpriteID(boost::lexical_cast<int>(mapRowTilesValue[i]));
		}
	}
}

int Map::GetTileType(int x, int y)
{
	return tiles[x][y].GetComponentSprite().GetSpriteID();
}

const sf::Vector2u Map::GetSize()
{
	return size;
}

Tile::Tile()
{

}

Tile::~Tile()
{

}

Tile::Tile(const Tile& other)
{
	componentSprite = other.GetComponentSprite();
}

Tile& Tile::operator=(const Tile& other)
{
	componentSprite = other.GetComponentSprite();
	return *this;
}

ComponentSprite Tile::GetComponentSprite() const
{
	return componentSprite;
}

ComponentSprite& Tile::UseComponentSprite()
{
	return componentSprite;
}

ComponentSprite::ComponentSprite() : spriteID(0)
{
	
}

ComponentSprite::~ComponentSprite()
{

}
ComponentSprite::ComponentSprite(const ComponentSprite& other)
{
	spriteID = other.GetSpriteID();
}

ComponentSprite& ComponentSprite::operator=(const ComponentSprite& other)
{
	spriteID = other.GetSpriteID();

	return *this;
}

int ComponentSprite::GetSpriteID() const
{
	return spriteID;
}

void ComponentSprite::SetSpriteID(int id)
{
	spriteID = id;
}
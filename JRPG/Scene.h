#ifndef SCENE_H
#define SCENE_H

#include <SFML\System\Vector2.hpp>

#include <string>
#include <vector>

#include <boost\algorithm\string.hpp>
#include <boost\lexical_cast.hpp>
#include <boost\multi_array.hpp>

/*---------------------
this component represent the position of it's container
----------------------*/
class ComponentPosition
{

};
/*---------------------
the container of this component will either be a solid entity/non walkable tile or a trigger (can be tile or an entity)
----------------------*/
class ComponentPhysics
{

};

/*---------------------
this component make the container able to move around the map hence will not work with tile
----------------------*/
class ComponentMouvement
{

};

/*---------------------
this component represent animation data
----------------------*/
class ComponentAnimation
{

};

/*---------------------
this component represent what will be displayed
----------------------*/
class ComponentSprite
{
public:
	ComponentSprite();
	~ComponentSprite();

	ComponentSprite(const ComponentSprite&);
	ComponentSprite& operator=(const ComponentSprite&);

	int GetSpriteID() const;
	void SetSpriteID(int);

private:
	int spriteID;
};

/*---------------------
this class is a container for components and is used to represent object that live in the map with out being bind to it  
----------------------*/
class Entity
{

};

/*---------------------
this class is a container for components and is used to represent an unmovable part of the map
----------------------*/
class Tile
{
public:
	Tile();
	~Tile();

	Tile(const Tile&);
	Tile& operator= (const Tile&);

	ComponentSprite GetComponentSprite() const;
	ComponentSprite& UseComponentSprite();

private:
	ComponentSprite componentSprite;
};

/*---------------------
this class represent the map general informations
----------------------*/
class Map
{
public:
	Map();
	~Map();

	void Init();
	int GetTileType(int,int);
	const sf::Vector2u GetSize();
private :
	sf::Vector2u size;
	std::vector<std::vector<Tile>> tiles;
};

/*---------------------
this class is the main access to datas used by systems
----------------------*/
class Scene
{
public:
	Scene();
	~Scene();

	void Init();
	sf::Vector2u GetMapSize();
	int GetTileType(int,int);

private:
	Map* map;
};

#endif
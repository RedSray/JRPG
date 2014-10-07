#ifndef SCENE_H
#define SCENE_H

#include <SFML\System\Vector2.hpp>

#include <string>
#include <vector>

#include <boost\algorithm\string.hpp>
#include <boost\lexical_cast.hpp>
#include <boost\multi_array.hpp>

#include "Components.h"

/*---------------------
this class is the Facade access to the representation of a Scene
----------------------*/
class Scene
{
	/*---------------------
	this class is a container for components and is used to represent object that live in the map with out being bind to it  (able to move)
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

		void SetTilesID(int);

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

		void Init(int,int,std::string);
		int GetTileType(int,int);
		const sf::Vector2u GetSize();

	private :
		Map(const Map&);
		Map& operator=(const Map&);

		sf::Vector2u size;
		std::vector<std::vector<Scene::Tile>> tiles;
	};


public:
	Scene();
	~Scene();

	void Init(int,int,std::string);
	sf::Vector2u GetMapSize();
	int GetTileType(int,int);

private:
	Scene(const Scene&);
	Scene& operator=(const Scene&);

	Map* map;
};

#endif
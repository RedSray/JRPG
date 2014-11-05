#include "TMXMap.h"

TMXMap::TMXMap()
{

}

TMXMap::~TMXMap()
{

}

Tile TMXMap::GetTile(int id) const
{
	return tiles[id];
}

sf::Vector2i TMXMap::GetSize() const
{
	return size;
}

int TMXMap::GetNbLayer() const
{
	return layers.size();
}

sf::Vector2i TMXMap::GetTileSize() const
{
	return tileSize;
}

int TMXMap::GetLayerCell(int layer, int x, int y) const
{
	return layers[layer].data[x][y];
}

std::string TMXMap::GetLayerName(int layer) const
{
	return layers[layer].name;
}

bool TMXMap::IsCellWalkable(sf::Vector2i cell) const
{
	//std::cout << "cell = " << layers[entitiesLayer].data[cell.x][cell.y] << std::endl; 
	return (layers[entitiesLayer].data[cell.x][cell.y] == -1)?true:false;
}




void TMXMap::SetTile(Tile tile)
{
	tiles.push_back(tile);
}

void TMXMap::SetSize(sf::Vector2i newSize)
{
	size = newSize;
}

void TMXMap::SetTileSize(sf::Vector2i newTileSize)
{
	tileSize = newTileSize;
}

void TMXMap::SetLayer(std::string name, std::string data)
{
	

	Layer newLayer;
	newLayer.name = name;
	newLayer.data.resize(size.x);
	for(int i=0; i < size.x; ++i) newLayer.data[i].resize(size.y);

	std::vector<std::string> parsedData;
	boost::split(parsedData, data, boost::is_any_of(","));

	int i = 0, j = 0;
	for each (std::string tileID in parsedData)
	{
		tileID.erase(std::remove(tileID.begin(), tileID.end(), '\n'), tileID.end());
		std::cout << "tileID = " << tileID << std::endl;
		int id = (boost::lexical_cast<int>(tileID));
		id -= 1; // because TMX format start tile id to 1 and they start at 0 in memomry...
		newLayer.data[i][j] = id;

		++i;
		if(i >= size.x)
		{
			i = 0;
			++j;
		}
	}

	layers.push_back(newLayer);
	if(newLayer.name == "Entities")entitiesLayer = layers.size()-1;
}
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>

#include "Player.h"
#include "TMXMap.h"

class Game
{
public:
	Game();
	~Game();

	Tile GetTile(int) const;
	sf::Vector2i GetMapSize() const;
	sf::Vector2f GetPlayerWorldPosition() const;
	int GetNbLayer() const;
	sf::Vector2f GetTileSize() const;
	int GetLayerCell(int,int,int) const;
	std::string GetLayerName(int) const;

	void SetTile(Tile);
	void SetPlayerWorldPosition(sf::Vector2f);
	void SetMapSize(sf::Vector2i);
	void SetTileSize(sf::Vector2f);
	void SetLayer(std::string, std::string);

	//movement
	bool IsCellWalkable(sf::Vector2f) const;
	sf::Vector2f GetPlayerMoveGoal() const;
	sf::Vector2f GetPlayerSpeed() const;

	void InitPlayerMovement();
	void ReinitPlayerMovement();
	void MovePlayer(MoveDirection);
	void SetPlayerSpeed(char, float);

	//animation
	int GetPlayerActiveAnimFPS() const;
	int GetPlayerActiveAnimeFrame() const;
	int GetPlayerActiveAnime() const;

	void PlayerNextAnimFrame();
	void SetPlayerActiveAnim(int);
	void SetPlayerActiveAnimFrame(int);
	void AddPlayerAnimation(Animation);

private:
	TMXMap map;
	Player player;
};

#endif
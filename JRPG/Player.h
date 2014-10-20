#ifndef PLAYER_H
#define PLAYER_H

#include <boost\math\special_functions\round.hpp>

#include <SFML\System\Vector2.hpp>

enum MoveDirection
{
	North,
	South,
	West,
	East
};

struct Animation {
	std::vector<int> framesID; // IDs of the sprites on the spritesheet 
	int fps;
	int LoopFrame;
};

class Player
{
public: 
	Player();
	~Player();

	sf::Vector2f GetWorldPosition() const;
	sf::Vector2f GetMoveGoal() const;
	sf::Vector2f GetSpeed() const;
	int GetActiveAnimFPS() const;
	int GetActiveAnimFrame() const;
	int GetActiveAnim() const;


	void SetWorldPosition(sf::Vector2f);
	void InitMovement();
	void ReinitMovement();
	void Move(MoveDirection);
	void SetSpeed(char, float);
	void NextAnimFrame();
	void SetActiveAnim(int);
	void SetActiveAnimFrame(int);
	void AddAnimation(Animation animation);

private:
	sf::Vector2f worldPosition;
	sf::Vector2f moveGoal;
	sf::Vector2f playerSpeed;
	sf::Vector2i activeAnimation; // x = anim id, y = frame id
	std::vector<Animation> animations;
};

#endif
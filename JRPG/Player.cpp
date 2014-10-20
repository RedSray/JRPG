#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

sf::Vector2f Player::GetWorldPosition() const
{
	return worldPosition;
}

sf::Vector2f Player::GetMoveGoal() const
{
	return moveGoal;
}

sf::Vector2f Player::GetSpeed() const
{
	return playerSpeed;
}

int Player::GetActiveAnimFPS() const
{
	return animations[activeAnimation.x].fps;
}

int Player::GetActiveAnimFrame() const
{
	return animations[activeAnimation.x].framesID[activeAnimation.y];
}

int Player::GetActiveAnim() const
{
	return activeAnimation.x;
}

void Player::SetWorldPosition(sf::Vector2f newPosition)
{
	worldPosition = newPosition;
}

void Player::InitMovement()
{
	moveGoal = GetWorldPosition();
	moveGoal.x = (int)moveGoal.x;
	moveGoal.y = (int)moveGoal.y;
	worldPosition = moveGoal;
}

void Player::ReinitMovement()
{
	//reinit speed to 0
	playerSpeed.x = 0.0f;
	playerSpeed.y = 0.0f;
	//replace properly (try to remove float imprecision)
	/*moveGoal.x = boost::math::round<float>(moveGoal.x);
	moveGoal.y = boost::math::round<float>(moveGoal.y);
	worldPosition = moveGoal;*/
}

void Player::Move(MoveDirection direction)
{
	switch (direction)
	{
	case North: moveGoal.y -= 1;
		break;
	case South: moveGoal.y += 1;
		break;
	case West: moveGoal.x -= 1;
		break;
	case East: moveGoal.x += 1;
		break;
	}
}

void Player::SetSpeed(char axe, float speed)
{
	if(axe == 'x') playerSpeed.x = speed;
	else if(axe == 'y') playerSpeed.y = speed;
}

void Player::NextAnimFrame()
{
	++activeAnimation.y;
	if(animations[activeAnimation.x].framesID.size() <= activeAnimation.y) activeAnimation.y = animations[activeAnimation.x].LoopFrame;
}

void Player::SetActiveAnim(int id)
{
	activeAnimation.x = id;
}

void Player::SetActiveAnimFrame(int id)
{
	activeAnimation.y = id;
}

void Player::AddAnimation(Animation animation)
{
	animations.push_back(animation);
}

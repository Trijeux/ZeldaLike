#include "Player.h"

void Player::SetTilePlayerCoord(char axe, char PorN, int num)
{
	if (axe == 'x')
	{
		if (PorN == '+')
		{
			sprite_player_Coord_.x += num;
			MovePlayer(kRight);
		}
		else if(PorN == '-')
		{
			sprite_player_Coord_.x -= num;
			MovePlayer(kLeft);
		}
		else if(PorN == '=')
		{
			sprite_player_Coord_.x = num;
			
		}
	}
	if (axe == 'y')
	{
		if (PorN == '+')
		{
			sprite_player_Coord_.y += num;
			MovePlayer(kDown);
		}
		else if (PorN == '-')
		{
			sprite_player_Coord_.y -= num;
			MovePlayer(kUp);
		}
		else if (PorN == '=')
		{
			sprite_player_Coord_.y = num;
		}
	}
}

void Player::SetKey(char PorN, int num)
{
	if (PorN == '+')
	{
		num_key_ += num;
	}
	else if (PorN == '-')
	{
		num_key_ -= num;
	}
	else if (PorN == '=')
	{
		num_key_ = num;
	}
}

void Player::SetExitKey(char PorN, int num)
{
	if (PorN == '+')
	{
		num_exit_key_ += num;
	}
	else if (PorN == '-')
	{
		num_exit_key_ -= num;
	}
	else if (PorN == '=')
	{
		num_exit_key_ = num;
	}
}

void Player::SetLife(char PorN, int num)
{
	if (PorN == '+')
	{
		life_ += num;
	}
	else if (PorN == '-')
	{
		life_ -= num;
	}
	else if (PorN == '=')
	{
		life_ = num;
	}
}

void Player::LoadPlayer()
{
	up_.loadFromFile("Sprite\\Player\\hero2.png");
	down_.loadFromFile("Sprite\\Player\\hero1.png");
	left_.loadFromFile("Sprite\\Player\\hero3.png");
	right_.loadFromFile("Sprite\\Player\\hero4.png");
	sprite_player_.setTexture(down_);
	sprite_player_.setScale(2, 2);
	sprite_player_.setOrigin(sprite_player_.getScale().x + 5.5, sprite_player_.getScale().y + 5);
}

void Player::MovePlayer(int num)
{
	if (num == kUp)
	{
		sprite_player_.setTexture(up_);
	}
	if (num == kDown || num == kSpawnMove)
	{
		sprite_player_.setTexture(down_);
	}
	if (num == kLeft) {
		sprite_player_.setTexture(left_);
	}
	if (num == kRight) {
		sprite_player_.setTexture(right_);
	}
}

#include "Player.h"

void Player::SetTilePlayerCoord(char axe, char PorN, int num)
{
	if (axe == 'x')
	{
		if (PorN == '+')
		{
			tile_player_Coord.x += num;
			MovePlayer(right);
		}
		else if(PorN == '-')
		{
			tile_player_Coord.x -= num;
			MovePlayer(left);
		}
		else if(PorN == '=')
		{
			tile_player_Coord.x = num;
			
		}
	}
	if (axe == 'y')
	{
		if (PorN == '+')
		{
			tile_player_Coord.y += num;
			MovePlayer(down);
		}
		else if (PorN == '-')
		{
			tile_player_Coord.y -= num;
			MovePlayer(up);
		}
		else if (PorN == '=')
		{
			tile_player_Coord.y = num;
		}
	}
}

void Player::SetClé(char PorN, int num)
{
	if (PorN == '+')
	{
		num_clé += num;
	}
	else if (PorN == '-')
	{
		num_clé -= num;
	}
	else if (PorN == '=')
	{
		num_clé = num;
	}
}

void Player::SetExitClé(char PorN, int num)
{
	if (PorN == '+')
	{
		num_exit_clé += num;
	}
	else if (PorN == '-')
	{
		num_exit_clé -= num;
	}
	else if (PorN == '=')
	{
		num_exit_clé = num;
	}
}

void Player::SetVie(char PorN, int num)
{
	if (PorN == '+')
	{
		vie += num;
	}
	else if (PorN == '-')
	{
		vie -= num;
	}
	else if (PorN == '=')
	{
		vie = num;
	}
}

void Player::LoadPlayer()
{
	up_.loadFromFile("Sprite\\Player\\hero2.png");
	down_.loadFromFile("Sprite\\Player\\hero1.png");
	left_.loadFromFile("Sprite\\Player\\hero3.png");
	right_.loadFromFile("Sprite\\Player\\hero4.png");
	tile_player.setTexture(down_);
	tile_player.setScale(2, 2);
	tile_player.setOrigin(tile_player.getScale().x + 5.5, tile_player.getScale().y + 5);
}

void Player::MovePlayer(int num)
{
	if (num == up)
	{
		tile_player.setTexture(up_);
	}
	if (num == down || num == spawnMove)
	{
		tile_player.setTexture(down_);
	}
	if (num == left) {
		tile_player.setTexture(left_);
	}
	if (num == right) {
		tile_player.setTexture(right_);
	}
}

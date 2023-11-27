#include "Player.h"

Player::Player()
{
	tile_player.setRadius(15);
	tile_player.setFillColor(sf::Color::Red);
	tile_player.setOutlineColor(sf::Color::Green);
	tile_player.setOutlineThickness(1);
	tile_player.setOrigin(tile_player.getRadius(), tile_player.getRadius());
	tile_player.setPosition(spawn.x * 50 + 25, spawn.y * 50 + 25);
}

void Player::SetTilePlayerCoord(char axe, char PorN, int num)
{
	if (axe == 'x')
	{
		if (PorN == '+')
		{
			tile_player_Coord.x += num;
		}
		else if(PorN == '-')
		{
			tile_player_Coord.x -= num;
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
		}
		else if (PorN == '-')
		{
			tile_player_Coord.y -= num;
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


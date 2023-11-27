#pragma once
#include <SFML/Graphics.hpp>
#include "GameText.h"


#define TILEMAP_WIDTH 20
#define TILEMAP_HEIGHT 20

enum block
{
	sole = 0,
	mur = 1,
	pi�ge = 2,
	pi�ge_invisible = 3,
	cl� = 4,
	exit_cl� = 5,
	porte_ferm� = 6,
	porte_ouverte = 7,
	exit_porte_ferm� = 8,
	exit_porte_ouverte = 9
};

class Game
{
public:
	Game();

	void GameLoop();

	void Move();
	void Collision();
	void GraphicInGame(GameText vie_player, GameText cl�_player, GameText exit_cl�_player);
	void GraphicEndGame(GameText gameover, GameText victory, GameText Enter);

	

	const sf::Vector2i GetSpawn() { sf::Vector2i spawn(5, 5); return spawn; }
	sf::Vector2i GetTilePlayerCoord() { sf::Vector2i tile_player_Coord(5, 5); return tile_player_Coord; }
	void SetTilePlayerCoord(char axe, int num);

private:
	sf::RenderWindow window;

	bool no_pressed = true;


	int tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT] = { 0 };
	const int kHorizontalMaxSpeed = 1;


	sf::RectangleShape tile_map;
	sf::RectangleShape Sole;
	sf::RectangleShape Mur;
	sf::RectangleShape Pi�ge;
	sf::RectangleShape Pi�ge_Invisible;
	sf::RectangleShape Cl�;
	sf::RectangleShape Exit_Cl�;
	sf::RectangleShape Porte_Ferm�;
	sf::RectangleShape Porte_Ouverte;
	sf::RectangleShape Exit_Porte_Ouverte;
	sf::RectangleShape Exit_Porte_Ferm�;

	sf::CircleShape tile_player;
	int vie = 3;
	int num_cl� = 0;
	int num_exit_cl� = 0;

	int level = 1;
	bool chargement = true;
	bool endgame = false;

	void load(int level);

	sf::Vector2i tile_player_Coord = sf::Vector2i(5, 5);
	const sf::Vector2i spawn = sf::Vector2i(5, 5);
	sf::Vector2i prev_player_coords;
};


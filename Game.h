#pragma once
#include <SFML/Graphics.hpp>
#include "GameText.h"


#define TILEMAP_WIDTH 20
#define TILEMAP_HEIGHT 20

enum block
{
	sole = 0,
	mur = 1,
	piège = 2,
	piège_invisible = 3,
	clé = 4,
	exit_clé = 5,
	porte_fermé = 6,
	porte_ouverte = 7,
	exit_porte_fermé = 8,
	exit_porte_ouverte = 9
};

class Game
{
public:
	Game();

	void GameLoop();

	void Move();
	void Collision();
	void GraphicInGame(GameText vie_player, GameText clé_player, GameText exit_clé_player);
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
	sf::RectangleShape Piège;
	sf::RectangleShape Piège_Invisible;
	sf::RectangleShape Clé;
	sf::RectangleShape Exit_Clé;
	sf::RectangleShape Porte_Fermé;
	sf::RectangleShape Porte_Ouverte;
	sf::RectangleShape Exit_Porte_Ouverte;
	sf::RectangleShape Exit_Porte_Fermé;

	sf::CircleShape tile_player;
	int vie = 3;
	int num_clé = 0;
	int num_exit_clé = 0;

	int level = 1;
	bool chargement = true;
	bool endgame = false;

	void load(int level);

	sf::Vector2i tile_player_Coord = sf::Vector2i(5, 5);
	const sf::Vector2i spawn = sf::Vector2i(5, 5);
	sf::Vector2i prev_player_coords;
};


#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Menu.h"
#include "Enemy.h"
#include "Utilities.h"
#include "EnemyBullet.h"

class Game
{
private:
	Texture background, ship, enemy1, enemy2, enemy3, death;
	Texture enemy1Move, enemy2Move, enemy3Move;
	Sprite backgroundSprite;

	Text score, lives, gameOverText, nextRoundText;
	Font font;

	Utilities utilities;
	Clock clock, deathClock, blinkClock;
	Time time, deathTime, blinkTime;
	Menu menu;

	const float WINDOW_WIDTH = 1280;
	const float WINDOW_HEIGHT = 720;
	const float DEFAULT_POS_X = (WINDOW_WIDTH / 2) - 30;
	const float DEFAULT_POS_Y = WINDOW_HEIGHT - 50;

	std::vector<Bullet> bullets;
	std::vector<Sprite> ships;
	std::vector<Sprite> deaths;
	std::vector<Enemy> enemies;
	std::vector<EnemyBullet> enemyBullets;
	std::vector<RectangleShape> shields;

	float furthestRight;
	float furthestLeft;

	bool blink = false;
	bool play = false;
	bool update = true;
	bool drawSprite = true;
	bool drawPlayer = false;
	bool isGameOver = false;
	bool drawGameOver = false;
	bool isNextRound = false;
	bool drawNextRound = false;

	int times = 0;
	int points = 0;
	int blinkTimes = 0;

public:
	Game();

	void run();

	void restart();

	void updateGame();

	void gameOver(RenderWindow& window);

	void nextRound(RenderWindow& window);

	void playing(RenderWindow& window, Player& player);

	void drawDeath(RenderWindow& window);

	void enemyOrShieldCollision(RenderWindow& window);

	void playerOrShieldCollision(RenderWindow& window, Player& player);
};


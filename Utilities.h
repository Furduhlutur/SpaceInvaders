#pragma once
#include <SFML\Graphics.hpp>
#include "Enemy.h"
#include "Bullet.h"

using namespace sf;

class Utilities
{
public:
	Utilities();

	float furthestDown(std::vector<Enemy>& enemies);

	float furthestRight(std::vector<Enemy>& enemies);

	float furthestLeft(std::vector<Enemy>& enemies);

	void initializeEnemies(std::vector<Enemy>& enemies, const Texture& enemy1, const Texture& enemy2, const Texture& enemy3, const Texture& enemy1Move, const Texture& enemy2Move, const Texture& enemy3Move);

	void initializeShield(std::vector<RectangleShape>& shields);

	void initializeLives(std::vector<Sprite>& ships, Texture& ship);

	void addDeath(std::vector<Sprite>& deaths, sf::Vector2f position, Texture& death, const Color colour);
};


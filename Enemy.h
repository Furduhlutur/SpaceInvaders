#pragma once
#include <SFML\Graphics.hpp>
#include "EnemyBullet.h"

using namespace sf;

class Enemy
{
private:
	float moveX = 10;

	bool goDown = true;

	Texture enemy, move;

	Sprite enemySprite, moveSprite;

	Vector2f position;

	bool drawSprite = true;

	int points;

public:
	Enemy(const Texture& enemy, const Texture& move, float x, float y, const sf::Color colour, const int points);

	Sprite getSprite();

	int getPoints() const;

	void shoot(std::vector<Enemy>& enemies, std::vector<EnemyBullet>& enemyBullets);

	void update(Time& time, Clock& clock, RenderWindow& window, const float furthestRight, const float furthestLeft);
};

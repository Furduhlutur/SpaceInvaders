#pragma once
#include <SFML\Graphics.hpp>
#include "Bullet.h"

using namespace sf;

class EnemyBullet
{
private:
	float enemyBulletSpeed = -5.0f;

	RectangleShape enemyBulletShape;

	Vector2f position;

public:
	EnemyBullet(float startX, float startY);

	RectangleShape getShape();

	FloatRect getPosition();

	bool onScreen();

	void update();
};


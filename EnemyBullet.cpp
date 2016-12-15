#include "stdafx.h"
#include "EnemyBullet.h"


EnemyBullet::EnemyBullet(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	enemyBulletShape.setSize(sf::Vector2f(4, 12));
	enemyBulletShape.setPosition(position);
	enemyBulletShape.setFillColor(sf::Color(245, 0, 0));
}

RectangleShape EnemyBullet::getShape()
{
	return enemyBulletShape;
}

FloatRect EnemyBullet::getPosition()
{
	return enemyBulletShape.getGlobalBounds();
}

bool EnemyBullet::onScreen()
{
	return position.y < 720;
}

void EnemyBullet::update()
{
	position.y -= enemyBulletSpeed;
	enemyBulletShape.setPosition(position);
}

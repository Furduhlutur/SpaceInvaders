#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	bulletShape.setSize(sf::Vector2f(4, 12));
	bulletShape.setPosition(position);
}

RectangleShape Bullet::getShape()
{
	return bulletShape;
}

FloatRect Bullet::getPosition()
{
	return bulletShape.getGlobalBounds();
}

bool Bullet::onScreen()
{
	return position.y > 0;
}

void Bullet::update()
{
	position.y -= bulletSpeed;
	bulletShape.setPosition(position);
}
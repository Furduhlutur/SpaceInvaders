#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(const Texture& enemy, const Texture& move, float x, float y, const sf::Color colour, const int points)
{
	position.x = x;
	position.y = y;

	this->points = points;
	this->enemy = enemy;
	this->move = move;

	enemySprite.setTexture(enemy);
	moveSprite.setTexture(move);

	enemySprite.setPosition(position);
	moveSprite.setPosition(position);

	enemySprite.setColor(colour);
	moveSprite.setColor(colour);
}

Sprite Enemy::getSprite()
{
	if (drawSprite)
	{
		return enemySprite;
	}
	return moveSprite;
}

int Enemy::getPoints() const
{
	return points;
}

void Enemy::update(Time& time, Clock& clock, RenderWindow& window, const float furthestRight, const float furthestLeft)
{
	if (time.asMilliseconds() > 200)
	{
		if ((furthestRight >= 1272 || furthestLeft <= 8) && goDown)
		{
			goDown = false;
			enemySprite.move(0, 50);
			moveSprite.move(0, 50);
			moveX *= -1;
		}

		else
		{
			goDown = true;
			enemySprite.move(moveX, 0);
			moveSprite.move(moveX, 0);
		}

		clock.restart();

		if (drawSprite)
		{
			drawSprite = false;
		}

		else
		{
			drawSprite = true;
		}
	}

	if (drawSprite)
	{
		window.draw(enemySprite);
	}

	else
	{
		window.draw(moveSprite);
	}
}

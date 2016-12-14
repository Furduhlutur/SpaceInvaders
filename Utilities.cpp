#include "stdafx.h"
#include "Utilities.h"

Utilities::Utilities()
{

}

int Utilities::addPoints(const int p)
{
	if (p <= 24)
	{
		return 30;
	}

	else if (p <= 48)
	{
		return 20;
	}
	return 10;
}

float Utilities::furthestDown(std::vector<Enemy>& enemies)
{
	float y = 0;
	for (auto& e : enemies)
	{
		if (y < e.getSprite().getPosition().y)
		{
			y = e.getSprite().getPosition().y;
		}
	}
	return y + 32;
}

float Utilities::furthestRight(std::vector<Enemy>& enemies)
{
	float x = 0;
	for (auto& e : enemies)
	{
		if (x < e.getSprite().getPosition().x)
		{
			x = e.getSprite().getPosition().x;
		}
	}
	return x + 42;
}

float Utilities::furthestLeft(std::vector<Enemy>& enemies)
{
	float x = 1280;
	for (auto& e : enemies)
	{
		if (x > e.getSprite().getPosition().x)
		{
			x = e.getSprite().getPosition().x;
		}
	}
	return x;
}

void Utilities::initializeEnemies(std::vector<Enemy>& enemies, const Texture& enemy1, const Texture& enemy2, const Texture& enemy3, const Texture& enemy1Move, const Texture& enemy2Move, const Texture& enemy3Move)
{
	float enemyPosX = 240;
	float enemyPosY = 40;

	for (short r = 0; r < 5; ++r)
	{
		for (short e = 0; e < 12; ++e)
		{
			if (enemyPosY + (r * 50) < 90)
			{
				Enemy enemy(enemy3, enemy3Move, enemyPosX + (e * 70) + 8, enemyPosY + (r * 50), sf::Color(160, 40, 253));
				enemies.push_back(enemy);
			}

			else if (enemyPosY + (r * 50) < 190)
			{
				Enemy enemy(enemy2, enemy2Move, enemyPosX + (e * 70), enemyPosY + (r * 50), sf::Color(0, 175, 255));
				enemies.push_back(enemy);
			}

			else
			{
				Enemy enemy(enemy1, enemy1Move, enemyPosX + (e * 70), enemyPosY + (r * 50), sf::Color(0, 254, 0));
				enemies.push_back(enemy);
			}
		}
	}
}

void Utilities::initializeShield(std::vector<RectangleShape>& shields)
{
	float shieldPosX = 75;
	float shieldPosY = 572;

	for (int y = 0; y < 6; ++y)
	{
		for (int x = 0; x < 68; ++x)
		{
			if (x > 50)
			{
				// +330
				RectangleShape shieldFragment;
				shieldFragment.setFillColor(sf::Color(0, 254, 0));
				shieldFragment.setSize(sf::Vector2f(10, 10));
				shieldFragment.setPosition(shieldPosX + (10 * x) + 450, shieldPosY + (10 * y));
				shields.push_back(shieldFragment);
			}

			else if (x > 33)
			{
				// +220
				RectangleShape shieldFragment;
				shieldFragment.setFillColor(sf::Color(0, 254, 0));
				shieldFragment.setSize(sf::Vector2f(10, 10));
				shieldFragment.setPosition(shieldPosX + (10 * x) + 300, shieldPosY + (10 * y));
				shields.push_back(shieldFragment);
			}

			else if (x > 16)
			{
				// +210x
				RectangleShape shieldFragment;
				shieldFragment.setFillColor(sf::Color(0, 254, 0));
				shieldFragment.setSize(sf::Vector2f(10, 10));
				shieldFragment.setPosition(shieldPosX + (10 * x) + 150, shieldPosY + (10 * y));
				shields.push_back(shieldFragment);
			}

			else
			{
				RectangleShape shieldFragment;
				shieldFragment.setFillColor(sf::Color(0, 254, 0));
				shieldFragment.setSize(sf::Vector2f(10, 10));
				shieldFragment.setPosition(shieldPosX + (10 * x), shieldPosY + (10 * y));
				shields.push_back(shieldFragment);
			}
		}
	}
}

void Utilities::initializeLives(std::vector<Sprite>& ships, Texture& ship)
{
	for (int i = 0; i < 3; ++i)
	{
		Sprite shipSprite;
		shipSprite.setTexture(ship);
		shipSprite.setPosition(1180 + (30 * i), 5);
		shipSprite.setColor(sf::Color(0, 254, 0));
		shipSprite.setScale(0.7, 0.7);
		ships.push_back(shipSprite);
	}
}

void Utilities::addDeath(std::vector<Sprite>& deaths, sf::Vector2f position, Texture& death, const Color colour)
{
	Sprite deathSprite;
	deathSprite.setTexture(death);
	deathSprite.setPosition(position);
	deathSprite.setColor(colour);
	deaths.push_back(deathSprite);
}

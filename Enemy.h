#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Enemy
{
private:
	float moveX = 20;

	bool goDown = true;

	Texture enemy, move;

	Sprite enemySprite, moveSprite;

	Vector2f position;

	bool drawSprite = true;

public:
	Enemy(const Texture& enemy, const Texture& move, float x, float y, sf::Color colour);

	Sprite getSprite();

	void update(Time& time, Clock& clock, RenderWindow& window, const float furthestRight, const float furthestLeft);
};

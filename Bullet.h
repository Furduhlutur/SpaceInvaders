#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Bullet
{
private:
	float bulletSpeed = 6.0f;

	RectangleShape bulletShape;

	Vector2f position;

public:
	Bullet(float startX, float startY);

	RectangleShape getShape();

	FloatRect getPosition();

	bool onScreen();

	void update();
};


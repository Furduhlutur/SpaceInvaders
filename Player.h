#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Player
{
private:
	Vector2f position;

	ConvexShape playerShape;

	float playerSpeed = 4.0f;

	Texture texturePlayer;

	Sprite playerSprite;

public:
	Player(float x, float y);

	Sprite getSprite();

	Vector2f getPosition();

	void moveLeft();

	void moveRight();
};

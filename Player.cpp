#include "stdafx.h"
#include "Player.h"
#include <iostream>

Player::Player(float x, float y)
{
	texturePlayer.loadFromFile("Images/player.png");
	playerSprite.setTexture(texturePlayer);
	playerSprite.setPosition(x, y);
	playerSprite.setColor(sf::Color(0, 254, 0));
}

Sprite Player::getSprite()
{
	return playerSprite;
}

void Player::moveLeft()
{
	if (getPosition().x > 2)
	{
		playerSprite.move(-playerSpeed, 0);
	}
}

void Player::moveRight()
{
	if (getPosition().x < 1242)
	{
		playerSprite.move(playerSpeed, 0);
	}
}

Vector2f Player::getPosition()
{
	return playerSprite.getPosition();
}

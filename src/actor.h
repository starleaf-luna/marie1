#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "tileset.h"

class Actor {

public:
	bool isPlayer;
	bool isActive;
	bool isDying;
	bool canHurtPlayer;
	bool isCutscene;
	bool inAir;
	float x;
	float y;
	float xvel;
	float yvel;
	unsigned int animation;
	unsigned int animationFrame;
	unsigned int sprWidth;
	unsigned int sprHeight;
	std::string spriteFileName;
	sf::Texture texture;
	sf::Sprite sprite;
	
	// create actor
	Actor(bool player, bool active, bool hurts, float ax, float ay, std::string filename, unsigned int width, unsigned int height) {
		isPlayer = player;
		isActive = active;
		isDying = false; // can't die while being spawned
		canHurtPlayer = hurts;
		isCutscene = false;
		inAir = false;
		x = ax;
		y = ay;
		xvel = 0.f;
		yvel = 0.f;
		animation = 0;
		animationFrame = 0;
		sprWidth = width;
		sprHeight = height;

		// we have to be able to load the texture! if we can't, give up!
		if (!texture.loadFromFile(filename, sf::IntRect(0, 0, width, height))) {
			printf("cannot find");
		};
		texture.setSmooth(false);
		
		sprite.setTexture(texture);
		sprite.setPosition(ax, ay);
		sprite.setScale(3, 3);
	}

	void update(TileMap collisionMap) {
		if (isActive) {
			x += xvel;
			y += yvel;
			inAir = true;
			yvel += 0.3f;
			sprite.setPosition(x, y);
			if (isPlayer && !isCutscene) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					xvel = -1.6f;
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					xvel = 1.6f;
				} else {
					xvel = 0.f;
				}
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					yvel = -6.f;
				} 
			}
		}
	}

	Actor() = default;
};

#endif
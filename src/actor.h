#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Actor {

public:
	bool isPlayer;
	bool isActive;
	bool isDying;
	bool canHurtPlayer;
	bool isCutscene;
	float x;
	float y;
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
		x = ax;
		y = ay;
		animation = 0;
		animationFrame = 0;
		sprWidth = width;
		sprHeight = height;

		// we have to be able to load the texture! if we can't, give up!
		if (!texture.loadFromFile(filename, sf::IntRect(0, 0, width, height))) return;
		texture.setSmooth(false);
		
		sprite.setTexture(texture);
		sprite.setPosition(ax, ay);
		sprite.setScale(3, 3);
	}

	void Move(float offsetX, float offsetY) {
		// placeholder, lacks many things
		x += offsetX;
		y += offsetY;
	}

	void Update() {
		if (isActive) {
			sprite.setPosition(x, y);
			if (isPlayer && !isCutscene) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					Move(-1, 0);
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					Move(1, 0);
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					Move(0, -1);
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					Move(0, 1);
				}
			}
		}
	}

	Actor() = default;
};

#endif
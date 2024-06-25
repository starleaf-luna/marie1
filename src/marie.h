#ifndef MARIE_H
#define MARIE_H

#include <string>
#include "actor.h"

class Player : public Actor {

public:
	unsigned char character;

	Player(unsigned char chara, float x, float y) {
		std::string filename;
		switch (chara) {
		case 1:
			// ??
			break;
		case 2:
			// ??
			break;
		default:
			// Marie is at the end
			filename = "assets\\sprites\\marie.png";
		}
		Actor* actor = new Actor(
			true,
			true, // player is always active
			false,
			x,
			y,
			filename,
			16u, 16u
		);
	}

	Player() = default;
};

#endif
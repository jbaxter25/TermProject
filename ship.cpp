//spaceship.cpp
#include "ship.h"


static const float ACCELERATION = 4;


struct ship {
	float x;
	float y;
	float v;
	float w;
	float h;
	float t;
	int lc;
};

struct ship* construct_ship(float x, float y, float w, float h) {
	struct ship* this_ship = (struct ship*) malloc(sizeof(struct ship));
	this_ship->x = x;
	this_ship->y = y;
	this_ship->w = w;
	this_ship->h = h;
	this_ship->t = 0;
	this_ship->v = 0;
	this_ship->lc = 0;
	return this_ship;
}

void ship_draw(struct ship* ship, ofImage* image) {
	ofSetColor(255, 255, 255);
	image->draw(ship->x, ship->y, ship->w, ship->h);
}

void ship_thrust_right(struct ship* ship) {
	ship->v += ACCELERATION;
}

void ship_thrust_left(struct ship* ship) {
	ship->v -= ACCELERATION;
}

void ship_move(struct ship* ship) {
	ship->x += ship->v;
	ship->v *= 0.90;
	ship->t += 0.05;
}

void ship_bob_around(struct ship* ship) {
	ship->y += 0.5 * sin(ship->t);
	ship->x -= 0.4 * cos(ship->t / 4);
	if (ship->t > 25.14) {
		ship->t = 0;
	}
}

bool ship_is_at_edge(struct ship* ship) {
	if (ship->x <= 0) {
		ship->x = 0;
		return true;
	}
	else if ((ship->x + ship->w) >= ofGetWidth()) {
		ship->x = ofGetWidth() - ship->w;
		return true;
	}
	return false;
}

void ship_bounce(struct ship* ship) {
	ship->v *= -0.5;
}

float get_ship_x(struct ship* s) {
	return s->x;
}

float get_ship_y(struct ship* s){
	return s->y;
}

float get_ship_w(struct ship* s) {
	return s->w;
}

float get_ship_h(struct ship* s) {
	return s->h;
}

int get_ship_lc(struct ship* s) {
	return s->lc;
}

void cycle_ship_lc(struct ship* s) {
	s->lc += 1;
	if (s->lc > 24) {
		s->lc = 0;
	}
}
#include "Player.h"
#include "Bullet.h"

Player::Player(float x, float y, int radius)
{
	p_X = x;
	p_Y = y;
	p_Radius = radius;
	p_SpeedX = 5;
	p_SpeedY = 5;
	schiesPause = 0;
}
Player::~Player()
{
}

void Player::draw(void) {
	al_draw_filled_circle(p_X, p_Y, p_Radius, al_map_rgb(100, 200, 255));
}
void Player::update(void) {
	float x_speed = 0;
	float y_speed = 0;
	if (Input::keyPressed(ALLEGRO_KEY_S)) {
		y_speed += p_SpeedY;
		if (p_Y + p_Radius > Screen::getHeight()) {
			p_Y = Screen::getHeight() - p_Radius;
		}
	}
	if (Input::keyPressed(ALLEGRO_KEY_W)) {
		y_speed -= p_SpeedY;
		if (p_Y - p_Radius < NULL) {
			p_Y = p_Radius;
		}
	}
	if (Input::keyPressed(ALLEGRO_KEY_D)) {
		x_speed += p_SpeedX;
		if (p_X + p_Radius > Screen::getWidth()) {
			p_X = Screen::getWidth() - p_Radius;
		}
	}
	if (Input::keyPressed(ALLEGRO_KEY_A)) {
		x_speed -= p_SpeedX;
		if (p_X - p_Radius < NULL) {
			p_X = p_Radius;
		}
	}
	if (x_speed != 0 && y_speed != 0) {
		p_X += x_speed/2;
		p_Y += y_speed/2;
	}
	else {
		p_X += x_speed;
		p_Y += y_speed;
	}

	if (schiesPause == 0) {
		int bulletSX = 0;
		int bulletSY = 0;
		int maxSpeed = 10;
		bool pressedX = false;
		bool pressedY = false;

		if (Input::keyPressed(ALLEGRO_KEY_RIGHT)) {
			bulletSX += maxSpeed;
			pressedX = true;
		}
		if(Input::keyPressed(ALLEGRO_KEY_LEFT)) {
			bulletSX -= maxSpeed;
			pressedX ^= true;
		}
		if (Input::keyPressed(ALLEGRO_KEY_UP)) {
			bulletSY -= maxSpeed;
			pressedY = true;
		}
		if (Input::keyPressed(ALLEGRO_KEY_DOWN)) {
			bulletSY += maxSpeed;
			pressedY ^= true;
		}

		if (pressedX || pressedY) {
			if (bulletSX != 0 && bulletSY != 0) {
				bulletSX = bulletSX / 2;
				bulletSY = bulletSY / 2;
			}
			ObjectControler::insert(new Bullet(p_X , p_Y , bulletSX, bulletSY));
			schiesPause = 10;
		}
	}
	else {
		schiesPause--;
	}
}
#include "Bullet.h"



Bullet::Bullet(int x, int y, int sx, int sy)
{
	p_X = x;
	p_Y = y;
	p_SpeedX = sx;
	p_SpeedY = sy;
	p_Radius = 4;
}


Bullet::~Bullet()
{
}

void Bullet::update(void) {
	p_X += p_SpeedX;
	p_Y += p_SpeedY;
	if (p_X  > Screen::getWidth()) {
		ObjectControler::remove(this);
	}
	if (p_X + (2 * p_Radius) < 0) {
		ObjectControler::remove(this);
	}
	if (p_Y  > Screen::getHeight()) {
		ObjectControler::remove(this);
	}
	if (p_Y + (2 * p_Radius) < 0) {
		ObjectControler::remove(this);
	}
}
void Bullet::draw(void) {
	al_draw_filled_circle(p_X, p_Y, p_Radius, al_map_rgb(255, 0, 0));
}

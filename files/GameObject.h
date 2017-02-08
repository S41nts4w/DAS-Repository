#pragma once
#include "Input.h"
class GameObject
{
protected:
	float p_X;
	float p_Y;
	float p_SpeedX;
	float p_SpeedY;
public:
	GameObject();
	virtual ~GameObject();
	virtual void draw(void) = 0;
	virtual void update(void) = 0;
};


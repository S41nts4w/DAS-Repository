#pragma once
#include "ObjectControler.h"

class Player : public GameObject
{
private:
	int p_Radius;
	int schiesPause;
public:
	Player(float, float,int);
	~Player();
	void draw(void);
	void update(void);
};


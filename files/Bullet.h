#pragma once
#include "ObjectControler.h"

class Bullet : public GameObject
{
private:
	int p_Radius;
public:
	Bullet(int,int,int,int);
	~Bullet();

	void update(void);
	void draw(void);
};


#pragma once

#define SCREENW 800
#define SCREENH 600
#define MAXFPS 60

class GameLoop
{
public:
	GameLoop();
	~GameLoop();
	int start(void);
};


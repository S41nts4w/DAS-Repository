#include "GameLoop.h"
#include "Scene.h"
#include <cstdio>


GameLoop::GameLoop()
{
}


GameLoop::~GameLoop()
{
}

int GameLoop::start(void) {
	try {
		Screen::init(SCREENW, SCREENH);
		Input::init(MAXFPS);
	}
	catch (const char* e) {
		Screen::deInit();
		Input::deInit();
		printf("%s", e);
		return -1;
	}
	bool draw = false;

	Scene scene;
	scene.build();

	Input::startTimer();
	while (Screen::isAlive())
	{
		if (Input::pollEvent()) {
			if (Input::isUpdate()) {
				for(auto it = ObjectControler::objects.begin(); it != ObjectControler::objects.end(); ++it){
					(*it)->update();
				}
				draw = true;
				ObjectControler::update();
			}
		}

		else if (draw) {
			draw = false;
			for (auto it = ObjectControler::objects.begin(); it != ObjectControler::objects.end(); ++it) {
				(*it)->draw();
			}
			Screen::swap();
		}
	}

	Screen::deInit();
	Input::deInit();
	ObjectControler::clear();
	return 0;
}

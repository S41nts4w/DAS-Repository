#include "Input.h"

ALLEGRO_EVENT_QUEUE *Input::p_Event_queue;
ALLEGRO_TIMER *Input::p_Fps_timer;
bool Input::p_IsUpdate;
bool Input::p_Keys[MAX_KEYS];

Input::Input()
{
}

Input::~Input()
{
}

void Input::init(int maxfps) {
	p_Event_queue = NULL;
	if (!al_install_keyboard()) {
		throw "No keyboard could be found";
	}
	p_Event_queue = al_create_event_queue();
	if (!p_Event_queue) {
		throw "Failed to create an event queue";
	}
	p_Fps_timer = al_create_timer(1.0 / maxfps);

	al_register_event_source(p_Event_queue, al_get_display_event_source(Screen::getDisplay()));
	al_register_event_source(p_Event_queue, al_get_timer_event_source(p_Fps_timer));
	al_register_event_source(p_Event_queue, al_get_keyboard_event_source());

	for (int i = 0; i < MAX_KEYS; i++) {
		p_Keys[i] = false;
	}
}
void Input::deInit(void) {
	al_destroy_event_queue(p_Event_queue);
	al_destroy_timer(p_Fps_timer);
}

void Input::startTimer(void) {
	al_start_timer(p_Fps_timer);
}
int Input::pollEvent(void) {
	p_IsUpdate = false;
	if (!al_is_event_queue_empty(p_Event_queue)) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(p_Event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			p_IsUpdate = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			Screen::close();
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			p_Keys[ev.keyboard.keycode] = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			p_Keys[ev.keyboard.keycode] = false;
		}
		return 1;
	}
	return 0;
}

bool Input::isUpdate(void) { return p_IsUpdate; }
bool Input::keyPressed(int key) { return p_Keys[key]; }
bool Input::keyReleased(int key) { return !p_Keys[key]; }

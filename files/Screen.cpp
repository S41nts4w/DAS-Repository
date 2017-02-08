#include "Screen.h"

ALLEGRO_DISPLAY *Screen::p_Display;
int Screen::p_Width;
int Screen::p_Height;
bool Screen::p_Alive;

Screen::Screen()
{
}

Screen::~Screen()
{
}

void Screen::init(int width, int height) {
	p_Width = width; 
	p_Height = height;
	p_Alive = true;

	p_Display = NULL;
	if (!al_init()) {
		throw "Failed to initialise allegro";
	}
	if (!al_init_primitives_addon()) {
		throw "Failed to initialise allegro primitives addon";
	}
	p_Display = al_create_display(width, height);
	if (!p_Display) {
		throw "Failed to create a display";
	}
}
void Screen::deInit(void) {
	al_destroy_display(p_Display);
}

ALLEGRO_DISPLAY* Screen::getDisplay(void) { return p_Display; }
int Screen::getWidth(void) { return p_Width; }
int Screen::getHeight(void) { return p_Height; }
bool Screen::isAlive(void) { return p_Alive; }

void Screen::swap(void) {
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

void Screen::close(void) {
	p_Alive = false;
}

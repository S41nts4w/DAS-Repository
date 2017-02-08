#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

class Screen
{
private:
	static ALLEGRO_DISPLAY *p_Display; //Das angezeigte bildschirm
	static int p_Width; //Die breite des bildschirms
	static int p_Height; //Die hoehe des bildschirms
	static bool p_Alive; //Zeigt ob das Bildschirm noch am leben ist
public:
	Screen();
	~Screen();
	static void init(int, int); //Initialisiert alle wichtigen allegro functionen und erschaft das bildschirm
	static void deInit(void); //Deinitialisiert alles
	static ALLEGRO_DISPLAY* getDisplay(void); //Gibt denn bildschirm zeiger zuruck
	static int getWidth(void); //Gibt die bildschirm breite zuruck
	static int getHeight(void); //Gibt die bildschirm hoehe zuruck
	static bool isAlive(void); //Gibt zuruck ob der bildschirm noch existiert

	static void swap(void); //Swapt denn bildschirm buffer wo man malt
	static void close(void); //Schliest denn bildschirm
};

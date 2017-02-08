#pragma once
#include "Screen.h"

#define MAX_KEYS 227

class Input
{
private:
	static ALLEGRO_EVENT_QUEUE *p_Event_queue; //Die event schlange
	static ALLEGRO_TIMER *p_Fps_timer; //Der timer der 1/MAXFPS tickt
	static bool p_IsUpdate; //Boolean der zeigt ob der timer diese runde getickt hat
	static bool p_Keys[MAX_KEYS]; //Ein boolean array wo der status aller knopfer ist
public:
	Input();
	~Input();
	static void init(int); //Initialisiert alle variabeln und alle notwendigen allegro funktionen
	static void deInit(void); //Deinitialisiert alles
	static void startTimer(void); //Startet denn fps timer
	static int pollEvent(void); //Bearbeitet denn nexten event

	static bool isUpdate(void); //Gibt zuruck ob der fps timer getickt hat
	static bool keyPressed(int); //Gibt zuruck ob der knopf gedruckt ist
	static bool keyReleased(int); //Gibt zuruck ob der knopf nicht gedruct ist
};


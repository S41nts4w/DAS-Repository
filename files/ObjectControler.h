#pragma once
#include <list>
#include "GameObject.h"
class ObjectControler
{
private:
	static std::list<std::list<GameObject*>::iterator> toDelete; //Liste alle elemente die gestorben sind wahrend update
	static std::list<GameObject*> toAdd; //Liste alle elemente die hinzugefugt sind wahrend update
public:
	ObjectControler();
	~ObjectControler();
	static std::list<GameObject*> objects; //Liste der objekte die existieren
	static void insert(GameObject*); //Fugt ein objekt zur toAdd liste ein
	static void remove(GameObject*); //Fugt ein objekt zur toDelete liste ein
	static void update(void); //Entfernt alle toDelete elemente aus objects aus und fugt alle toAdd elemente hinzu
	static void clear(void); //Loscht alle elemente von objects
};


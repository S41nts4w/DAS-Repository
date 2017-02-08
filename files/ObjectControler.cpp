#include "ObjectControler.h"

std::list<GameObject*> ObjectControler::objects;
std::list<std::list<GameObject*>::iterator> ObjectControler::toDelete;
std::list<GameObject*> ObjectControler::toAdd;

ObjectControler::ObjectControler()
{
}


ObjectControler::~ObjectControler()
{
}

void ObjectControler::insert(GameObject* element) {
	toAdd.push_back(element);
}
void ObjectControler::update(void) {
	for (auto it = toDelete.begin(); it != toDelete.end(); ++it) {
		delete (*(*it));
		objects.erase(*it);
	}
	for (auto it = toAdd.begin(); it != toAdd.end(); ++it) {
		objects.push_back((*it));
	}
	toDelete.clear();
	toAdd.clear();
}
void ObjectControler::remove(GameObject* element) {
	auto it = objects.begin();
	while (it != objects.end()) {
		if ((*it) == element) {
			toDelete.push_back(it);
			break;
		}
		++it;
	}
}
void ObjectControler::clear(void) {
	for (auto it = objects.begin(); it != objects.end(); ++it) {
		delete (*it);
	}
}
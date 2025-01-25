#include "Factory.h"

void Factory::AddObject(AString* obj) {
    objects.push_back(obj);
}

void Factory::DeleteObject(int index) {
    if (index >= 0 && index < objects.size()) {
        delete objects[index];
        objects.erase(objects.begin() + index);
    }
}

const std::vector<AString*>& Factory::GetObjects() const {
    return objects;
}

Factory::~Factory() {
    for (auto obj : objects) {
        delete obj;
    }
}
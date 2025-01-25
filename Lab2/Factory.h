#pragma once

#include <vector>
#include "AString.h"

class Factory {
public:
    void AddObject(AString* obj);
    void DeleteObject(int index);
    const std::vector<AString*>& GetObjects() const;
    ~Factory();

private:
    std::vector<AString*> objects;
};

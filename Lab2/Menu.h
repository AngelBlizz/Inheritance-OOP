#pragma once

#include "Factory.h"

class Menu {
public:
    Menu(Factory& factory);
    void ShowMenu();

private:
    void AddSymbString();
    void AddBinString();
    void DeleteObject();
    void ShowObjects();
    void SubtractObjects();
    Factory& factory;
};


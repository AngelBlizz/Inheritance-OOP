#include "Menu.h"
#include "Factory.h"
#include <clocale>

int main() {
    setlocale(LC_CTYPE, "rus");
    Factory factory;
    Menu menu(factory);
    menu.ShowMenu();
    return 0;
}
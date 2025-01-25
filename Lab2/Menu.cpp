#include "Menu.h"
#include "SymbString.h"
#include "BinString.h"
#include <iostream>

Menu::Menu(Factory& factory) : factory(factory) {}

void Menu::ShowMenu() {
    while (true) {
        std::cout << "1. Добавить SymbString\n";
        std::cout << "2. Добавить BinString\n";
        std::cout << "3. Удалить Объект\n";
        std::cout << "4. Показать Объекты\n";
        std::cout << "5. Вычесть(Subtract) Объекты\n";
        std::cout << "6. Выход\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: AddSymbString(); break;
        case 2: AddBinString(); break;
        case 3: DeleteObject(); break;
        case 4: ShowObjects(); break;
        case 5: SubtractObjects(); break;
        case 6: return;
        default: std::cout << "Неправильный выбор\n";
        }
    }
}

void Menu::AddSymbString() {
    std::string name, val;
    std::cout << "Введите имя: ";
    std::getline(std::cin, name);
    std::cout << "Введите значение: ";
    std::getline(std::cin, val);
    factory.AddObject(new SymbString(name, val));
}

void Menu::AddBinString() {
    std::string name, val;
    std::cout << "Введите имя: ";
    std::getline(std::cin, name);
    std::cout << "Введите бинарное значение: ";
    std::getline(std::cin, val);
    factory.AddObject(new BinString(name, val));
}

void Menu::DeleteObject() {
    int index;
    std::cout << "Введите индекс объекта для его удаления: ";
    std::cin >> index;
    factory.DeleteObject(index - 1);
}

void Menu::ShowObjects() {
    const auto& objects = factory.GetObjects();
    for (size_t i = 0; i < objects.size(); ++i) {
        std::cout << i + 1 << ". ";
        objects[i]->Show();
    }
}

void Menu::SubtractObjects() {
    int index1, index2;
    std::cout << "Введите индекс первого объекта: ";
    std::cin >> index1;
    std::cout << "Введите индекс второго объекта: ";
    std::cin >> index2;
    const auto& objects = factory.GetObjects();
    if (index1 > 0 && index1 <= objects.size() && index2 > 0 && index2 <= objects.size()) {
        AString* result = (*objects[index1 - 1]) - (*objects[index2 - 1]);
        if (result) {
            result->Show();
            delete result;
        }
        else {
            std::cout << "Вычитание для этих типов не поддерживается.\n";
        }
    }
    else {
        std::cout << "Invalid indices!\n";
    }
}
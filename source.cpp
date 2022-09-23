#include <iostream>
#include <Windows.h>
#include "Editor.h"

using namespace EDIT;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int id;
    
    RunEditor* program = nullptr;

    cout << "Який редактор потрібно відкрити?\n";
    cin >> id;

    switch (id)
    {
    case 1: program = new RunTextEditor; break;
    }

    Editor* edt = program->open();


    return 0;
}


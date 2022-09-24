#include <iostream>
#include <Windows.h>
#include "Editor.h"
#include "Menu.h"



void menu();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	menu();

    return 0;
}

void menu()
{
	using namespace EDIT;
	using namespace MENU;

	RunEditor* program = nullptr;

	while (true)
	{
		system("cls");
		int c = Menu::select_vertical({ "Відкрити текстовий редактор",
										"Відкрити графічний редактр",
										"Вихід" },
			HorizontalAlignment::Center, 5);

		switch (c)
		{
		case 0:
		{
			program = new RunTextEditor;
			Editor* edt = program->open();
			edt->menu();
			break;
		}
		//case 1: printAllwords(); break;
		case 2: exit(0);
		default:
			break;
		}
	}
}

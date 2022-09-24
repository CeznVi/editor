#pragma once
#include <Windows.h> 
#include "Menu.h"



namespace EDIT
{
	using std::cout;
	using std::cin;
	using std::string;
	using namespace MENU;

	class Editor
	{
	public:
		virtual ~Editor() {}
		virtual string getProgramName() = 0;
		virtual void menu() = 0;
		virtual void fileMenu() = 0;
		virtual void create() = 0;
		virtual void openFile() = 0;
		virtual void saveFile() = 0;
		virtual void saveFileNewName() = 0;
		virtual void print() = 0;
		virtual void close() = 0;	
	};

	class TextEditor : public Editor
	{

	public:
		virtual string getProgramName()override
		{
			return "текстовий редактор \n";
		}
		virtual void menu() override
		{
			Sleep(500);
			
			while (true)
			{
				system("cls");
				int c = Menu::select_vertical({ "Файлове меню",
												"Шрифт",
												"Абзац",
												"Таблиця",
												"Зображення",
												"Вихід" },
					HorizontalAlignment::Center, 5);

				switch (c)
				{
				case 0: this->fileMenu(); break;
				case 1: break;
				case 2: break;
				case 3: break;
				case 4: break;
				case 5: return;
				default:
					break;
				}
			}

		}
		virtual void fileMenu() override
		{
			Sleep(500);

			while (true)
			{
				system("cls");
				int c = Menu::select_vertical({ "Створити новий текстовий файл",
												"Відкрити текстовий файл",
												"Зберегти текстовий файл",
												"Зберегти текстовий файл під новим ім'ям",
												"Роздрукувати файл",
												"Закрити файл",
												"Вихід" },
					HorizontalAlignment::Center, 5);

				switch (c)
				{
				case 0: this->create(); break;
				case 1: this->openFile(); break;
				case 2: this->saveFile(); break;
				case 3: this->saveFileNewName(); break;
				case 4: this->print(); break;
				case 5: this->close(); break;
				case 6: return;
				default:
					break;
				}
			}
		}
		virtual void create() override 
		{ 
			system("cls");
			cout << "Cтворено текстовий файл\n"; 
			Sleep(500);
		}
		virtual void openFile() override
		{
			system("cls");
			cout << "Відкрито текстовий файл\n";
			Sleep(500);
		}
		virtual void saveFile() override
		{
			system("cls");
			cout << "Збережено текстовий файл\n";
			Sleep(500);
		}
		virtual void saveFileNewName() override
		{
			string name;

			system("cls");
			cout << "Введіть ім'я файлу\n";
			cin >> name;
			cout << "Збережено текстовий файл під ім'ям " << name << "\n";
			Sleep(1000);
		}
		virtual void print() override
		{
			system("cls");
			cout << "Роздруковано текстовий файл\n";
			Sleep(500);
		}
		virtual void close() override
		{
			system("cls");
			cout << "Закрито текстовий файл\n";
			Sleep(500);
		}
	};

	class ImageEditor : public Editor
	{
	public:
		virtual string getProgramName()override
		{
			return "графічний редактор \n";
		}
		virtual void menu() override
		{
			Sleep(500);

			while (true)
			{
				system("cls");
				int c = Menu::select_vertical({ "Файлове меню",
												"Палітра кольорів",
												"Панель інструментів",
												"Панель текстова",
												"Зображення",
												"Вихід" },
					HorizontalAlignment::Center, 5);

				switch (c)
				{
				case 0: this->fileMenu(); break;
				case 1: break;
				case 2: break;
				case 3: break;
				case 4: break;
				case 5: return;
				default:
					break;
				}
			}

		}

		virtual void fileMenu() override
		{
			Sleep(500);

			while (true)
			{
				system("cls");
				int c = Menu::select_vertical({ "Створити нове зображення",
												"Відкрити файл зображення",
												"Зберегти файл зображення",
												"Зберегти файл зображенння під новим ім'ям",
												"Змінити формат файлу зображенння",
												"Роздрукувати зображення",
												"Закрити зображення",
												"Вихід" },
					HorizontalAlignment::Center, 5);

				switch (c)
				{
				case 0: this->create(); break;
				case 1: this->openFile(); break;
				case 2: this->saveFile(); break;
				case 3: this->saveFileNewName(); break;
				case 4: this->saveFileEXP(); break;
				case 5: this->print(); break;
				case 6: this->close(); break;
				case 7: return;
				default:
					break;
				}
			}
		}
		virtual void create() override
		{
			system("cls");
			cout << "Cтворено файл зображення\n";
			Sleep(500);
		}
		virtual void openFile() override
		{
			system("cls");
			cout << "Відкрито файл зображення\n";
			Sleep(500);
		}
		virtual void saveFile() override
		{
			system("cls");
			cout << "Збережено файл зображення\n";
			Sleep(500);
		}
		virtual void saveFileNewName() override
		{
			string name;

			system("cls");
			cout << "Введіть ім'я файл зображення\n";
			cin >> name;
			cout << "Збережено файл зображення під ім'ям " << name << "\n";
			Sleep(1000);
		}
		virtual void saveFileEXP()
		{
			string name;

			system("cls");
			cout << "Введіть розширення файлу зображення\n";
			cin >> name;
			cout << "Збережено файл зображення у форматі " << name << "\n";
			Sleep(1000);
		}
		virtual void print() override
		{
			system("cls");
			cout << "Роздруковано файл зображення\n";
			Sleep(500);
		}
		virtual void close() override
		{
			system("cls");
			cout << "Закрито файл зображення\n";
			Sleep(500);
		}
	};

	class RunEditor
	{
	public:
		virtual ~RunEditor() {}
		virtual Editor* openEditor() = 0;
		Editor* open()
		{
			Editor* program = this->openEditor();
			cout << "Відкрито " << program->getProgramName() << '\n';
			return program;
		}
	};

	class RunTextEditor : public RunEditor
	{
	public:
		virtual Editor* openEditor() override
		{
			return new TextEditor();
		}

	};

	class RunImageEditor : public RunEditor
	{
	public:
		virtual Editor* openEditor() override
		{
			return new ImageEditor();
		}

	};

}
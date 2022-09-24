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
			return "��������� �������� \n";
		}
		virtual void menu() override
		{
			Sleep(500);
			
			while (true)
			{
				system("cls");
				int c = Menu::select_vertical({ "������� ����",
												"�����",
												"�����",
												"�������",
												"�����" },
					HorizontalAlignment::Center, 5);

				switch (c)
				{
				case 0: this->fileMenu(); break;
				//case 1: this->openFile(); break;
				//case 2: this->saveFile(); break;
				//case 3: this->saveFileNewName(); break;
				//case 4: this->print(); break;
				//case 5: this->close(); break;
				case 6: return;
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
				int c = Menu::select_vertical({ "�������� ����� ��������� ����",
												"³������ ��������� ����",
												"�������� ��������� ����",
												"�������� ��������� ���� �� ����� ��'��",
												"������������ ����",
												"������� ����",
												"�����" },
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
			cout << "C������� ��������� ����\n"; 
			Sleep(500);
		}
		virtual void openFile() override
		{
			system("cls");
			cout << "³������ ��������� ����\n";
			Sleep(500);
		}
		virtual void saveFile() override
		{
			system("cls");
			cout << "��������� ��������� ����\n";
			Sleep(500);
		}
		virtual void saveFileNewName() override
		{
			string name;

			system("cls");
			cout << "������ ��'� �����\n";
			cin >> name;
			cout << "��������� ��������� ���� �� ��'�� " << name << "\n";
			Sleep(1000);
		}
		virtual void print() override
		{
			system("cls");
			cout << "������������ ��������� ����\n";
			Sleep(500);
		}
		virtual void close() override
		{
			system("cls");
			cout << "������� ��������� ����\n";
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
			cout << "³������ " << program->getProgramName() << '\n';
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



}
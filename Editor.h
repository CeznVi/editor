#pragma once


namespace EDIT
{
	using std::cout;
	using std::cin;
	using std::string;

	class Editor
	{
	public:
		virtual ~Editor() {}
		

		virtual string getProgramName() = 0;
	};

	class TextEditor : public Editor
	{

	public:
		virtual string getProgramName()override
		{
			return "текстовий редактор \n";
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



}
#pragma once
#include <cliext/map>
#include <vector>

#include <Windows.h>

#include "Keys_codes.h"

//[System::Runtime::InteropServices::DllImport("user32.dll")]
//UINT SendInput(UINT, INPUT[], int);
#pragma comment(lib,"user32.lib")

//using System::Runtime::InteropServices;

std::vector <INPUT> input;
std::vector <UINT> v_keys;

namespace SendImput {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			init_key_map();
			init_key_obj_map();
			clamp_flag = radioButtonHold->Checked;
			interval = Convert::ToInt16(textBoxTime1->Text);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Esc;
	private: System::Windows::Forms::Button^ F1;
	private: System::Windows::Forms::Button^ F2;
	private: System::Windows::Forms::Button^ F3;
	private: System::Windows::Forms::Button^ F4;
	private: System::Windows::Forms::Button^ F5;
	private: System::Windows::Forms::Button^ F6;
	private: System::Windows::Forms::Button^ F7;
	private: System::Windows::Forms::Button^ F8;
	private: System::Windows::Forms::Button^ F9;
	private: System::Windows::Forms::Button^ F10;
	private: System::Windows::Forms::Button^ F11;
	private: System::Windows::Forms::Button^ F12;
	private: System::Windows::Forms::Button^ PrintScr;
	private: System::Windows::Forms::Button^ ScrLoc;
	private: System::Windows::Forms::Button^ Pause;
	private: System::Windows::Forms::Button^ Tilda;
	private: System::Windows::Forms::Button^ n1;
	private: System::Windows::Forms::Button^ n2;
	private: System::Windows::Forms::Button^ n3;
	private: System::Windows::Forms::Button^ n4;
	private: System::Windows::Forms::Button^ n5;
	private: System::Windows::Forms::Button^ n6;
	private: System::Windows::Forms::Button^ n7;
	private: System::Windows::Forms::Button^ n8;
	private: System::Windows::Forms::Button^ n9;
	private: System::Windows::Forms::Button^ n0;
	private: System::Windows::Forms::Button^ minus;
	private: System::Windows::Forms::Button^ plus;
	private: System::Windows::Forms::Button^ slash;
	private: System::Windows::Forms::Button^ backspace;
	private: System::Windows::Forms::Button^ Ins;
	private: System::Windows::Forms::Button^ Home;
	private: System::Windows::Forms::Button^ PgUp;
	private: System::Windows::Forms::Button^ NumLoc;
	private: System::Windows::Forms::Button^ c_backslash;
	private: System::Windows::Forms::Button^ c_mult;
	private: System::Windows::Forms::Button^ c_minus;
	private: System::Windows::Forms::Button^ Tab;
	private: System::Windows::Forms::Button^ k_Q;
	private: System::Windows::Forms::Button^ k_W;
	private: System::Windows::Forms::Button^ k_E;
	private: System::Windows::Forms::Button^ k_R;
	private: System::Windows::Forms::Button^ k_T;
	private: System::Windows::Forms::Button^ k_Y;
	private: System::Windows::Forms::Button^ k_U;
	private: System::Windows::Forms::Button^ k_I;
	private: System::Windows::Forms::Button^ k_O;
	private: System::Windows::Forms::Button^ k_P;
	private: System::Windows::Forms::Button^ bracket_left;
	private: System::Windows::Forms::Button^ bracket_right;
	private: System::Windows::Forms::Button^ Enter;
	private: System::Windows::Forms::Button^ CapsLock;
	private: System::Windows::Forms::Button^ k_A;
	private: System::Windows::Forms::Button^ k_S;
	private: System::Windows::Forms::Button^ k_D;
	private: System::Windows::Forms::Button^ k_F;
	private: System::Windows::Forms::Button^ k_G;
	private: System::Windows::Forms::Button^ k_H;
	private: System::Windows::Forms::Button^ k_J;
	private: System::Windows::Forms::Button^ k_K;
	private: System::Windows::Forms::Button^ k_L;
	private: System::Windows::Forms::Button^ Colon;
	private: System::Windows::Forms::Button^ QuotationMarks;
	private: System::Windows::Forms::Button^ Del;
	private: System::Windows::Forms::Button^ End;
	private: System::Windows::Forms::Button^ PgDwn;
	private: System::Windows::Forms::Button^ c_7;
	private: System::Windows::Forms::Button^ c_8;
	private: System::Windows::Forms::Button^ c_9;
	private: System::Windows::Forms::Button^ c_plus;
	private: System::Windows::Forms::Button^ c_4;
	private: System::Windows::Forms::Button^ c_5;
	private: System::Windows::Forms::Button^ c_6;
	private: System::Windows::Forms::Button^ c_1;
	private: System::Windows::Forms::Button^ c_2;
	private: System::Windows::Forms::Button^ c_3;
	private: System::Windows::Forms::Button^ c_enter;
	private: System::Windows::Forms::Button^ c_0;
	private: System::Windows::Forms::Button^ c_point;
	private: System::Windows::Forms::Button^ arrow_right;
	private: System::Windows::Forms::Button^ arrow_down;
	private: System::Windows::Forms::Button^ arrow_left;
	private: System::Windows::Forms::Button^ arrow_up;
	private: System::Windows::Forms::Button^ ShiftL;
	private: System::Windows::Forms::Button^ k_Z;
	private: System::Windows::Forms::Button^ k_X;
	private: System::Windows::Forms::Button^ k_C;
	private: System::Windows::Forms::Button^ k_V;
	private: System::Windows::Forms::Button^ k_B;
	private: System::Windows::Forms::Button^ k_N;
	private: System::Windows::Forms::Button^ k_M;
	private: System::Windows::Forms::Button^ k_lesser;
	private: System::Windows::Forms::Button^ k_greater;
	private: System::Windows::Forms::Button^ QuestionMark;
	private: System::Windows::Forms::Button^ ShiftR;
	private: System::Windows::Forms::Button^ CtrlL;
	private: System::Windows::Forms::Button^ k_WinL;
	private: System::Windows::Forms::Button^ AltL;
	private: System::Windows::Forms::Button^ Space;
	private: System::Windows::Forms::Button^ AltR;
	private: System::Windows::Forms::Button^ k_WinR;
	private: System::Windows::Forms::Button^ Menu;
	private: System::Windows::Forms::Button^ CtrlR;
	private: System::Windows::Forms::CheckBox^ checkBoxStart;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ ClearButton;
	private: System::Windows::Forms::RadioButton^ radioButtonHold;



	private: System::Windows::Forms::TextBox^ textBoxTime1;
	private: System::Windows::Forms::Label^ labelTime1;
	private: System::Windows::Forms::RadioButton^ radioButtonOneClick;

	private: System::Windows::Forms::TextBox^ textBoxTime2;
	private: System::Windows::Forms::Label^ labelTime2;
	private: System::Windows::Forms::Timer^ timer1;

	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Esc = (gcnew System::Windows::Forms::Button());
			this->F1 = (gcnew System::Windows::Forms::Button());
			this->F2 = (gcnew System::Windows::Forms::Button());
			this->F3 = (gcnew System::Windows::Forms::Button());
			this->F4 = (gcnew System::Windows::Forms::Button());
			this->F5 = (gcnew System::Windows::Forms::Button());
			this->F6 = (gcnew System::Windows::Forms::Button());
			this->F7 = (gcnew System::Windows::Forms::Button());
			this->F8 = (gcnew System::Windows::Forms::Button());
			this->F9 = (gcnew System::Windows::Forms::Button());
			this->F10 = (gcnew System::Windows::Forms::Button());
			this->F11 = (gcnew System::Windows::Forms::Button());
			this->F12 = (gcnew System::Windows::Forms::Button());
			this->PrintScr = (gcnew System::Windows::Forms::Button());
			this->ScrLoc = (gcnew System::Windows::Forms::Button());
			this->Pause = (gcnew System::Windows::Forms::Button());
			this->Tilda = (gcnew System::Windows::Forms::Button());
			this->n1 = (gcnew System::Windows::Forms::Button());
			this->n2 = (gcnew System::Windows::Forms::Button());
			this->n3 = (gcnew System::Windows::Forms::Button());
			this->n4 = (gcnew System::Windows::Forms::Button());
			this->n5 = (gcnew System::Windows::Forms::Button());
			this->n6 = (gcnew System::Windows::Forms::Button());
			this->n7 = (gcnew System::Windows::Forms::Button());
			this->n8 = (gcnew System::Windows::Forms::Button());
			this->n9 = (gcnew System::Windows::Forms::Button());
			this->n0 = (gcnew System::Windows::Forms::Button());
			this->minus = (gcnew System::Windows::Forms::Button());
			this->plus = (gcnew System::Windows::Forms::Button());
			this->slash = (gcnew System::Windows::Forms::Button());
			this->backspace = (gcnew System::Windows::Forms::Button());
			this->Ins = (gcnew System::Windows::Forms::Button());
			this->Home = (gcnew System::Windows::Forms::Button());
			this->PgUp = (gcnew System::Windows::Forms::Button());
			this->NumLoc = (gcnew System::Windows::Forms::Button());
			this->c_backslash = (gcnew System::Windows::Forms::Button());
			this->c_mult = (gcnew System::Windows::Forms::Button());
			this->c_minus = (gcnew System::Windows::Forms::Button());
			this->Tab = (gcnew System::Windows::Forms::Button());
			this->k_Q = (gcnew System::Windows::Forms::Button());
			this->k_W = (gcnew System::Windows::Forms::Button());
			this->k_E = (gcnew System::Windows::Forms::Button());
			this->k_R = (gcnew System::Windows::Forms::Button());
			this->k_T = (gcnew System::Windows::Forms::Button());
			this->k_Y = (gcnew System::Windows::Forms::Button());
			this->k_U = (gcnew System::Windows::Forms::Button());
			this->k_I = (gcnew System::Windows::Forms::Button());
			this->k_O = (gcnew System::Windows::Forms::Button());
			this->k_P = (gcnew System::Windows::Forms::Button());
			this->bracket_left = (gcnew System::Windows::Forms::Button());
			this->bracket_right = (gcnew System::Windows::Forms::Button());
			this->Enter = (gcnew System::Windows::Forms::Button());
			this->CapsLock = (gcnew System::Windows::Forms::Button());
			this->k_A = (gcnew System::Windows::Forms::Button());
			this->k_S = (gcnew System::Windows::Forms::Button());
			this->k_D = (gcnew System::Windows::Forms::Button());
			this->k_F = (gcnew System::Windows::Forms::Button());
			this->k_G = (gcnew System::Windows::Forms::Button());
			this->k_H = (gcnew System::Windows::Forms::Button());
			this->k_J = (gcnew System::Windows::Forms::Button());
			this->k_K = (gcnew System::Windows::Forms::Button());
			this->k_L = (gcnew System::Windows::Forms::Button());
			this->Colon = (gcnew System::Windows::Forms::Button());
			this->QuotationMarks = (gcnew System::Windows::Forms::Button());
			this->Del = (gcnew System::Windows::Forms::Button());
			this->End = (gcnew System::Windows::Forms::Button());
			this->PgDwn = (gcnew System::Windows::Forms::Button());
			this->c_7 = (gcnew System::Windows::Forms::Button());
			this->c_8 = (gcnew System::Windows::Forms::Button());
			this->c_9 = (gcnew System::Windows::Forms::Button());
			this->c_plus = (gcnew System::Windows::Forms::Button());
			this->c_4 = (gcnew System::Windows::Forms::Button());
			this->c_5 = (gcnew System::Windows::Forms::Button());
			this->c_6 = (gcnew System::Windows::Forms::Button());
			this->c_1 = (gcnew System::Windows::Forms::Button());
			this->c_2 = (gcnew System::Windows::Forms::Button());
			this->c_3 = (gcnew System::Windows::Forms::Button());
			this->c_enter = (gcnew System::Windows::Forms::Button());
			this->c_0 = (gcnew System::Windows::Forms::Button());
			this->c_point = (gcnew System::Windows::Forms::Button());
			this->arrow_right = (gcnew System::Windows::Forms::Button());
			this->arrow_down = (gcnew System::Windows::Forms::Button());
			this->arrow_left = (gcnew System::Windows::Forms::Button());
			this->arrow_up = (gcnew System::Windows::Forms::Button());
			this->ShiftL = (gcnew System::Windows::Forms::Button());
			this->k_Z = (gcnew System::Windows::Forms::Button());
			this->k_X = (gcnew System::Windows::Forms::Button());
			this->k_C = (gcnew System::Windows::Forms::Button());
			this->k_V = (gcnew System::Windows::Forms::Button());
			this->k_B = (gcnew System::Windows::Forms::Button());
			this->k_N = (gcnew System::Windows::Forms::Button());
			this->k_M = (gcnew System::Windows::Forms::Button());
			this->k_lesser = (gcnew System::Windows::Forms::Button());
			this->k_greater = (gcnew System::Windows::Forms::Button());
			this->QuestionMark = (gcnew System::Windows::Forms::Button());
			this->ShiftR = (gcnew System::Windows::Forms::Button());
			this->CtrlL = (gcnew System::Windows::Forms::Button());
			this->k_WinL = (gcnew System::Windows::Forms::Button());
			this->AltL = (gcnew System::Windows::Forms::Button());
			this->Space = (gcnew System::Windows::Forms::Button());
			this->AltR = (gcnew System::Windows::Forms::Button());
			this->k_WinR = (gcnew System::Windows::Forms::Button());
			this->Menu = (gcnew System::Windows::Forms::Button());
			this->CtrlR = (gcnew System::Windows::Forms::Button());
			this->checkBoxStart = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->radioButtonHold = (gcnew System::Windows::Forms::RadioButton());
			this->textBoxTime1 = (gcnew System::Windows::Forms::TextBox());
			this->labelTime1 = (gcnew System::Windows::Forms::Label());
			this->radioButtonOneClick = (gcnew System::Windows::Forms::RadioButton());
			this->textBoxTime2 = (gcnew System::Windows::Forms::TextBox());
			this->labelTime2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// Esc
			// 
			this->Esc->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Esc->Location = System::Drawing::Point(12, 12);
			this->Esc->Name = L"Esc";
			this->Esc->Size = System::Drawing::Size(37, 38);
			this->Esc->TabIndex = 0;
			this->Esc->Text = L"Esc";
			this->Esc->UseVisualStyleBackColor = true;
			this->Esc->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F1
			// 
			this->F1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F1->Location = System::Drawing::Point(98, 12);
			this->F1->Name = L"F1";
			this->F1->Size = System::Drawing::Size(37, 38);
			this->F1->TabIndex = 1;
			this->F1->Text = L"F1";
			this->F1->UseVisualStyleBackColor = true;
			this->F1->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F2
			// 
			this->F2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F2->Location = System::Drawing::Point(141, 12);
			this->F2->Name = L"F2";
			this->F2->Size = System::Drawing::Size(37, 38);
			this->F2->TabIndex = 2;
			this->F2->Text = L"F2";
			this->F2->UseVisualStyleBackColor = true;
			this->F2->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F3
			// 
			this->F3->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F3->Location = System::Drawing::Point(184, 12);
			this->F3->Name = L"F3";
			this->F3->Size = System::Drawing::Size(37, 38);
			this->F3->TabIndex = 3;
			this->F3->Text = L"F3";
			this->F3->UseVisualStyleBackColor = true;
			this->F3->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F4
			// 
			this->F4->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F4->Location = System::Drawing::Point(227, 12);
			this->F4->Name = L"F4";
			this->F4->Size = System::Drawing::Size(37, 38);
			this->F4->TabIndex = 4;
			this->F4->Text = L"F4";
			this->F4->UseVisualStyleBackColor = true;
			this->F4->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F5
			// 
			this->F5->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F5->Location = System::Drawing::Point(292, 12);
			this->F5->Name = L"F5";
			this->F5->Size = System::Drawing::Size(37, 38);
			this->F5->TabIndex = 5;
			this->F5->Text = L"F5";
			this->F5->UseVisualStyleBackColor = true;
			this->F5->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F6
			// 
			this->F6->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F6->Location = System::Drawing::Point(335, 12);
			this->F6->Name = L"F6";
			this->F6->Size = System::Drawing::Size(37, 38);
			this->F6->TabIndex = 6;
			this->F6->Text = L"F6";
			this->F6->UseVisualStyleBackColor = true;
			this->F6->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F7
			// 
			this->F7->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F7->Location = System::Drawing::Point(378, 12);
			this->F7->Name = L"F7";
			this->F7->Size = System::Drawing::Size(37, 38);
			this->F7->TabIndex = 7;
			this->F7->Text = L"F7";
			this->F7->UseVisualStyleBackColor = true;
			this->F7->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F8
			// 
			this->F8->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F8->Location = System::Drawing::Point(421, 12);
			this->F8->Name = L"F8";
			this->F8->Size = System::Drawing::Size(37, 38);
			this->F8->TabIndex = 8;
			this->F8->Text = L"F8";
			this->F8->UseVisualStyleBackColor = true;
			this->F8->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F9
			// 
			this->F9->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F9->Location = System::Drawing::Point(485, 12);
			this->F9->Name = L"F9";
			this->F9->Size = System::Drawing::Size(37, 38);
			this->F9->TabIndex = 9;
			this->F9->Text = L"F9";
			this->F9->UseVisualStyleBackColor = true;
			this->F9->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F10
			// 
			this->F10->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F10->Location = System::Drawing::Point(528, 12);
			this->F10->Name = L"F10";
			this->F10->Size = System::Drawing::Size(37, 38);
			this->F10->TabIndex = 10;
			this->F10->Text = L"F10";
			this->F10->UseVisualStyleBackColor = true;
			this->F10->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F11
			// 
			this->F11->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F11->Location = System::Drawing::Point(571, 12);
			this->F11->Name = L"F11";
			this->F11->Size = System::Drawing::Size(37, 38);
			this->F11->TabIndex = 11;
			this->F11->Text = L"F11";
			this->F11->UseVisualStyleBackColor = true;
			this->F11->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// F12
			// 
			this->F12->BackColor = System::Drawing::SystemColors::ControlDark;
			this->F12->Location = System::Drawing::Point(614, 12);
			this->F12->Name = L"F12";
			this->F12->Size = System::Drawing::Size(37, 38);
			this->F12->TabIndex = 12;
			this->F12->Text = L"F12";
			this->F12->UseVisualStyleBackColor = true;
			this->F12->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// PrintScr
			// 
			this->PrintScr->BackColor = System::Drawing::SystemColors::ControlDark;
			this->PrintScr->Location = System::Drawing::Point(674, 12);
			this->PrintScr->Name = L"PrintScr";
			this->PrintScr->Size = System::Drawing::Size(37, 38);
			this->PrintScr->TabIndex = 13;
			this->PrintScr->Text = L"Print Scr";
			this->PrintScr->UseVisualStyleBackColor = true;
			this->PrintScr->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// ScrLoc
			// 
			this->ScrLoc->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ScrLoc->Location = System::Drawing::Point(717, 12);
			this->ScrLoc->Name = L"ScrLoc";
			this->ScrLoc->Size = System::Drawing::Size(37, 38);
			this->ScrLoc->TabIndex = 14;
			this->ScrLoc->Text = L"Scr Loc";
			this->ScrLoc->UseVisualStyleBackColor = true;
			this->ScrLoc->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// Pause
			// 
			this->Pause->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Pause->Location = System::Drawing::Point(760, 12);
			this->Pause->Name = L"Pause";
			this->Pause->Size = System::Drawing::Size(37, 38);
			this->Pause->TabIndex = 15;
			this->Pause->Text = L"Pause";
			this->Pause->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->Pause->UseVisualStyleBackColor = true;
			this->Pause->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// Tilda
			// 
			this->Tilda->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Tilda->Location = System::Drawing::Point(12, 67);
			this->Tilda->Name = L"Tilda";
			this->Tilda->Size = System::Drawing::Size(37, 38);
			this->Tilda->TabIndex = 16;
			this->Tilda->Text = L"~";
			this->Tilda->UseVisualStyleBackColor = true;
			this->Tilda->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// n1
			// 
			this->n1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->n1->Location = System::Drawing::Point(55, 67);
			this->n1->Name = L"n1";
			this->n1->Size = System::Drawing::Size(37, 38);
			this->n1->TabIndex = 17;
			this->n1->Text = L"1";
			this->n1->UseVisualStyleBackColor = true;
			this->n1->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// n2
			// 
			this->n2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->n2->Location = System::Drawing::Point(98, 67);
			this->n2->Name = L"n2";
			this->n2->Size = System::Drawing::Size(37, 38);
			this->n2->TabIndex = 18;
			this->n2->Text = L"2";
			this->n2->UseVisualStyleBackColor = true;
			this->n2->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// n3
			// 
			this->n3->BackColor = System::Drawing::SystemColors::ControlDark;
			this->n3->Location = System::Drawing::Point(141, 67);
			this->n3->Name = L"n3";
			this->n3->Size = System::Drawing::Size(37, 38);
			this->n3->TabIndex = 19;
			this->n3->Text = L"3";
			this->n3->UseVisualStyleBackColor = true;
			this->n3->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// n4
			// 
			this->n4->BackColor = System::Drawing::SystemColors::ControlDark;
			this->n4->Location = System::Drawing::Point(184, 67);
			this->n4->Name = L"n4";
			this->n4->Size = System::Drawing::Size(37, 38);
			this->n4->TabIndex = 20;
			this->n4->Text = L"4";
			this->n4->UseVisualStyleBackColor = true;
			this->n4->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// n5
			// 
			this->n5->BackColor = System::Drawing::SystemColors::ControlDark;
			this->n5->Location = System::Drawing::Point(227, 67);
			this->n5->Name = L"n5";
			this->n5->Size = System::Drawing::Size(37, 38);
			this->n5->TabIndex = 21;
			this->n5->Text = L"5";
			this->n5->UseVisualStyleBackColor = true;
			this->n5->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// n6
			// 
			this->n6->BackColor = System::Drawing::SystemColors::ControlDark;
			this->n6->Location = System::Drawing::Point(270, 67);
			this->n6->Name = L"n6";
			this->n6->Size = System::Drawing::Size(37, 38);
			this->n6->TabIndex = 22;
			this->n6->Text = L"6";
			this->n6->UseVisualStyleBackColor = true;
			this->n6->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// n7
			// 
			this->n7->BackColor = System::Drawing::SystemColors::ControlDark;
			this->n7->Location = System::Drawing::Point(313, 67);
			this->n7->Name = L"n7";
			this->n7->Size = System::Drawing::Size(37, 38);
			this->n7->TabIndex = 23;
			this->n7->Text = L"7";
			this->n7->UseVisualStyleBackColor = true;
			this->n7->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// n8
			// 
			this->n8->BackColor = System::Drawing::SystemColors::ControlDark;
			this->n8->Location = System::Drawing::Point(356, 67);
			this->n8->Name = L"n8";
			this->n8->Size = System::Drawing::Size(37, 38);
			this->n8->TabIndex = 24;
			this->n8->Text = L"8";
			this->n8->UseVisualStyleBackColor = true;
			this->n8->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// n9
			// 
			this->n9->BackColor = System::Drawing::SystemColors::ControlDark;
			this->n9->Location = System::Drawing::Point(399, 67);
			this->n9->Name = L"n9";
			this->n9->Size = System::Drawing::Size(37, 38);
			this->n9->TabIndex = 25;
			this->n9->Text = L"9";
			this->n9->UseVisualStyleBackColor = true;
			this->n9->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// n0
			// 
			this->n0->BackColor = System::Drawing::SystemColors::ControlDark;
			this->n0->Location = System::Drawing::Point(442, 67);
			this->n0->Name = L"n0";
			this->n0->Size = System::Drawing::Size(37, 38);
			this->n0->TabIndex = 26;
			this->n0->Text = L"0";
			this->n0->UseVisualStyleBackColor = true;
			this->n0->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// minus
			// 
			this->minus->BackColor = System::Drawing::SystemColors::ControlDark;
			this->minus->Location = System::Drawing::Point(485, 67);
			this->minus->Name = L"minus";
			this->minus->Size = System::Drawing::Size(37, 38);
			this->minus->TabIndex = 27;
			this->minus->Text = L"-";
			this->minus->UseVisualStyleBackColor = true;
			this->minus->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// plus
			// 
			this->plus->BackColor = System::Drawing::SystemColors::ControlDark;
			this->plus->Location = System::Drawing::Point(528, 67);
			this->plus->Name = L"plus";
			this->plus->Size = System::Drawing::Size(37, 38);
			this->plus->TabIndex = 28;
			this->plus->Text = L"+";
			this->plus->UseVisualStyleBackColor = true;
			this->plus->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// slash
			// 
			this->slash->BackColor = System::Drawing::SystemColors::ControlDark;
			this->slash->Location = System::Drawing::Point(571, 67);
			this->slash->Name = L"slash";
			this->slash->Size = System::Drawing::Size(37, 38);
			this->slash->TabIndex = 29;
			this->slash->Text = L"|      \\ /";
			this->slash->UseVisualStyleBackColor = true;
			this->slash->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// backspace
			// 
			this->backspace->BackColor = System::Drawing::SystemColors::ControlDark;
			this->backspace->Location = System::Drawing::Point(614, 67);
			this->backspace->Name = L"backspace";
			this->backspace->Size = System::Drawing::Size(37, 38);
			this->backspace->TabIndex = 30;
			this->backspace->Text = L"<-";
			this->backspace->UseVisualStyleBackColor = true;
			this->backspace->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// Ins
			// 
			this->Ins->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Ins->Location = System::Drawing::Point(674, 67);
			this->Ins->Name = L"Ins";
			this->Ins->Size = System::Drawing::Size(37, 38);
			this->Ins->TabIndex = 31;
			this->Ins->Text = L"Ins";
			this->Ins->UseVisualStyleBackColor = true;
			this->Ins->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// Home
			// 
			this->Home->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Home->Location = System::Drawing::Point(717, 67);
			this->Home->Name = L"Home";
			this->Home->Size = System::Drawing::Size(37, 38);
			this->Home->TabIndex = 32;
			this->Home->Text = L"Home";
			this->Home->UseVisualStyleBackColor = true;
			this->Home->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// PgUp
			// 
			this->PgUp->BackColor = System::Drawing::SystemColors::ControlDark;
			this->PgUp->Location = System::Drawing::Point(760, 67);
			this->PgUp->Name = L"PgUp";
			this->PgUp->Size = System::Drawing::Size(37, 38);
			this->PgUp->TabIndex = 33;
			this->PgUp->Text = L"Pg   Up";
			this->PgUp->UseVisualStyleBackColor = true;
			this->PgUp->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// NumLoc
			// 
			this->NumLoc->BackColor = System::Drawing::SystemColors::ControlDark;
			this->NumLoc->Location = System::Drawing::Point(826, 67);
			this->NumLoc->Name = L"NumLoc";
			this->NumLoc->Size = System::Drawing::Size(37, 38);
			this->NumLoc->TabIndex = 34;
			this->NumLoc->Text = L"Num Loc";
			this->NumLoc->UseVisualStyleBackColor = true;
			this->NumLoc->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_backslash
			// 
			this->c_backslash->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_backslash->Location = System::Drawing::Point(869, 67);
			this->c_backslash->Name = L"c_backslash";
			this->c_backslash->Size = System::Drawing::Size(37, 38);
			this->c_backslash->TabIndex = 35;
			this->c_backslash->Text = L"/";
			this->c_backslash->UseVisualStyleBackColor = true;
			this->c_backslash->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_mult
			// 
			this->c_mult->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_mult->Location = System::Drawing::Point(912, 67);
			this->c_mult->Name = L"c_mult";
			this->c_mult->Size = System::Drawing::Size(37, 38);
			this->c_mult->TabIndex = 36;
			this->c_mult->Text = L"*";
			this->c_mult->UseVisualStyleBackColor = true;
			this->c_mult->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_minus
			// 
			this->c_minus->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_minus->Location = System::Drawing::Point(955, 67);
			this->c_minus->Name = L"c_minus";
			this->c_minus->Size = System::Drawing::Size(37, 38);
			this->c_minus->TabIndex = 37;
			this->c_minus->Text = L"-";
			this->c_minus->UseVisualStyleBackColor = true;
			this->c_minus->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// Tab
			// 
			this->Tab->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Tab->Location = System::Drawing::Point(12, 111);
			this->Tab->Name = L"Tab";
			this->Tab->Size = System::Drawing::Size(59, 38);
			this->Tab->TabIndex = 38;
			this->Tab->Text = L"Tab";
			this->Tab->UseVisualStyleBackColor = true;
			this->Tab->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_Q
			// 
			this->k_Q->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_Q->Location = System::Drawing::Point(77, 111);
			this->k_Q->Name = L"k_Q";
			this->k_Q->Size = System::Drawing::Size(37, 38);
			this->k_Q->TabIndex = 39;
			this->k_Q->Text = L"Q";
			this->k_Q->UseVisualStyleBackColor = true;
			this->k_Q->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_W
			// 
			this->k_W->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_W->Location = System::Drawing::Point(120, 111);
			this->k_W->Name = L"k_W";
			this->k_W->Size = System::Drawing::Size(37, 38);
			this->k_W->TabIndex = 40;
			this->k_W->Text = L"W";
			this->k_W->UseVisualStyleBackColor = true;
			this->k_W->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_E
			// 
			this->k_E->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_E->Location = System::Drawing::Point(163, 111);
			this->k_E->Name = L"k_E";
			this->k_E->Size = System::Drawing::Size(37, 38);
			this->k_E->TabIndex = 41;
			this->k_E->Text = L"E";
			this->k_E->UseVisualStyleBackColor = true;
			this->k_E->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_R
			// 
			this->k_R->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_R->Location = System::Drawing::Point(206, 111);
			this->k_R->Name = L"k_R";
			this->k_R->Size = System::Drawing::Size(37, 38);
			this->k_R->TabIndex = 42;
			this->k_R->Text = L"R";
			this->k_R->UseVisualStyleBackColor = true;
			this->k_R->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_T
			// 
			this->k_T->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_T->Location = System::Drawing::Point(249, 111);
			this->k_T->Name = L"k_T";
			this->k_T->Size = System::Drawing::Size(37, 38);
			this->k_T->TabIndex = 43;
			this->k_T->Text = L"T";
			this->k_T->UseVisualStyleBackColor = true;
			this->k_T->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_Y
			// 
			this->k_Y->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_Y->Location = System::Drawing::Point(292, 111);
			this->k_Y->Name = L"k_Y";
			this->k_Y->Size = System::Drawing::Size(37, 38);
			this->k_Y->TabIndex = 44;
			this->k_Y->Text = L"Y";
			this->k_Y->UseVisualStyleBackColor = true;
			this->k_Y->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_U
			// 
			this->k_U->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_U->Location = System::Drawing::Point(335, 111);
			this->k_U->Name = L"k_U";
			this->k_U->Size = System::Drawing::Size(37, 38);
			this->k_U->TabIndex = 45;
			this->k_U->Text = L"U";
			this->k_U->UseVisualStyleBackColor = true;
			this->k_U->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_I
			// 
			this->k_I->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_I->Location = System::Drawing::Point(378, 111);
			this->k_I->Name = L"k_I";
			this->k_I->Size = System::Drawing::Size(37, 38);
			this->k_I->TabIndex = 46;
			this->k_I->Text = L"I";
			this->k_I->UseVisualStyleBackColor = true;
			this->k_I->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_O
			// 
			this->k_O->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_O->Location = System::Drawing::Point(421, 111);
			this->k_O->Name = L"k_O";
			this->k_O->Size = System::Drawing::Size(37, 38);
			this->k_O->TabIndex = 47;
			this->k_O->Text = L"O";
			this->k_O->UseVisualStyleBackColor = true;
			this->k_O->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_P
			// 
			this->k_P->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_P->Location = System::Drawing::Point(464, 111);
			this->k_P->Name = L"k_P";
			this->k_P->Size = System::Drawing::Size(37, 38);
			this->k_P->TabIndex = 48;
			this->k_P->Text = L"P";
			this->k_P->UseVisualStyleBackColor = true;
			this->k_P->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// bracket_left
			// 
			this->bracket_left->BackColor = System::Drawing::SystemColors::ControlDark;
			this->bracket_left->Location = System::Drawing::Point(507, 111);
			this->bracket_left->Name = L"bracket_left";
			this->bracket_left->Size = System::Drawing::Size(37, 38);
			this->bracket_left->TabIndex = 49;
			this->bracket_left->Text = L"[";
			this->bracket_left->UseVisualStyleBackColor = true;
			this->bracket_left->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// bracket_right
			// 
			this->bracket_right->BackColor = System::Drawing::SystemColors::ControlDark;
			this->bracket_right->Location = System::Drawing::Point(550, 111);
			this->bracket_right->Name = L"bracket_right";
			this->bracket_right->Size = System::Drawing::Size(37, 38);
			this->bracket_right->TabIndex = 50;
			this->bracket_right->Text = L"]";
			this->bracket_right->UseVisualStyleBackColor = true;
			this->bracket_right->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// Enter
			// 
			this->Enter->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Enter->Location = System::Drawing::Point(593, 111);
			this->Enter->Name = L"Enter";
			this->Enter->Size = System::Drawing::Size(58, 82);
			this->Enter->TabIndex = 51;
			this->Enter->Text = L"Enter";
			this->Enter->UseVisualStyleBackColor = true;
			this->Enter->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// CapsLock
			// 
			this->CapsLock->BackColor = System::Drawing::SystemColors::ControlDark;
			this->CapsLock->Location = System::Drawing::Point(12, 155);
			this->CapsLock->Name = L"CapsLock";
			this->CapsLock->Size = System::Drawing::Size(72, 38);
			this->CapsLock->TabIndex = 52;
			this->CapsLock->Text = L"Caps Lock";
			this->CapsLock->UseVisualStyleBackColor = true;
			this->CapsLock->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_A
			// 
			this->k_A->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_A->Location = System::Drawing::Point(90, 155);
			this->k_A->Name = L"k_A";
			this->k_A->Size = System::Drawing::Size(37, 38);
			this->k_A->TabIndex = 53;
			this->k_A->Text = L"A";
			this->k_A->UseVisualStyleBackColor = true;
			this->k_A->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_S
			// 
			this->k_S->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_S->Location = System::Drawing::Point(133, 155);
			this->k_S->Name = L"k_S";
			this->k_S->Size = System::Drawing::Size(37, 38);
			this->k_S->TabIndex = 54;
			this->k_S->Text = L"S";
			this->k_S->UseVisualStyleBackColor = true;
			this->k_S->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_D
			// 
			this->k_D->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_D->Location = System::Drawing::Point(176, 155);
			this->k_D->Name = L"k_D";
			this->k_D->Size = System::Drawing::Size(37, 38);
			this->k_D->TabIndex = 55;
			this->k_D->Text = L"D";
			this->k_D->UseVisualStyleBackColor = true;
			this->k_D->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_F
			// 
			this->k_F->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_F->Location = System::Drawing::Point(219, 155);
			this->k_F->Name = L"k_F";
			this->k_F->Size = System::Drawing::Size(37, 38);
			this->k_F->TabIndex = 56;
			this->k_F->Text = L"F";
			this->k_F->UseVisualStyleBackColor = true;
			this->k_F->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_G
			// 
			this->k_G->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_G->Location = System::Drawing::Point(262, 155);
			this->k_G->Name = L"k_G";
			this->k_G->Size = System::Drawing::Size(37, 38);
			this->k_G->TabIndex = 57;
			this->k_G->Text = L"G";
			this->k_G->UseVisualStyleBackColor = true;
			this->k_G->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_H
			// 
			this->k_H->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_H->Location = System::Drawing::Point(305, 155);
			this->k_H->Name = L"k_H";
			this->k_H->Size = System::Drawing::Size(37, 38);
			this->k_H->TabIndex = 58;
			this->k_H->Text = L"H";
			this->k_H->UseVisualStyleBackColor = true;
			this->k_H->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_J
			// 
			this->k_J->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_J->Location = System::Drawing::Point(348, 155);
			this->k_J->Name = L"k_J";
			this->k_J->Size = System::Drawing::Size(37, 38);
			this->k_J->TabIndex = 59;
			this->k_J->Text = L"J";
			this->k_J->UseVisualStyleBackColor = true;
			this->k_J->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_K
			// 
			this->k_K->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_K->Location = System::Drawing::Point(391, 155);
			this->k_K->Name = L"k_K";
			this->k_K->Size = System::Drawing::Size(37, 38);
			this->k_K->TabIndex = 60;
			this->k_K->Text = L"K";
			this->k_K->UseVisualStyleBackColor = true;
			this->k_K->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_L
			// 
			this->k_L->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_L->Location = System::Drawing::Point(434, 155);
			this->k_L->Name = L"k_L";
			this->k_L->Size = System::Drawing::Size(37, 38);
			this->k_L->TabIndex = 61;
			this->k_L->Text = L"L";
			this->k_L->UseVisualStyleBackColor = true;
			this->k_L->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// Colon
			// 
			this->Colon->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Colon->Location = System::Drawing::Point(477, 155);
			this->Colon->Name = L"Colon";
			this->Colon->Size = System::Drawing::Size(37, 38);
			this->Colon->TabIndex = 62;
			this->Colon->Text = L"  :    ;";
			this->Colon->UseVisualStyleBackColor = true;
			this->Colon->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// QuotationMarks
			// 
			this->QuotationMarks->BackColor = System::Drawing::SystemColors::ControlDark;
			this->QuotationMarks->Location = System::Drawing::Point(520, 155);
			this->QuotationMarks->Name = L"QuotationMarks";
			this->QuotationMarks->Size = System::Drawing::Size(37, 38);
			this->QuotationMarks->TabIndex = 63;
			this->QuotationMarks->Text = L"  \"    \'";
			this->QuotationMarks->UseVisualStyleBackColor = true;
			this->QuotationMarks->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// Del
			// 
			this->Del->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Del->Location = System::Drawing::Point(674, 111);
			this->Del->Name = L"Del";
			this->Del->Size = System::Drawing::Size(37, 38);
			this->Del->TabIndex = 64;
			this->Del->Text = L"Del";
			this->Del->UseVisualStyleBackColor = true;
			this->Del->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// End
			// 
			this->End->BackColor = System::Drawing::SystemColors::ControlDark;
			this->End->Location = System::Drawing::Point(717, 111);
			this->End->Name = L"End";
			this->End->Size = System::Drawing::Size(37, 38);
			this->End->TabIndex = 65;
			this->End->Text = L"End";
			this->End->UseVisualStyleBackColor = true;
			this->End->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// PgDwn
			// 
			this->PgDwn->BackColor = System::Drawing::SystemColors::ControlDark;
			this->PgDwn->Location = System::Drawing::Point(760, 111);
			this->PgDwn->Name = L"PgDwn";
			this->PgDwn->Size = System::Drawing::Size(37, 38);
			this->PgDwn->TabIndex = 66;
			this->PgDwn->Text = L"Pg  Dwn";
			this->PgDwn->UseVisualStyleBackColor = true;
			this->PgDwn->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_7
			// 
			this->c_7->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_7->Location = System::Drawing::Point(826, 111);
			this->c_7->Name = L"c_7";
			this->c_7->Size = System::Drawing::Size(37, 38);
			this->c_7->TabIndex = 67;
			this->c_7->Text = L"7";
			this->c_7->UseVisualStyleBackColor = true;
			this->c_7->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_8
			// 
			this->c_8->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_8->Location = System::Drawing::Point(869, 111);
			this->c_8->Name = L"c_8";
			this->c_8->Size = System::Drawing::Size(37, 38);
			this->c_8->TabIndex = 68;
			this->c_8->Text = L"8";
			this->c_8->UseVisualStyleBackColor = true;
			this->c_8->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_9
			// 
			this->c_9->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_9->Location = System::Drawing::Point(912, 111);
			this->c_9->Name = L"c_9";
			this->c_9->Size = System::Drawing::Size(37, 38);
			this->c_9->TabIndex = 69;
			this->c_9->Text = L"9";
			this->c_9->UseVisualStyleBackColor = true;
			this->c_9->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_plus
			// 
			this->c_plus->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_plus->Location = System::Drawing::Point(955, 111);
			this->c_plus->Name = L"c_plus";
			this->c_plus->Size = System::Drawing::Size(37, 82);
			this->c_plus->TabIndex = 70;
			this->c_plus->Text = L"+";
			this->c_plus->UseVisualStyleBackColor = true;
			this->c_plus->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_4
			// 
			this->c_4->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_4->Location = System::Drawing::Point(826, 155);
			this->c_4->Name = L"c_4";
			this->c_4->Size = System::Drawing::Size(37, 38);
			this->c_4->TabIndex = 71;
			this->c_4->Text = L"4";
			this->c_4->UseVisualStyleBackColor = true;
			this->c_4->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_5
			// 
			this->c_5->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_5->Location = System::Drawing::Point(869, 155);
			this->c_5->Name = L"c_5";
			this->c_5->Size = System::Drawing::Size(37, 38);
			this->c_5->TabIndex = 72;
			this->c_5->Text = L"5";
			this->c_5->UseVisualStyleBackColor = true;
			this->c_5->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_6
			// 
			this->c_6->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_6->Location = System::Drawing::Point(912, 155);
			this->c_6->Name = L"c_6";
			this->c_6->Size = System::Drawing::Size(37, 38);
			this->c_6->TabIndex = 73;
			this->c_6->Text = L"6";
			this->c_6->UseVisualStyleBackColor = true;
			this->c_6->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_1
			// 
			this->c_1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_1->Location = System::Drawing::Point(826, 199);
			this->c_1->Name = L"c_1";
			this->c_1->Size = System::Drawing::Size(37, 38);
			this->c_1->TabIndex = 74;
			this->c_1->Text = L"1";
			this->c_1->UseVisualStyleBackColor = true;
			this->c_1->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_2
			// 
			this->c_2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_2->Location = System::Drawing::Point(869, 199);
			this->c_2->Name = L"c_2";
			this->c_2->Size = System::Drawing::Size(37, 38);
			this->c_2->TabIndex = 75;
			this->c_2->Text = L"2";
			this->c_2->UseVisualStyleBackColor = true;
			this->c_2->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_3
			// 
			this->c_3->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_3->Location = System::Drawing::Point(912, 199);
			this->c_3->Name = L"c_3";
			this->c_3->Size = System::Drawing::Size(37, 38);
			this->c_3->TabIndex = 76;
			this->c_3->Text = L"3";
			this->c_3->UseVisualStyleBackColor = true;
			this->c_3->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_enter
			// 
			this->c_enter->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_enter->Location = System::Drawing::Point(955, 199);
			this->c_enter->Name = L"c_enter";
			this->c_enter->Size = System::Drawing::Size(37, 82);
			this->c_enter->TabIndex = 77;
			this->c_enter->Text = L"Ent er";
			this->c_enter->UseVisualStyleBackColor = true;
			this->c_enter->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_0
			// 
			this->c_0->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_0->Location = System::Drawing::Point(826, 243);
			this->c_0->Name = L"c_0";
			this->c_0->Size = System::Drawing::Size(80, 38);
			this->c_0->TabIndex = 78;
			this->c_0->Text = L"0";
			this->c_0->UseVisualStyleBackColor = true;
			this->c_0->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// c_point
			// 
			this->c_point->BackColor = System::Drawing::SystemColors::ControlDark;
			this->c_point->Location = System::Drawing::Point(912, 243);
			this->c_point->Name = L"c_point";
			this->c_point->Size = System::Drawing::Size(37, 38);
			this->c_point->TabIndex = 79;
			this->c_point->Text = L".     del";
			this->c_point->UseVisualStyleBackColor = true;
			this->c_point->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// arrow_right
			// 
			this->arrow_right->BackColor = System::Drawing::SystemColors::ControlDark;
			this->arrow_right->Location = System::Drawing::Point(760, 243);
			this->arrow_right->Name = L"arrow_right";
			this->arrow_right->Size = System::Drawing::Size(37, 38);
			this->arrow_right->TabIndex = 80;
			this->arrow_right->Text = L"->";
			this->arrow_right->UseVisualStyleBackColor = true;
			this->arrow_right->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// arrow_down
			// 
			this->arrow_down->BackColor = System::Drawing::SystemColors::ControlDark;
			this->arrow_down->Location = System::Drawing::Point(717, 243);
			this->arrow_down->Name = L"arrow_down";
			this->arrow_down->Size = System::Drawing::Size(37, 38);
			this->arrow_down->TabIndex = 81;
			this->arrow_down->Text = L"  |    v";
			this->arrow_down->UseVisualStyleBackColor = true;
			this->arrow_down->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// arrow_left
			// 
			this->arrow_left->BackColor = System::Drawing::SystemColors::ControlDark;
			this->arrow_left->Location = System::Drawing::Point(674, 243);
			this->arrow_left->Name = L"arrow_left";
			this->arrow_left->Size = System::Drawing::Size(37, 38);
			this->arrow_left->TabIndex = 82;
			this->arrow_left->Text = L"<-";
			this->arrow_left->UseVisualStyleBackColor = true;
			this->arrow_left->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// arrow_up
			// 
			this->arrow_up->BackColor = System::Drawing::SystemColors::ControlDark;
			this->arrow_up->Location = System::Drawing::Point(717, 199);
			this->arrow_up->Name = L"arrow_up";
			this->arrow_up->Size = System::Drawing::Size(37, 38);
			this->arrow_up->TabIndex = 83;
			this->arrow_up->Text = L"  ^    |";
			this->arrow_up->UseVisualStyleBackColor = true;
			this->arrow_up->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// ShiftL
			// 
			this->ShiftL->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ShiftL->Location = System::Drawing::Point(12, 199);
			this->ShiftL->Name = L"ShiftL";
			this->ShiftL->Size = System::Drawing::Size(80, 38);
			this->ShiftL->TabIndex = 84;
			this->ShiftL->Text = L"Shift L";
			this->ShiftL->UseVisualStyleBackColor = true;
			this->ShiftL->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_Z
			// 
			this->k_Z->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_Z->Location = System::Drawing::Point(98, 199);
			this->k_Z->Name = L"k_Z";
			this->k_Z->Size = System::Drawing::Size(37, 38);
			this->k_Z->TabIndex = 85;
			this->k_Z->Text = L"Z";
			this->k_Z->UseVisualStyleBackColor = true;
			this->k_Z->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_X
			// 
			this->k_X->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_X->Location = System::Drawing::Point(141, 199);
			this->k_X->Name = L"k_X";
			this->k_X->Size = System::Drawing::Size(37, 38);
			this->k_X->TabIndex = 86;
			this->k_X->Text = L"X";
			this->k_X->UseVisualStyleBackColor = true;
			this->k_X->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_C
			// 
			this->k_C->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_C->Location = System::Drawing::Point(184, 199);
			this->k_C->Name = L"k_C";
			this->k_C->Size = System::Drawing::Size(37, 38);
			this->k_C->TabIndex = 87;
			this->k_C->Text = L"C";
			this->k_C->UseVisualStyleBackColor = true;
			this->k_C->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_V
			// 
			this->k_V->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_V->Location = System::Drawing::Point(227, 199);
			this->k_V->Name = L"k_V";
			this->k_V->Size = System::Drawing::Size(37, 38);
			this->k_V->TabIndex = 88;
			this->k_V->Text = L"V";
			this->k_V->UseVisualStyleBackColor = true;
			this->k_V->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_B
			// 
			this->k_B->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_B->Location = System::Drawing::Point(270, 199);
			this->k_B->Name = L"k_B";
			this->k_B->Size = System::Drawing::Size(37, 38);
			this->k_B->TabIndex = 89;
			this->k_B->Text = L"B";
			this->k_B->UseVisualStyleBackColor = true;
			this->k_B->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_N
			// 
			this->k_N->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_N->Location = System::Drawing::Point(313, 199);
			this->k_N->Name = L"k_N";
			this->k_N->Size = System::Drawing::Size(37, 38);
			this->k_N->TabIndex = 90;
			this->k_N->Text = L"N";
			this->k_N->UseVisualStyleBackColor = true;
			this->k_N->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_M
			// 
			this->k_M->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_M->Location = System::Drawing::Point(356, 199);
			this->k_M->Name = L"k_M";
			this->k_M->Size = System::Drawing::Size(37, 38);
			this->k_M->TabIndex = 91;
			this->k_M->Text = L"M";
			this->k_M->UseVisualStyleBackColor = true;
			this->k_M->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_lesser
			// 
			this->k_lesser->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_lesser->Location = System::Drawing::Point(399, 199);
			this->k_lesser->Name = L"k_lesser";
			this->k_lesser->Size = System::Drawing::Size(37, 38);
			this->k_lesser->TabIndex = 92;
			this->k_lesser->Text = L"  <   ,";
			this->k_lesser->UseVisualStyleBackColor = true;
			this->k_lesser->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_greater
			// 
			this->k_greater->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_greater->Location = System::Drawing::Point(442, 199);
			this->k_greater->Name = L"k_greater";
			this->k_greater->Size = System::Drawing::Size(37, 38);
			this->k_greater->TabIndex = 93;
			this->k_greater->Text = L"  >   .";
			this->k_greater->UseVisualStyleBackColor = true;
			this->k_greater->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// QuestionMark
			// 
			this->QuestionMark->BackColor = System::Drawing::SystemColors::ControlDark;
			this->QuestionMark->Location = System::Drawing::Point(485, 199);
			this->QuestionMark->Name = L"QuestionMark";
			this->QuestionMark->Size = System::Drawing::Size(37, 38);
			this->QuestionMark->TabIndex = 94;
			this->QuestionMark->Text = L" \?    /";
			this->QuestionMark->UseVisualStyleBackColor = true;
			this->QuestionMark->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// ShiftR
			// 
			this->ShiftR->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ShiftR->Location = System::Drawing::Point(528, 199);
			this->ShiftR->Name = L"ShiftR";
			this->ShiftR->Size = System::Drawing::Size(123, 38);
			this->ShiftR->TabIndex = 95;
			this->ShiftR->Text = L"Shift R";
			this->ShiftR->UseVisualStyleBackColor = true;
			this->ShiftR->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// CtrlL
			// 
			this->CtrlL->BackColor = System::Drawing::SystemColors::ControlDark;
			this->CtrlL->Location = System::Drawing::Point(12, 243);
			this->CtrlL->Name = L"CtrlL";
			this->CtrlL->Size = System::Drawing::Size(59, 38);
			this->CtrlL->TabIndex = 96;
			this->CtrlL->Text = L"Ctrl L";
			this->CtrlL->UseVisualStyleBackColor = true;
			this->CtrlL->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_WinL
			// 
			this->k_WinL->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_WinL->Location = System::Drawing::Point(77, 243);
			this->k_WinL->Name = L"k_WinL";
			this->k_WinL->Size = System::Drawing::Size(50, 38);
			this->k_WinL->TabIndex = 97;
			this->k_WinL->Text = L"Win";
			this->k_WinL->UseVisualStyleBackColor = true;
			this->k_WinL->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// AltL
			// 
			this->AltL->BackColor = System::Drawing::SystemColors::ControlDark;
			this->AltL->Location = System::Drawing::Point(133, 243);
			this->AltL->Name = L"AltL";
			this->AltL->Size = System::Drawing::Size(50, 38);
			this->AltL->TabIndex = 98;
			this->AltL->Text = L"Alt L";
			this->AltL->UseVisualStyleBackColor = true;
			this->AltL->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// Space
			// 
			this->Space->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Space->Location = System::Drawing::Point(189, 243);
			this->Space->Name = L"Space";
			this->Space->Size = System::Drawing::Size(232, 38);
			this->Space->TabIndex = 99;
			this->Space->Text = L"Space";
			this->Space->UseVisualStyleBackColor = true;
			this->Space->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// AltR
			// 
			this->AltR->BackColor = System::Drawing::SystemColors::ControlDark;
			this->AltR->Location = System::Drawing::Point(427, 243);
			this->AltR->Name = L"AltR";
			this->AltR->Size = System::Drawing::Size(50, 38);
			this->AltR->TabIndex = 100;
			this->AltR->Text = L"Alt R";
			this->AltR->UseVisualStyleBackColor = true;
			this->AltR->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// k_WinR
			// 
			this->k_WinR->BackColor = System::Drawing::SystemColors::ControlDark;
			this->k_WinR->Location = System::Drawing::Point(483, 243);
			this->k_WinR->Name = L"k_WinR";
			this->k_WinR->Size = System::Drawing::Size(50, 38);
			this->k_WinR->TabIndex = 101;
			this->k_WinR->Text = L"Win";
			this->k_WinR->UseVisualStyleBackColor = true;
			this->k_WinR->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// Menu
			// 
			this->Menu->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Menu->Location = System::Drawing::Point(539, 243);
			this->Menu->Name = L"Menu";
			this->Menu->Size = System::Drawing::Size(50, 38);
			this->Menu->TabIndex = 102;
			this->Menu->Text = L"Menu";
			this->Menu->UseVisualStyleBackColor = true;
			this->Menu->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// CtrlR
			// 
			this->CtrlR->BackColor = System::Drawing::SystemColors::ControlDark;
			this->CtrlR->Location = System::Drawing::Point(592, 243);
			this->CtrlR->Name = L"CtrlR";
			this->CtrlR->Size = System::Drawing::Size(59, 38);
			this->CtrlR->TabIndex = 103;
			this->CtrlR->Text = L"Ctrl R";
			this->CtrlR->UseVisualStyleBackColor = true;
			this->CtrlR->Click += gcnew System::EventHandler(this, &MyForm::Keyboard_Click);
			// 
			// checkBoxStart
			// 
			this->checkBoxStart->AutoSize = true;
			this->checkBoxStart->Location = System::Drawing::Point(12, 331);
			this->checkBoxStart->Name = L"checkBoxStart";
			this->checkBoxStart->Size = System::Drawing::Size(115, 17);
			this->checkBoxStart->TabIndex = 104;
			this->checkBoxStart->Text = L"Применить через";
			this->checkBoxStart->UseVisualStyleBackColor = true;
			this->checkBoxStart->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxStart_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->Location = System::Drawing::Point(12, 354);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(894, 20);
			this->textBox1->TabIndex = 105;
			// 
			// ClearButton
			// 
			this->ClearButton->Location = System::Drawing::Point(915, 354);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(75, 23);
			this->ClearButton->TabIndex = 107;
			this->ClearButton->Text = L"Clear";
			this->ClearButton->UseVisualStyleBackColor = true;
			this->ClearButton->Click += gcnew System::EventHandler(this, &MyForm::ClearButton_Click);
			// 
			// radioButtonHold
			// 
			this->radioButtonHold->AutoSize = true;
			this->radioButtonHold->Checked = true;
			this->radioButtonHold->Location = System::Drawing::Point(296, 330);
			this->radioButtonHold->Name = L"radioButtonHold";
			this->radioButtonHold->Size = System::Drawing::Size(244, 17);
			this->radioButtonHold->TabIndex = 108;
			this->radioButtonHold->TabStop = true;
			this->radioButtonHold->Text = L"Нажимать многократно через промежуток";
			this->radioButtonHold->UseVisualStyleBackColor = true;
			this->radioButtonHold->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonHold_CheckedChanged);
			// 
			// textBoxTime1
			// 
			this->textBoxTime1->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxTime1->Location = System::Drawing::Point(538, 330);
			this->textBoxTime1->MaxLength = 5;
			this->textBoxTime1->Name = L"textBoxTime1";
			this->textBoxTime1->Size = System::Drawing::Size(40, 20);
			this->textBoxTime1->TabIndex = 110;
			this->textBoxTime1->Text = L"100";
			this->textBoxTime1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxTime_TextChanged);
			this->textBoxTime1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxTime_KeyPress);
			// 
			// labelTime1
			// 
			this->labelTime1->AutoSize = true;
			this->labelTime1->Location = System::Drawing::Point(580, 332);
			this->labelTime1->Name = L"labelTime1";
			this->labelTime1->Size = System::Drawing::Size(68, 13);
			this->labelTime1->TabIndex = 111;
			this->labelTime1->Text = L"милисекунд";
			// 
			// radioButtonOneClick
			// 
			this->radioButtonOneClick->AutoSize = true;
			this->radioButtonOneClick->Location = System::Drawing::Point(806, 330);
			this->radioButtonOneClick->Name = L"radioButtonOneClick";
			this->radioButtonOneClick->Size = System::Drawing::Size(188, 17);
			this->radioButtonOneClick->TabIndex = 112;
			this->radioButtonOneClick->Text = L"Однократно нажать и отпустить";
			this->radioButtonOneClick->UseVisualStyleBackColor = true;
			// 
			// textBoxTime2
			// 
			this->textBoxTime2->Location = System::Drawing::Point(121, 327);
			this->textBoxTime2->MaxLength = 3;
			this->textBoxTime2->Name = L"textBoxTime2";
			this->textBoxTime2->Size = System::Drawing::Size(40, 20);
			this->textBoxTime2->TabIndex = 113;
			this->textBoxTime2->Text = L"5";
			this->textBoxTime2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxTime_TextChanged);
			this->textBoxTime2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxTime_KeyPress);
			// 
			// labelTime2
			// 
			this->labelTime2->AutoSize = true;
			this->labelTime2->Location = System::Drawing::Point(164, 332);
			this->labelTime2->Name = L"labelTime2";
			this->labelTime2->Size = System::Drawing::Size(42, 13);
			this->labelTime2->TabIndex = 114;
			this->labelTime2->Text = L"секунд";
			// 
			// timer1
			// 
			this->timer1->Interval = 5000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1002, 386);
			this->Controls->Add(this->labelTime2);
			this->Controls->Add(this->textBoxTime2);
			this->Controls->Add(this->radioButtonOneClick);
			this->Controls->Add(this->labelTime1);
			this->Controls->Add(this->textBoxTime1);
			this->Controls->Add(this->radioButtonHold);
			this->Controls->Add(this->ClearButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->checkBoxStart);
			this->Controls->Add(this->CtrlR);
			this->Controls->Add(this->Menu);
			this->Controls->Add(this->k_WinR);
			this->Controls->Add(this->AltR);
			this->Controls->Add(this->Space);
			this->Controls->Add(this->AltL);
			this->Controls->Add(this->k_WinL);
			this->Controls->Add(this->CtrlL);
			this->Controls->Add(this->ShiftR);
			this->Controls->Add(this->QuestionMark);
			this->Controls->Add(this->k_greater);
			this->Controls->Add(this->k_lesser);
			this->Controls->Add(this->k_M);
			this->Controls->Add(this->k_N);
			this->Controls->Add(this->k_B);
			this->Controls->Add(this->k_V);
			this->Controls->Add(this->k_C);
			this->Controls->Add(this->k_X);
			this->Controls->Add(this->k_Z);
			this->Controls->Add(this->ShiftL);
			this->Controls->Add(this->arrow_up);
			this->Controls->Add(this->arrow_left);
			this->Controls->Add(this->arrow_down);
			this->Controls->Add(this->arrow_right);
			this->Controls->Add(this->c_point);
			this->Controls->Add(this->c_0);
			this->Controls->Add(this->c_enter);
			this->Controls->Add(this->c_3);
			this->Controls->Add(this->c_2);
			this->Controls->Add(this->c_1);
			this->Controls->Add(this->c_6);
			this->Controls->Add(this->c_5);
			this->Controls->Add(this->c_4);
			this->Controls->Add(this->c_plus);
			this->Controls->Add(this->c_9);
			this->Controls->Add(this->c_8);
			this->Controls->Add(this->c_7);
			this->Controls->Add(this->PgDwn);
			this->Controls->Add(this->End);
			this->Controls->Add(this->Del);
			this->Controls->Add(this->QuotationMarks);
			this->Controls->Add(this->Colon);
			this->Controls->Add(this->k_L);
			this->Controls->Add(this->k_K);
			this->Controls->Add(this->k_J);
			this->Controls->Add(this->k_H);
			this->Controls->Add(this->k_G);
			this->Controls->Add(this->k_F);
			this->Controls->Add(this->k_D);
			this->Controls->Add(this->k_S);
			this->Controls->Add(this->k_A);
			this->Controls->Add(this->CapsLock);
			this->Controls->Add(this->Enter);
			this->Controls->Add(this->bracket_right);
			this->Controls->Add(this->bracket_left);
			this->Controls->Add(this->k_P);
			this->Controls->Add(this->k_O);
			this->Controls->Add(this->k_I);
			this->Controls->Add(this->k_U);
			this->Controls->Add(this->k_Y);
			this->Controls->Add(this->k_T);
			this->Controls->Add(this->k_R);
			this->Controls->Add(this->k_E);
			this->Controls->Add(this->k_W);
			this->Controls->Add(this->k_Q);
			this->Controls->Add(this->Tab);
			this->Controls->Add(this->c_minus);
			this->Controls->Add(this->c_mult);
			this->Controls->Add(this->c_backslash);
			this->Controls->Add(this->NumLoc);
			this->Controls->Add(this->PgUp);
			this->Controls->Add(this->Home);
			this->Controls->Add(this->Ins);
			this->Controls->Add(this->backspace);
			this->Controls->Add(this->slash);
			this->Controls->Add(this->plus);
			this->Controls->Add(this->minus);
			this->Controls->Add(this->n0);
			this->Controls->Add(this->n9);
			this->Controls->Add(this->n8);
			this->Controls->Add(this->n7);
			this->Controls->Add(this->n6);
			this->Controls->Add(this->n5);
			this->Controls->Add(this->n4);
			this->Controls->Add(this->n3);
			this->Controls->Add(this->n2);
			this->Controls->Add(this->n1);
			this->Controls->Add(this->Tilda);
			this->Controls->Add(this->Pause);
			this->Controls->Add(this->ScrLoc);
			this->Controls->Add(this->PrintScr);
			this->Controls->Add(this->F12);
			this->Controls->Add(this->F11);
			this->Controls->Add(this->F10);
			this->Controls->Add(this->F9);
			this->Controls->Add(this->F8);
			this->Controls->Add(this->F7);
			this->Controls->Add(this->F6);
			this->Controls->Add(this->F5);
			this->Controls->Add(this->F4);
			this->Controls->Add(this->F3);
			this->Controls->Add(this->F2);
			this->Controls->Add(this->F1);
			this->Controls->Add(this->Esc);
			this->MaximumSize = System::Drawing::Size(1018, 425);
			this->MinimumSize = System::Drawing::Size(1018, 425);
			this->Name = L"MyForm";
			this->Text = L"Keyboard Input";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Мои поля-----------------------------------------------------

	private:
		using KeyM = cliext::map <String^, UINT >;
		using KeyObjM = cliext::map <String^, System::Windows::Forms::Button^ >;
		KeyM keys{};
		KeyObjM keys_obj{};
		String^ sequenceStr;
		System::Threading::Thread^ thread;
		volatile bool clamp_flag;
		int interval;
		// 		   -----------------------------------------------------
		// Мои методы---------------------------------------------------
	private:
		void init_key_map()
		{
			keys.insert(KeyM::make_value("Esc", VK_ESCAPE));
			keys.insert(KeyM::make_value("F1", VK_F1));
			keys.insert(KeyM::make_value("F2", VK_F2));
			keys.insert(KeyM::make_value("F3", VK_F3));
			keys.insert(KeyM::make_value("F4", VK_F4));
			keys.insert(KeyM::make_value("F5", VK_F5));
			keys.insert(KeyM::make_value("F6", VK_F6));
			keys.insert(KeyM::make_value("F7", VK_F7));
			keys.insert(KeyM::make_value("F8", VK_F8));
			keys.insert(KeyM::make_value("F9", VK_F9));
			keys.insert(KeyM::make_value("F10", VK_F9));
			keys.insert(KeyM::make_value("F11", VK_F11));
			keys.insert(KeyM::make_value("F12", VK_F12));
			keys.insert(KeyM::make_value("PrintScr", VK_SNAPSHOT));
			keys.insert(KeyM::make_value("ScrLoc", VK_SCROLL));
			keys.insert(KeyM::make_value("Pause", VK_PAUSE));
			keys.insert(KeyM::make_value("Tilda", VK_OEM_3));
			keys.insert(KeyM::make_value("n1", key1_));
			keys.insert(KeyM::make_value("n2", key2_));
			keys.insert(KeyM::make_value("n3", key3_));
			keys.insert(KeyM::make_value("n4", key4_));
			keys.insert(KeyM::make_value("n5", key5_));
			keys.insert(KeyM::make_value("n6", key6_));
			keys.insert(KeyM::make_value("n7", key7_));
			keys.insert(KeyM::make_value("n8", key8_));
			keys.insert(KeyM::make_value("n9", key9_));
			keys.insert(KeyM::make_value("n0", key0_));
			keys.insert(KeyM::make_value("minus", VK_OEM_MINUS));
			keys.insert(KeyM::make_value("plus", VK_OEM_PLUS));
			keys.insert(KeyM::make_value("slash", VK_OEM_5));
			keys.insert(KeyM::make_value("backspace", VK_BACK));
			keys.insert(KeyM::make_value("Ins", VK_INSERT));
			keys.insert(KeyM::make_value("Home", VK_HOME));
			keys.insert(KeyM::make_value("PgUp", VK_PRIOR));
			keys.insert(KeyM::make_value("NumLoc", VK_NUMLOCK));
			keys.insert(KeyM::make_value("c_backslash", VK_NUMLOCK));
			keys.insert(KeyM::make_value("c_mult", VK_MULTIPLY));
			keys.insert(KeyM::make_value("c_minus", VK_SUBTRACT));
			keys.insert(KeyM::make_value("Tab", VK_TAB));
			keys.insert(KeyM::make_value("k_Q", keyQ_));
			keys.insert(KeyM::make_value("k_W", keyW_));
			keys.insert(KeyM::make_value("k_E", keyE_));
			keys.insert(KeyM::make_value("k_R", keyR_));
			keys.insert(KeyM::make_value("k_T", keyT_));
			keys.insert(KeyM::make_value("k_Y", keyY_));
			keys.insert(KeyM::make_value("k_U", keyU_));
			keys.insert(KeyM::make_value("k_I", keyI_));
			keys.insert(KeyM::make_value("k_O", keyO_));
			keys.insert(KeyM::make_value("k_P", keyP_));
			keys.insert(KeyM::make_value("bracket_left", VK_OEM_4));
			keys.insert(KeyM::make_value("bracket_right", VK_OEM_6));
			keys.insert(KeyM::make_value("Enter", VK_RETURN));
			keys.insert(KeyM::make_value("CapsLock", VK_CAPITAL));
			keys.insert(KeyM::make_value("k_A", keyA_));
			keys.insert(KeyM::make_value("k_S", keyS_));
			keys.insert(KeyM::make_value("k_D", keyD_));
			keys.insert(KeyM::make_value("k_F", keyF_));
			keys.insert(KeyM::make_value("k_G", keyG_));
			keys.insert(KeyM::make_value("k_F", keyF_));
			keys.insert(KeyM::make_value("k_H", keyH_));
			keys.insert(KeyM::make_value("k_J", keyJ_));
			keys.insert(KeyM::make_value("k_K", keyK_));
			keys.insert(KeyM::make_value("k_L", keyL_));
			keys.insert(KeyM::make_value("Colon", VK_OEM_1));
			keys.insert(KeyM::make_value("QuotationMarks", VK_OEM_COMMA));
			keys.insert(KeyM::make_value("Del", VK_DELETE));
			keys.insert(KeyM::make_value("End", VK_END));
			keys.insert(KeyM::make_value("PgDwn", VK_NEXT));
			keys.insert(KeyM::make_value("c_7", VK_NUMPAD7));
			keys.insert(KeyM::make_value("c_8", VK_NUMPAD8));
			keys.insert(KeyM::make_value("c_9", VK_NUMPAD9));
			keys.insert(KeyM::make_value("c_plus", VK_ADD));
			keys.insert(KeyM::make_value("c_4", VK_NUMPAD4));
			keys.insert(KeyM::make_value("c_5", VK_NUMPAD5));
			keys.insert(KeyM::make_value("c_6", VK_NUMPAD6));
			keys.insert(KeyM::make_value("c_1", VK_NUMPAD1));
			keys.insert(KeyM::make_value("c_2", VK_NUMPAD2));
			keys.insert(KeyM::make_value("c_3", VK_NUMPAD3));
			keys.insert(KeyM::make_value("c_enter", VK_RETURN));
			keys.insert(KeyM::make_value("c_0", VK_NUMPAD0));
			keys.insert(KeyM::make_value("c_point", VK_DECIMAL));
			keys.insert(KeyM::make_value("arrow_right", VK_RIGHT));
			keys.insert(KeyM::make_value("arrow_down", VK_DOWN));
			keys.insert(KeyM::make_value("arrow_left", VK_LEFT));
			keys.insert(KeyM::make_value("arrow_up", VK_UP));
			keys.insert(KeyM::make_value("ShiftL", VK_LSHIFT));
			keys.insert(KeyM::make_value("k_Z", keyZ_));
			keys.insert(KeyM::make_value("k_X", keyX_));
			keys.insert(KeyM::make_value("k_C", keyC_));
			keys.insert(KeyM::make_value("k_V", keyV_));
			keys.insert(KeyM::make_value("k_B", keyB_));
			keys.insert(KeyM::make_value("k_N", keyN_));
			keys.insert(KeyM::make_value("k_M", keyM_));
			keys.insert(KeyM::make_value("k_lesser", VK_OEM_COMMA));
			keys.insert(KeyM::make_value("k_greater", VK_OEM_PERIOD));
			keys.insert(KeyM::make_value("QuestionMark", VK_OEM_2));
			keys.insert(KeyM::make_value("ShiftR", VK_RSHIFT));
			keys.insert(KeyM::make_value("CtrlL", VK_LCONTROL));
			keys.insert(KeyM::make_value("k_WinL", VK_LWIN));
			keys.insert(KeyM::make_value("AltL", VK_LMENU));
			keys.insert(KeyM::make_value("Space", VK_SPACE));
			keys.insert(KeyM::make_value("AltR", VK_RMENU));
			keys.insert(KeyM::make_value("k_WinR", VK_RWIN));
			keys.insert(KeyM::make_value("Menu", 0));
			keys.insert(KeyM::make_value("CtrlR", VK_RCONTROL));
		}
		void init_key_obj_map()
		{
			keys_obj.insert(KeyObjM::make_value("Esc", Esc));
			keys_obj.insert(KeyObjM::make_value("F1", F1));
			keys_obj.insert(KeyObjM::make_value("F2", F2));
			keys_obj.insert(KeyObjM::make_value("F3", F3));
			keys_obj.insert(KeyObjM::make_value("F4", F4));
			keys_obj.insert(KeyObjM::make_value("F5", F5));
			keys_obj.insert(KeyObjM::make_value("F6", F6));
			keys_obj.insert(KeyObjM::make_value("F7", F7));
			keys_obj.insert(KeyObjM::make_value("F8", F8));
			keys_obj.insert(KeyObjM::make_value("F9", F9));
			keys_obj.insert(KeyObjM::make_value("F10", F9));
			keys_obj.insert(KeyObjM::make_value("F11", F11));
			keys_obj.insert(KeyObjM::make_value("F12", F12));
			keys_obj.insert(KeyObjM::make_value("PrintScr", PrintScr));
			keys_obj.insert(KeyObjM::make_value("ScrLoc", ScrLoc));
			keys_obj.insert(KeyObjM::make_value("Pause", Pause));
			keys_obj.insert(KeyObjM::make_value("Tilda", Tilda));
			keys_obj.insert(KeyObjM::make_value("n1", n1));
			keys_obj.insert(KeyObjM::make_value("n2", n2));
			keys_obj.insert(KeyObjM::make_value("n3", n3));
			keys_obj.insert(KeyObjM::make_value("n4", n4));
			keys_obj.insert(KeyObjM::make_value("n5", n5));
			keys_obj.insert(KeyObjM::make_value("n6", n6));
			keys_obj.insert(KeyObjM::make_value("n7", n7));
			keys_obj.insert(KeyObjM::make_value("n8", n8));
			keys_obj.insert(KeyObjM::make_value("n9", n9));
			keys_obj.insert(KeyObjM::make_value("n0", n0));
			keys_obj.insert(KeyObjM::make_value("minus", minus));
			keys_obj.insert(KeyObjM::make_value("plus", plus));
			keys_obj.insert(KeyObjM::make_value("slash", slash));
			keys_obj.insert(KeyObjM::make_value("backspace", backspace));
			keys_obj.insert(KeyObjM::make_value("Ins", Ins));
			keys_obj.insert(KeyObjM::make_value("Home", Home));
			keys_obj.insert(KeyObjM::make_value("PgUp", PgUp));
			keys_obj.insert(KeyObjM::make_value("NumLoc", NumLoc));
			keys_obj.insert(KeyObjM::make_value("c_backslash", c_backslash));
			keys_obj.insert(KeyObjM::make_value("c_mult", c_mult));
			keys_obj.insert(KeyObjM::make_value("c_minus", c_minus));
			keys_obj.insert(KeyObjM::make_value("Tab", Tab));
			keys_obj.insert(KeyObjM::make_value("k_Q", k_Q));
			keys_obj.insert(KeyObjM::make_value("k_W", k_W));
			keys_obj.insert(KeyObjM::make_value("k_E", k_E));
			keys_obj.insert(KeyObjM::make_value("k_R", k_R));
			keys_obj.insert(KeyObjM::make_value("k_T", k_T));
			keys_obj.insert(KeyObjM::make_value("k_Y", k_Y));
			keys_obj.insert(KeyObjM::make_value("k_U", k_U));
			keys_obj.insert(KeyObjM::make_value("k_I", k_I));
			keys_obj.insert(KeyObjM::make_value("k_O", k_O));
			keys_obj.insert(KeyObjM::make_value("k_P", k_P));
			keys_obj.insert(KeyObjM::make_value("bracket_left", bracket_left));
			keys_obj.insert(KeyObjM::make_value("bracket_right", bracket_right));
			keys_obj.insert(KeyObjM::make_value("Enter", Enter));
			keys_obj.insert(KeyObjM::make_value("CapsLock", CapsLock));
			keys_obj.insert(KeyObjM::make_value("k_A", k_A));
			keys_obj.insert(KeyObjM::make_value("k_S", k_S));
			keys_obj.insert(KeyObjM::make_value("k_D", k_D));
			keys_obj.insert(KeyObjM::make_value("k_F", k_F));
			keys_obj.insert(KeyObjM::make_value("k_G", k_G));
			keys_obj.insert(KeyObjM::make_value("k_F", k_F));
			keys_obj.insert(KeyObjM::make_value("k_H", k_H));
			keys_obj.insert(KeyObjM::make_value("k_J", k_J));
			keys_obj.insert(KeyObjM::make_value("k_K", k_K));
			keys_obj.insert(KeyObjM::make_value("k_L", k_L));
			keys_obj.insert(KeyObjM::make_value("Colon", Colon));
			keys_obj.insert(KeyObjM::make_value("QuotationMarks", QuotationMarks));
			keys_obj.insert(KeyObjM::make_value("Del", Del));
			keys_obj.insert(KeyObjM::make_value("End", End));
			keys_obj.insert(KeyObjM::make_value("PgDwn", PgDwn));
			keys_obj.insert(KeyObjM::make_value("c_7", c_7));
			keys_obj.insert(KeyObjM::make_value("c_8", c_8));
			keys_obj.insert(KeyObjM::make_value("c_9", c_9));
			keys_obj.insert(KeyObjM::make_value("c_plus", c_plus));
			keys_obj.insert(KeyObjM::make_value("c_4", c_4));
			keys_obj.insert(KeyObjM::make_value("c_5", c_5));
			keys_obj.insert(KeyObjM::make_value("c_6", c_6));
			keys_obj.insert(KeyObjM::make_value("c_1", c_1));
			keys_obj.insert(KeyObjM::make_value("c_2", c_2));
			keys_obj.insert(KeyObjM::make_value("c_3", c_3));
			keys_obj.insert(KeyObjM::make_value("c_enter", c_enter));
			keys_obj.insert(KeyObjM::make_value("c_0", c_0));
			keys_obj.insert(KeyObjM::make_value("c_point", c_point));
			keys_obj.insert(KeyObjM::make_value("arrow_right", arrow_right));
			keys_obj.insert(KeyObjM::make_value("arrow_down", arrow_down));
			keys_obj.insert(KeyObjM::make_value("arrow_left", arrow_left));
			keys_obj.insert(KeyObjM::make_value("arrow_up", arrow_up));
			keys_obj.insert(KeyObjM::make_value("ShiftL", ShiftL));
			keys_obj.insert(KeyObjM::make_value("k_Z", k_Z));
			keys_obj.insert(KeyObjM::make_value("k_X", k_X));
			keys_obj.insert(KeyObjM::make_value("k_C", k_C));
			keys_obj.insert(KeyObjM::make_value("k_V", k_V));
			keys_obj.insert(KeyObjM::make_value("k_B", k_B));
			keys_obj.insert(KeyObjM::make_value("k_N", k_N));
			keys_obj.insert(KeyObjM::make_value("k_M", k_M));
			keys_obj.insert(KeyObjM::make_value("k_lesser", k_lesser));
			keys_obj.insert(KeyObjM::make_value("k_greater", k_greater));
			keys_obj.insert(KeyObjM::make_value("QuestionMark", QuestionMark));
			keys_obj.insert(KeyObjM::make_value("ShiftR", ShiftR));
			keys_obj.insert(KeyObjM::make_value("CtrlL", CtrlL));
			keys_obj.insert(KeyObjM::make_value("k_WinL", k_WinL));
			keys_obj.insert(KeyObjM::make_value("AltL", AltL));
			keys_obj.insert(KeyObjM::make_value("Space", Space));
			keys_obj.insert(KeyObjM::make_value("AltR", AltR));
			keys_obj.insert(KeyObjM::make_value("k_WinR", k_WinR));
			keys_obj.insert(KeyObjM::make_value("Menu", Menu));
			keys_obj.insert(KeyObjM::make_value("CtrlR", CtrlR));
		}
			void OptionInputEnableStateChange()
		{
			radioButtonHold->Enabled -= 1;
			radioButtonOneClick->Enabled -= 1;
			textBoxTime1->ReadOnly -= 1;
			textBoxTime2->ReadOnly -= 1;
			ClearButton->Enabled -= 1;
		}
		UINT GetMaxInputs(String^ str)
		{
			if (str == "") return 0;
			int pos{}, res{}, count{};
			while (res != -1) {
				res = str->IndexOf("+", pos);
				++count;
				pos = res + 1;
			}
			res = pos = 0;
			while (res != -1) {
				res = str->IndexOf(",", pos);
				++count;
				pos = res + 1;
			}
			return count - 1;
		}
		void FillInput(std::vector <INPUT>& v, std::vector <UINT>& k, String^ str, bool k_press)
		{
			int count{};
			for (auto& elem : v)
			{
				elem.type = INPUT_KEYBOARD;
				elem.ki.wVk = k[count++];
				elem.ki.dwFlags = KEYEVENTF_KEYUP * (!k_press) | 0;
				elem.ki.dwExtraInfo = 0;
			}
		}
		void FillKeys(std::vector <UINT>& v, String^ str)
		{
			int count{};
			String^ tmp(str); tmp = tmp->Replace(',', '+');
			auto str_array = tmp->Split('+');
			for (auto& elem : v)
			{
				elem = keys[str_array[count++]->Replace(" ", "")];
			}
		}
		void PressKeysInThread()
		{
			bool tmp_flag= clamp_flag;
			do
			{
				SendInput(input.size(), &input[0], sizeof(INPUT));
				Sleep(interval);
			} while (clamp_flag);
			FillInput(input, v_keys, sequenceStr, false);
			SendInput(input.size(), &input[0], sizeof(INPUT));
			clamp_flag = tmp_flag;
		}
		// 		   -----------------------------------------------------

	private: System::Void checkBoxStart_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		OptionInputEnableStateChange();
		if (!checkBoxStart->Checked) { return; }
		if (textBox1->Text == "") { checkBoxStart->Checked = false; return; }
		UINT maxinputs = GetMaxInputs(textBox1->Text);
		sequenceStr = textBox1->Text;
		input.resize(maxinputs);
		v_keys.resize(maxinputs);
		FillKeys(v_keys, sequenceStr);
		FillInput(input, v_keys, sequenceStr, true);
		checkBoxStart->Enabled = false;
		timer1->Enabled = true;
	}
	private: System::Void Keyboard_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ k_name = Convert::ToString(static_cast<System::Windows::Forms::Button^>(sender)->Name);
		UINT k_code = keys[k_name];
		System::Windows::Forms::Button^ k_obj = keys_obj[k_name];
		k_obj->UseVisualStyleBackColor = false;
		if (textBox1->Text != "") textBox1->Text += "+";
		textBox1->Text += k_name;
		
	}

	private: System::Void ClearButton_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "";
		for each (auto elem in keys_obj)
		{
			elem->second->UseVisualStyleBackColor = true;
		}
		if (ClearButton->Text == "Stop") 
		{	
			clamp_flag=false; 
			checkBoxStart->Enabled = true;
			checkBoxStart->Checked = false;
			ClearButton->Text = "Clear";
			ClearButton->Enabled = true;
		}

	}
	private: System::Void textBoxTime_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char number = e->KeyChar;
		if (!Char::IsDigit(number) && number != 8 && number != 13)
		{
			e->Handled = true;
		}
	}

	private: System::Void textBoxTime_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::TextBox^ tbTime = static_cast<System::Windows::Forms::TextBox^>(sender);
		if (tbTime->Text == ""|| tbTime->Text == "0") tbTime->Text = "1";
		int time = Convert::ToInt16(textBoxTime2->Text);
		if (!time) timer1->Interval = 1;
			else timer1->Interval = time * 1000;
		interval = Convert::ToInt16(textBoxTime1->Text);
	}
	private: System::Void radioButtonHold_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		clamp_flag = radioButtonHold->Checked;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
		if (clamp_flag) { ClearButton->Text = "Stop"; ClearButton->Enabled = true; }
		else {
			checkBoxStart->Enabled = true;
			checkBoxStart->Checked = false;
		}
		thread= gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyForm::PressKeysInThread));
		thread->Start();
	}
	};
}

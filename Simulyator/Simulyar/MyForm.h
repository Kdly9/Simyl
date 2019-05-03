#pragma once
#include <math.h>
#include <iostream>                                    
#include <fstream>
#include <string>
#include <iostream>
#include <string>
#include <memory.h>
#include <string.h>
#include <WS2tcpip.h>
#include <cstdlib>
#include <ctime>
#include <cmath> 
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <dos.h> 
#include <windows.h>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <msclr/marshal.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include "structures.h" 
#include "Parser.h" 

#pragma comment(lib, "ws2_32.lib")




using namespace System::IO;
using namespace msclr::interop;
double fazi[4], sfi[4], sfu[4], AU[4], Ai[4];
DATA_SEGMENT dat;
SOCKET sock;
float timeF=0, fr;
int  i = 0;
std::string fili("Data_simulator.ini");
boost::property_tree::ptree bar;
std::string Temp;

namespace Simulyar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	// Объявляем переменные
	 int counter = 0;
	
	std::string ipAddress = "";
	int port;
	 // Объявляем переменные
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//TODO: добавьте код конструктора
			//
			try
			{
				boost::property_tree::ini_parser::read_ini(fili, bar);

				Temp = bar.get<std::string>("a.samfrequency");
				String^ managed = msclr::interop::marshal_as<String^>(Temp);
				textBox1->Text = managed;
				Temp = bar.get<std::string>("a.frequencydSignal");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox20->Text = managed;
				Temp = bar.get<std::string>("a.ip");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox10->Text = managed;
				Temp = bar.get<std::string>("a.port");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox11->Text = managed;
				Temp = bar.get<std::string>("DATA.phase shiftUA");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox2->Text = managed;
				Temp = bar.get<std::string>("DATA.phase shift UB");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox3->Text = managed;
				Temp = bar.get<std::string>("DATA.phase shift UC");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox4->Text = managed;
				Temp = bar.get<std::string>("DATA.phase shift U0");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox5->Text = managed;
				Temp = bar.get<std::string>("DATA.phase shift IA");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox6->Text = managed;
				Temp = bar.get<std::string>("DATA.phase shift IB");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox7->Text = managed;
				Temp = bar.get<std::string>("DATA.phase shift IC");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox8->Text = managed;
				Temp = bar.get<std::string>("DATA.phase shift I0");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox9->Text = managed;
				Temp = bar.get<std::string>("DATA.Amplitude UA");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox19->Text = managed;
				Temp = bar.get<std::string>("DATA.Amplitude UB");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox18->Text = managed;
				Temp = bar.get<std::string>("DATA.Amplitude UC");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox17->Text = managed;
				Temp = bar.get<std::string>("DATA.Amplitude U0");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox16->Text = managed;
				Temp = bar.get<std::string>("DATA.Amplitude IA");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox15->Text = managed;
				Temp = bar.get<std::string>("DATA.Amplitude IB");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox14->Text = managed;
				Temp = bar.get<std::string>("DATA.Amplitude IC");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox13->Text = managed;
				Temp = bar.get<std::string>("DATA.Amplitude I0");
				managed = msclr::interop::marshal_as<String^>(Temp);
				textBox12->Text = managed;
			}
			catch (std::exception &ex)
			{
				// you either print it out or have a MessageBox pop up or hide it.
				// std::cerr << ex.what() << std::endl;
				Temp = ex.what();
				String^ Err = msclr::interop::marshal_as<String^>(Temp);
				MessageBox::Show(Err);
			}
			
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

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  timer1;


	private: System::Windows::Forms::Label^  label14;



	private: System::ComponentModel::IContainer^  components;







	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(172, 282);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Отправить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(116, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(70, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"f дискретизации (Гц)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 131);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"A";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 163);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"B";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 192);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(14, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"C";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 222);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(264, 102);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Ф(U) Град";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(46, 102);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(68, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"A ( I ) Ампер";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(120, 102);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"A (U) Вольт";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(267, 128);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(55, 20);
			this->textBox2->TabIndex = 11;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(267, 160);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(55, 20);
			this->textBox3->TabIndex = 12;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(267, 189);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(55, 20);
			this->textBox4->TabIndex = 13;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(267, 219);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(55, 20);
			this->textBox5->TabIndex = 14;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(192, 128);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(55, 20);
			this->textBox6->TabIndex = 15;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(193, 160);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(55, 20);
			this->textBox7->TabIndex = 16;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(193, 189);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(55, 20);
			this->textBox8->TabIndex = 17;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(193, 219);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(55, 20);
			this->textBox9->TabIndex = 18;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(192, 102);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(60, 13);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Ф( I ) Град";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(242, 12);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 20);
			this->textBox10->TabIndex = 20;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(209, 15);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(17, 13);
			this->label10->TabIndex = 21;
			this->label10->Text = L"IP";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(242, 45);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 20);
			this->textBox11->TabIndex = 22;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(209, 48);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 13);
			this->label11->TabIndex = 23;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(-1, 115);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 13);
			this->label12->TabIndex = 24;
			this->label12->Click += gcnew System::EventHandler(this, &MyForm::label12_Click);
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(46, 219);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(55, 20);
			this->textBox12->TabIndex = 32;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(46, 189);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(55, 20);
			this->textBox13->TabIndex = 31;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(46, 160);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(55, 20);
			this->textBox14->TabIndex = 30;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(45, 128);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(55, 20);
			this->textBox15->TabIndex = 29;
			this->textBox15->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox15_TextChanged);
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(120, 219);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(55, 20);
			this->textBox16->TabIndex = 28;
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(120, 189);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(55, 20);
			this->textBox17->TabIndex = 27;
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(120, 160);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(55, 20);
			this->textBox18->TabIndex = 26;
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(120, 128);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(55, 20);
			this->textBox19->TabIndex = 25;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(13, 49);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(75, 13);
			this->label13->TabIndex = 33;
			this->label13->Text = L"f сигнала (Гц)\r\n";
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(116, 49);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(70, 20);
			this->textBox20->TabIndex = 34;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(267, 282);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 35;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_2);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(204, 49);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(37, 13);
			this->label14->TabIndex = 39;
			this->label14->Text = L"PORT";
			this->label14->Click += gcnew System::EventHandler(this, &MyForm::label14_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(350, 317);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox20);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->textBox16);
			this->Controls->Add(this->textBox17);
			this->Controls->Add(this->textBox18);
			this->Controls->Add(this->textBox19);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Симулятор";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		

	



#pragma endregion
	
	void MarshalString(String ^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

	

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		
		button1->Text = "Отправить";
		
		std::string s;
		DATA_HEAD hew;
		Single t, t1;
		
		label9->ForeColor = Color::Black;
		label3->ForeColor = Color::Black;
		label6->ForeColor = Color::Black;
		label2->ForeColor = Color::Black;
		label4->ForeColor = Color::Black;
		label5->ForeColor = Color::Black;
		label1->ForeColor = Color::Black;
		label13->ForeColor = Color::Black;
		label14->ForeColor = Color::Black;
		label10->ForeColor = Color::Black;
		label7->ForeColor = Color::Black;
		label8->ForeColor = Color::Black;
		textBox1->ForeColor = Color::Black;
		textBox2->ForeColor = Color::Black;
		textBox3->ForeColor = Color::Black;
		textBox4->ForeColor = Color::Black;
		textBox5->ForeColor = Color::Black;
		textBox6->ForeColor = Color::Black;
		textBox7->ForeColor = Color::Black;
		textBox8->ForeColor = Color::Black;
		textBox9->ForeColor = Color::Black;
		textBox10->ForeColor = Color::Black;
		textBox11->ForeColor = Color::Black;
		textBox12->ForeColor = Color::Black;
		textBox13->ForeColor = Color::Black;
		textBox14->ForeColor = Color::Black;
		textBox15->ForeColor = Color::Black;
		textBox16->ForeColor = Color::Black;
		textBox17->ForeColor = Color::Black;
		textBox18->ForeColor = Color::Black;
		textBox19->ForeColor = Color::Black;
		textBox20->ForeColor = Color::Black;
		
		  

		  
//--------защита от дурака - проверка вводимой переменной
		bool X = Single::TryParse(textBox1->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, t1);
		label1->ForeColor = Color::Black;
		if (X == false)
		{
			label1->ForeColor = Color::Red;
			textBox1->ForeColor = Color::Red;
			MessageBox::Show("f дискретизации не является числом " + " ( " + textBox1->Text + " )", "Ошибка");
			
			return;
		}
		
	
		::fr = t1;
		bool X1 = Double::TryParse(textBox2->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::sfu[0]);
		
		if (X1 == false)
		{
			label6->ForeColor = Color::Red;
			label2->ForeColor = Color::Red;
			textBox2->ForeColor = Color::Red;
			MessageBox::Show("В строке А Ф(U) Град не является числом " + " ( " + textBox2->Text + " )", "Ошибка");
			
			return;
		}
		bool X2 = Double::TryParse(textBox3->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::sfu[1]);
		
		if (X2 == false)
		{
			textBox3->ForeColor = Color::Red;
			label6->ForeColor = Color::Red;
			label3->ForeColor = Color::Red;
			MessageBox::Show("В строке В Ф(U) Град не является числом  " + " ( " + textBox3->Text + " )", "Ошибка");
			return;
		}
		bool X3 = Double::TryParse(textBox4->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::sfu[2]);
		
		if (X3 == false)
		{
			textBox4->ForeColor = Color::Red;
			label6->ForeColor = Color::Red;
			label4->ForeColor = Color::Red;
			MessageBox::Show("В строке С Ф(U) Град не является числом " + " ( " + textBox4->Text + " )", "Ошибка");
			return;
		}
		bool X4 = Double::TryParse(textBox5->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::sfu[3]);
		
		if (X4 == false)
		{
			textBox5->ForeColor = Color::Red;
			label6->ForeColor = Color::Red;
			label5->ForeColor = Color::Red;
			MessageBox::Show("В строке 0 Ф(U) Град не является числом  " + " ( " + textBox5->Text + " )", "Ошибка");
			return;
		}
		bool X5 = Double::TryParse(textBox6->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::sfi[0]);
		
		if (X5 == false)
		{
			textBox6->ForeColor = Color::Red;
			label9->ForeColor = Color::Red;
			label2->ForeColor = Color::Red;
			MessageBox::Show("В строке А Ф(I) Град не является числом  " + " ( " + textBox6->Text + " )", "Ошибка");
			return;
		}
		bool X6 = Double::TryParse(textBox7->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::sfi[1]);
		
		if (X6 == false)
		{
			textBox7->ForeColor = Color::Red;
			label9->ForeColor = Color::Red;
			label3->ForeColor = Color::Red;
			MessageBox::Show("В строке B Ф(I) Град не является числом " + " ( " + textBox7->Text + " )", "Ошибка");
			return;
		}
		bool X7 = Double::TryParse(textBox8->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::sfi[2]);
		
		if (X7 == false)
		{
			textBox8->ForeColor = Color::Red;
			label9->ForeColor = Color::Red;
			label4->ForeColor = Color::Red;
			MessageBox::Show("В строке C Ф(I) Град не является числом " + " ( " + textBox8->Text + " )", "Ошибка");
			return;
		}
		bool X8 = Double::TryParse(textBox9->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::sfi[3]);
		
		if (X8 == false)
		{
			textBox9->ForeColor = Color::Red;
			label9->ForeColor = Color::Red;
			label5->ForeColor = Color::Red;
			MessageBox::Show("В строке 0 Ф(I) Град не является числом " + " ( " + textBox9->Text + " )", "Ошибка");
			return;
		}
		bool X9 = Double::TryParse(textBox19->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::AU[0]);
		if (X9 == false)
		{
			textBox19->ForeColor = Color::Red;
			label8->ForeColor = Color::Red;
			label2->ForeColor = Color::Red;
			MessageBox::Show("В строке А A(I) Ампер не является числом " + " ( " + textBox19->Text + " )", "Ошибка");
			return;
		}
		bool X10 = Double::TryParse(textBox18->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::AU[1]);
		if (X10 == false)
		{
			textBox18->ForeColor = Color::Red;
			label8->ForeColor = Color::Red;
			label3->ForeColor = Color::Red;
			MessageBox::Show("В строке B A(I) Ампер не является числом " + " ( " + textBox18->Text + " )", "Ошибка");
			return;
		}
		bool X11 = Double::TryParse(textBox17->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::AU[2]);
		if (X11 == false)
		{
			textBox17->ForeColor = Color::Red;
			label8->ForeColor = Color::Red;
			label4->ForeColor = Color::Red;
			MessageBox::Show("В строке С A(I) Ампер не является числом " + " ( " + textBox17->Text + " )", "Ошибка");
			return;
		}
		
		bool X12 = Double::TryParse(textBox16->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::AU[3]);
		if (X12 == false)
		{
			textBox16->ForeColor = Color::Red;
			label8->ForeColor = Color::Red;
			label5->ForeColor = Color::Red;
			MessageBox::Show("В строке 0 A(I) Ампер не является числом " + " ( " + textBox16->Text + " )", "Ошибка");
			return;
		}

		bool X13 = Double::TryParse(textBox15->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::Ai[0]);
		if (X13 == false)
		{
			textBox15->ForeColor = Color::Red;
			label7->ForeColor = Color::Red;
			label2->ForeColor = Color::Red;
			MessageBox::Show("В строке А A(U) Вольт не является числом " + " ( " + textBox15->Text + " )", "Ошибка");
			return;
		}
		bool X14 = Double::TryParse(textBox14->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::Ai[1]);
		if (X14 == false)
		{
			textBox14->ForeColor = Color::Red;
			label7->ForeColor = Color::Red;
			label3->ForeColor = Color::Red;
			MessageBox::Show("В строке B A(U) Вольт не является числом " + " ( " + textBox14->Text + " )", "Ошибка");
			return;
		}
		bool X15 = Double::TryParse(textBox13->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::Ai[2]);
		if (X15 == false)
		{
			textBox13->ForeColor = Color::Red;
			label7->ForeColor = Color::Red;
			label4->ForeColor = Color::Red;
			MessageBox::Show("В строке С A(U) Вольт не является числом " + " ( " + textBox13->Text + " )", "Ошибка");
			return;
		}
		bool X16 = Double::TryParse(textBox12->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::Ai[3]);
		if (X16 == false)
		{
			textBox12->ForeColor = Color::Red;
			label7->ForeColor = Color::Red;
			label5->ForeColor = Color::Red;
			MessageBox::Show("В строке 0 A(U) Вольт не является числом " + " ( " + textBox12->Text + " )", "Ошибка");
			return;
		}
		bool X17 = Double::TryParse(textBox20->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, ::fazi[0]);
		if (X17 == false)
		{
			textBox20->ForeColor = Color::Red;
			label13->ForeColor = Color::Red;
			MessageBox::Show("f сигнала (Гц) не является числом " + " ( " + textBox20->Text + " )", "Ошибка");
			return;
		}
		if ((fazi[0] < 48.0)|| (fazi[0] > 52)) {
			textBox20->ForeColor = Color::Red;
			label13->ForeColor = Color::Red;
			MessageBox::Show("Частота сигнала от 48 до 52 Гц", "Ошибка");
			return;
		}
	
		using boost::property_tree::ptree;
		
		ptree pt;
		pt.put("a.samfrequency", t1);
		// Overwrites the value
		pt.put("DATA.phase shiftUA", ::sfu[0]);
		// Adds a second node with the new value.
		pt.put("DATA.phase shift UB", ::sfu[1]);
		pt.put("DATA.phase shift UC", ::sfu[2]);
		pt.put("DATA.phase shift U0", ::sfu[3]);
		pt.put("DATA.phase shift IA", ::sfi[0]);
		pt.put("DATA.phase shift IB", ::sfi[1]);
		pt.put("DATA.phase shift IC", ::sfi[2]);
		pt.put("DATA.phase shift I0", ::sfi[3]);
		pt.put("DATA.Amplitude UA", ::AU[0]);
		pt.put("DATA.Amplitude UB", ::AU[1]);
		pt.put("DATA.Amplitude UC", ::AU[2]);
		pt.put("DATA.Amplitude U0", ::AU[3]);
		pt.put("DATA.Amplitude IA", ::Ai[0]);
		pt.put("DATA.Amplitude IB", ::Ai[1]);
		pt.put("DATA.Amplitude IC", ::Ai[2]);
		pt.put("DATA.Amplitude I0", ::Ai[3]);
		pt.put("a.frequencydSignal", ::fazi[0]);
		write_ini(fili, pt);
	

	
		
		String^ s1 = textBox10->Text;
		
		MarshalString(s1, ipAddress);

		bool X171=int::TryParse(textBox11->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, port);
		if (X171 == false)
		{
			textBox11->ForeColor = Color::Red;
			label14->ForeColor = Color::Red;
			MessageBox::Show("PORT не является числом " + " ( " + textBox11->Text + " )", "Ошибка");
			return;
		}
		pt.put("a.ip", ipAddress);
		pt.put("a.port", port);
		write_ini(fili, pt);
		// Initialize WinSock
		WSAData data;
		WORD ver = MAKEWORD(2, 2);
		int wsResult = WSAStartup(ver, &data);
		if (wsResult != 0)
		{
			MessageBox::Show("Can't start Winsock, Err #" + wsResult, "Ошибка");
			return;
		}
		 ::sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock == INVALID_SOCKET)
		{
			MessageBox::Show("Can't create socket, Err #"+ WSAGetLastError(), "Ошибка");
			WSACleanup();
			return;
		}
		// Fill in a hint structure
		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(port);
		inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);
		// Connect to server
		int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
		if (connResult == SOCKET_ERROR)
		{
			MessageBox::Show("Can't connect to server, Err #" + WSAGetLastError(), "Ошибка");
			closesocket(sock);
			WSACleanup();
			return;
		}
		hew.key[0] = 'a';
		hew.key[1] = '1';
		hew.key[2] = 'b';
		hew.key[3] = '2';
		hew.key[4] = 'c';
		hew.key[5] = '3';
		hew.key[6] = '\0';
		hew.version = 35781; 
		hew.amountChannel = 8;
		hew.amountElements = 4096;
		bool X110 = Single::TryParse(textBox1->Text,
			System::Globalization::NumberStyles::Number,
			System::Globalization::NumberFormatInfo::CurrentInfo, t1);
		if (X110 == false)
		{
			label11->Text = "Вводите числа";
			label11->ForeColor = Color::Red;
			return;
		}
		hew.frequency = t1;

		char *pChar;
		int sendResult = send(sock, (const char*)&hew, sizeof(hew), 0);
		if (sendResult == SOCKET_ERROR)
		{
				MessageBox::Show("Can't send to server, Err #", "Ошибка");

		}

		::dat.timeMark = 0;
		::dat.id = 0;
		
		this->timer1->Start();

	}
	
	private: System::Void button2_Click_2(System::Object^  sender, System::EventArgs^  e) {

		this->timer1->Stop();
		closesocket(::sock);
		WSACleanup();
	}
			 


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
		
	}
	private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox15_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}
public: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {


}
private: System::Void textBox11_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

public:

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	
		while (::i < 4096) {

			::dat.arr[0][i] = ::Ai[0] * sin(2 * PI * ::fazi[0] * ::timeF + ::sfi[0]);
			::dat.arr[1][i] = ::AU[0] * sin(2 * PI * ::fazi[0] * ::timeF + ::sfu[0]);
			::dat.arr[2][i] = ::Ai[1] * sin(2 * PI * ::fazi[0] * ::timeF + ::sfi[1]);
			::dat.arr[3][i] = ::AU[1] * sin(2 * PI * ::fazi[0] * ::timeF + ::sfu[1]);
			::dat.arr[4][i] = ::Ai[2] * sin(2 * PI * ::fazi[0] * ::timeF + ::sfi[2]);
			::dat.arr[5][i] = ::AU[2] * sin(2 * PI * ::fazi[0] * ::timeF + ::sfu[2]);
			::dat.arr[6][i] = ::Ai[3] * sin(2 * PI * ::fazi[0] * ::timeF + ::sfi[3]);
			::dat.arr[7][i] = ::AU[3] * sin(2 * PI * ::fazi[0] * ::timeF + ::sfu[3]);
			::timeF += (1 / ::fr);
			::i++;
		//	::dat.timeMark = ::timeF;
	
			
		}
		::dat.timeMark += ::timeF*1000000;
		::dat.id++;
		::i = 0;
		int sendRe = send(sock, (char*)&dat, sizeof(DATA_SEGMENT), 0);
			if (sendRe == SOCKET_ERROR)
				{
				
					
			}
		System::Threading::Tasks::Task::Delay(500);


}
private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {
	
	
}
		 
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	

	
}
	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		
}
private: System::Void label14_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}



		


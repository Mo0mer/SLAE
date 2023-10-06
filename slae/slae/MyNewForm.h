#pragma once

namespace slae {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyNewForm
	/// </summary>
	public ref class MyNewForm : public System::Windows::Forms::Form
	{
	public:
		MyNewForm(void)
		{
			InitializeComponent();
			dataGridView1->RowCount = 2;
			dataGridView1->ColumnCount = 2;

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyNewForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
		   System::Windows::Forms::Button^ createdButton;
		   System::Windows::Forms::Button^ createdButton1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button3;


		   bool corr_input = true;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button12;


		   //bool corr_input = false;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(-2, -5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(834, 76);
			this->panel1->TabIndex = 0;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button6->Location = System::Drawing::Point(682, 15);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(104, 42);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Якоби";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyNewForm::button6_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)), static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button5->Location = System::Drawing::Point(572, 15);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(104, 42);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Матричный";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyNewForm::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(107)));
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)), static_cast<System::Int32>(static_cast<System::Byte>(107)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button4->Location = System::Drawing::Point(462, 15);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(104, 42);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Гаус";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyNewForm::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(62)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button3->Location = System::Drawing::Point(352, 15);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(104, 42);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Крамер";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyNewForm::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(186)));
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(186)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->Location = System::Drawing::Point(137, 15);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 42);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Ввод";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyNewForm::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->Location = System::Drawing::Point(12, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 42);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Файл";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyNewForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn7,
					this->dataGridViewTextBoxColumn8
			});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(12, 87);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(434, 235);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->Visible = false;
			this->dataGridView1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyNewForm::dataGridView1_KeyDown);
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(472, 341);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(71, 17);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Успешно";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyNewForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(472, 364);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(81, 17);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Провально";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyNewForm::radioButton2_CheckedChanged);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Column2";
			this->Column2->Name = L"Column2";
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(195)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button7->Location = System::Drawing::Point(12, 341);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(104, 42);
			this->button7->TabIndex = 7;
			this->button7->Text = L" + строка";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyNewForm::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button8->Location = System::Drawing::Point(232, 341);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(104, 42);
			this->button8->TabIndex = 7;
			this->button8->Text = L"+ столбец";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyNewForm::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->button9->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(195)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button9->Location = System::Drawing::Point(122, 341);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(104, 42);
			this->button9->TabIndex = 8;
			this->button9->Text = L" - строка";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Visible = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyNewForm::button9_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->button10->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button10->Location = System::Drawing::Point(342, 341);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(104, 42);
			this->button10->TabIndex = 9;
			this->button10->Text = L"- столбец";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Visible = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyNewForm::button10_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15));
			this->label1->Location = System::Drawing::Point(568, 133);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 23);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Решение системы";
			this->label1->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(523, 184);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(214, 20);
			this->textBox1->TabIndex = 11;
			this->textBox1->Visible = false;
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->button11->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(83)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button11->Location = System::Drawing::Point(523, 236);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(214, 42);
			this->button11->TabIndex = 7;
			this->button11->Text = L"Сохранить решение";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Visible = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyNewForm::button11_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15));
			this->label2->Location = System::Drawing::Point(554, 133);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(163, 23);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Введите погрешность";
			this->label2->Visible = false;
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(129)), static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->button12->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(228)));
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button12->Location = System::Drawing::Point(523, 236);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(214, 42);
			this->button12->TabIndex = 13;
			this->button12->Text = L"Решить систему";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Visible = false;
			this->button12->Click += gcnew System::EventHandler(this, &MyNewForm::button12_Click);
			// 
			// MyNewForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(802, 398);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"MyNewForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"SLAE";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (createdButton == nullptr) {
			createdButton = gcnew Button();

			createdButton->Text = "Сохранить";
			createdButton->Font = gcnew System::Drawing::Font("Baskerville Old Face", 15);
			createdButton->ForeColor = System::Drawing::Color::FromArgb(244, 250, 255);

			createdButton->Size = System::Drawing::Size(104, 42);
			createdButton->Location = System::Drawing::Point(12, 60);
			createdButton->BackColor = System::Drawing::Color::FromArgb(255, 169, 64);

			createdButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			createdButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(255, 169, 64);

			createdButton->Click += gcnew System::EventHandler(this, &MyNewForm::createdButton_Click);

			this->Controls->Add(createdButton);
			createdButton->BringToFront();

			createdButton1 = gcnew Button();

			createdButton1->Text = "Загрузить";
			createdButton1->Font = gcnew System::Drawing::Font("Baskerville Old Face", 15);
			createdButton1->ForeColor = System::Drawing::Color::FromArgb(244, 250, 255);

			createdButton1->Size = System::Drawing::Size(104, 42);
			createdButton1->Location = System::Drawing::Point(12, 108);
			createdButton1->BackColor = System::Drawing::Color::FromArgb(255, 169, 64);

			createdButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			createdButton1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(255, 169, 64);

			createdButton1->Click += gcnew System::EventHandler(this, &MyNewForm::createdButton1_Click);

			this->Controls->Add(createdButton1);
			createdButton1->BringToFront();
		}
		else {
			// Удаляем созданную кнопку
			this->Controls->Remove(createdButton);
			createdButton = nullptr;

			this->Controls->Remove(createdButton1);
			createdButton1 = nullptr;
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->Visible == false) {
			dataGridView1->Visible = true;

			button7->Visible = true;
			button8->Visible = true;
			button9->Visible = true;
			button10->Visible = true;
		}
		else {
			dataGridView1->Visible = false;

			button7->Visible = false;
			button8->Visible = false;
			button9->Visible = false;
			button10->Visible = false;
		}
	}
private: System::Void dataGridView1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter) {
		MessageBox::Show("Идет проверка файла");

		if (corr_input == true) {
			MessageBox::Show("Данные введены корректно, включаю выбор метода решения");

			button3->Visible = true;
			button4->Visible = true;
			button5->Visible = true;
			button6->Visible = true;
		}
		else {
			MessageBox::Show("Данные введены не корректно, повторите ввод");
		}
	}
}

private: System::Void createdButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

	openFileDialog->Title = "Выберите файл";
	openFileDialog->Filter = "Все файлы (*.*)|*.*";

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ selectedFilePath = openFileDialog->FileName;
		MessageBox::Show("Выбран файл: " + selectedFilePath);
	}
}

private: System::Void createdButton_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();

	saveFileDialog->Title = "Сохранить файл";
	saveFileDialog->Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";

	if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ filePath = saveFileDialog->FileName;

		// Ваш код для сохранения элемента в выбранный файл
		// Например, можно использовать StreamWriter для записи данных в файл:
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(filePath);
		writer->WriteLine("Содержимое элемента для сохранения");
		writer->Close();

		MessageBox::Show("Файл сохранен: " + filePath);
	}
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	corr_input = true;
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	corr_input = false;
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->RowCount < 10) {
		dataGridView1->RowCount = dataGridView1->RowCount + 1;
	}
	else {
		MessageBox::Show("Достигнут лимит");
	}
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->RowCount > 2) {
		dataGridView1->RowCount = dataGridView1->RowCount - 1;
	}
	else {
		MessageBox::Show("Достигнут лимит");
	}
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->ColumnCount < 10) {
		dataGridView1->ColumnCount = dataGridView1->ColumnCount + 1;
	}
	else {
		MessageBox::Show("Достигнут лимит");
	}
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->ColumnCount > 2) {
		dataGridView1->ColumnCount = dataGridView1->ColumnCount - 1;
	}
	else {
		MessageBox::Show("Достигнут лимит");
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Решение системы");

	label1->Visible = true;
	textBox1->Visible = true;
	button11->Visible = true;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Решение системы");

	label1->Visible = true;
	textBox1->Visible = true;
	button11->Visible = true;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Решение системы");

	label1->Visible = true;
	textBox1->Visible = true;
	button11->Visible = true;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	label2->Visible = true;
	textBox1->Visible = true;
	button12->Visible = true;
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();

	saveFileDialog->Title = "Сохранить файл";
	saveFileDialog->Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";

	if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ filePath = saveFileDialog->FileName;

		// Ваш код для сохранения элемента в выбранный файл
		// Например, можно использовать StreamWriter для записи данных в файл:
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(filePath);
		writer->WriteLine("Содержимое элемента для сохранения");
		writer->Close();

		MessageBox::Show("Файл сохранен: " + filePath);
	}
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Решение системы");

	label1->Visible = true;
	textBox1->Visible = true;
	button11->Visible = true;

	label2->Visible = false;
	button12->Visible = false;

}
};
}

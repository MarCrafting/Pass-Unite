#pragma once
#include <random>

namespace PassUnite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Generator
	/// </summary>
	public ref class Generator : public System::Windows::Forms::Form
	{
	public:
		Generator(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Generator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelRandomText;
	private: System::Windows::Forms::Button^ buttonGenerator;
	private: System::Windows::Forms::CheckBox^ checkBoxNumbers;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownStringLength;
	private: System::Windows::Forms::Label^ labelStringLength;
	private: System::Windows::Forms::CheckBox^ checkBoxSpecialChars;
	private: System::Windows::Forms::CheckBox^ checkBoxUppercase;
	private: System::Windows::Forms::CheckBox^ checkBoxLowercase;

	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelRandomText = (gcnew System::Windows::Forms::Label());
			this->buttonGenerator = (gcnew System::Windows::Forms::Button());
			this->checkBoxNumbers = (gcnew System::Windows::Forms::CheckBox());
			this->numericUpDownStringLength = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelStringLength = (gcnew System::Windows::Forms::Label());
			this->checkBoxSpecialChars = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxUppercase = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxLowercase = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownStringLength))->BeginInit();
			this->SuspendLayout();
			// 
			// labelRandomText
			// 
			this->labelRandomText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelRandomText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelRandomText->Location = System::Drawing::Point(-1, 26);
			this->labelRandomText->Name = L"labelRandomText";
			this->labelRandomText->Size = System::Drawing::Size(966, 52);
			this->labelRandomText->TabIndex = 0;
			this->labelRandomText->Text = L"...";
			this->labelRandomText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonGenerator
			// 
			this->buttonGenerator->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonGenerator->Location = System::Drawing::Point(161, 81);
			this->buttonGenerator->Name = L"buttonGenerator";
			this->buttonGenerator->Size = System::Drawing::Size(608, 48);
			this->buttonGenerator->TabIndex = 1;
			this->buttonGenerator->Text = L"Generate";
			this->buttonGenerator->UseVisualStyleBackColor = true;
			this->buttonGenerator->Click += gcnew System::EventHandler(this, &Generator::buttonGenerator_Click);
			// 
			// checkBoxNumbers
			// 
			this->checkBoxNumbers->AutoSize = true;
			this->checkBoxNumbers->Location = System::Drawing::Point(227, 227);
			this->checkBoxNumbers->Name = L"checkBoxNumbers";
			this->checkBoxNumbers->Size = System::Drawing::Size(106, 17);
			this->checkBoxNumbers->TabIndex = 2;
			this->checkBoxNumbers->Text = L"Include Numbers";
			this->checkBoxNumbers->UseVisualStyleBackColor = true;
			// 
			// numericUpDownStringLength
			// 
			this->numericUpDownStringLength->Location = System::Drawing::Point(273, 182);
			this->numericUpDownStringLength->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDownStringLength->Name = L"numericUpDownStringLength";
			this->numericUpDownStringLength->Size = System::Drawing::Size(60, 20);
			this->numericUpDownStringLength->TabIndex = 3;
			this->numericUpDownStringLength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// labelStringLength
			// 
			this->labelStringLength->AutoSize = true;
			this->labelStringLength->Location = System::Drawing::Point(224, 184);
			this->labelStringLength->Name = L"labelStringLength";
			this->labelStringLength->Size = System::Drawing::Size(43, 13);
			this->labelStringLength->TabIndex = 4;
			this->labelStringLength->Text = L"Length:";
			// 
			// checkBoxSpecialChars
			// 
			this->checkBoxSpecialChars->AutoSize = true;
			this->checkBoxSpecialChars->Location = System::Drawing::Point(227, 259);
			this->checkBoxSpecialChars->Name = L"checkBoxSpecialChars";
			this->checkBoxSpecialChars->Size = System::Drawing::Size(153, 17);
			this->checkBoxSpecialChars->TabIndex = 5;
			this->checkBoxSpecialChars->Text = L"Include Special Characters";
			this->checkBoxSpecialChars->UseVisualStyleBackColor = true;
			// 
			// checkBoxUppercase
			// 
			this->checkBoxUppercase->AutoSize = true;
			this->checkBoxUppercase->Location = System::Drawing::Point(464, 259);
			this->checkBoxUppercase->Name = L"checkBoxUppercase";
			this->checkBoxUppercase->Size = System::Drawing::Size(151, 17);
			this->checkBoxUppercase->TabIndex = 6;
			this->checkBoxUppercase->Text = L"Include Uppercase Letters";
			this->checkBoxUppercase->UseVisualStyleBackColor = true;
			// 
			// checkBoxLowercase
			// 
			this->checkBoxLowercase->AutoSize = true;
			this->checkBoxLowercase->Checked = true;
			this->checkBoxLowercase->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxLowercase->Location = System::Drawing::Point(464, 227);
			this->checkBoxLowercase->Name = L"checkBoxLowercase";
			this->checkBoxLowercase->Size = System::Drawing::Size(151, 17);
			this->checkBoxLowercase->TabIndex = 7;
			this->checkBoxLowercase->Text = L"Include Lowercase Letters";
			this->checkBoxLowercase->UseVisualStyleBackColor = true;
			// 
			// Generator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(965, 297);
			this->Controls->Add(this->checkBoxLowercase);
			this->Controls->Add(this->checkBoxUppercase);
			this->Controls->Add(this->checkBoxSpecialChars);
			this->Controls->Add(this->labelStringLength);
			this->Controls->Add(this->numericUpDownStringLength);
			this->Controls->Add(this->checkBoxNumbers);
			this->Controls->Add(this->buttonGenerator);
			this->Controls->Add(this->labelRandomText);
			this->Name = L"Generator";
			this->Text = L"Generator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownStringLength))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonGenerator_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string characters;

		// if numbers and letters are unchecked
		if (!checkBoxNumbers->Checked && !checkBoxLowercase->Checked && !checkBoxUppercase->Checked)
		{
			MessageBox::Show("Numbers and Letters cannot both be unselected.",

				"Failed to Generate", MessageBoxButtons::OK);
		}
		else
		{
			if (checkBoxNumbers->Checked)
			{
				// add numbers to list of strings
				characters += "0123456789";
			}
			if (checkBoxLowercase->Checked)
			{
				// add lowercase to list of strings
				characters += "abcdefghijklmnopqrstuvwxyz";
			}
			if (checkBoxUppercase->Checked)
			{
				// add uppercase to list of strings
				characters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			}
			if (checkBoxSpecialChars->Checked)
			{
				// add special chars to list of strings
				characters += "!@#$<>%^:;./,-&*+(|)~{}=?/";
			}

			std::string randString;

			for (int i = 0; i < numericUpDownStringLength->Value; i++)
			{
				// generate random number
				int randNum = std::rand() % characters.length() + 0;

				// append character at index(random number) to random string
				randString += characters[randNum];
			}
			String^ rString = gcnew String(randString.c_str());
			labelRandomText->Text = rString;
		}
	}
	};
}

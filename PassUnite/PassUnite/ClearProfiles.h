#pragma once
#include "User.h"

namespace PassUnite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for ClearProfiles
	/// </summary>
	public ref class ClearProfiles : public System::Windows::Forms::Form
	{
	public:
		ClearProfiles(User^ _user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			user = _user;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ClearProfiles()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::PictureBox^ pictureBoxReturn;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::TextBox^ textBoxPassword;

	private: System::Windows::Forms::Label^ labelPrompt;
	private: System::Windows::Forms::Button^ buttonYes;
	private: System::Windows::Forms::Button^ buttonNo;
	private: System::Windows::Forms::Label^ labelPassIncorrect;











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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ClearProfiles::typeid));
			this->pictureBoxReturn = (gcnew System::Windows::Forms::PictureBox());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelPrompt = (gcnew System::Windows::Forms::Label());
			this->buttonYes = (gcnew System::Windows::Forms::Button());
			this->buttonNo = (gcnew System::Windows::Forms::Button());
			this->labelPassIncorrect = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxReturn))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxReturn
			// 
			this->pictureBoxReturn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxReturn.Image")));
			this->pictureBoxReturn->Location = System::Drawing::Point(26, 17);
			this->pictureBoxReturn->Margin = System::Windows::Forms::Padding(0);
			this->pictureBoxReturn->Name = L"pictureBoxReturn";
			this->pictureBoxReturn->Size = System::Drawing::Size(35, 35);
			this->pictureBoxReturn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxReturn->TabIndex = 11;
			this->pictureBoxReturn->TabStop = false;
			this->pictureBoxReturn->Click += gcnew System::EventHandler(this, &ClearProfiles::pictureBoxReturn_Click);
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(12, 17);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(683, 78);
			this->labelTitle->TabIndex = 12;
			this->labelTitle->Text = L"Confirm Clear Profiles Request";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPassword->Location = System::Drawing::Point(119, 117);
			this->labelPassword->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(142, 31);
			this->labelPassword->TabIndex = 13;
			this->labelPassword->Text = L"Password:";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(69)),
				static_cast<System::Int32>(static_cast<System::Byte>(97)));
			this->textBoxPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxPassword->Location = System::Drawing::Point(320, 117);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(282, 31);
			this->textBoxPassword->TabIndex = 14;
			this->textBoxPassword->UseSystemPasswordChar = true;
			// 
			// labelPrompt
			// 
			this->labelPrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPrompt->Location = System::Drawing::Point(89, 180);
			this->labelPrompt->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelPrompt->Name = L"labelPrompt";
			this->labelPrompt->Size = System::Drawing::Size(566, 70);
			this->labelPrompt->TabIndex = 13;
			this->labelPrompt->Text = L"All saved profiles will be permanently deleted, would you like to continue\?";
			this->labelPrompt->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonYes
			// 
			this->buttonYes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(3)), static_cast<System::Int32>(static_cast<System::Byte>(3)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->buttonYes->FlatAppearance->BorderSize = 0;
			this->buttonYes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonYes->ForeColor = System::Drawing::Color::White;
			this->buttonYes->Location = System::Drawing::Point(135, 287);
			this->buttonYes->Name = L"buttonYes";
			this->buttonYes->Size = System::Drawing::Size(170, 35);
			this->buttonYes->TabIndex = 15;
			this->buttonYes->Text = L"YES";
			this->buttonYes->UseVisualStyleBackColor = false;
			this->buttonYes->Click += gcnew System::EventHandler(this, &ClearProfiles::buttonYes_Click);
			this->buttonYes->Enter += gcnew System::EventHandler(this, &ClearProfiles::buttonYes_Click);
			// 
			// buttonNo
			// 
			this->buttonNo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(3)), static_cast<System::Int32>(static_cast<System::Byte>(3)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->buttonNo->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonNo->FlatAppearance->BorderSize = 0;
			this->buttonNo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonNo->ForeColor = System::Drawing::Color::White;
			this->buttonNo->Location = System::Drawing::Point(423, 287);
			this->buttonNo->Name = L"buttonNo";
			this->buttonNo->Size = System::Drawing::Size(170, 35);
			this->buttonNo->TabIndex = 15;
			this->buttonNo->Text = L"NO";
			this->buttonNo->UseVisualStyleBackColor = false;
			this->buttonNo->Click += gcnew System::EventHandler(this, &ClearProfiles::buttonNo_Click);
			// 
			// labelPassIncorrect
			// 
			this->labelPassIncorrect->AutoSize = true;
			this->labelPassIncorrect->ForeColor = System::Drawing::Color::Red;
			this->labelPassIncorrect->Location = System::Drawing::Point(315, 89);
			this->labelPassIncorrect->Name = L"labelPassIncorrect";
			this->labelPassIncorrect->Size = System::Drawing::Size(201, 25);
			this->labelPassIncorrect->TabIndex = 16;
			this->labelPassIncorrect->Text = L"Password Incorrect.";
			this->labelPassIncorrect->Visible = false;
			// 
			// ClearProfiles
			// 
			this->AcceptButton = this->buttonYes;
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->CancelButton = this->buttonNo;
			this->ClientSize = System::Drawing::Size(707, 365);
			this->Controls->Add(this->labelPassIncorrect);
			this->Controls->Add(this->buttonNo);
			this->Controls->Add(this->buttonYes);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->labelPrompt);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->pictureBoxReturn);
			this->Controls->Add(this->labelTitle);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"ClearProfiles";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ClearProfiles";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxReturn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: User^ user;

	private: System::Void buttonYes_Click(System::Object^ sender, System::EventArgs^ e) {
		// if the password is correct
		if (textBoxPassword->Text == user->password)
		{
			// clear each profile saved
			DeleteProfiles();

			// clear profile slots

			// close overlay
			this->Close();
		}
		else
			labelPassIncorrect->Visible = true;
	}
	private: System::Void buttonNo_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// close overlay
		this->Close();
	}
	private: System::Void pictureBoxReturn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// close overlay
		this->Close();
	}

	private: void DeleteProfiles()
	{
		try
		{
			// open connection
			String^ connString = "Data Source=localhost;Initial Catalog=passuniteusers;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// build sql query
			String^ sqlQuery = "DELETE FROM profiles WHERE accountId=@id";

			// replace placeholder(s)
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@id", user->id);

			// execute
			command.ExecuteNonQuery();

			// close connection
			sqlConn.Close();
		}
		catch (Exception^ ex)
		{
			//MessageBox::Show(ex->Message);			// for troubleshooting
			MessageBox::Show("Failed to connect to database",
				"Database Connection Error", MessageBoxButtons::OK);
		}
	}
	};
}

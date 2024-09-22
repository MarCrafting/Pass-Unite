#pragma once

namespace PassUnite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Register
	/// </summary>
	public ref class Register : public System::Windows::Forms::Form
	{
	public:
		Register(void)
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
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Label^ labelUser;
	private: System::Windows::Forms::TextBox^ textBoxUser;
	private: System::Windows::Forms::Label^ labelPass;
	private: System::Windows::Forms::TextBox^ textBoxPass;
	private: System::Windows::Forms::Label^ labelPassConfirm;
	private: System::Windows::Forms::TextBox^ textBoxPassConfirm;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::TextBox^ textBoxEmail;
	private: System::Windows::Forms::Label^ labelEmail;
	private: System::Windows::Forms::Button^ buttonOK;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::LinkLabel^ linkLabelLogin;


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
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelUser = (gcnew System::Windows::Forms::Label());
			this->textBoxUser = (gcnew System::Windows::Forms::TextBox());
			this->labelPass = (gcnew System::Windows::Forms::Label());
			this->textBoxPass = (gcnew System::Windows::Forms::TextBox());
			this->labelPassConfirm = (gcnew System::Windows::Forms::Label());
			this->textBoxPassConfirm = (gcnew System::Windows::Forms::TextBox());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->labelEmail = (gcnew System::Windows::Forms::Label());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->linkLabelLogin = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(15, 9);
			this->labelTitle->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(747, 121);
			this->labelTitle->TabIndex = 1;
			this->labelTitle->Text = L"Register";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelUser
			// 
			this->labelUser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUser->Location = System::Drawing::Point(57, 269);
			this->labelUser->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelUser->Name = L"labelUser";
			this->labelUser->Size = System::Drawing::Size(185, 35);
			this->labelUser->TabIndex = 3;
			this->labelUser->Text = L"Username";
			// 
			// textBoxUser
			// 
			this->textBoxUser->Location = System::Drawing::Point(376, 272);
			this->textBoxUser->Margin = System::Windows::Forms::Padding(6);
			this->textBoxUser->Name = L"textBoxUser";
			this->textBoxUser->Size = System::Drawing::Size(352, 35);
			this->textBoxUser->TabIndex = 8;
			// 
			// labelPass
			// 
			this->labelPass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPass->Location = System::Drawing::Point(57, 315);
			this->labelPass->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelPass->Name = L"labelPass";
			this->labelPass->Size = System::Drawing::Size(185, 35);
			this->labelPass->TabIndex = 4;
			this->labelPass->Text = L"Password";
			// 
			// textBoxPass
			// 
			this->textBoxPass->Location = System::Drawing::Point(376, 318);
			this->textBoxPass->Margin = System::Windows::Forms::Padding(6);
			this->textBoxPass->Name = L"textBoxPass";
			this->textBoxPass->PasswordChar = '*';
			this->textBoxPass->Size = System::Drawing::Size(352, 35);
			this->textBoxPass->TabIndex = 9;
			// 
			// labelPassConfirm
			// 
			this->labelPassConfirm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelPassConfirm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPassConfirm->Location = System::Drawing::Point(57, 364);
			this->labelPassConfirm->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelPassConfirm->Name = L"labelPassConfirm";
			this->labelPassConfirm->Size = System::Drawing::Size(307, 35);
			this->labelPassConfirm->TabIndex = 5;
			this->labelPassConfirm->Text = L"Confirm Password";
			// 
			// textBoxPassConfirm
			// 
			this->textBoxPassConfirm->Location = System::Drawing::Point(376, 364);
			this->textBoxPassConfirm->Margin = System::Windows::Forms::Padding(6);
			this->textBoxPassConfirm->Name = L"textBoxPassConfirm";
			this->textBoxPassConfirm->PasswordChar = '*';
			this->textBoxPassConfirm->Size = System::Drawing::Size(352, 35);
			this->textBoxPassConfirm->TabIndex = 10;
			// 
			// labelName
			// 
			this->labelName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelName->Location = System::Drawing::Point(57, 175);
			this->labelName->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(185, 35);
			this->labelName->TabIndex = 2;
			this->labelName->Text = L"Name";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(376, 178);
			this->textBoxName->Margin = System::Windows::Forms::Padding(6);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(352, 35);
			this->textBoxName->TabIndex = 6;
			// 
			// textBoxEmail
			// 
			this->textBoxEmail->Location = System::Drawing::Point(376, 225);
			this->textBoxEmail->Margin = System::Windows::Forms::Padding(6);
			this->textBoxEmail->Name = L"textBoxEmail";
			this->textBoxEmail->Size = System::Drawing::Size(352, 35);
			this->textBoxEmail->TabIndex = 7;
			// 
			// labelEmail
			// 
			this->labelEmail->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelEmail->Location = System::Drawing::Point(57, 222);
			this->labelEmail->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelEmail->Name = L"labelEmail";
			this->labelEmail->Size = System::Drawing::Size(185, 35);
			this->labelEmail->TabIndex = 3;
			this->labelEmail->Text = L"Email";
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(452, 408);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(135, 45);
			this->buttonOK->TabIndex = 11;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &Register::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(593, 408);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(135, 45);
			this->buttonCancel->TabIndex = 12;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &Register::buttonCancel_Click);
			// 
			// linkLabelLogin
			// 
			this->linkLabelLogin->AutoSize = true;
			this->linkLabelLogin->Location = System::Drawing::Point(655, 482);
			this->linkLabelLogin->Name = L"linkLabelLogin";
			this->linkLabelLogin->Size = System::Drawing::Size(73, 29);
			this->linkLabelLogin->TabIndex = 13;
			this->linkLabelLogin->TabStop = true;
			this->linkLabelLogin->Text = L"Login";
			this->linkLabelLogin->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Register::linkLabelLogin_LinkClicked);
			// 
			// Register
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(777, 529);
			this->Controls->Add(this->linkLabelLogin);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->textBoxEmail);
			this->Controls->Add(this->labelEmail);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->textBoxPassConfirm);
			this->Controls->Add(this->labelPassConfirm);
			this->Controls->Add(this->textBoxPass);
			this->Controls->Add(this->labelPass);
			this->Controls->Add(this->textBoxUser);
			this->Controls->Add(this->labelUser);
			this->Controls->Add(this->labelTitle);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(7);
			this->Name = L"Register";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Register";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: bool switchToLogin = false;

	private: System::Void buttonOK_Click(System::Object^ sender, System::EventArgs^ e) {
		switchToLogin = false;

		// check if any fields are blank
		if (textBoxName->Text == "" || textBoxEmail->Text == "" || textBoxUser->Text == "" || textBoxPass->Text == "")
		{
			MessageBox::Show("Please fill in every field",
				"Field Left Empty", MessageBoxButtons::OK);

			return;
		}
		// check password textboxes
		if (textBoxPass->Text != textBoxPassConfirm->Text)
		{
			// provide error message
			MessageBox::Show("Password and Confirm Password do not match",
				"Password Error", MessageBoxButtons::OK);
		}
		else
		{
			String^ username = textBoxUser->Text;
			String^ password = textBoxPass->Text;

			CreateAccount(username, password);

			// clear textboxes
			textBoxName->Text = "";
			textBoxEmail->Text = "";
			textBoxUser->Text = "";
			textBoxPass->Text = "";
			textBoxPassConfirm->Text = "";
		}
	}
	private: void CreateAccount(String^ _user, String^ _pass)
	{
		try
		{
			// connect to database
			String^ connString = "Data Source=localhost;Initial Catalog=passuniteusers;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// create sql query with placeholders
			String^ sqlQuery = "INSERT INTO accountUsers (username, password) " +
				"VALUES (@user, @pass)";

			// swap placeholders
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@user", _user);
			command.Parameters->AddWithValue("@pass", _pass);

			// execute
			command.ExecuteNonQuery();
		}
		catch (Exception^ ex)
		{
			//MessageBox::Show(ex->Message);		// for troubleshooting
			MessageBox::Show("Failed to connect to register new user",
				"Register Failure", MessageBoxButtons::OK);
		}
	}
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void linkLabelLogin_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		switchToLogin = true;
		this->Close();
	}
	};
}

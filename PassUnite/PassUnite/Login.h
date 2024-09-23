#pragma once
#include "User.h"
#include "PageProperties.h"

namespace PassUnite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
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
		~Login()
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


	private: System::Windows::Forms::LinkLabel^ linkLabelRegister;
	private: System::Windows::Forms::Button^ buttonOK;
	private: System::Windows::Forms::Button^ buttonCancel;






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
			this->linkLabelRegister = (gcnew System::Windows::Forms::LinkLabel());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
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
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Login";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelUser
			// 
			this->labelUser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUser->Location = System::Drawing::Point(134, 195);
			this->labelUser->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelUser->Name = L"labelUser";
			this->labelUser->Size = System::Drawing::Size(185, 35);
			this->labelUser->TabIndex = 1;
			this->labelUser->Text = L"Username:";
			// 
			// textBoxUser
			// 
			this->textBoxUser->Location = System::Drawing::Point(331, 195);
			this->textBoxUser->Margin = System::Windows::Forms::Padding(6);
			this->textBoxUser->Name = L"textBoxUser";
			this->textBoxUser->Size = System::Drawing::Size(268, 35);
			this->textBoxUser->TabIndex = 1;
			// 
			// labelPass
			// 
			this->labelPass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPass->Location = System::Drawing::Point(134, 241);
			this->labelPass->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelPass->Name = L"labelPass";
			this->labelPass->Size = System::Drawing::Size(185, 35);
			this->labelPass->TabIndex = 1;
			this->labelPass->Text = L"Password:";
			// 
			// textBoxPass
			// 
			this->textBoxPass->Location = System::Drawing::Point(331, 241);
			this->textBoxPass->Margin = System::Windows::Forms::Padding(6);
			this->textBoxPass->Name = L"textBoxPass";
			this->textBoxPass->PasswordChar = '*';
			this->textBoxPass->Size = System::Drawing::Size(268, 35);
			this->textBoxPass->TabIndex = 2;
			this->textBoxPass->TextChanged += gcnew System::EventHandler(this, &Login::textBoxPass_TextChanged);
			// 
			// linkLabelRegister
			// 
			this->linkLabelRegister->AutoSize = true;
			this->linkLabelRegister->Location = System::Drawing::Point(623, 347);
			this->linkLabelRegister->Name = L"linkLabelRegister";
			this->linkLabelRegister->Size = System::Drawing::Size(104, 29);
			this->linkLabelRegister->TabIndex = 5;
			this->linkLabelRegister->TabStop = true;
			this->linkLabelRegister->Text = L"Register";
			this->linkLabelRegister->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Login::linkLabelRegister_LinkClicked);
			// 
			// buttonOK
			// 
			this->buttonOK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonOK->Location = System::Drawing::Point(433, 285);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(80, 31);
			this->buttonOK->TabIndex = 3;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &Login::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCancel->Location = System::Drawing::Point(519, 285);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(80, 31);
			this->buttonCancel->TabIndex = 4;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &Login::buttonCancel_Click);
			// 
			// Login
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(777, 400);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->linkLabelRegister);
			this->Controls->Add(this->textBoxPass);
			this->Controls->Add(this->textBoxUser);
			this->Controls->Add(this->labelPass);
			this->Controls->Add(this->labelUser);
			this->Controls->Add(this->labelTitle);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->Activated += gcnew System::EventHandler(this, &Login::Login_Activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Login::Login_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: PageProperties pageProps;

	public: User^ user = nullptr;

	public: bool switchToRegister = false;

	private: bool clearPass = false;

	public: bool loggedOut = true;

	private: System::Void buttonOK_Click(System::Object^ sender, System::EventArgs^ e) {
		switchToRegister = false;

		// check if either textbox is empty
		String^ username = textBoxUser->Text;
		String^ password = textBoxPass->Text;

		if (username == "" || password == "")
		{
			MessageBox::Show("Please enter both a username and password",
				"Username or Password Empty", MessageBoxButtons::OK);

			// exit function
			return;
		}
		try
		{
			// connect to database
			String^ connString = "Data Source=localhost;Initial Catalog=passuniteusers;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// create SQL query, with placeholders
			String^ sqlQuery = "SELECT * FROM accountUsers WHERE username=@user AND password=@pass;";

			// swap placeholders
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("user", username);
			command.Parameters->AddWithValue("pass", password);

			// read and save the output
			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read())		// if query finds possible match (readable), then read it
			{
				user = gcnew User();
				user->id = reader->GetInt32(0);
				user->username = reader->GetString(1);
				user->password = reader->GetString(2);
			}
			else
			{
				MessageBox::Show("Username or password is incorrect",
					"Username or Password Error", MessageBoxButtons::OK);

				clearPass = true;
				return;
			}

		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Failed to connect to database",
				"Database Connection Error", MessageBoxButtons::OK);

			// exit function
			return;
		}

		// point to home page
		pageProps.page = 1;

		// update signed in flag
		loggedOut = false;

		// close to redirect
		this->Close();
	}
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		// point to terminate condition
		pageProps.page = -1;

		// close app
		this->Close();
	}

	private: System::Void linkLabelRegister_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		switchToRegister = true;
		this->Close();
	}
	private: System::Void Login_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		// check if textfields empty
		if (loggedOut || (textBoxUser->Text == "" && textBoxPass->Text == ""))
			pageProps.page = -1;
	}
	private: System::Void textBoxPass_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (clearPass)
		{
			textBoxPass->Text = "";
			clearPass = false;
		}
	}
private: System::Void Login_Activated(System::Object^ sender, System::EventArgs^ e) {
	// clear text fields
	textBoxUser->Text = "";
	textBoxPass->Text = "";

	// focus username field
	textBoxUser->Focus();
	
	// update loggedOut flag
	loggedOut = true;
}
};
}

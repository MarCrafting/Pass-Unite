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
		System::ComponentModel::Container ^components;

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
			this->labelUser->Location = System::Drawing::Point(134, 203);
			this->labelUser->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelUser->Name = L"labelUser";
			this->labelUser->Size = System::Drawing::Size(185, 35);
			this->labelUser->TabIndex = 1;
			this->labelUser->Text = L"Username:";
			// 
			// textBoxUser
			// 
			this->textBoxUser->Location = System::Drawing::Point(331, 203);
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
			// 
			// buttonOK
			// 
			this->buttonOK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonOK->Location = System::Drawing::Point(443, 285);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 3;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &Login::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCancel->Location = System::Drawing::Point(524, 285);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void buttonOK_Click(System::Object^ sender, System::EventArgs^ e) {
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
	else
	{
		// connect to database
		String^ connString = "";
	}
}
private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	// close app
	this->Close();
}
};
}

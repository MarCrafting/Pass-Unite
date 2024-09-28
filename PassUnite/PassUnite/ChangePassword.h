#pragma once
#include "User.h"

namespace PassUnite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChangePassword
	/// </summary>
	public ref class ChangePassword : public System::Windows::Forms::Form
	{
	public:
		ChangePassword(User^ _user)
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
		~ChangePassword()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::TextBox^ textBoxCurrentPassword;
	protected:

	private: System::Windows::Forms::Label^ labelCurrentPassword;
	private: System::Windows::Forms::Label^ labelNewPassword;
	private: System::Windows::Forms::Label^ labelConfirmPassword;
	private: System::Windows::Forms::TextBox^ textBoxNewPassword;
	private: System::Windows::Forms::TextBox^ textBoxConfirmPassword;
	private: System::Windows::Forms::PictureBox^ pictureBoxReturn;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ChangePassword::typeid));
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->textBoxCurrentPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelCurrentPassword = (gcnew System::Windows::Forms::Label());
			this->labelNewPassword = (gcnew System::Windows::Forms::Label());
			this->labelConfirmPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxNewPassword = (gcnew System::Windows::Forms::TextBox());
			this->textBoxConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxReturn = (gcnew System::Windows::Forms::PictureBox());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxReturn))->BeginInit();
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(15, 9);
			this->labelTitle->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(677, 104);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Change Password";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBoxCurrentPassword
			// 
			this->textBoxCurrentPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(97)));
			this->textBoxCurrentPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxCurrentPassword->Location = System::Drawing::Point(349, 110);
			this->textBoxCurrentPassword->Margin = System::Windows::Forms::Padding(2);
			this->textBoxCurrentPassword->Name = L"textBoxCurrentPassword";
			this->textBoxCurrentPassword->Size = System::Drawing::Size(268, 31);
			this->textBoxCurrentPassword->TabIndex = 1;
			this->textBoxCurrentPassword->UseSystemPasswordChar = true;
			// 
			// labelCurrentPassword
			// 
			this->labelCurrentPassword->AutoSize = true;
			this->labelCurrentPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelCurrentPassword->Location = System::Drawing::Point(106, 110);
			this->labelCurrentPassword->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelCurrentPassword->Name = L"labelCurrentPassword";
			this->labelCurrentPassword->Size = System::Drawing::Size(189, 25);
			this->labelCurrentPassword->TabIndex = 0;
			this->labelCurrentPassword->Text = L"Current Password:";
			// 
			// labelNewPassword
			// 
			this->labelNewPassword->AutoSize = true;
			this->labelNewPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelNewPassword->Location = System::Drawing::Point(106, 177);
			this->labelNewPassword->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelNewPassword->Name = L"labelNewPassword";
			this->labelNewPassword->Size = System::Drawing::Size(160, 25);
			this->labelNewPassword->TabIndex = 0;
			this->labelNewPassword->Text = L"New Password:";
			// 
			// labelConfirmPassword
			// 
			this->labelConfirmPassword->AutoSize = true;
			this->labelConfirmPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelConfirmPassword->Location = System::Drawing::Point(106, 214);
			this->labelConfirmPassword->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->labelConfirmPassword->Name = L"labelConfirmPassword";
			this->labelConfirmPassword->Size = System::Drawing::Size(192, 25);
			this->labelConfirmPassword->TabIndex = 0;
			this->labelConfirmPassword->Text = L"Confirm Password:";
			// 
			// textBoxNewPassword
			// 
			this->textBoxNewPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(97)));
			this->textBoxNewPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxNewPassword->Location = System::Drawing::Point(349, 171);
			this->textBoxNewPassword->Margin = System::Windows::Forms::Padding(2);
			this->textBoxNewPassword->Name = L"textBoxNewPassword";
			this->textBoxNewPassword->Size = System::Drawing::Size(268, 31);
			this->textBoxNewPassword->TabIndex = 2;
			this->textBoxNewPassword->UseSystemPasswordChar = true;
			// 
			// textBoxConfirmPassword
			// 
			this->textBoxConfirmPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(97)));
			this->textBoxConfirmPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxConfirmPassword->Location = System::Drawing::Point(349, 206);
			this->textBoxConfirmPassword->Margin = System::Windows::Forms::Padding(2);
			this->textBoxConfirmPassword->Name = L"textBoxConfirmPassword";
			this->textBoxConfirmPassword->Size = System::Drawing::Size(268, 31);
			this->textBoxConfirmPassword->TabIndex = 3;
			this->textBoxConfirmPassword->UseSystemPasswordChar = true;
			// 
			// pictureBoxReturn
			// 
			this->pictureBoxReturn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxReturn.Image")));
			this->pictureBoxReturn->Location = System::Drawing::Point(26, 17);
			this->pictureBoxReturn->Name = L"pictureBoxReturn";
			this->pictureBoxReturn->Size = System::Drawing::Size(35, 35);
			this->pictureBoxReturn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxReturn->TabIndex = 2;
			this->pictureBoxReturn->TabStop = false;
			this->pictureBoxReturn->Click += gcnew System::EventHandler(this, &ChangePassword::pictureBoxReturn_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(3)), static_cast<System::Int32>(static_cast<System::Byte>(3)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->buttonOK->FlatAppearance->BorderSize = 0;
			this->buttonOK->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonOK->ForeColor = System::Drawing::Color::White;
			this->buttonOK->Location = System::Drawing::Point(133, 282);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(165, 35);
			this->buttonOK->TabIndex = 4;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = false;
			this->buttonOK->Click += gcnew System::EventHandler(this, &ChangePassword::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(3)), static_cast<System::Int32>(static_cast<System::Byte>(3)),
				static_cast<System::Int32>(static_cast<System::Byte>(3)));
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->FlatAppearance->BorderSize = 0;
			this->buttonCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonCancel->ForeColor = System::Drawing::Color::White;
			this->buttonCancel->Location = System::Drawing::Point(403, 282);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(165, 35);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = false;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &ChangePassword::buttonCancel_Click);
			// 
			// ChangePassword
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(707, 365);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->pictureBoxReturn);
			this->Controls->Add(this->textBoxConfirmPassword);
			this->Controls->Add(this->textBoxNewPassword);
			this->Controls->Add(this->textBoxCurrentPassword);
			this->Controls->Add(this->labelConfirmPassword);
			this->Controls->Add(this->labelNewPassword);
			this->Controls->Add(this->labelCurrentPassword);
			this->Controls->Add(this->labelTitle);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"ChangePassword";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"ChangePassword";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxReturn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: User^ user = nullptr;

	private: System::Void buttonOK_Click(System::Object^ sender, System::EventArgs^ e) {
		// textbox checks
		{
			// check current password
			if (textBoxCurrentPassword->Text != user->password)
			{
				// provide error message
				MessageBox::Show("Current Password is incorrect",
					"Incorrect Password", MessageBoxButtons::OK);
				return;
			}
			// check if password textboxes empty
			if (textBoxNewPassword->Text == "")
			{
				// provide error message
				MessageBox::Show("Important fields cannot be left empty",
					"Empty Fields", MessageBoxButtons::OK);
				return;
			}
			// check if password textboxes match
			if (textBoxNewPassword->Text != textBoxConfirmPassword->Text)
			{
				// provide error message
				MessageBox::Show("New Password and Confirm Password does not match",
					"Passwords Do Not Match", MessageBoxButtons::OK);
				return;
			}
		}
		// update current user password in login database

		// clear textboxes
		textBoxCurrentPassword->Text = "";
		textBoxNewPassword->Text = "";
		textBoxConfirmPassword->Text = "";

		// close this overlay
		this->Close();
	}
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear textboxes
		textBoxCurrentPassword->Text = "";
		textBoxNewPassword->Text = "";
		textBoxConfirmPassword->Text = "";

		// close this overlay
		this->Close();
	}
	private: System::Void pictureBoxReturn_Click(System::Object^ sender, System::EventArgs^ e) {
		// close this overlay
		this->Close();
	}
	};
}

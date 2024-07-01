#pragma once
#include "ChangePassword.h"
#include "ClearProfiles.h"
#include "PageProperties.h"

namespace PassUnite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(void)
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
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::PictureBox^ pictureBoxReturn;
	private: System::Windows::Forms::Label^ labelLoggedUser;
	private: System::Windows::Forms::Label^ labelChangePass;
	private: System::Windows::Forms::Label^ labelClearProfiles;
	private: System::Windows::Forms::Label^ labelDeleteAccount;
	private: System::Windows::Forms::Label^ labelLogout;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Settings::typeid));
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->pictureBoxReturn = (gcnew System::Windows::Forms::PictureBox());
			this->labelLoggedUser = (gcnew System::Windows::Forms::Label());
			this->labelChangePass = (gcnew System::Windows::Forms::Label());
			this->labelClearProfiles = (gcnew System::Windows::Forms::Label());
			this->labelDeleteAccount = (gcnew System::Windows::Forms::Label());
			this->labelLogout = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxReturn))->BeginInit();
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(12, 9);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(960, 161);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Settings";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBoxReturn
			// 
			this->pictureBoxReturn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)),
				static_cast<System::Int32>(static_cast<System::Byte>(188)), static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->pictureBoxReturn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxReturn.Image")));
			this->pictureBoxReturn->Location = System::Drawing::Point(27, 17);
			this->pictureBoxReturn->Name = L"pictureBoxReturn";
			this->pictureBoxReturn->Size = System::Drawing::Size(35, 35);
			this->pictureBoxReturn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxReturn->TabIndex = 2;
			this->pictureBoxReturn->TabStop = false;
			this->pictureBoxReturn->Click += gcnew System::EventHandler(this, &Settings::pictureBox1_Click);
			// 
			// labelLoggedUser
			// 
			this->labelLoggedUser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelLoggedUser->AutoSize = true;
			this->labelLoggedUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelLoggedUser->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(171)));
			this->labelLoggedUser->Location = System::Drawing::Point(798, 21);
			this->labelLoggedUser->Name = L"labelLoggedUser";
			this->labelLoggedUser->Size = System::Drawing::Size(142, 31);
			this->labelLoggedUser->TabIndex = 3;
			this->labelLoggedUser->Text = L"username";
			// 
			// labelChangePass
			// 
			this->labelChangePass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelChangePass->AutoSize = true;
			this->labelChangePass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelChangePass->Location = System::Drawing::Point(36, 200);
			this->labelChangePass->Name = L"labelChangePass";
			this->labelChangePass->Size = System::Drawing::Size(252, 33);
			this->labelChangePass->TabIndex = 4;
			this->labelChangePass->Text = L"Change Password";
			this->labelChangePass->Click += gcnew System::EventHandler(this, &Settings::labelChangePass_Click);
			// 
			// labelClearProfiles
			// 
			this->labelClearProfiles->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelClearProfiles->AutoSize = true;
			this->labelClearProfiles->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelClearProfiles->Location = System::Drawing::Point(36, 254);
			this->labelClearProfiles->Name = L"labelClearProfiles";
			this->labelClearProfiles->Size = System::Drawing::Size(232, 33);
			this->labelClearProfiles->TabIndex = 4;
			this->labelClearProfiles->Text = L"Clear All Profiles";
			this->labelClearProfiles->Click += gcnew System::EventHandler(this, &Settings::labelClearProfiles_Click);
			// 
			// labelDeleteAccount
			// 
			this->labelDeleteAccount->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelDeleteAccount->AutoSize = true;
			this->labelDeleteAccount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelDeleteAccount->Location = System::Drawing::Point(36, 306);
			this->labelDeleteAccount->Name = L"labelDeleteAccount";
			this->labelDeleteAccount->Size = System::Drawing::Size(212, 33);
			this->labelDeleteAccount->TabIndex = 4;
			this->labelDeleteAccount->Text = L"Delete Account";
			// 
			// labelLogout
			// 
			this->labelLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelLogout->AutoSize = true;
			this->labelLogout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelLogout->Location = System::Drawing::Point(36, 431);
			this->labelLogout->Name = L"labelLogout";
			this->labelLogout->Size = System::Drawing::Size(103, 33);
			this->labelLogout->TabIndex = 4;
			this->labelLogout->Text = L"Logout";
			this->labelLogout->Click += gcnew System::EventHandler(this, &Settings::labelLogout_Click);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(22, 42);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->ClientSize = System::Drawing::Size(984, 511);
			this->Controls->Add(this->labelLogout);
			this->Controls->Add(this->labelDeleteAccount);
			this->Controls->Add(this->labelClearProfiles);
			this->Controls->Add(this->labelChangePass);
			this->Controls->Add(this->labelLoggedUser);
			this->Controls->Add(this->pictureBoxReturn);
			this->Controls->Add(this->labelTitle);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(12, 10, 12, 10);
			this->Name = L"Settings";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Pass Unite";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxReturn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: PageProperties pageProps;

	public: bool logUserOut = false;

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		// close Settings overlay
		this->Close();
	}
	private: System::Void labelChangePass_Click(System::Object^ sender, System::EventArgs^ e) {
		// open "Change Password" overlay
		PassUnite::ChangePassword changePassOverlay;
		changePassOverlay.ShowDialog();
	}
	private: System::Void labelClearProfiles_Click(System::Object^ sender, System::EventArgs^ e) {
		// open "ClearProfiles" overlay
		PassUnite::ClearProfiles clearProfilesOverlay;
		clearProfilesOverlay.ShowDialog();
	}
	private: System::Void labelLogout_Click(System::Object^ sender, System::EventArgs^ e) {

		logUserOut = true;

		// close overlay
		this->Close();
	}
	};
}

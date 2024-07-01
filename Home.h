#pragma once

#include "PageProperties.h"
#include "Settings.h"

namespace PassUnite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void)
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
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelSidebar;
	private: System::Windows::Forms::Panel^ panelTopbar;
	private: System::Windows::Forms::Label^ labelAppName;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBoxMenu;
	private: System::Windows::Forms::PictureBox^ pictureBoxProfiles;


	private: System::Windows::Forms::PictureBox^ pictureBoxSettings;

	private: System::Windows::Forms::PictureBox^ pictureBoxGeneratePassword;

	private: System::Windows::Forms::PictureBox^ pictureBoxAddProfile;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->panelSidebar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxMenu = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxProfiles = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSettings = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGeneratePassword = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAddProfile = (gcnew System::Windows::Forms::PictureBox());
			this->panelTopbar = (gcnew System::Windows::Forms::Panel());
			this->labelAppName = (gcnew System::Windows::Forms::Label());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panelSidebar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGeneratePassword))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->BeginInit();
			this->panelTopbar->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelSidebar
			// 
			this->panelSidebar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panelSidebar->Controls->Add(this->pictureBoxMenu);
			this->panelSidebar->Controls->Add(this->pictureBoxProfiles);
			this->panelSidebar->Controls->Add(this->pictureBoxSettings);
			this->panelSidebar->Controls->Add(this->pictureBoxGeneratePassword);
			this->panelSidebar->Controls->Add(this->pictureBoxAddProfile);
			this->panelSidebar->Location = System::Drawing::Point(0, 0);
			this->panelSidebar->Name = L"panelSidebar";
			this->panelSidebar->Size = System::Drawing::Size(75, 515);
			this->panelSidebar->TabIndex = 0;
			// 
			// pictureBoxMenu
			// 
			this->pictureBoxMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxMenu.Image")));
			this->pictureBoxMenu->Location = System::Drawing::Point(20, 20);
			this->pictureBoxMenu->Name = L"pictureBoxMenu";
			this->pictureBoxMenu->Size = System::Drawing::Size(35, 35);
			this->pictureBoxMenu->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMenu->TabIndex = 1;
			this->pictureBoxMenu->TabStop = false;
			// 
			// pictureBoxProfiles
			// 
			this->pictureBoxProfiles->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxProfiles.Image")));
			this->pictureBoxProfiles->Location = System::Drawing::Point(20, 350);
			this->pictureBoxProfiles->Name = L"pictureBoxProfiles";
			this->pictureBoxProfiles->Size = System::Drawing::Size(35, 35);
			this->pictureBoxProfiles->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxProfiles->TabIndex = 0;
			this->pictureBoxProfiles->TabStop = false;
			this->pictureBoxProfiles->Click += gcnew System::EventHandler(this, &Home::pictureBoxProfiles_Click);
			// 
			// pictureBoxSettings
			// 
			this->pictureBoxSettings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxSettings.Image")));
			this->pictureBoxSettings->Location = System::Drawing::Point(20, 230);
			this->pictureBoxSettings->Name = L"pictureBoxSettings";
			this->pictureBoxSettings->Size = System::Drawing::Size(35, 35);
			this->pictureBoxSettings->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxSettings->TabIndex = 0;
			this->pictureBoxSettings->TabStop = false;
			this->pictureBoxSettings->Click += gcnew System::EventHandler(this, &Home::pictureBoxSettings_Click);
			// 
			// pictureBoxGeneratePassword
			// 
			this->pictureBoxGeneratePassword->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxGeneratePassword.Image")));
			this->pictureBoxGeneratePassword->Location = System::Drawing::Point(20, 170);
			this->pictureBoxGeneratePassword->Name = L"pictureBoxGeneratePassword";
			this->pictureBoxGeneratePassword->Size = System::Drawing::Size(35, 35);
			this->pictureBoxGeneratePassword->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxGeneratePassword->TabIndex = 0;
			this->pictureBoxGeneratePassword->TabStop = false;
			// 
			// pictureBoxAddProfile
			// 
			this->pictureBoxAddProfile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxAddProfile.Image")));
			this->pictureBoxAddProfile->Location = System::Drawing::Point(20, 110);
			this->pictureBoxAddProfile->Name = L"pictureBoxAddProfile";
			this->pictureBoxAddProfile->Size = System::Drawing::Size(35, 35);
			this->pictureBoxAddProfile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxAddProfile->TabIndex = 0;
			this->pictureBoxAddProfile->TabStop = false;
			this->pictureBoxAddProfile->Click += gcnew System::EventHandler(this, &Home::pictureBox2_Click);
			// 
			// panelTopbar
			// 
			this->panelTopbar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelTopbar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panelTopbar->Controls->Add(this->labelAppName);
			this->panelTopbar->Location = System::Drawing::Point(0, 0);
			this->panelTopbar->Name = L"panelTopbar";
			this->panelTopbar->Size = System::Drawing::Size(985, 75);
			this->panelTopbar->TabIndex = 0;
			// 
			// labelAppName
			// 
			this->labelAppName->AutoSize = true;
			this->labelAppName->Font = (gcnew System::Drawing::Font(L"Yet R", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->labelAppName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(135)));
			this->labelAppName->Location = System::Drawing::Point(100, 23);
			this->labelAppName->Name = L"labelAppName";
			this->labelAppName->Size = System::Drawing::Size(152, 28);
			this->labelAppName->TabIndex = 0;
			this->labelAppName->Text = L"Pass Unite";
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"MoeumT R", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->labelTitle->Location = System::Drawing::Point(75, 78);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(910, 124);
			this->labelTitle->TabIndex = 1;
			this->labelTitle->Text = L"Welcome to Pass Unite";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel1->Location = System::Drawing::Point(179, 205);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(715, 2);
			this->panel1->TabIndex = 2;
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->ClientSize = System::Drawing::Size(984, 511);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->labelTitle);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelTopbar);
			this->Name = L"Home";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Pass Unite";
			this->panelSidebar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGeneratePassword))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->EndInit();
			this->panelTopbar->ResumeLayout(false);
			this->panelTopbar->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: PageProperties pageProps;

	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		// redirect to "Add Profile" page
		pageProps.page = 2;

		// close this window
		this->Close();
	}
	private: System::Void pictureBoxProfiles_Click(System::Object^ sender, System::EventArgs^ e) {
		// redirect to "Profiles" page
		pageProps.page = 3;

		// close this window
		this->Close();
	}
	private: System::Void pictureBoxSettings_Click(System::Object^ sender, System::EventArgs^ e) {
		// open Settings overlay
		PassUnite::Settings settingsOverlay;
		settingsOverlay.ShowDialog();

		// check if user wants to sign out
		if (settingsOverlay.logUserOut)
		{
			// redirect to login screen
			pageProps.page = 0;

			// close window
			this->Close();
		}
	}
};
}

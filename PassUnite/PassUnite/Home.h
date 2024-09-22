#pragma once

#include "PageProperties.h"
#include "Generator.h"
#include "Settings.h"
#include "User.h"

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
		Home(User^ _user)
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
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}














	private: System::Windows::Forms::Panel^ panelContent;

	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Panel^ panel2;









	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ labelAppName;
	private: System::Windows::Forms::PictureBox^ pictureBoxMenu;
	private: System::Windows::Forms::Panel^ panelTopbar;
	private: System::Windows::Forms::PictureBox^ pictureBoxAddProfile;
	private: System::Windows::Forms::PictureBox^ pictureBoxGeneratePassword;
	private: System::Windows::Forms::PictureBox^ pictureBoxSettings;
	private: System::Windows::Forms::PictureBox^ pictureBoxProfiles;
	private: System::Windows::Forms::Panel^ panelSidebar;









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
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->labelAppName = (gcnew System::Windows::Forms::Label());
			this->pictureBoxMenu = (gcnew System::Windows::Forms::PictureBox());
			this->panelTopbar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxAddProfile = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGeneratePassword = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSettings = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxProfiles = (gcnew System::Windows::Forms::PictureBox());
			this->panelSidebar = (gcnew System::Windows::Forms::Panel());
			this->panelContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->BeginInit();
			this->panelTopbar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGeneratePassword))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->BeginInit();
			this->panelSidebar->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelContent
			// 
			this->panelContent->AutoScroll = true;
			this->panelContent->AutoSize = true;
			this->panelContent->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panelContent->Controls->Add(this->panel1);
			this->panelContent->Controls->Add(this->panel2);
			this->panelContent->Controls->Add(this->labelTitle);
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(75, 75);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(926, 436);
			this->panelContent->TabIndex = 3;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(200)));
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Location = System::Drawing::Point(24, 160);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(859, 371);
			this->panel2->TabIndex = 5;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"MoeumT R", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->labelTitle->Location = System::Drawing::Point(6, 5);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(891, 116);
			this->labelTitle->TabIndex = 3;
			this->labelTitle->Text = L"Welcome to Pass Unite";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel1->Location = System::Drawing::Point(68, 123);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(767, 2);
			this->panel1->TabIndex = 6;
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
			// pictureBoxMenu
			// 
			this->pictureBoxMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxMenu.Image")));
			this->pictureBoxMenu->Location = System::Drawing::Point(20, 20);
			this->pictureBoxMenu->Name = L"pictureBoxMenu";
			this->pictureBoxMenu->Size = System::Drawing::Size(35, 35);
			this->pictureBoxMenu->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMenu->TabIndex = 1;
			this->pictureBoxMenu->TabStop = false;
			this->pictureBoxMenu->Click += gcnew System::EventHandler(this, &Home::pictureBoxMenu_Click);
			// 
			// panelTopbar
			// 
			this->panelTopbar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panelTopbar->Controls->Add(this->pictureBoxMenu);
			this->panelTopbar->Controls->Add(this->labelAppName);
			this->panelTopbar->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelTopbar->Location = System::Drawing::Point(0, 0);
			this->panelTopbar->Name = L"panelTopbar";
			this->panelTopbar->Size = System::Drawing::Size(1001, 75);
			this->panelTopbar->TabIndex = 0;
			// 
			// pictureBoxAddProfile
			// 
			this->pictureBoxAddProfile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxAddProfile.Image")));
			this->pictureBoxAddProfile->Location = System::Drawing::Point(20, 38);
			this->pictureBoxAddProfile->Name = L"pictureBoxAddProfile";
			this->pictureBoxAddProfile->Size = System::Drawing::Size(35, 35);
			this->pictureBoxAddProfile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxAddProfile->TabIndex = 0;
			this->pictureBoxAddProfile->TabStop = false;
			this->pictureBoxAddProfile->Click += gcnew System::EventHandler(this, &Home::pictureBox2_Click);
			// 
			// pictureBoxGeneratePassword
			// 
			this->pictureBoxGeneratePassword->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxGeneratePassword.Image")));
			this->pictureBoxGeneratePassword->Location = System::Drawing::Point(20, 98);
			this->pictureBoxGeneratePassword->Name = L"pictureBoxGeneratePassword";
			this->pictureBoxGeneratePassword->Size = System::Drawing::Size(35, 35);
			this->pictureBoxGeneratePassword->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxGeneratePassword->TabIndex = 0;
			this->pictureBoxGeneratePassword->TabStop = false;
			this->pictureBoxGeneratePassword->Click += gcnew System::EventHandler(this, &Home::pictureBoxGeneratePassword_Click);
			// 
			// pictureBoxSettings
			// 
			this->pictureBoxSettings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxSettings.Image")));
			this->pictureBoxSettings->Location = System::Drawing::Point(20, 158);
			this->pictureBoxSettings->Name = L"pictureBoxSettings";
			this->pictureBoxSettings->Size = System::Drawing::Size(35, 35);
			this->pictureBoxSettings->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxSettings->TabIndex = 0;
			this->pictureBoxSettings->TabStop = false;
			this->pictureBoxSettings->Click += gcnew System::EventHandler(this, &Home::pictureBoxSettings_Click);
			// 
			// pictureBoxProfiles
			// 
			this->pictureBoxProfiles->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxProfiles.Image")));
			this->pictureBoxProfiles->Location = System::Drawing::Point(20, 278);
			this->pictureBoxProfiles->Name = L"pictureBoxProfiles";
			this->pictureBoxProfiles->Size = System::Drawing::Size(35, 35);
			this->pictureBoxProfiles->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxProfiles->TabIndex = 0;
			this->pictureBoxProfiles->TabStop = false;
			this->pictureBoxProfiles->Click += gcnew System::EventHandler(this, &Home::pictureBoxProfiles_Click);
			// 
			// panelSidebar
			// 
			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panelSidebar->Controls->Add(this->pictureBoxProfiles);
			this->panelSidebar->Controls->Add(this->pictureBoxSettings);
			this->panelSidebar->Controls->Add(this->pictureBoxGeneratePassword);
			this->panelSidebar->Controls->Add(this->pictureBoxAddProfile);
			this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSidebar->Location = System::Drawing::Point(0, 75);
			this->panelSidebar->Name = L"panelSidebar";
			this->panelSidebar->Size = System::Drawing::Size(75, 436);
			this->panelSidebar->TabIndex = 0;
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->ClientSize = System::Drawing::Size(1001, 511);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelTopbar);
			this->Name = L"Home";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pass Unite";
			this->panelContent->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->EndInit();
			this->panelTopbar->ResumeLayout(false);
			this->panelTopbar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGeneratePassword))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->EndInit();
			this->panelSidebar->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: PageProperties pageProps;

		  public: User^ user = nullptr;

	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// redirect to "Add Profile" page
		pageProps.page = 2;

		// close this window
		this->Close();
	}
	private: System::Void pictureBoxProfiles_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// redirect to "Profiles" page
		pageProps.page = 3;

		// close this window
		this->Close();
	}
	private: System::Void pictureBoxSettings_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// open Settings overlay
		PassUnite::Settings settingsOverlay(user);
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
private: System::Void pictureBoxGeneratePassword_Click(System::Object^ sender, System::EventArgs^ e)
{
	// open Generator overlay
	PassUnite::Generator generatorOverlay;
	generatorOverlay.ShowDialog();
}
private: System::Void pictureBoxMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	// open side bar
}
};
}

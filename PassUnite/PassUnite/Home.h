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
	private: System::Windows::Forms::Label^ labelAboutHeader1;
	private: System::Windows::Forms::Label^ labelAboutParagraph1;
	private: System::Windows::Forms::Label^ labelAboutParagraph2;
	private: System::Windows::Forms::Label^ labelAboutHeader2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ labelContactEmail;

	private: System::Windows::Forms::Label^ labelContactParagraph1;

	private: System::Windows::Forms::Label^ labelContactHeader1;
	private: System::Windows::Forms::Label^ labelContactParagraph2;













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
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->labelContactParagraph2 = (gcnew System::Windows::Forms::Label());
			this->labelContactEmail = (gcnew System::Windows::Forms::Label());
			this->labelContactParagraph1 = (gcnew System::Windows::Forms::Label());
			this->labelContactHeader1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->labelAboutParagraph2 = (gcnew System::Windows::Forms::Label());
			this->labelAboutHeader2 = (gcnew System::Windows::Forms::Label());
			this->labelAboutParagraph1 = (gcnew System::Windows::Forms::Label());
			this->labelAboutHeader1 = (gcnew System::Windows::Forms::Label());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelAppName = (gcnew System::Windows::Forms::Label());
			this->pictureBoxMenu = (gcnew System::Windows::Forms::PictureBox());
			this->panelTopbar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxAddProfile = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGeneratePassword = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSettings = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxProfiles = (gcnew System::Windows::Forms::PictureBox());
			this->panelSidebar = (gcnew System::Windows::Forms::Panel());
			this->panelContent->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
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
			this->panelContent->Controls->Add(this->panel4);
			this->panelContent->Controls->Add(this->panel3);
			this->panelContent->Controls->Add(this->panel1);
			this->panelContent->Controls->Add(this->panel2);
			this->panelContent->Controls->Add(this->labelTitle);
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(75, 75);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(926, 436);
			this->panelContent->TabIndex = 3;
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel4->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel4->Location = System::Drawing::Point(69, 632);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(771, 2);
			this->panel4->TabIndex = 8;
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->panel3->Controls->Add(this->labelContactParagraph2);
			this->panel3->Controls->Add(this->labelContactEmail);
			this->panel3->Controls->Add(this->labelContactParagraph1);
			this->panel3->Controls->Add(this->labelContactHeader1);
			this->panel3->Location = System::Drawing::Point(88, 688);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(738, 297);
			this->panel3->TabIndex = 7;
			// 
			// labelContactParagraph2
			// 
			this->labelContactParagraph2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelContactParagraph2->Font = (gcnew System::Drawing::Font(L"Gadugi", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelContactParagraph2->Location = System::Drawing::Point(21, 142);
			this->labelContactParagraph2->Name = L"labelContactParagraph2";
			this->labelContactParagraph2->Size = System::Drawing::Size(699, 71);
			this->labelContactParagraph2->TabIndex = 3;
			this->labelContactParagraph2->Text = L"Any reports and suggestions towards improving this app are welcome, feel free to "
				L"reach out to me by the email below!";
			this->labelContactParagraph2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelContactEmail
			// 
			this->labelContactEmail->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelContactEmail->Font = (gcnew System::Drawing::Font(L"Gadugi", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelContactEmail->Location = System::Drawing::Point(64, 213);
			this->labelContactEmail->Name = L"labelContactEmail";
			this->labelContactEmail->Size = System::Drawing::Size(620, 69);
			this->labelContactEmail->TabIndex = 2;
			this->labelContactEmail->Text = L"marcuslaguerre11@gmail.com";
			this->labelContactEmail->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelContactParagraph1
			// 
			this->labelContactParagraph1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelContactParagraph1->Font = (gcnew System::Drawing::Font(L"Gadugi", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelContactParagraph1->Location = System::Drawing::Point(25, 69);
			this->labelContactParagraph1->Name = L"labelContactParagraph1";
			this->labelContactParagraph1->Size = System::Drawing::Size(695, 71);
			this->labelContactParagraph1->TabIndex = 1;
			this->labelContactParagraph1->Text = L"Hello, my name is Marcus Laguerre and I am currently a full-time student at Full "
				L"Sail University enrolled for the Bachelor\'s of Computer Science online course.";
			this->labelContactParagraph1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelContactHeader1
			// 
			this->labelContactHeader1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelContactHeader1->Font = (gcnew System::Drawing::Font(L"Gadugi", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelContactHeader1->Location = System::Drawing::Point(64, 0);
			this->labelContactHeader1->Name = L"labelContactHeader1";
			this->labelContactHeader1->Size = System::Drawing::Size(620, 69);
			this->labelContactHeader1->TabIndex = 0;
			this->labelContactHeader1->Text = L"Contact Me";
			this->labelContactHeader1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel1->Location = System::Drawing::Point(68, 115);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(771, 2);
			this->panel1->TabIndex = 6;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->panel2->Controls->Add(this->labelAboutParagraph2);
			this->panel2->Controls->Add(this->labelAboutHeader2);
			this->panel2->Controls->Add(this->labelAboutParagraph1);
			this->panel2->Controls->Add(this->labelAboutHeader1);
			this->panel2->Location = System::Drawing::Point(24, 160);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(856, 420);
			this->panel2->TabIndex = 5;
			// 
			// labelAboutParagraph2
			// 
			this->labelAboutParagraph2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelAboutParagraph2->Font = (gcnew System::Drawing::Font(L"Gadugi", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAboutParagraph2->Location = System::Drawing::Point(60, 255);
			this->labelAboutParagraph2->Name = L"labelAboutParagraph2";
			this->labelAboutParagraph2->Size = System::Drawing::Size(742, 147);
			this->labelAboutParagraph2->TabIndex = 3;
			this->labelAboutParagraph2->Text = resources->GetString(L"labelAboutParagraph2.Text");
			this->labelAboutParagraph2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelAboutHeader2
			// 
			this->labelAboutHeader2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelAboutHeader2->Font = (gcnew System::Drawing::Font(L"Gadugi", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAboutHeader2->Location = System::Drawing::Point(64, 213);
			this->labelAboutHeader2->Name = L"labelAboutHeader2";
			this->labelAboutHeader2->Size = System::Drawing::Size(738, 69);
			this->labelAboutHeader2->TabIndex = 2;
			this->labelAboutHeader2->Text = L"Why Use Pass Unite\?";
			this->labelAboutHeader2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelAboutParagraph1
			// 
			this->labelAboutParagraph1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelAboutParagraph1->Font = (gcnew System::Drawing::Font(L"Gadugi", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAboutParagraph1->Location = System::Drawing::Point(64, 44);
			this->labelAboutParagraph1->Name = L"labelAboutParagraph1";
			this->labelAboutParagraph1->Size = System::Drawing::Size(738, 169);
			this->labelAboutParagraph1->TabIndex = 1;
			this->labelAboutParagraph1->Text = resources->GetString(L"labelAboutParagraph1.Text");
			this->labelAboutParagraph1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelAboutHeader1
			// 
			this->labelAboutHeader1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelAboutHeader1->Font = (gcnew System::Drawing::Font(L"Gadugi", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAboutHeader1->Location = System::Drawing::Point(64, 0);
			this->labelAboutHeader1->Name = L"labelAboutHeader1";
			this->labelAboutHeader1->Size = System::Drawing::Size(738, 69);
			this->labelAboutHeader1->TabIndex = 0;
			this->labelAboutHeader1->Text = L"About Pass Unite";
			this->labelAboutHeader1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"MoeumT R", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->labelTitle->Location = System::Drawing::Point(6, 5);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(874, 116);
			this->labelTitle->TabIndex = 3;
			this->labelTitle->Text = L"Welcome to Pass Unite";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
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

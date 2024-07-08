#pragma once
#include "PageProperties.h"
#include "User.h"
#include "Settings.h"
#include "Profiles.h"
#include <vector>

namespace PassUnite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Profiles
	/// </summary>
	public ref class ProfilesForm : public System::Windows::Forms::Form
	{
	public:
		ProfilesForm(User^ _user, Profiles^ _profile, int _profileCount)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			profile = _profile;

			// while there's an unchecked profile, continue
			while (profile->prev != nullptr)
			{
				// if this is the first check, just update the existing labels
				if (profile->next == nullptr)
				{
					labelProfileWebsite1->Text = profile->website;
					labelProfileUsername1->Text = profile->username;
					labelProfilePassword1->Text = profile->password;
				}
				else
				{
					// move existing slots down
					
				}

				// move back one profile
				profile = profile->prev;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProfilesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelSidebar;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBoxMenu;
	private: System::Windows::Forms::PictureBox^ pictureBoxProfiles;
	private: System::Windows::Forms::PictureBox^ pictureBoxSettings;
	private: System::Windows::Forms::PictureBox^ pictureBoxGeneratePassword;
	private: System::Windows::Forms::PictureBox^ pictureBoxAddProfile;
	private: System::Windows::Forms::Panel^ panelTopbar;
	private: System::Windows::Forms::Label^ labelAppName;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Panel^ panelSeperationLine1;
	private: System::Windows::Forms::Label^ labelColumnWebsite;
	private: System::Windows::Forms::Label^ labelColumnUsernames;
	private: System::Windows::Forms::Label^ labelColumnPasswords;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ labelProfilePassword1;

	private: System::Windows::Forms::Label^ labelProfileUsername1;

	private: System::Windows::Forms::Label^ labelProfileWebsite1;








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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProfilesForm::typeid));
			this->panelSidebar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxMenu = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxProfiles = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSettings = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGeneratePassword = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAddProfile = (gcnew System::Windows::Forms::PictureBox());
			this->panelTopbar = (gcnew System::Windows::Forms::Panel());
			this->labelAppName = (gcnew System::Windows::Forms::Label());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panelSeperationLine1 = (gcnew System::Windows::Forms::Panel());
			this->labelColumnWebsite = (gcnew System::Windows::Forms::Label());
			this->labelColumnUsernames = (gcnew System::Windows::Forms::Label());
			this->labelColumnPasswords = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword1 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername1 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite1 = (gcnew System::Windows::Forms::Label());
			this->panelSidebar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGeneratePassword))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->BeginInit();
			this->panelTopbar->SuspendLayout();
			this->panel1->SuspendLayout();
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
			this->panelSidebar->Location = System::Drawing::Point(0, -1);
			this->panelSidebar->Name = L"panelSidebar";
			this->panelSidebar->Size = System::Drawing::Size(75, 515);
			this->panelSidebar->TabIndex = 7;
			// 
			// pictureBoxMenu
			// 
			this->pictureBoxMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxMenu.Image")));
			this->pictureBoxMenu->Location = System::Drawing::Point(20, 21);
			this->pictureBoxMenu->Name = L"pictureBoxMenu";
			this->pictureBoxMenu->Size = System::Drawing::Size(35, 35);
			this->pictureBoxMenu->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMenu->TabIndex = 1;
			this->pictureBoxMenu->TabStop = false;
			// 
			// pictureBoxProfiles
			// 
			this->pictureBoxProfiles->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxProfiles.Image")));
			this->pictureBoxProfiles->Location = System::Drawing::Point(20, 351);
			this->pictureBoxProfiles->Name = L"pictureBoxProfiles";
			this->pictureBoxProfiles->Size = System::Drawing::Size(35, 35);
			this->pictureBoxProfiles->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxProfiles->TabIndex = 0;
			this->pictureBoxProfiles->TabStop = false;
			this->pictureBoxProfiles->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxProfiles_Click);
			// 
			// pictureBoxSettings
			// 
			this->pictureBoxSettings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxSettings.Image")));
			this->pictureBoxSettings->Location = System::Drawing::Point(20, 231);
			this->pictureBoxSettings->Name = L"pictureBoxSettings";
			this->pictureBoxSettings->Size = System::Drawing::Size(35, 35);
			this->pictureBoxSettings->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxSettings->TabIndex = 0;
			this->pictureBoxSettings->TabStop = false;
			this->pictureBoxSettings->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxSettings_Click);
			// 
			// pictureBoxGeneratePassword
			// 
			this->pictureBoxGeneratePassword->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxGeneratePassword.Image")));
			this->pictureBoxGeneratePassword->Location = System::Drawing::Point(20, 171);
			this->pictureBoxGeneratePassword->Name = L"pictureBoxGeneratePassword";
			this->pictureBoxGeneratePassword->Size = System::Drawing::Size(35, 35);
			this->pictureBoxGeneratePassword->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxGeneratePassword->TabIndex = 0;
			this->pictureBoxGeneratePassword->TabStop = false;
			// 
			// pictureBoxAddProfile
			// 
			this->pictureBoxAddProfile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxAddProfile.Image")));
			this->pictureBoxAddProfile->Location = System::Drawing::Point(20, 111);
			this->pictureBoxAddProfile->Name = L"pictureBoxAddProfile";
			this->pictureBoxAddProfile->Size = System::Drawing::Size(35, 35);
			this->pictureBoxAddProfile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxAddProfile->TabIndex = 0;
			this->pictureBoxAddProfile->TabStop = false;
			this->pictureBoxAddProfile->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxAddProfile_Click);
			// 
			// panelTopbar
			// 
			this->panelTopbar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelTopbar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panelTopbar->Controls->Add(this->labelAppName);
			this->panelTopbar->Location = System::Drawing::Point(0, -1);
			this->panelTopbar->Name = L"panelTopbar";
			this->panelTopbar->Size = System::Drawing::Size(985, 75);
			this->panelTopbar->TabIndex = 8;
			// 
			// labelAppName
			// 
			this->labelAppName->AutoSize = true;
			this->labelAppName->Font = (gcnew System::Drawing::Font(L"Yet R", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->labelAppName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(135)));
			this->labelAppName->Location = System::Drawing::Point(100, 24);
			this->labelAppName->Name = L"labelAppName";
			this->labelAppName->Size = System::Drawing::Size(152, 28);
			this->labelAppName->TabIndex = 0;
			this->labelAppName->Text = L"Pass Unite";
			this->labelAppName->Click += gcnew System::EventHandler(this, &ProfilesForm::labelAppName_Click);
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(77, 77);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(904, 104);
			this->labelTitle->TabIndex = 9;
			this->labelTitle->Text = L"Profiles";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panelSeperationLine1
			// 
			this->panelSeperationLine1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelSeperationLine1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panelSeperationLine1->Location = System::Drawing::Point(168, 177);
			this->panelSeperationLine1->Name = L"panelSeperationLine1";
			this->panelSeperationLine1->Size = System::Drawing::Size(715, 2);
			this->panelSeperationLine1->TabIndex = 10;
			// 
			// labelColumnWebsite
			// 
			this->labelColumnWebsite->AutoSize = true;
			this->labelColumnWebsite->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelColumnWebsite->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->labelColumnWebsite->Location = System::Drawing::Point(115, 191);
			this->labelColumnWebsite->Name = L"labelColumnWebsite";
			this->labelColumnWebsite->Size = System::Drawing::Size(137, 29);
			this->labelColumnWebsite->TabIndex = 11;
			this->labelColumnWebsite->Text = L"WEBSITES";
			// 
			// labelColumnUsernames
			// 
			this->labelColumnUsernames->AutoSize = true;
			this->labelColumnUsernames->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelColumnUsernames->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->labelColumnUsernames->Location = System::Drawing::Point(448, 191);
			this->labelColumnUsernames->Name = L"labelColumnUsernames";
			this->labelColumnUsernames->Size = System::Drawing::Size(164, 29);
			this->labelColumnUsernames->TabIndex = 11;
			this->labelColumnUsernames->Text = L"USERNAMES";
			// 
			// labelColumnPasswords
			// 
			this->labelColumnPasswords->AutoSize = true;
			this->labelColumnPasswords->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelColumnPasswords->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->labelColumnPasswords->Location = System::Drawing::Point(783, 191);
			this->labelColumnPasswords->Name = L"labelColumnPasswords";
			this->labelColumnPasswords->Size = System::Drawing::Size(167, 29);
			this->labelColumnPasswords->TabIndex = 11;
			this->labelColumnPasswords->Text = L"PASSWORDS";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel1->Controls->Add(this->labelProfilePassword1);
			this->panel1->Controls->Add(this->labelProfileUsername1);
			this->panel1->Controls->Add(this->labelProfileWebsite1);
			this->panel1->Location = System::Drawing::Point(84, 236);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(888, 48);
			this->panel1->TabIndex = 12;
			// 
			// labelProfilePassword1
			// 
			this->labelProfilePassword1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword1->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword1->Location = System::Drawing::Point(597, 0);
			this->labelProfilePassword1->Name = L"labelProfilePassword1";
			this->labelProfilePassword1->Size = System::Drawing::Size(262, 48);
			this->labelProfilePassword1->TabIndex = 0;
			this->labelProfilePassword1->Text = L"empty";
			this->labelProfilePassword1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelProfileUsername1
			// 
			this->labelProfileUsername1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername1->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername1->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername1->Name = L"labelProfileUsername1";
			this->labelProfileUsername1->Size = System::Drawing::Size(288, 48);
			this->labelProfileUsername1->TabIndex = 0;
			this->labelProfileUsername1->Text = L"empty";
			this->labelProfileUsername1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite1
			// 
			this->labelProfileWebsite1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileWebsite1->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite1->Location = System::Drawing::Point(13, 0);
			this->labelProfileWebsite1->Name = L"labelProfileWebsite1";
			this->labelProfileWebsite1->Size = System::Drawing::Size(284, 48);
			this->labelProfileWebsite1->TabIndex = 0;
			this->labelProfileWebsite1->Text = L"empty";
			this->labelProfileWebsite1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ProfilesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->ClientSize = System::Drawing::Size(984, 511);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->labelColumnPasswords);
			this->Controls->Add(this->labelColumnUsernames);
			this->Controls->Add(this->labelColumnWebsite);
			this->Controls->Add(this->panelSeperationLine1);
			this->Controls->Add(this->labelTitle);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelTopbar);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"ProfilesForm";
			this->Text = L"Profiles";
			this->panelSidebar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGeneratePassword))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->EndInit();
			this->panelTopbar->ResumeLayout(false);
			this->panelTopbar->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: PageProperties pageProps;

	public: Profiles^ profile = nullptr;

	private: System::Void labelAppName_Click(System::Object^ sender, System::EventArgs^ e) {
		// redirect to "Home" page
		pageProps.page = 1;

		// close window
		this->Close();
	}
	private: System::Void pictureBoxAddProfile_Click(System::Object^ sender, System::EventArgs^ e) {
		// redirect to "AddProfiles" page
		pageProps.page = 2;

		// close window
		this->Close();
	}
	private: System::Void pictureBoxSettings_Click(System::Object^ sender, System::EventArgs^ e) {
		// open "Settings" overlay
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
	private: System::Void pictureBoxProfiles_Click(System::Object^ sender, System::EventArgs^ e) {
		// redirect to "Profiles" page
		pageProps.page = 3;

		// close window
		this->Close();
	}
	};
}

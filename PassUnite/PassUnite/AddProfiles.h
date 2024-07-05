#pragma once
#include "PageProperties.h"
#include "Profiles.h"
#include "Settings.h"
#include "ProfilesForm.h"

namespace PassUnite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddProfiles
	/// </summary>
	public ref class AddProfiles : public System::Windows::Forms::Form
	{
	public:
		AddProfiles(void)
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
		~AddProfiles()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxWebsite;
	protected:

	protected:
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Panel^ panelSidebar;
	private: System::Windows::Forms::PictureBox^ pictureBoxMenu;
	private: System::Windows::Forms::PictureBox^ pictureBoxProfiles;


	private: System::Windows::Forms::PictureBox^ pictureBoxSettings;
	private: System::Windows::Forms::PictureBox^ pictureBoxGeneratePassword;



	private: System::Windows::Forms::PictureBox^ pictureBoxAddProfile;


	private: System::Windows::Forms::Panel^ panelTopbar;
	private: System::Windows::Forms::Label^ labelAppName;
	private: System::Windows::Forms::Label^ labelWebsite;
	private: System::Windows::Forms::TextBox^ textBoxUsername;

	private: System::Windows::Forms::Label^ labelUsername;
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::Button^ buttonGen;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingPass;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowingPass;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddProfiles::typeid));
			this->textBoxWebsite = (gcnew System::Windows::Forms::TextBox());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panelSidebar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxMenu = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxProfiles = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSettings = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGeneratePassword = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAddProfile = (gcnew System::Windows::Forms::PictureBox());
			this->panelTopbar = (gcnew System::Windows::Forms::Panel());
			this->labelAppName = (gcnew System::Windows::Forms::Label());
			this->labelWebsite = (gcnew System::Windows::Forms::Label());
			this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->labelUsername = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->buttonGen = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->pictureBoxHidingPass = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowingPass = (gcnew System::Windows::Forms::PictureBox());
			this->panelSidebar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGeneratePassword))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->BeginInit();
			this->panelTopbar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingPass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingPass))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxWebsite
			// 
			this->textBoxWebsite->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxWebsite->Location = System::Drawing::Point(484, 229);
			this->textBoxWebsite->Name = L"textBoxWebsite";
			this->textBoxWebsite->Size = System::Drawing::Size(316, 38);
			this->textBoxWebsite->TabIndex = 0;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"MoeumT R", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->labelTitle->Location = System::Drawing::Point(81, 76);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(904, 124);
			this->labelTitle->TabIndex = 4;
			this->labelTitle->Text = L"Add a Profile";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->panelSidebar->TabIndex = 5;
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
			this->pictureBoxProfiles->Click += gcnew System::EventHandler(this, &AddProfiles::pictureBoxProfiles_Click);
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
			this->pictureBoxSettings->Click += gcnew System::EventHandler(this, &AddProfiles::pictureBoxSettings_Click);
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
			this->panelTopbar->TabIndex = 6;
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
			this->labelAppName->Click += gcnew System::EventHandler(this, &AddProfiles::labelAppName_Click);
			// 
			// labelWebsite
			// 
			this->labelWebsite->AutoSize = true;
			this->labelWebsite->Location = System::Drawing::Point(290, 232);
			this->labelWebsite->Name = L"labelWebsite";
			this->labelWebsite->Size = System::Drawing::Size(128, 31);
			this->labelWebsite->TabIndex = 7;
			this->labelWebsite->Text = L"Webstite:";
			// 
			// textBoxUsername
			// 
			this->textBoxUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxUsername->Location = System::Drawing::Point(484, 297);
			this->textBoxUsername->Name = L"textBoxUsername";
			this->textBoxUsername->Size = System::Drawing::Size(316, 38);
			this->textBoxUsername->TabIndex = 1;
			// 
			// labelUsername
			// 
			this->labelUsername->AutoSize = true;
			this->labelUsername->Location = System::Drawing::Point(290, 300);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(147, 31);
			this->labelUsername->TabIndex = 7;
			this->labelUsername->Text = L"Username:";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxPassword->Location = System::Drawing::Point(484, 345);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(316, 38);
			this->textBoxPassword->TabIndex = 2;
			this->textBoxPassword->UseSystemPasswordChar = true;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Location = System::Drawing::Point(290, 348);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(142, 31);
			this->labelPassword->TabIndex = 7;
			this->labelPassword->Text = L"Password:";
			// 
			// buttonGen
			// 
			this->buttonGen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->buttonGen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonGen->ForeColor = System::Drawing::Color::Black;
			this->buttonGen->Location = System::Drawing::Point(608, 389);
			this->buttonGen->Name = L"buttonGen";
			this->buttonGen->Size = System::Drawing::Size(90, 28);
			this->buttonGen->TabIndex = 4;
			this->buttonGen->Text = L"Generate";
			this->buttonGen->UseVisualStyleBackColor = false;
			// 
			// buttonAdd
			// 
			this->buttonAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAdd->ForeColor = System::Drawing::Color::White;
			this->buttonAdd->Location = System::Drawing::Point(710, 389);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(90, 28);
			this->buttonAdd->TabIndex = 3;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = false;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &AddProfiles::buttonAdd_Click);
			// 
			// pictureBoxHidingPass
			// 
			this->pictureBoxHidingPass->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingPass.Image")));
			this->pictureBoxHidingPass->Location = System::Drawing::Point(808, 353);
			this->pictureBoxHidingPass->Name = L"pictureBoxHidingPass";
			this->pictureBoxHidingPass->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingPass->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingPass->TabIndex = 9;
			this->pictureBoxHidingPass->TabStop = false;
			this->pictureBoxHidingPass->Click += gcnew System::EventHandler(this, &AddProfiles::pictureBoxHidingPass_Click);
			// 
			// pictureBoxShowingPass
			// 
			this->pictureBoxShowingPass->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingPass.Image")));
			this->pictureBoxShowingPass->Location = System::Drawing::Point(808, 353);
			this->pictureBoxShowingPass->Name = L"pictureBoxShowingPass";
			this->pictureBoxShowingPass->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingPass->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingPass->TabIndex = 9;
			this->pictureBoxShowingPass->TabStop = false;
			this->pictureBoxShowingPass->Visible = false;
			this->pictureBoxShowingPass->Click += gcnew System::EventHandler(this, &AddProfiles::pictureBoxShowingPass_Click);
			// 
			// AddProfiles
			// 
			this->AcceptButton = this->buttonAdd;
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->ClientSize = System::Drawing::Size(984, 511);
			this->Controls->Add(this->pictureBoxShowingPass);
			this->Controls->Add(this->pictureBoxHidingPass);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->buttonGen);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->labelUsername);
			this->Controls->Add(this->labelWebsite);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelTopbar);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->labelTitle);
			this->Controls->Add(this->textBoxUsername);
			this->Controls->Add(this->textBoxWebsite);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(8);
			this->Name = L"AddProfiles";
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingPass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingPass))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: PageProperties pageProps;

	public: Profiles profile;

	private: System::Void labelAppName_Click(System::Object^ sender, System::EventArgs^ e) {
		// redirect to "Home"
		pageProps.page = 1;

		// close this window
		this->Close();
	}
	private: System::Void pictureBoxHidingPass_Click(System::Object^ sender, System::EventArgs^ e) {
		// hide current image
		pictureBoxHidingPass->Visible = false;

		// show other image
		pictureBoxShowingPass->Visible = true;

		// show password
		textBoxPassword->UseSystemPasswordChar = false;
	}
	private: System::Void pictureBoxShowingPass_Click(System::Object^ sender, System::EventArgs^ e) {
		// hide current image
		pictureBoxShowingPass->Visible = false;

		// show "show password" image
		pictureBoxHidingPass->Visible = true;

		// hide password
		textBoxPassword->UseSystemPasswordChar = true;
	}
	private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {

		// check if all fields are empty
		if (textBoxWebsite->Text == "" && textBoxUsername->Text == "" && textBoxPassword->Text == "")
		{
			// prompt the user to input into the fields
			MessageBox::Show("Please enter info in one of the fields before attempting to add a profile",
				"All Fields Empty", MessageBoxButtons::OK);

			// exit function
			return;
		}

		// save user input
		profile.website = textBoxWebsite->Text;
		profile.username = textBoxUsername->Text;
		profile.password = textBoxPassword->Text;

		// clear textboxes
		textBoxWebsite->Text = "";
		textBoxUsername->Text = "";
		textBoxPassword->Text = "";

		// prevent redirecting
		pageProps.page = 2;

		// simulate refreshing the screen
		this->Close();
	}
	private: System::Void pictureBoxProfiles_Click(System::Object^ sender, System::EventArgs^ e) {
		// redirect to "Profiles" page
		pageProps.page = 3;

		// close this window
		this->Close();
	}
private: System::Void pictureBoxSettings_Click(System::Object^ sender, System::EventArgs^ e) {
	// show "Settings" overlay
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

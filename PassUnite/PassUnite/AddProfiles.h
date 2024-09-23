#pragma once
#include "PageProperties.h"
#include "Profiles.h"
#include "Generator.h"
#include "Settings.h"
#include "ProfilesForm.h"
#include "User.h"

namespace PassUnite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for AddProfiles
	/// </summary>
	public ref class AddProfiles : public System::Windows::Forms::Form
	{
	public:
		AddProfiles(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->user = user;		// user holding logged in user's id

			profileCount = 0;		// number of saved profiles

			// create profile node list based on database
			try
			{
				String^ connString = "Data Source=localhost;Initial Catalog=passuniteusers;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
				SqlConnection sqlConn(connString);
				sqlConn.Open();

				// first read
				String^ sqlQuery = "SELECT * FROM profiles " +
					"WHERE accountid=@id";

				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@id", user->id);

				SqlDataReader^ reader = command.ExecuteReader();
				if (reader->Read())
				{
					// create blank profile
					profile = gcnew Profiles();

					profile->id = profileCount + 1;

					// Website
					try
					{
						profile->website = reader->GetString(1);			// assign read value for website
					}
					catch (System::Data::SqlTypes::SqlNullValueException^)
					{
						// leave blank (do nothing) " - "
						profile->website = "-";								// if null, assign " - "
					}
					// Username
					try
					{
						profile->username = reader->GetString(2);			// assign read value for username
					}
					catch (System::Data::SqlTypes::SqlNullValueException^)
					{
						// leave blank
						profile->username = "-";
					}
					// Password
					try
					{
						profile->password = reader->GetString(3);			// assign read value for password
					}
					catch (System::Data::SqlTypes::SqlNullValueException^)
					{
						// leave blank
						profile->password = "-";
					}

					profileCount++;
				}
				else		// no saved profiles
					return;

				// nth read after first			// adjust this loop: duplicate websites, usernames, passwords allowed BUT all 3 must not be true
												// don't have to check password if website & username are the same (websites don't allow duplicate users)
												// if website & username are empty, check the password
				while (true)
				{
					sqlQuery += " AND NOT website='" + profile->website + "'" +
						" AND NOT profileUser='" + profile->username + "'" +
						" AND NOT profilePass='" + profile->password + "'";

					if (reader->Read())
					{
						// create blank profile
						nextProfile = gcnew Profiles();

						nextProfile->id = profileCount + 1;

						// Website
						try
						{
							nextProfile->website = reader->GetString(1);			// assign read value for website
						}
						catch (System::Data::SqlTypes::SqlNullValueException^)
						{
							// leave blank (do nothing) " - "
							nextProfile->website = "-";								// if null, assign " - "
						}
						// Username
						try
						{
							nextProfile->username = reader->GetString(2);			// assign read value for username
						}
						catch (System::Data::SqlTypes::SqlNullValueException^)
						{
							// leave blank
							nextProfile->username = "-";
						}
						// Password
						try
						{
							nextProfile->password = reader->GetString(3);			// assign read value for password
						}
						catch (System::Data::SqlTypes::SqlNullValueException^)
						{
							// leave blank
							nextProfile->password = "-";
						}

						profileCount++;
					}
					else
					{
						break;
					}

					// assign connection
					profile->next = nextProfile;
					nextProfile->prev = profile;
					// move to last saved profile
					profile = profile->next;
				}

				// close connection
				sqlConn.Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);		// for troubleshooting
			}
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

	protected:

	protected:


























	private: System::Windows::Forms::Panel^ panelSidebar;
	private: System::Windows::Forms::PictureBox^ pictureBoxProfiles;
	private: System::Windows::Forms::PictureBox^ pictureBoxSettings;
	private: System::Windows::Forms::PictureBox^ pictureBoxGeneratePassword;
	private: System::Windows::Forms::PictureBox^ pictureBoxAddProfile;
	private: System::Windows::Forms::Panel^ panelTopbar;
	private: System::Windows::Forms::PictureBox^ pictureBoxMenu;
	private: System::Windows::Forms::Label^ labelAppName;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowingPass;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingPass;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonGen;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::Label^ labelUsername;
	private: System::Windows::Forms::Label^ labelWebsite;
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::TextBox^ textBoxUsername;
	private: System::Windows::Forms::TextBox^ textBoxWebsite;
























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
			this->panelSidebar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxProfiles = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSettings = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGeneratePassword = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAddProfile = (gcnew System::Windows::Forms::PictureBox());
			this->panelTopbar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxMenu = (gcnew System::Windows::Forms::PictureBox());
			this->labelAppName = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxShowingPass = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingPass = (gcnew System::Windows::Forms::PictureBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonGen = (gcnew System::Windows::Forms::Button());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->labelUsername = (gcnew System::Windows::Forms::Label());
			this->labelWebsite = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWebsite = (gcnew System::Windows::Forms::TextBox());
			this->panelSidebar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGeneratePassword))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->BeginInit();
			this->panelTopbar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingPass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingPass))->BeginInit();
			this->SuspendLayout();
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
			this->panelSidebar->TabIndex = 10;
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
			this->pictureBoxProfiles->Click += gcnew System::EventHandler(this, &AddProfiles::pictureBoxProfiles_Click);
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
			this->pictureBoxSettings->Click += gcnew System::EventHandler(this, &AddProfiles::pictureBoxSettings_Click);
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
			this->pictureBoxGeneratePassword->Click += gcnew System::EventHandler(this, &AddProfiles::pictureBoxGeneratePassword_Click);
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
			this->panelTopbar->Size = System::Drawing::Size(984, 75);
			this->panelTopbar->TabIndex = 11;
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
			this->labelAppName->Click += gcnew System::EventHandler(this, &AddProfiles::labelAppName_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBoxShowingPass);
			this->panel1->Controls->Add(this->pictureBoxHidingPass);
			this->panel1->Controls->Add(this->buttonAdd);
			this->panel1->Controls->Add(this->buttonGen);
			this->panel1->Controls->Add(this->labelPassword);
			this->panel1->Controls->Add(this->labelUsername);
			this->panel1->Controls->Add(this->labelWebsite);
			this->panel1->Controls->Add(this->textBoxPassword);
			this->panel1->Controls->Add(this->labelTitle);
			this->panel1->Controls->Add(this->textBoxUsername);
			this->panel1->Controls->Add(this->textBoxWebsite);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(75, 75);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(909, 436);
			this->panel1->TabIndex = 12;
			// 
			// pictureBoxShowingPass
			// 
			this->pictureBoxShowingPass->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingPass->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingPass.Image")));
			this->pictureBoxShowingPass->Location = System::Drawing::Point(708, 267);
			this->pictureBoxShowingPass->Name = L"pictureBoxShowingPass";
			this->pictureBoxShowingPass->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingPass->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingPass->TabIndex = 19;
			this->pictureBoxShowingPass->TabStop = false;
			this->pictureBoxShowingPass->Visible = false;
			this->pictureBoxShowingPass->Click += gcnew System::EventHandler(this, &AddProfiles::pictureBoxShowingPass_Click);
			// 
			// pictureBoxHidingPass
			// 
			this->pictureBoxHidingPass->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingPass->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingPass.Image")));
			this->pictureBoxHidingPass->Location = System::Drawing::Point(708, 267);
			this->pictureBoxHidingPass->Name = L"pictureBoxHidingPass";
			this->pictureBoxHidingPass->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingPass->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingPass->TabIndex = 20;
			this->pictureBoxHidingPass->TabStop = false;
			this->pictureBoxHidingPass->Click += gcnew System::EventHandler(this, &AddProfiles::pictureBoxHidingPass_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->buttonAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAdd->ForeColor = System::Drawing::Color::White;
			this->buttonAdd->Location = System::Drawing::Point(610, 303);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(90, 28);
			this->buttonAdd->TabIndex = 13;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = false;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &AddProfiles::buttonAdd_Click);
			// 
			// buttonGen
			// 
			this->buttonGen->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->buttonGen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->buttonGen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonGen->ForeColor = System::Drawing::Color::Black;
			this->buttonGen->Location = System::Drawing::Point(508, 303);
			this->buttonGen->Name = L"buttonGen";
			this->buttonGen->Size = System::Drawing::Size(90, 28);
			this->buttonGen->TabIndex = 14;
			this->buttonGen->Text = L"Generate";
			this->buttonGen->UseVisualStyleBackColor = false;
			this->buttonGen->Visible = false;
			// 
			// labelPassword
			// 
			this->labelPassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelPassword->AutoSize = true;
			this->labelPassword->Location = System::Drawing::Point(190, 262);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(142, 31);
			this->labelPassword->TabIndex = 16;
			this->labelPassword->Text = L"Password:";
			// 
			// labelUsername
			// 
			this->labelUsername->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelUsername->AutoSize = true;
			this->labelUsername->Location = System::Drawing::Point(190, 214);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(147, 31);
			this->labelUsername->TabIndex = 17;
			this->labelUsername->Text = L"Username:";
			// 
			// labelWebsite
			// 
			this->labelWebsite->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelWebsite->AutoSize = true;
			this->labelWebsite->Location = System::Drawing::Point(190, 146);
			this->labelWebsite->Name = L"labelWebsite";
			this->labelWebsite->Size = System::Drawing::Size(128, 31);
			this->labelWebsite->TabIndex = 18;
			this->labelWebsite->Text = L"Webstite:";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->textBoxPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxPassword->Location = System::Drawing::Point(384, 259);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(316, 38);
			this->textBoxPassword->TabIndex = 12;
			this->textBoxPassword->UseSystemPasswordChar = true;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"MoeumT R", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->labelTitle->Location = System::Drawing::Point(3, 3);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(904, 124);
			this->labelTitle->TabIndex = 15;
			this->labelTitle->Text = L"Add a Profile";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBoxUsername
			// 
			this->textBoxUsername->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->textBoxUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxUsername->Location = System::Drawing::Point(384, 211);
			this->textBoxUsername->Name = L"textBoxUsername";
			this->textBoxUsername->Size = System::Drawing::Size(316, 38);
			this->textBoxUsername->TabIndex = 11;
			// 
			// textBoxWebsite
			// 
			this->textBoxWebsite->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->textBoxWebsite->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxWebsite->Location = System::Drawing::Point(384, 143);
			this->textBoxWebsite->Name = L"textBoxWebsite";
			this->textBoxWebsite->Size = System::Drawing::Size(316, 38);
			this->textBoxWebsite->TabIndex = 10;
			// 
			// AddProfiles
			// 
			this->AcceptButton = this->buttonAdd;
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->ClientSize = System::Drawing::Size(984, 511);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelTopbar);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(8);
			this->Name = L"AddProfiles";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pass Unite";
			this->panelSidebar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGeneratePassword))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->EndInit();
			this->panelTopbar->ResumeLayout(false);
			this->panelTopbar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingPass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingPass))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: PageProperties pageProps;

	public: User^ user = nullptr;

	public: int profileCount;
	public: Profiles^ profile = nullptr;
		  Profiles^ nextProfile = nullptr;

		  String^ website;
		  String^ username;
		  String^ password;

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
		website = textBoxWebsite->Text;
		username = textBoxUsername->Text;
		password = textBoxPassword->Text;

		// clear textboxes
		textBoxWebsite->Text = "";
		textBoxUsername->Text = "";
		textBoxPassword->Text = "";

		// insert new profile in profiles table
		try
		{
			// connect to database
			String^ connString = "Data Source=localhost;Initial Catalog=passuniteusers;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// build sql query
			String^ sqlQuery = "INSERT INTO profiles " +
				"(accountid";

			// columns and values
			{
				// COLUMNS
				if (website != "")
					sqlQuery += ", website";

				if (username != "")
					sqlQuery += ", profileUser";

				if (password != "")
					sqlQuery += ", profilePass) VALUES (@id";
				else
					sqlQuery += ") VALUES (@id";

				// VALUES
				if (website != "")
					sqlQuery += ", @web";

				if (username != "")
					sqlQuery += ", @user";

				if (password != "")
					sqlQuery += ", @pass);";
				else
					sqlQuery += ");";
			}

			// swap placeholders with variables
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@id", user->id);
			command.Parameters->AddWithValue("@web", website);
			command.Parameters->AddWithValue("@user", username);
			command.Parameters->AddWithValue("@pass", password);

			command.ExecuteNonQuery();

			// close connection
			sqlConn.Close();
		}
		catch (Exception^ ex)
		{
			//MessageBox::Show(ex->Message);		// for troubleshooting
			MessageBox::Show("Failed to connect to database",
				"Database Connection Error", MessageBoxButtons::OK);
		}

		// check if this is first profile in node
		if (profile == nullptr)
		{
			// assign values to first profile
			profile = gcnew Profiles();
			profile->website = website;
			profile->username = username;
			profile->password = password;
		}
		else
		{
			// create next profile
			nextProfile = gcnew Profiles();
			// assign values to next profile
			nextProfile->website = website;
			nextProfile->username = username;
			nextProfile->password = password;

			// set node connections
			profile->next = nextProfile;
			nextProfile->prev = profile;

			// move to last saved profile
			profile = profile->next;
		}

		// simulate refreshing the screen
		textBoxWebsite->Text = "";
		textBoxUsername->Text = "";
		textBoxPassword->Text = "";
	}
	private: System::Void pictureBoxProfiles_Click(System::Object^ sender, System::EventArgs^ e) {
		// redirect to "Profiles" page
		pageProps.page = 3;

		// close this window
		this->Close();
	}
	private: System::Void pictureBoxSettings_Click(System::Object^ sender, System::EventArgs^ e) {
		// show "Settings" overlay
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
	private: System::Void pictureBoxGeneratePassword_Click(System::Object^ sender, System::EventArgs^ e) {
		// open Generator overlay
		PassUnite::Generator generatorOverlay;
		generatorOverlay.ShowDialog();

		textBoxPassword->Text = generatorOverlay.randString;
	}
};
}

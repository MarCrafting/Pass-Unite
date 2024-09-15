#pragma once
#include "PageProperties.h"
#include "User.h"
#include "Generator.h"
#include "Settings.h"
#include "Profiles.h"
#include "Panels.h"

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
			user = _user;
			profile = _profile;
			profileCount = _profileCount;

			// save panels into a list in order to access them
			// Panel 1
			Panels^ panel = gcnew Panels();							// create pointer
			panel->panel = panel1;									// assign pointer to panel1
			panel->labelProfileWebsite = labelProfileWebsite1;		// assign website label
			panel->labelProfileUsername = labelProfileUsername1;	// assign username label
			panel->labelProfilePassword = labelProfilePassword1;	// assign password label
			// Panel 2
			Panels^ nextPanel = gcnew Panels();						// create pointer
			nextPanel->panel = panel2;								// assign pointer to panel2
			nextPanel->panel->Visible = false;						// hide panel by default
			nextPanel->labelProfileWebsite = labelProfileWebsite2;	// assign website label
			nextPanel->labelProfileUsername = labelProfileUsername2;// assign username label
			nextPanel->labelProfilePassword = labelProfilePassword2;// assign password label
			// Link Panel 1 & 2
			panel->next = nextPanel;								// create link between pointers
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 3
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel3;								// assign pointer to panel3
			nextPanel->panel->Visible = false;						// hide panel by default
			nextPanel->labelProfileWebsite = labelProfileWebsite3;	// assign website label
			nextPanel->labelProfileUsername = labelProfileUsername3;// assign username label
			nextPanel->labelProfilePassword = labelProfilePassword3;// assign password label
			// Link Panel 2 & 3
			panel->next = nextPanel;
			nextPanel->prev = panel;								// create link between pointers

			panel = nextPanel;										// traverse through node list
			// Panel 4
			nextPanel = gcnew Panels();								// create a pointer
			nextPanel->panel = panel4;								// assign pointer to panel4
			nextPanel->panel->Visible = false;						// hide panel by default
			nextPanel->labelProfileWebsite = labelProfileWebsite4;	// assign website label
			nextPanel->labelProfileUsername = labelProfileUsername4;// assign username label
			nextPanel->labelProfilePassword = labelProfilePassword4;// assign password label
			// Link Panel 3 & 4
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 5
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel5;								// assign pointer to panel5
			nextPanel->panel->Visible = false;						// hide by default
			nextPanel->labelProfileWebsite = labelProfileWebsite5;	// assign website label
			nextPanel->labelProfileUsername = labelProfileUsername5;// assign username label
			nextPanel->labelProfilePassword = labelProfilePassword5;// assign password label
			// Link Panel 4 & 5
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 6
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel6;								// assign pointer to panel6
			nextPanel->panel->Visible = false;						// hide panel by default
			nextPanel->labelProfileWebsite = labelProfileWebsite6;	// assign website label
			nextPanel->labelProfileUsername = labelProfileUsername6;// assign username label
			nextPanel->labelProfilePassword = labelProfilePassword6;// assign password label
			// Link Panel 5 & 6
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 7
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel7;								// assign pointer to panel7
			nextPanel->panel->Visible = false;						// hide by default
			nextPanel->labelProfileWebsite = labelProfileWebsite7;	// assign website label
			nextPanel->labelProfileUsername = labelProfileUsername7;// assign username label
			nextPanel->labelProfilePassword = labelProfilePassword7;// assign password label
			// Link Panel 6 & 7
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 8
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel8;								// assign pointer to panel8
			nextPanel->panel->Visible = false;						// hide by default
			nextPanel->labelProfileWebsite = labelProfileWebsite8;	// assign website label
			nextPanel->labelProfileUsername = labelProfileUsername8;// assign username label
			nextPanel->labelProfilePassword = labelProfilePassword8;// assign password label
			// Link Panel 7 & 8
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 9
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel9;								// assign pointer to panel9
			nextPanel->panel->Visible = false;						// hide by default
			nextPanel->labelProfileWebsite = labelProfileWebsite9;	// assign website label
			nextPanel->labelProfileUsername = labelProfileUsername9;// assign username label
			nextPanel->labelProfilePassword = labelProfilePassword9;// assign password label
			// Link Panel 8 & 9
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 10
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel10;								// assign pointer to panel10
			nextPanel->panel->Visible = false;						// hide by default
			nextPanel->labelProfileWebsite = labelProfileWebsite10;	// assign website label
			nextPanel->labelProfileUsername = labelProfileUsername10;// assign username label
			nextPanel->labelProfilePassword = labelProfilePassword10;// assign password label
			// Link Panel 9 & 10
			panel->next = nextPanel;
			nextPanel->prev = panel;

			// set panel pointer to first node
			while (panel->prev != nullptr)
			{
				panel = panel->prev;
			}
			// traversal node
			Panels^ currPanel = panel;

			// while there's a valid profile
			if (profile != nullptr)
			{
				// while there's an unchecked profile, continue
				while (true)
				{
					// (profile pointer starts at the end of the node list, traversing backwards)
					// if next profile isn't null
					if (profile->next != nullptr)
					{
						// make next panel visible
						currPanel->next->panel->Visible = true;

						// copy label values into next panel
						currPanel->next->labelProfileWebsite->Text = currPanel->labelProfileWebsite->Text;
						currPanel->next->labelProfileUsername->Text = currPanel->labelProfileUsername->Text;
						currPanel->next->labelProfilePassword->Text = currPanel->labelProfilePassword->Text;

						if (currPanel != panel)
						{
							// copy previous panels to their next panel
							int i = 0;						// back jump counter
							while (currPanel->prev != panel)
							{
								currPanel = currPanel->prev;	// back jump
								i++;							// increment back jump

								// assigns next slot to the current slot values
								currPanel->next->labelProfileWebsite->Text = currPanel->labelProfileWebsite->Text;
								currPanel->next->labelProfileUsername->Text = currPanel->labelProfileUsername->Text;
								currPanel->next->labelProfilePassword->Text = currPanel->labelProfilePassword->Text;
							}

							if (currPanel->prev == panel)
							{
								// assigns current slot to the previous slot values
								currPanel->labelProfileWebsite->Text = currPanel->prev->labelProfileWebsite->Text;
								currPanel->labelProfileUsername->Text = currPanel->prev->labelProfileUsername->Text;
								currPanel->labelProfilePassword->Text = currPanel->prev->labelProfilePassword->Text;
							}

							// jump forward to correct position
							for (int j = 0; j < i; j++)
								currPanel = currPanel->next;
						}

						if (currPanel->next != nullptr)
							currPanel = currPanel->next;

					}

					// update first panel labels
					panel->labelProfileWebsite->Text = profile->website;
					panel->labelProfileUsername->Text = profile->username;
					panel->labelProfilePassword->Text = profile->password;

					if (profile->prev == nullptr)
						break;

					// move back one profile
					profile = profile->prev;
				}
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
	private: System::Windows::Forms::Panel^ panelContent;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Label^ labelProfilePassword10;
	private: System::Windows::Forms::Label^ labelProfileUsername10;
	private: System::Windows::Forms::Label^ labelProfileWebsite10;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Label^ labelProfilePassword8;
	private: System::Windows::Forms::Label^ labelProfileUsername8;
	private: System::Windows::Forms::Label^ labelProfileWebsite8;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ labelProfilePassword6;
	private: System::Windows::Forms::Label^ labelProfileUsername6;
	private: System::Windows::Forms::Label^ labelProfileWebsite6;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Label^ labelProfilePassword9;
	private: System::Windows::Forms::Label^ labelProfileUsername9;
	private: System::Windows::Forms::Label^ labelProfileWebsite9;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ labelProfilePassword7;
	private: System::Windows::Forms::Label^ labelProfileUsername7;
	private: System::Windows::Forms::Label^ labelProfileWebsite7;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ labelProfilePassword5;
	private: System::Windows::Forms::Label^ labelProfileUsername5;
	private: System::Windows::Forms::Label^ labelProfileWebsite5;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ labelProfilePassword1;
	private: System::Windows::Forms::Label^ labelProfileUsername1;
	private: System::Windows::Forms::Label^ labelProfileWebsite1;
	private: System::Windows::Forms::Label^ labelColumnPasswords;
	private: System::Windows::Forms::Label^ labelColumnUsernames;
	private: System::Windows::Forms::Label^ labelColumnWebsite;
	private: System::Windows::Forms::Panel^ panelSeperationLine1;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ labelProfilePassword2;
	private: System::Windows::Forms::Label^ labelProfileUsername2;
	private: System::Windows::Forms::Label^ labelProfileWebsite2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ labelProfilePassword3;
	private: System::Windows::Forms::Label^ labelProfileUsername3;
	private: System::Windows::Forms::Label^ labelProfileWebsite3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ labelProfilePassword4;
	private: System::Windows::Forms::Label^ labelProfileUsername4;
	private: System::Windows::Forms::Label^ labelProfileWebsite4;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf1;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf2;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf3;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf4;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf5;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf6;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf7;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf8;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf9;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf10;

































































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
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxDelProf1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDelProf2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDelProf3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDelProf4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDelProf5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDelProf6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDelProf10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDelProf9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDelProf8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDelProf7 = (gcnew System::Windows::Forms::PictureBox());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelColumnWebsite = (gcnew System::Windows::Forms::Label());
			this->labelColumnUsernames = (gcnew System::Windows::Forms::Label());
			this->labelColumnPasswords = (gcnew System::Windows::Forms::Label());
			this->panelSeperationLine1 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword1 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername1 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword2 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername2 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword3 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername3 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword4 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername4 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite4 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword5 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername5 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite5 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword6 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername6 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite6 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword7 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername7 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite7 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword8 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername8 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite8 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword9 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername9 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite9 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->labelProfilePassword10 = (gcnew System::Windows::Forms::Label());
			this->labelProfileUsername10 = (gcnew System::Windows::Forms::Label());
			this->labelProfileWebsite10 = (gcnew System::Windows::Forms::Label());
			this->panelSidebar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGeneratePassword))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->BeginInit();
			this->panelTopbar->SuspendLayout();
			this->panelContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf7))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel10->SuspendLayout();
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
			this->panelSidebar->Size = System::Drawing::Size(75, 512);
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
			this->pictureBoxGeneratePassword->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxGeneratePassword_Click);
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
			this->panelTopbar->Size = System::Drawing::Size(983, 75);
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
			// panelContent
			// 
			this->panelContent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelContent->AutoScroll = true;
			this->panelContent->Controls->Add(this->pictureBoxDelProf1);
			this->panelContent->Controls->Add(this->pictureBoxDelProf2);
			this->panelContent->Controls->Add(this->pictureBoxDelProf3);
			this->panelContent->Controls->Add(this->pictureBoxDelProf4);
			this->panelContent->Controls->Add(this->pictureBoxDelProf5);
			this->panelContent->Controls->Add(this->pictureBoxDelProf6);
			this->panelContent->Controls->Add(this->pictureBoxDelProf10);
			this->panelContent->Controls->Add(this->pictureBoxDelProf9);
			this->panelContent->Controls->Add(this->pictureBoxDelProf8);
			this->panelContent->Controls->Add(this->pictureBoxDelProf7);
			this->panelContent->Controls->Add(this->labelTitle);
			this->panelContent->Controls->Add(this->labelColumnWebsite);
			this->panelContent->Controls->Add(this->labelColumnUsernames);
			this->panelContent->Controls->Add(this->labelColumnPasswords);
			this->panelContent->Controls->Add(this->panelSeperationLine1);
			this->panelContent->Controls->Add(this->panel1);
			this->panelContent->Controls->Add(this->panel2);
			this->panelContent->Controls->Add(this->panel3);
			this->panelContent->Controls->Add(this->panel4);
			this->panelContent->Controls->Add(this->panel5);
			this->panelContent->Controls->Add(this->panel6);
			this->panelContent->Controls->Add(this->panel7);
			this->panelContent->Controls->Add(this->panel8);
			this->panelContent->Controls->Add(this->panel9);
			this->panelContent->Controls->Add(this->panel10);
			this->panelContent->Location = System::Drawing::Point(74, 70);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(909, 441);
			this->panelContent->TabIndex = 9;
			// 
			// pictureBoxDelProf1
			// 
			this->pictureBoxDelProf1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDelProf1.Image")));
			this->pictureBoxDelProf1->Location = System::Drawing::Point(3, 177);
			this->pictureBoxDelProf1->Name = L"pictureBoxDelProf1";
			this->pictureBoxDelProf1->Size = System::Drawing::Size(19, 18);
			this->pictureBoxDelProf1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDelProf1->TabIndex = 1;
			this->pictureBoxDelProf1->TabStop = false;
			this->pictureBoxDelProf1->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxDelProf1_Click);
			// 
			// pictureBoxDelProf2
			// 
			this->pictureBoxDelProf2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDelProf2.Image")));
			this->pictureBoxDelProf2->Location = System::Drawing::Point(3, 238);
			this->pictureBoxDelProf2->Name = L"pictureBoxDelProf2";
			this->pictureBoxDelProf2->Size = System::Drawing::Size(19, 18);
			this->pictureBoxDelProf2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDelProf2->TabIndex = 1;
			this->pictureBoxDelProf2->TabStop = false;
			this->pictureBoxDelProf2->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxDelProf2_Click);
			// 
			// pictureBoxDelProf3
			// 
			this->pictureBoxDelProf3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDelProf3.Image")));
			this->pictureBoxDelProf3->Location = System::Drawing::Point(3, 302);
			this->pictureBoxDelProf3->Name = L"pictureBoxDelProf3";
			this->pictureBoxDelProf3->Size = System::Drawing::Size(19, 18);
			this->pictureBoxDelProf3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDelProf3->TabIndex = 1;
			this->pictureBoxDelProf3->TabStop = false;
			this->pictureBoxDelProf3->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxDelProf3_Click);
			// 
			// pictureBoxDelProf4
			// 
			this->pictureBoxDelProf4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDelProf4.Image")));
			this->pictureBoxDelProf4->Location = System::Drawing::Point(3, 361);
			this->pictureBoxDelProf4->Name = L"pictureBoxDelProf4";
			this->pictureBoxDelProf4->Size = System::Drawing::Size(19, 18);
			this->pictureBoxDelProf4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDelProf4->TabIndex = 1;
			this->pictureBoxDelProf4->TabStop = false;
			this->pictureBoxDelProf4->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxDelProf4_Click);
			// 
			// pictureBoxDelProf5
			// 
			this->pictureBoxDelProf5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDelProf5.Image")));
			this->pictureBoxDelProf5->Location = System::Drawing::Point(3, 420);
			this->pictureBoxDelProf5->Name = L"pictureBoxDelProf5";
			this->pictureBoxDelProf5->Size = System::Drawing::Size(19, 18);
			this->pictureBoxDelProf5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDelProf5->TabIndex = 1;
			this->pictureBoxDelProf5->TabStop = false;
			this->pictureBoxDelProf5->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxDelProf5_Click);
			// 
			// pictureBoxDelProf6
			// 
			this->pictureBoxDelProf6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDelProf6.Image")));
			this->pictureBoxDelProf6->Location = System::Drawing::Point(3, 479);
			this->pictureBoxDelProf6->Name = L"pictureBoxDelProf6";
			this->pictureBoxDelProf6->Size = System::Drawing::Size(19, 18);
			this->pictureBoxDelProf6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDelProf6->TabIndex = 1;
			this->pictureBoxDelProf6->TabStop = false;
			this->pictureBoxDelProf6->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxDelProf6_Click);
			// 
			// pictureBoxDelProf10
			// 
			this->pictureBoxDelProf10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDelProf10.Image")));
			this->pictureBoxDelProf10->Location = System::Drawing::Point(3, 716);
			this->pictureBoxDelProf10->Name = L"pictureBoxDelProf10";
			this->pictureBoxDelProf10->Size = System::Drawing::Size(19, 18);
			this->pictureBoxDelProf10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDelProf10->TabIndex = 1;
			this->pictureBoxDelProf10->TabStop = false;
			this->pictureBoxDelProf10->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxDelProf10_Click);
			// 
			// pictureBoxDelProf9
			// 
			this->pictureBoxDelProf9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDelProf9.Image")));
			this->pictureBoxDelProf9->Location = System::Drawing::Point(3, 661);
			this->pictureBoxDelProf9->Name = L"pictureBoxDelProf9";
			this->pictureBoxDelProf9->Size = System::Drawing::Size(19, 18);
			this->pictureBoxDelProf9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDelProf9->TabIndex = 1;
			this->pictureBoxDelProf9->TabStop = false;
			this->pictureBoxDelProf9->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxDelProf9_Click);
			// 
			// pictureBoxDelProf8
			// 
			this->pictureBoxDelProf8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDelProf8.Image")));
			this->pictureBoxDelProf8->Location = System::Drawing::Point(3, 601);
			this->pictureBoxDelProf8->Name = L"pictureBoxDelProf8";
			this->pictureBoxDelProf8->Size = System::Drawing::Size(19, 18);
			this->pictureBoxDelProf8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDelProf8->TabIndex = 1;
			this->pictureBoxDelProf8->TabStop = false;
			this->pictureBoxDelProf8->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxDelProf8_Click);
			// 
			// pictureBoxDelProf7
			// 
			this->pictureBoxDelProf7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDelProf7.Image")));
			this->pictureBoxDelProf7->Location = System::Drawing::Point(3, 539);
			this->pictureBoxDelProf7->Name = L"pictureBoxDelProf7";
			this->pictureBoxDelProf7->Size = System::Drawing::Size(19, 18);
			this->pictureBoxDelProf7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDelProf7->TabIndex = 1;
			this->pictureBoxDelProf7->TabStop = false;
			this->pictureBoxDelProf7->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxDelProf7_Click);
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(0, 3);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(892, 104);
			this->labelTitle->TabIndex = 19;
			this->labelTitle->Text = L"Profiles";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelColumnWebsite
			// 
			this->labelColumnWebsite->AutoSize = true;
			this->labelColumnWebsite->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelColumnWebsite->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->labelColumnWebsite->Location = System::Drawing::Point(45, 117);
			this->labelColumnWebsite->Name = L"labelColumnWebsite";
			this->labelColumnWebsite->Size = System::Drawing::Size(137, 29);
			this->labelColumnWebsite->TabIndex = 23;
			this->labelColumnWebsite->Text = L"WEBSITES";
			// 
			// labelColumnUsernames
			// 
			this->labelColumnUsernames->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelColumnUsernames->AutoSize = true;
			this->labelColumnUsernames->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelColumnUsernames->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->labelColumnUsernames->Location = System::Drawing::Point(374, 117);
			this->labelColumnUsernames->Name = L"labelColumnUsernames";
			this->labelColumnUsernames->Size = System::Drawing::Size(164, 29);
			this->labelColumnUsernames->TabIndex = 22;
			this->labelColumnUsernames->Text = L"USERNAMES";
			// 
			// labelColumnPasswords
			// 
			this->labelColumnPasswords->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelColumnPasswords->AutoSize = true;
			this->labelColumnPasswords->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelColumnPasswords->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->labelColumnPasswords->Location = System::Drawing::Point(703, 117);
			this->labelColumnPasswords->Name = L"labelColumnPasswords";
			this->labelColumnPasswords->Size = System::Drawing::Size(167, 29);
			this->labelColumnPasswords->TabIndex = 21;
			this->labelColumnPasswords->Text = L"PASSWORDS";
			// 
			// panelSeperationLine1
			// 
			this->panelSeperationLine1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelSeperationLine1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panelSeperationLine1->Location = System::Drawing::Point(98, 103);
			this->panelSeperationLine1->Name = L"panelSeperationLine1";
			this->panelSeperationLine1->Size = System::Drawing::Size(686, 2);
			this->panelSeperationLine1->TabIndex = 20;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel1->Controls->Add(this->labelProfilePassword1);
			this->panel1->Controls->Add(this->labelProfileUsername1);
			this->panel1->Controls->Add(this->labelProfileWebsite1);
			this->panel1->Location = System::Drawing::Point(14, 162);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(878, 48);
			this->panel1->TabIndex = 24;
			// 
			// labelProfilePassword1
			// 
			this->labelProfilePassword1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword1->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword1->Location = System::Drawing::Point(625, 0);
			this->labelProfilePassword1->Name = L"labelProfilePassword1";
			this->labelProfilePassword1->Size = System::Drawing::Size(252, 48);
			this->labelProfilePassword1->TabIndex = 0;
			this->labelProfilePassword1->Text = L"-";
			this->labelProfilePassword1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileUsername1
			// 
			this->labelProfileUsername1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername1->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername1->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername1->Name = L"labelProfileUsername1";
			this->labelProfileUsername1->Size = System::Drawing::Size(278, 48);
			this->labelProfileUsername1->TabIndex = 0;
			this->labelProfileUsername1->Text = L"-";
			this->labelProfileUsername1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite1
			// 
			this->labelProfileWebsite1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite1->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite1->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite1->Name = L"labelProfileWebsite1";
			this->labelProfileWebsite1->Size = System::Drawing::Size(274, 48);
			this->labelProfileWebsite1->TabIndex = 0;
			this->labelProfileWebsite1->Text = L"-";
			this->labelProfileWebsite1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel2->Controls->Add(this->labelProfilePassword2);
			this->panel2->Controls->Add(this->labelProfileUsername2);
			this->panel2->Controls->Add(this->labelProfileWebsite2);
			this->panel2->Location = System::Drawing::Point(13, 222);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(879, 48);
			this->panel2->TabIndex = 25;
			// 
			// labelProfilePassword2
			// 
			this->labelProfilePassword2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword2->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword2->Location = System::Drawing::Point(625, 0);
			this->labelProfilePassword2->Name = L"labelProfilePassword2";
			this->labelProfilePassword2->Size = System::Drawing::Size(253, 48);
			this->labelProfilePassword2->TabIndex = 0;
			this->labelProfilePassword2->Text = L"-";
			this->labelProfilePassword2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileUsername2
			// 
			this->labelProfileUsername2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername2->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername2->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername2->Name = L"labelProfileUsername2";
			this->labelProfileUsername2->Size = System::Drawing::Size(279, 48);
			this->labelProfileUsername2->TabIndex = 0;
			this->labelProfileUsername2->Text = L"-";
			this->labelProfileUsername2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite2
			// 
			this->labelProfileWebsite2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite2->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite2->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite2->Name = L"labelProfileWebsite2";
			this->labelProfileWebsite2->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite2->TabIndex = 0;
			this->labelProfileWebsite2->Text = L"-";
			this->labelProfileWebsite2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel3->Controls->Add(this->labelProfilePassword3);
			this->panel3->Controls->Add(this->labelProfileUsername3);
			this->panel3->Controls->Add(this->labelProfileWebsite3);
			this->panel3->Location = System::Drawing::Point(13, 282);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(879, 48);
			this->panel3->TabIndex = 26;
			// 
			// labelProfilePassword3
			// 
			this->labelProfilePassword3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword3->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword3->Location = System::Drawing::Point(625, 0);
			this->labelProfilePassword3->Name = L"labelProfilePassword3";
			this->labelProfilePassword3->Size = System::Drawing::Size(253, 48);
			this->labelProfilePassword3->TabIndex = 0;
			this->labelProfilePassword3->Text = L"-";
			this->labelProfilePassword3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileUsername3
			// 
			this->labelProfileUsername3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername3->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername3->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername3->Name = L"labelProfileUsername3";
			this->labelProfileUsername3->Size = System::Drawing::Size(279, 48);
			this->labelProfileUsername3->TabIndex = 0;
			this->labelProfileUsername3->Text = L"-";
			this->labelProfileUsername3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite3
			// 
			this->labelProfileWebsite3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite3->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite3->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite3->Name = L"labelProfileWebsite3";
			this->labelProfileWebsite3->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite3->TabIndex = 0;
			this->labelProfileWebsite3->Text = L"-";
			this->labelProfileWebsite3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel4->Controls->Add(this->labelProfilePassword4);
			this->panel4->Controls->Add(this->labelProfileUsername4);
			this->panel4->Controls->Add(this->labelProfileWebsite4);
			this->panel4->Location = System::Drawing::Point(13, 342);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(879, 48);
			this->panel4->TabIndex = 27;
			// 
			// labelProfilePassword4
			// 
			this->labelProfilePassword4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword4->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword4->Location = System::Drawing::Point(625, 0);
			this->labelProfilePassword4->Name = L"labelProfilePassword4";
			this->labelProfilePassword4->Size = System::Drawing::Size(253, 48);
			this->labelProfilePassword4->TabIndex = 0;
			this->labelProfilePassword4->Text = L"-";
			this->labelProfilePassword4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileUsername4
			// 
			this->labelProfileUsername4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername4->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername4->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername4->Name = L"labelProfileUsername4";
			this->labelProfileUsername4->Size = System::Drawing::Size(279, 48);
			this->labelProfileUsername4->TabIndex = 0;
			this->labelProfileUsername4->Text = L"-";
			this->labelProfileUsername4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite4
			// 
			this->labelProfileWebsite4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite4->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite4->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite4->Name = L"labelProfileWebsite4";
			this->labelProfileWebsite4->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite4->TabIndex = 0;
			this->labelProfileWebsite4->Text = L"-";
			this->labelProfileWebsite4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel5->Controls->Add(this->labelProfilePassword5);
			this->panel5->Controls->Add(this->labelProfileUsername5);
			this->panel5->Controls->Add(this->labelProfileWebsite5);
			this->panel5->Location = System::Drawing::Point(13, 402);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(879, 48);
			this->panel5->TabIndex = 31;
			// 
			// labelProfilePassword5
			// 
			this->labelProfilePassword5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword5->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword5->Location = System::Drawing::Point(625, 0);
			this->labelProfilePassword5->Name = L"labelProfilePassword5";
			this->labelProfilePassword5->Size = System::Drawing::Size(253, 48);
			this->labelProfilePassword5->TabIndex = 0;
			this->labelProfilePassword5->Text = L"-";
			this->labelProfilePassword5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileUsername5
			// 
			this->labelProfileUsername5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername5->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername5->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername5->Name = L"labelProfileUsername5";
			this->labelProfileUsername5->Size = System::Drawing::Size(279, 48);
			this->labelProfileUsername5->TabIndex = 0;
			this->labelProfileUsername5->Text = L"-";
			this->labelProfileUsername5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite5
			// 
			this->labelProfileWebsite5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite5->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite5->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite5->Name = L"labelProfileWebsite5";
			this->labelProfileWebsite5->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite5->TabIndex = 0;
			this->labelProfileWebsite5->Text = L"-";
			this->labelProfileWebsite5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel6
			// 
			this->panel6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel6->Controls->Add(this->labelProfilePassword6);
			this->panel6->Controls->Add(this->labelProfileUsername6);
			this->panel6->Controls->Add(this->labelProfileWebsite6);
			this->panel6->Location = System::Drawing::Point(13, 462);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(879, 48);
			this->panel6->TabIndex = 32;
			// 
			// labelProfilePassword6
			// 
			this->labelProfilePassword6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword6->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword6->Location = System::Drawing::Point(625, 0);
			this->labelProfilePassword6->Name = L"labelProfilePassword6";
			this->labelProfilePassword6->Size = System::Drawing::Size(253, 48);
			this->labelProfilePassword6->TabIndex = 0;
			this->labelProfilePassword6->Text = L"-";
			this->labelProfilePassword6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileUsername6
			// 
			this->labelProfileUsername6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername6->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername6->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername6->Name = L"labelProfileUsername6";
			this->labelProfileUsername6->Size = System::Drawing::Size(279, 48);
			this->labelProfileUsername6->TabIndex = 0;
			this->labelProfileUsername6->Text = L"-";
			this->labelProfileUsername6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite6
			// 
			this->labelProfileWebsite6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite6->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite6->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite6->Name = L"labelProfileWebsite6";
			this->labelProfileWebsite6->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite6->TabIndex = 0;
			this->labelProfileWebsite6->Text = L"-";
			this->labelProfileWebsite6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel7
			// 
			this->panel7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel7->Controls->Add(this->labelProfilePassword7);
			this->panel7->Controls->Add(this->labelProfileUsername7);
			this->panel7->Controls->Add(this->labelProfileWebsite7);
			this->panel7->Location = System::Drawing::Point(13, 522);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(879, 48);
			this->panel7->TabIndex = 33;
			// 
			// labelProfilePassword7
			// 
			this->labelProfilePassword7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword7->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword7->Location = System::Drawing::Point(625, 0);
			this->labelProfilePassword7->Name = L"labelProfilePassword7";
			this->labelProfilePassword7->Size = System::Drawing::Size(253, 48);
			this->labelProfilePassword7->TabIndex = 0;
			this->labelProfilePassword7->Text = L"-";
			this->labelProfilePassword7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileUsername7
			// 
			this->labelProfileUsername7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername7->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername7->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername7->Name = L"labelProfileUsername7";
			this->labelProfileUsername7->Size = System::Drawing::Size(279, 48);
			this->labelProfileUsername7->TabIndex = 0;
			this->labelProfileUsername7->Text = L"-";
			this->labelProfileUsername7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite7
			// 
			this->labelProfileWebsite7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite7->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite7->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite7->Name = L"labelProfileWebsite7";
			this->labelProfileWebsite7->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite7->TabIndex = 0;
			this->labelProfileWebsite7->Text = L"-";
			this->labelProfileWebsite7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel8
			// 
			this->panel8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel8->Controls->Add(this->labelProfilePassword8);
			this->panel8->Controls->Add(this->labelProfileUsername8);
			this->panel8->Controls->Add(this->labelProfileWebsite8);
			this->panel8->Location = System::Drawing::Point(13, 582);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(879, 48);
			this->panel8->TabIndex = 29;
			// 
			// labelProfilePassword8
			// 
			this->labelProfilePassword8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword8->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword8->Location = System::Drawing::Point(625, 0);
			this->labelProfilePassword8->Name = L"labelProfilePassword8";
			this->labelProfilePassword8->Size = System::Drawing::Size(253, 48);
			this->labelProfilePassword8->TabIndex = 0;
			this->labelProfilePassword8->Text = L"-";
			this->labelProfilePassword8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileUsername8
			// 
			this->labelProfileUsername8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername8->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername8->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername8->Name = L"labelProfileUsername8";
			this->labelProfileUsername8->Size = System::Drawing::Size(279, 48);
			this->labelProfileUsername8->TabIndex = 0;
			this->labelProfileUsername8->Text = L"-";
			this->labelProfileUsername8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite8
			// 
			this->labelProfileWebsite8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite8->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite8->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite8->Name = L"labelProfileWebsite8";
			this->labelProfileWebsite8->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite8->TabIndex = 0;
			this->labelProfileWebsite8->Text = L"-";
			this->labelProfileWebsite8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel9
			// 
			this->panel9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel9->Controls->Add(this->labelProfilePassword9);
			this->panel9->Controls->Add(this->labelProfileUsername9);
			this->panel9->Controls->Add(this->labelProfileWebsite9);
			this->panel9->Location = System::Drawing::Point(13, 642);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(879, 48);
			this->panel9->TabIndex = 30;
			// 
			// labelProfilePassword9
			// 
			this->labelProfilePassword9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword9->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword9->Location = System::Drawing::Point(625, 0);
			this->labelProfilePassword9->Name = L"labelProfilePassword9";
			this->labelProfilePassword9->Size = System::Drawing::Size(253, 48);
			this->labelProfilePassword9->TabIndex = 0;
			this->labelProfilePassword9->Text = L"-";
			this->labelProfilePassword9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileUsername9
			// 
			this->labelProfileUsername9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername9->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername9->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername9->Name = L"labelProfileUsername9";
			this->labelProfileUsername9->Size = System::Drawing::Size(279, 48);
			this->labelProfileUsername9->TabIndex = 0;
			this->labelProfileUsername9->Text = L"-";
			this->labelProfileUsername9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite9
			// 
			this->labelProfileWebsite9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite9->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite9->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite9->Name = L"labelProfileWebsite9";
			this->labelProfileWebsite9->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite9->TabIndex = 0;
			this->labelProfileWebsite9->Text = L"-";
			this->labelProfileWebsite9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel10
			// 
			this->panel10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel10->Controls->Add(this->labelProfilePassword10);
			this->panel10->Controls->Add(this->labelProfileUsername10);
			this->panel10->Controls->Add(this->labelProfileWebsite10);
			this->panel10->Location = System::Drawing::Point(13, 702);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(879, 48);
			this->panel10->TabIndex = 28;
			// 
			// labelProfilePassword10
			// 
			this->labelProfilePassword10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfilePassword10->ForeColor = System::Drawing::Color::White;
			this->labelProfilePassword10->Location = System::Drawing::Point(625, 0);
			this->labelProfilePassword10->Name = L"labelProfilePassword10";
			this->labelProfilePassword10->Size = System::Drawing::Size(253, 48);
			this->labelProfilePassword10->TabIndex = 0;
			this->labelProfilePassword10->Text = L"-";
			this->labelProfilePassword10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileUsername10
			// 
			this->labelProfileUsername10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelProfileUsername10->ForeColor = System::Drawing::Color::White;
			this->labelProfileUsername10->Location = System::Drawing::Point(303, 0);
			this->labelProfileUsername10->Name = L"labelProfileUsername10";
			this->labelProfileUsername10->Size = System::Drawing::Size(279, 48);
			this->labelProfileUsername10->TabIndex = 0;
			this->labelProfileUsername10->Text = L"-";
			this->labelProfileUsername10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfileWebsite10
			// 
			this->labelProfileWebsite10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite10->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite10->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite10->Name = L"labelProfileWebsite10";
			this->labelProfileWebsite10->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite10->TabIndex = 0;
			this->labelProfileWebsite10->Text = L"-";
			this->labelProfileWebsite10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ProfilesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->ClientSize = System::Drawing::Size(984, 511);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelTopbar);
			this->Controls->Add(this->panelContent);
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
			this->panelContent->ResumeLayout(false);
			this->panelContent->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDelProf7))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:  System::Drawing::Point firstPanelPoint;

	public: int profileCount;

	public: PageProperties pageProps;

	public: User^ user = nullptr;

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
	private: System::Void pictureBoxProfiles_Click(System::Object^ sender, System::EventArgs^ e) {
		// redirect to "Profiles" page
		pageProps.page = 3;

		// close window
		this->Close();
	}
	private: System::Void pictureBoxGeneratePassword_Click(System::Object^ sender, System::EventArgs^ e) {
		// open Generator overlay
		PassUnite::Generator generatorOverlay;
		generatorOverlay.ShowDialog();
	}
	private: System::Void pictureBoxDelProf1_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite1->Text != "-" && labelProfileUsername1->Text != "-" && labelProfilePassword1->Text != "-")
		{
			// grab credentials
			String^ website = labelProfileWebsite1->Text;
			String^ username = labelProfileUsername1->Text;
			String^ password = labelProfilePassword1->Text;

			labelProfileWebsite1->Text = "-";
			labelProfileUsername1->Text = "-";
			labelProfilePassword1->Text = "-";

			// search database for matching data

			// reinitialize page
			this->Update();
			this->Refresh();
		}
	}
	private: System::Void pictureBoxDelProf2_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite2->Text != "-" && labelProfileUsername2->Text != "-" && labelProfilePassword2->Text != "-")
		{
			// grab credentials
			String^ website = labelProfileWebsite2->Text;
			String^ username = labelProfileUsername2->Text;
			String^ password = labelProfilePassword2->Text;

			labelProfileWebsite2->Text = "-";
			labelProfileUsername2->Text = "-";
			labelProfilePassword2->Text = "-";

			// search database for matching data

			// reinitialize page
		}
	}
	private: System::Void pictureBoxDelProf3_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite3->Text != "-" && labelProfileUsername3->Text != "-" && labelProfilePassword3->Text != "-")
		{
			// grab credentials
			String^ website = labelProfileWebsite3->Text;
			String^ username = labelProfileUsername3->Text;
			String^ password = labelProfilePassword3->Text;

			labelProfileWebsite3->Text = "-";
			labelProfileUsername3->Text = "-";
			labelProfilePassword3->Text = "-";

			// search database for matching data

			// reinitialize page
		}
	}
	private: System::Void pictureBoxDelProf4_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite4->Text != "-" && labelProfileUsername4->Text != "-" && labelProfilePassword4->Text != "-")
		{
			// grab credentials
			String^ website = labelProfileWebsite4->Text;
			String^ username = labelProfileUsername4->Text;
			String^ password = labelProfilePassword4->Text;

			labelProfileWebsite4->Text = "-";
			labelProfileUsername4->Text = "-";
			labelProfilePassword4->Text = "-";

			// search database for matching data

			// reinitialize page
		}
	}
	private: System::Void pictureBoxDelProf5_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite5->Text != "-" && labelProfileUsername5->Text != "-" && labelProfilePassword5->Text != "-")
		{
			// grab credentials
			String^ website = labelProfileWebsite5->Text;
			String^ username = labelProfileUsername5->Text;
			String^ password = labelProfilePassword5->Text;

			labelProfileWebsite5->Text = "-";
			labelProfileUsername5->Text = "-";
			labelProfilePassword5->Text = "-";

			// search database for matching data

			// reinitialize page
		}
	}
	private: System::Void pictureBoxDelProf6_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite6->Text != "-" && labelProfileUsername6->Text != "-" && labelProfilePassword6->Text != "-")
		{
			// grab credentials
			String^ website = labelProfileWebsite6->Text;
			String^ username = labelProfileUsername6->Text;
			String^ password = labelProfilePassword6->Text;

			labelProfileWebsite6->Text = "-";
			labelProfileUsername6->Text = "-";
			labelProfilePassword6->Text = "-";

			// search database for matching data

			// reinitialize page
		}
	}
	private: System::Void pictureBoxDelProf7_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite7->Text != "-" && labelProfileUsername7->Text != "-" && labelProfilePassword7->Text != "-")
		{
			// grab credentials
			String^ website = labelProfileWebsite7->Text;
			String^ username = labelProfileUsername7->Text;
			String^ password = labelProfilePassword7->Text;

			labelProfileWebsite7->Text = "-";
			labelProfileUsername7->Text = "-";
			labelProfilePassword7->Text = "-";

			// search database for matching data

			// reinitialize page
		}
	}
	private: System::Void pictureBoxDelProf8_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite8->Text != "-" && labelProfileUsername8->Text != "-" && labelProfilePassword8->Text != "-")
		{
			// grab credentials
			String^ website = labelProfileWebsite8->Text;
			String^ username = labelProfileUsername8->Text;
			String^ password = labelProfilePassword8->Text;

			labelProfileWebsite8->Text = "-";
			labelProfileUsername8->Text = "-";
			labelProfilePassword8->Text = "-";

			// search database for matching data

			// reinitialize page
		}
	}
	private: System::Void pictureBoxDelProf9_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite9->Text != "-" && labelProfileUsername9->Text != "-" && labelProfilePassword9->Text != "-")
		{
			// grab credentials
			String^ website = labelProfileWebsite9->Text;
			String^ username = labelProfileUsername9->Text;
			String^ password = labelProfilePassword9->Text;

			labelProfileWebsite9->Text = "-";
			labelProfileUsername9->Text = "-";
			labelProfilePassword9->Text = "-";

			// search database for matching data

			// reinitialize page
		}
	}
	private: System::Void pictureBoxDelProf10_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite10->Text != "-" && labelProfileUsername10->Text != "-" && labelProfilePassword10->Text != "-")
		{
			// grab credentials
			String^ website = labelProfileWebsite10->Text;
			String^ username = labelProfileUsername10->Text;
			String^ password = labelProfilePassword10->Text;

			labelProfileWebsite10->Text = "-";
			labelProfileUsername10->Text = "-";
			labelProfilePassword10->Text = "-";

			// search database for matching data

			// reinitialize page
		}
	}
	};
}

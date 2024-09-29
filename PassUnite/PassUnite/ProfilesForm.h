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
	using namespace System::Data::SqlClient;

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

			// profile dump
			trashProfile = gcnew Profiles();
			trashProfile->id = 0;
			trashProfile->website = "-";
			trashProfile->username = "-";
			trashProfile->password = "-";

			// save panels into a list in order to access them
			// Panel 1
			panel = gcnew Panels();							// create pointer
			panel->panel = panel1;									// assign pointer to panel1
			panel->id = 1;											// ID
			panel->labelProfileWebsite = labelProfileWebsite1;		// assign website label
			panel->textBoxProfileUsername = textBoxProfileUsername1;	// assign username label
			panel->textBoxProfilePassword = textBoxProfilePassword1;	// assign password label
			// Panel 2
			Panels^ nextPanel = gcnew Panels();						// create pointer
			nextPanel->panel = panel2;								// assign pointer to panel2
			nextPanel->id = 2;										// ID
			nextPanel->panel->Visible = false;						// hide panel by default
			nextPanel->labelProfileWebsite = labelProfileWebsite2;	// assign website label
			nextPanel->textBoxProfileUsername = textBoxProfileUsername2;// assign username label
			nextPanel->textBoxProfilePassword = textBoxProfilePassword2;// assign password label
			// Link Panel 1 & 2
			panel->next = nextPanel;								// create link between pointers
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 3
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel3;								// assign pointer to panel3
			nextPanel->id = 3;										// ID
			nextPanel->panel->Visible = false;						// hide panel by default
			nextPanel->labelProfileWebsite = labelProfileWebsite3;	// assign website label
			nextPanel->textBoxProfileUsername = textBoxProfileUsername3;// assign username label
			nextPanel->textBoxProfilePassword = textBoxProfilePassword3;// assign password label
			// Link Panel 2 & 3
			panel->next = nextPanel;
			nextPanel->prev = panel;								// create link between pointers

			panel = nextPanel;										// traverse through node list
			// Panel 4
			nextPanel = gcnew Panels();								// create a pointer
			nextPanel->panel = panel4;								// assign pointer to panel4
			nextPanel->id = 4;										// ID
			nextPanel->panel->Visible = false;						// hide panel by default
			nextPanel->labelProfileWebsite = labelProfileWebsite4;	// assign website label
			nextPanel->textBoxProfileUsername = textBoxProfileUsername4;// assign username label
			nextPanel->textBoxProfilePassword = textBoxProfilePassword4;// assign password label
			// Link Panel 3 & 4
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 5
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel5;								// assign pointer to panel5
			nextPanel->id = 5;										// ID
			nextPanel->panel->Visible = false;						// hide by default
			nextPanel->labelProfileWebsite = labelProfileWebsite5;	// assign website label
			nextPanel->textBoxProfileUsername = textBoxProfileUsername5;// assign username label
			nextPanel->textBoxProfilePassword = textBoxProfilePassword5;// assign password label
			// Link Panel 4 & 5
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 6
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel6;								// assign pointer to panel6
			nextPanel->id = 6;										// ID
			nextPanel->panel->Visible = false;						// hide panel by default
			nextPanel->labelProfileWebsite = labelProfileWebsite6;	// assign website label
			nextPanel->textBoxProfileUsername = textBoxProfileUsername6;// assign username label
			nextPanel->textBoxProfilePassword = textBoxProfilePassword6;// assign password label
			// Link Panel 5 & 6
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 7
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel7;								// assign pointer to panel7
			nextPanel->id = 7;										// ID
			nextPanel->panel->Visible = false;						// hide by default
			nextPanel->labelProfileWebsite = labelProfileWebsite7;	// assign website label
			nextPanel->textBoxProfileUsername = textBoxProfileUsername7;// assign username label
			nextPanel->textBoxProfilePassword = textBoxProfilePassword7;// assign password label
			// Link Panel 6 & 7
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 8
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel8;								// assign pointer to panel8
			nextPanel->id = 8;										// ID
			nextPanel->panel->Visible = false;						// hide by default
			nextPanel->labelProfileWebsite = labelProfileWebsite8;	// assign website label
			nextPanel->textBoxProfileUsername = textBoxProfileUsername8;// assign username label
			nextPanel->textBoxProfilePassword = textBoxProfilePassword8;// assign password label
			// Link Panel 7 & 8
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 9
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel9;								// assign pointer to panel9
			nextPanel->id = 9;										// ID
			nextPanel->panel->Visible = false;						// hide by default
			nextPanel->labelProfileWebsite = labelProfileWebsite9;	// assign website label
			nextPanel->textBoxProfileUsername = textBoxProfileUsername9;// assign username label
			nextPanel->textBoxProfilePassword = textBoxProfilePassword9;// assign password label
			// Link Panel 8 & 9
			panel->next = nextPanel;
			nextPanel->prev = panel;

			panel = nextPanel;										// traverse through node list
			// Panel 10
			nextPanel = gcnew Panels();								// create pointer
			nextPanel->panel = panel10;								// assign pointer to panel10
			nextPanel->id = 10;										// ID
			nextPanel->panel->Visible = false;						// hide by default
			nextPanel->labelProfileWebsite = labelProfileWebsite10;	// assign website label
			nextPanel->textBoxProfileUsername = textBoxProfileUsername10;// assign username label
			nextPanel->textBoxProfilePassword = textBoxProfilePassword10;// assign password label
			// Link Panel 9 & 10
			panel->next = nextPanel;
			nextPanel->prev = panel;

			// LAST PANEL
			nextPanel->next = nullptr;

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
						currPanel->next->textBoxProfileUsername->Text = currPanel->textBoxProfileUsername->Text;
						currPanel->next->textBoxProfilePassword->Text = currPanel->textBoxProfilePassword->Text;

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
								currPanel->next->textBoxProfileUsername->Text = currPanel->textBoxProfileUsername->Text;
								currPanel->next->textBoxProfilePassword->Text = currPanel->textBoxProfilePassword->Text;
							}

							if (currPanel->prev == panel)
							{
								// assigns current slot to the previous slot values
								currPanel->labelProfileWebsite->Text = currPanel->prev->labelProfileWebsite->Text;
								currPanel->textBoxProfileUsername->Text = currPanel->prev->textBoxProfileUsername->Text;
								currPanel->textBoxProfilePassword->Text = currPanel->prev->textBoxProfilePassword->Text;
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
					panel->textBoxProfileUsername->Text = profile->username;
					panel->textBoxProfilePassword->Text = profile->password;

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

	protected:































































	private: System::Windows::Forms::Panel^ panelSidebar;
	private: System::Windows::Forms::PictureBox^ pictureBoxProfiles;
	private: System::Windows::Forms::PictureBox^ pictureBoxSettings;

	private: System::Windows::Forms::PictureBox^ pictureBoxAddProfile;
	private: System::Windows::Forms::Panel^ panelTopbar;
	private: System::Windows::Forms::PictureBox^ pictureBoxMenu;
	private: System::Windows::Forms::Label^ labelAppName;
	private: System::Windows::Forms::Panel^ panelContent;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf1;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf2;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf3;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf4;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf5;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf6;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf10;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf9;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf8;
	private: System::Windows::Forms::PictureBox^ pictureBoxDelProf7;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Label^ labelColumnWebsite;
	private: System::Windows::Forms::Label^ labelColumnUsernames;
	private: System::Windows::Forms::Label^ labelColumnPasswords;
	private: System::Windows::Forms::Panel^ panelSeperationLine1;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Label^ labelProfileWebsite1;
	private: System::Windows::Forms::TextBox^ textBoxProfileUsername1;
	private: System::Windows::Forms::TextBox^ textBoxProfilePassword1;
	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::Label^ labelProfileWebsite2;
	private: System::Windows::Forms::TextBox^ textBoxProfileUsername2;
	private: System::Windows::Forms::TextBox^ textBoxProfilePassword2;
	private: System::Windows::Forms::Panel^ panel3;

	private: System::Windows::Forms::Label^ labelProfileWebsite3;
	private: System::Windows::Forms::TextBox^ textBoxProfileUsername3;
	private: System::Windows::Forms::TextBox^ textBoxProfilePassword3;
	private: System::Windows::Forms::Panel^ panel4;

	private: System::Windows::Forms::Label^ labelProfileWebsite4;
	private: System::Windows::Forms::TextBox^ textBoxProfileUsername4;
	private: System::Windows::Forms::TextBox^ textBoxProfilePassword4;
	private: System::Windows::Forms::Panel^ panel5;

	private: System::Windows::Forms::Label^ labelProfileWebsite5;
	private: System::Windows::Forms::TextBox^ textBoxProfileUsername5;
	private: System::Windows::Forms::TextBox^ textBoxProfilePassword5;
	private: System::Windows::Forms::Panel^ panel6;

	private: System::Windows::Forms::Label^ labelProfileWebsite6;
	private: System::Windows::Forms::TextBox^ textBoxProfileUsername6;
	private: System::Windows::Forms::TextBox^ textBoxProfilePassword6;
	private: System::Windows::Forms::Panel^ panel7;

	private: System::Windows::Forms::Label^ labelProfileWebsite7;
	private: System::Windows::Forms::TextBox^ textBoxProfileUsername7;
	private: System::Windows::Forms::TextBox^ textBoxProfilePassword7;
	private: System::Windows::Forms::Panel^ panel8;

	private: System::Windows::Forms::Label^ labelProfileWebsite8;
	private: System::Windows::Forms::TextBox^ textBoxProfileUsername8;
	private: System::Windows::Forms::TextBox^ textBoxProfilePassword8;
	private: System::Windows::Forms::Panel^ panel9;

	private: System::Windows::Forms::Label^ labelProfileWebsite9;
	private: System::Windows::Forms::TextBox^ textBoxProfileUsername9;
	private: System::Windows::Forms::TextBox^ textBoxProfilePassword9;
	private: System::Windows::Forms::Panel^ panel10;


	private: System::Windows::Forms::Label^ labelProfileWebsite10;
	private: System::Windows::Forms::TextBox^ textBoxProfileUsername10;
	private: System::Windows::Forms::TextBox^ textBoxProfilePassword10;

	private: System::Windows::Forms::Panel^ panelSidebarExtend;
	private: System::Windows::Forms::Label^ labelSidebarSettings;
	private: System::Windows::Forms::Label^ labelSidebarViewProfiles;
	private: System::Windows::Forms::Label^ labelSidebarAddProfiles;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowingSlot1;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingSlot1;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowingSlot2;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingSlot2;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowingSlot10;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingSlot10;










	private: System::Windows::Forms::PictureBox^ pictureBoxShowingSlot9;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingSlot9;


	private: System::Windows::Forms::PictureBox^ pictureBoxShowingSlot8;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingSlot8;


	private: System::Windows::Forms::PictureBox^ pictureBoxShowingSlot7;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingSlot7;


	private: System::Windows::Forms::PictureBox^ pictureBoxShowingSlot6;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingSlot6;


	private: System::Windows::Forms::PictureBox^ pictureBoxShowingSlot5;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingSlot5;


	private: System::Windows::Forms::PictureBox^ pictureBoxShowingSlot4;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingSlot4;



	private: System::Windows::Forms::PictureBox^ pictureBoxShowingSlot3;
	private: System::Windows::Forms::PictureBox^ pictureBoxHidingSlot3;
















































































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
			this->pictureBoxProfiles = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSettings = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAddProfile = (gcnew System::Windows::Forms::PictureBox());
			this->panelTopbar = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxMenu = (gcnew System::Windows::Forms::PictureBox());
			this->labelAppName = (gcnew System::Windows::Forms::Label());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxShowingSlot10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingSlot10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowingSlot9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingSlot9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowingSlot8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingSlot8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowingSlot7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingSlot7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowingSlot6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingSlot6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowingSlot5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingSlot5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowingSlot4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingSlot4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowingSlot3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingSlot3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowingSlot2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingSlot2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowingSlot1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHidingSlot1 = (gcnew System::Windows::Forms::PictureBox());
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
			this->textBoxProfilePassword1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProfileUsername1 = (gcnew System::Windows::Forms::TextBox());
			this->labelProfileWebsite1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBoxProfilePassword2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProfileUsername2 = (gcnew System::Windows::Forms::TextBox());
			this->labelProfileWebsite2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBoxProfilePassword3 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProfileUsername3 = (gcnew System::Windows::Forms::TextBox());
			this->labelProfileWebsite3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBoxProfilePassword4 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProfileUsername4 = (gcnew System::Windows::Forms::TextBox());
			this->labelProfileWebsite4 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textBoxProfilePassword5 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProfileUsername5 = (gcnew System::Windows::Forms::TextBox());
			this->labelProfileWebsite5 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->textBoxProfilePassword6 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProfileUsername6 = (gcnew System::Windows::Forms::TextBox());
			this->labelProfileWebsite6 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->textBoxProfilePassword7 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProfileUsername7 = (gcnew System::Windows::Forms::TextBox());
			this->labelProfileWebsite7 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->textBoxProfilePassword8 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProfileUsername8 = (gcnew System::Windows::Forms::TextBox());
			this->labelProfileWebsite8 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->textBoxProfilePassword9 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProfileUsername9 = (gcnew System::Windows::Forms::TextBox());
			this->labelProfileWebsite9 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->textBoxProfilePassword10 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProfileUsername10 = (gcnew System::Windows::Forms::TextBox());
			this->labelProfileWebsite10 = (gcnew System::Windows::Forms::Label());
			this->panelSidebarExtend = (gcnew System::Windows::Forms::Panel());
			this->labelSidebarSettings = (gcnew System::Windows::Forms::Label());
			this->labelSidebarViewProfiles = (gcnew System::Windows::Forms::Label());
			this->labelSidebarAddProfiles = (gcnew System::Windows::Forms::Label());
			this->panelSidebar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->BeginInit();
			this->panelTopbar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->BeginInit();
			this->panelContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot1))->BeginInit();
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
			this->panelSidebarExtend->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelSidebar
			// 
			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panelSidebar->Controls->Add(this->pictureBoxProfiles);
			this->panelSidebar->Controls->Add(this->pictureBoxSettings);
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
			this->pictureBoxProfiles->Location = System::Drawing::Point(18, 98);
			this->pictureBoxProfiles->Name = L"pictureBoxProfiles";
			this->pictureBoxProfiles->Size = System::Drawing::Size(40, 40);
			this->pictureBoxProfiles->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxProfiles->TabIndex = 0;
			this->pictureBoxProfiles->TabStop = false;
			this->pictureBoxProfiles->MouseEnter += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxIcons_MouseEnter);
			this->pictureBoxProfiles->MouseLeave += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxIcons_MouseLeave);
			// 
			// pictureBoxSettings
			// 
			this->pictureBoxSettings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxSettings.Image")));
			this->pictureBoxSettings->Location = System::Drawing::Point(18, 338);
			this->pictureBoxSettings->Name = L"pictureBoxSettings";
			this->pictureBoxSettings->Size = System::Drawing::Size(40, 40);
			this->pictureBoxSettings->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxSettings->TabIndex = 0;
			this->pictureBoxSettings->TabStop = false;
			this->pictureBoxSettings->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxSettings_Click);
			this->pictureBoxSettings->MouseEnter += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxIcons_MouseEnter);
			this->pictureBoxSettings->MouseLeave += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxIcons_MouseLeave);
			// 
			// pictureBoxAddProfile
			// 
			this->pictureBoxAddProfile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxAddProfile.Image")));
			this->pictureBoxAddProfile->Location = System::Drawing::Point(18, 38);
			this->pictureBoxAddProfile->Name = L"pictureBoxAddProfile";
			this->pictureBoxAddProfile->Size = System::Drawing::Size(40, 40);
			this->pictureBoxAddProfile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxAddProfile->TabIndex = 0;
			this->pictureBoxAddProfile->TabStop = false;
			this->pictureBoxAddProfile->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxAddProfile_Click);
			this->pictureBoxAddProfile->MouseEnter += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxIcons_MouseEnter);
			this->pictureBoxAddProfile->MouseLeave += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxIcons_MouseLeave);
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
			this->pictureBoxMenu->Location = System::Drawing::Point(18, 20);
			this->pictureBoxMenu->Name = L"pictureBoxMenu";
			this->pictureBoxMenu->Size = System::Drawing::Size(40, 40);
			this->pictureBoxMenu->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMenu->TabIndex = 1;
			this->pictureBoxMenu->TabStop = false;
			this->pictureBoxMenu->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxMenu_Click);
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
			this->labelAppName->Click += gcnew System::EventHandler(this, &ProfilesForm::labelAppName_Click);
			// 
			// panelContent
			// 
			this->panelContent->AutoScroll = true;
			this->panelContent->AutoSize = true;
			this->panelContent->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panelContent->Controls->Add(this->pictureBoxShowingSlot10);
			this->panelContent->Controls->Add(this->pictureBoxHidingSlot10);
			this->panelContent->Controls->Add(this->pictureBoxShowingSlot9);
			this->panelContent->Controls->Add(this->pictureBoxHidingSlot9);
			this->panelContent->Controls->Add(this->pictureBoxShowingSlot8);
			this->panelContent->Controls->Add(this->pictureBoxHidingSlot8);
			this->panelContent->Controls->Add(this->pictureBoxShowingSlot7);
			this->panelContent->Controls->Add(this->pictureBoxHidingSlot7);
			this->panelContent->Controls->Add(this->pictureBoxShowingSlot6);
			this->panelContent->Controls->Add(this->pictureBoxHidingSlot6);
			this->panelContent->Controls->Add(this->pictureBoxShowingSlot5);
			this->panelContent->Controls->Add(this->pictureBoxHidingSlot5);
			this->panelContent->Controls->Add(this->pictureBoxShowingSlot4);
			this->panelContent->Controls->Add(this->pictureBoxHidingSlot4);
			this->panelContent->Controls->Add(this->pictureBoxShowingSlot3);
			this->panelContent->Controls->Add(this->pictureBoxHidingSlot3);
			this->panelContent->Controls->Add(this->pictureBoxShowingSlot2);
			this->panelContent->Controls->Add(this->pictureBoxHidingSlot2);
			this->panelContent->Controls->Add(this->pictureBoxShowingSlot1);
			this->panelContent->Controls->Add(this->pictureBoxHidingSlot1);
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
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(75, 75);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(909, 436);
			this->panelContent->TabIndex = 12;
			// 
			// pictureBoxShowingSlot10
			// 
			this->pictureBoxShowingSlot10->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingSlot10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingSlot10.Image")));
			this->pictureBoxShowingSlot10->Location = System::Drawing::Point(869, 718);
			this->pictureBoxShowingSlot10->Name = L"pictureBoxShowingSlot10";
			this->pictureBoxShowingSlot10->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingSlot10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingSlot10->TabIndex = 39;
			this->pictureBoxShowingSlot10->TabStop = false;
			this->pictureBoxShowingSlot10->Visible = false;
			// 
			// pictureBoxHidingSlot10
			// 
			this->pictureBoxHidingSlot10->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingSlot10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingSlot10.Image")));
			this->pictureBoxHidingSlot10->Location = System::Drawing::Point(869, 718);
			this->pictureBoxHidingSlot10->Name = L"pictureBoxHidingSlot10";
			this->pictureBoxHidingSlot10->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingSlot10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingSlot10->TabIndex = 40;
			this->pictureBoxHidingSlot10->TabStop = false;
			// 
			// pictureBoxShowingSlot9
			// 
			this->pictureBoxShowingSlot9->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingSlot9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingSlot9.Image")));
			this->pictureBoxShowingSlot9->Location = System::Drawing::Point(869, 656);
			this->pictureBoxShowingSlot9->Name = L"pictureBoxShowingSlot9";
			this->pictureBoxShowingSlot9->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingSlot9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingSlot9->TabIndex = 37;
			this->pictureBoxShowingSlot9->TabStop = false;
			this->pictureBoxShowingSlot9->Visible = false;
			// 
			// pictureBoxHidingSlot9
			// 
			this->pictureBoxHidingSlot9->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingSlot9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingSlot9.Image")));
			this->pictureBoxHidingSlot9->Location = System::Drawing::Point(869, 656);
			this->pictureBoxHidingSlot9->Name = L"pictureBoxHidingSlot9";
			this->pictureBoxHidingSlot9->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingSlot9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingSlot9->TabIndex = 38;
			this->pictureBoxHidingSlot9->TabStop = false;
			// 
			// pictureBoxShowingSlot8
			// 
			this->pictureBoxShowingSlot8->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingSlot8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingSlot8.Image")));
			this->pictureBoxShowingSlot8->Location = System::Drawing::Point(869, 596);
			this->pictureBoxShowingSlot8->Name = L"pictureBoxShowingSlot8";
			this->pictureBoxShowingSlot8->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingSlot8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingSlot8->TabIndex = 35;
			this->pictureBoxShowingSlot8->TabStop = false;
			this->pictureBoxShowingSlot8->Visible = false;
			// 
			// pictureBoxHidingSlot8
			// 
			this->pictureBoxHidingSlot8->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingSlot8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingSlot8.Image")));
			this->pictureBoxHidingSlot8->Location = System::Drawing::Point(869, 596);
			this->pictureBoxHidingSlot8->Name = L"pictureBoxHidingSlot8";
			this->pictureBoxHidingSlot8->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingSlot8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingSlot8->TabIndex = 36;
			this->pictureBoxHidingSlot8->TabStop = false;
			// 
			// pictureBoxShowingSlot7
			// 
			this->pictureBoxShowingSlot7->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingSlot7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingSlot7.Image")));
			this->pictureBoxShowingSlot7->Location = System::Drawing::Point(869, 537);
			this->pictureBoxShowingSlot7->Name = L"pictureBoxShowingSlot7";
			this->pictureBoxShowingSlot7->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingSlot7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingSlot7->TabIndex = 33;
			this->pictureBoxShowingSlot7->TabStop = false;
			this->pictureBoxShowingSlot7->Visible = false;
			// 
			// pictureBoxHidingSlot7
			// 
			this->pictureBoxHidingSlot7->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingSlot7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingSlot7.Image")));
			this->pictureBoxHidingSlot7->Location = System::Drawing::Point(869, 537);
			this->pictureBoxHidingSlot7->Name = L"pictureBoxHidingSlot7";
			this->pictureBoxHidingSlot7->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingSlot7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingSlot7->TabIndex = 34;
			this->pictureBoxHidingSlot7->TabStop = false;
			// 
			// pictureBoxShowingSlot6
			// 
			this->pictureBoxShowingSlot6->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingSlot6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingSlot6.Image")));
			this->pictureBoxShowingSlot6->Location = System::Drawing::Point(869, 477);
			this->pictureBoxShowingSlot6->Name = L"pictureBoxShowingSlot6";
			this->pictureBoxShowingSlot6->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingSlot6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingSlot6->TabIndex = 31;
			this->pictureBoxShowingSlot6->TabStop = false;
			this->pictureBoxShowingSlot6->Visible = false;
			// 
			// pictureBoxHidingSlot6
			// 
			this->pictureBoxHidingSlot6->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingSlot6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingSlot6.Image")));
			this->pictureBoxHidingSlot6->Location = System::Drawing::Point(869, 477);
			this->pictureBoxHidingSlot6->Name = L"pictureBoxHidingSlot6";
			this->pictureBoxHidingSlot6->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingSlot6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingSlot6->TabIndex = 32;
			this->pictureBoxHidingSlot6->TabStop = false;
			// 
			// pictureBoxShowingSlot5
			// 
			this->pictureBoxShowingSlot5->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingSlot5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingSlot5.Image")));
			this->pictureBoxShowingSlot5->Location = System::Drawing::Point(869, 417);
			this->pictureBoxShowingSlot5->Name = L"pictureBoxShowingSlot5";
			this->pictureBoxShowingSlot5->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingSlot5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingSlot5->TabIndex = 29;
			this->pictureBoxShowingSlot5->TabStop = false;
			this->pictureBoxShowingSlot5->Visible = false;
			// 
			// pictureBoxHidingSlot5
			// 
			this->pictureBoxHidingSlot5->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingSlot5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingSlot5.Image")));
			this->pictureBoxHidingSlot5->Location = System::Drawing::Point(869, 417);
			this->pictureBoxHidingSlot5->Name = L"pictureBoxHidingSlot5";
			this->pictureBoxHidingSlot5->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingSlot5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingSlot5->TabIndex = 30;
			this->pictureBoxHidingSlot5->TabStop = false;
			// 
			// pictureBoxShowingSlot4
			// 
			this->pictureBoxShowingSlot4->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingSlot4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingSlot4.Image")));
			this->pictureBoxShowingSlot4->Location = System::Drawing::Point(869, 355);
			this->pictureBoxShowingSlot4->Name = L"pictureBoxShowingSlot4";
			this->pictureBoxShowingSlot4->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingSlot4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingSlot4->TabIndex = 27;
			this->pictureBoxShowingSlot4->TabStop = false;
			this->pictureBoxShowingSlot4->Visible = false;
			// 
			// pictureBoxHidingSlot4
			// 
			this->pictureBoxHidingSlot4->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingSlot4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingSlot4.Image")));
			this->pictureBoxHidingSlot4->Location = System::Drawing::Point(869, 355);
			this->pictureBoxHidingSlot4->Name = L"pictureBoxHidingSlot4";
			this->pictureBoxHidingSlot4->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingSlot4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingSlot4->TabIndex = 28;
			this->pictureBoxHidingSlot4->TabStop = false;
			// 
			// pictureBoxShowingSlot3
			// 
			this->pictureBoxShowingSlot3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingSlot3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingSlot3.Image")));
			this->pictureBoxShowingSlot3->Location = System::Drawing::Point(869, 295);
			this->pictureBoxShowingSlot3->Name = L"pictureBoxShowingSlot3";
			this->pictureBoxShowingSlot3->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingSlot3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingSlot3->TabIndex = 25;
			this->pictureBoxShowingSlot3->TabStop = false;
			this->pictureBoxShowingSlot3->Visible = false;
			// 
			// pictureBoxHidingSlot3
			// 
			this->pictureBoxHidingSlot3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingSlot3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingSlot3.Image")));
			this->pictureBoxHidingSlot3->Location = System::Drawing::Point(869, 295);
			this->pictureBoxHidingSlot3->Name = L"pictureBoxHidingSlot3";
			this->pictureBoxHidingSlot3->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingSlot3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingSlot3->TabIndex = 26;
			this->pictureBoxHidingSlot3->TabStop = false;
			// 
			// pictureBoxShowingSlot2
			// 
			this->pictureBoxShowingSlot2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingSlot2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingSlot2.Image")));
			this->pictureBoxShowingSlot2->Location = System::Drawing::Point(869, 236);
			this->pictureBoxShowingSlot2->Name = L"pictureBoxShowingSlot2";
			this->pictureBoxShowingSlot2->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingSlot2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingSlot2->TabIndex = 23;
			this->pictureBoxShowingSlot2->TabStop = false;
			this->pictureBoxShowingSlot2->Visible = false;
			// 
			// pictureBoxHidingSlot2
			// 
			this->pictureBoxHidingSlot2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingSlot2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingSlot2.Image")));
			this->pictureBoxHidingSlot2->Location = System::Drawing::Point(869, 236);
			this->pictureBoxHidingSlot2->Name = L"pictureBoxHidingSlot2";
			this->pictureBoxHidingSlot2->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingSlot2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingSlot2->TabIndex = 24;
			this->pictureBoxHidingSlot2->TabStop = false;
			// 
			// pictureBoxShowingSlot1
			// 
			this->pictureBoxShowingSlot1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxShowingSlot1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowingSlot1.Image")));
			this->pictureBoxShowingSlot1->Location = System::Drawing::Point(869, 176);
			this->pictureBoxShowingSlot1->Name = L"pictureBoxShowingSlot1";
			this->pictureBoxShowingSlot1->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowingSlot1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowingSlot1->TabIndex = 21;
			this->pictureBoxShowingSlot1->TabStop = false;
			this->pictureBoxShowingSlot1->Visible = false;
			this->pictureBoxShowingSlot1->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxShowingSlot1_Click);
			// 
			// pictureBoxHidingSlot1
			// 
			this->pictureBoxHidingSlot1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBoxHidingSlot1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHidingSlot1.Image")));
			this->pictureBoxHidingSlot1->Location = System::Drawing::Point(869, 176);
			this->pictureBoxHidingSlot1->Name = L"pictureBoxHidingSlot1";
			this->pictureBoxHidingSlot1->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHidingSlot1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHidingSlot1->TabIndex = 22;
			this->pictureBoxHidingSlot1->TabStop = false;
			this->pictureBoxHidingSlot1->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxHidingSlot1_Click);
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
			this->labelTitle->Size = System::Drawing::Size(889, 93);
			this->labelTitle->TabIndex = 0;
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
			this->labelColumnWebsite->Location = System::Drawing::Point(65, 117);
			this->labelColumnWebsite->Name = L"labelColumnWebsite";
			this->labelColumnWebsite->Size = System::Drawing::Size(137, 29);
			this->labelColumnWebsite->TabIndex = 0;
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
			this->labelColumnUsernames->Location = System::Drawing::Point(353, 117);
			this->labelColumnUsernames->Name = L"labelColumnUsernames";
			this->labelColumnUsernames->Size = System::Drawing::Size(164, 29);
			this->labelColumnUsernames->TabIndex = 0;
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
			this->labelColumnPasswords->Location = System::Drawing::Point(650, 117);
			this->labelColumnPasswords->Name = L"labelColumnPasswords";
			this->labelColumnPasswords->Size = System::Drawing::Size(167, 29);
			this->labelColumnPasswords->TabIndex = 0;
			this->labelColumnPasswords->Text = L"PASSWORDS";
			// 
			// panelSeperationLine1
			// 
			this->panelSeperationLine1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelSeperationLine1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panelSeperationLine1->Location = System::Drawing::Point(98, 99);
			this->panelSeperationLine1->Name = L"panelSeperationLine1";
			this->panelSeperationLine1->Size = System::Drawing::Size(694, 2);
			this->panelSeperationLine1->TabIndex = 20;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel1->Controls->Add(this->textBoxProfilePassword1);
			this->panel1->Controls->Add(this->textBoxProfileUsername1);
			this->panel1->Controls->Add(this->labelProfileWebsite1);
			this->panel1->Location = System::Drawing::Point(20, 162);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(860, 48);
			this->panel1->TabIndex = 0;
			// 
			// textBoxProfilePassword1
			// 
			this->textBoxProfilePassword1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxProfilePassword1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfilePassword1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfilePassword1->CausesValidation = false;
			this->textBoxProfilePassword1->ForeColor = System::Drawing::Color::White;
			this->textBoxProfilePassword1->Location = System::Drawing::Point(537, 9);
			this->textBoxProfilePassword1->Name = L"textBoxProfilePassword1";
			this->textBoxProfilePassword1->ReadOnly = true;
			this->textBoxProfilePassword1->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword1->TabIndex = 3;
			this->textBoxProfilePassword1->Text = L"-";
			this->textBoxProfilePassword1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfilePassword1->UseSystemPasswordChar = true;
			this->textBoxProfilePassword1->WordWrap = false;
			// 
			// textBoxProfileUsername1
			// 
			this->textBoxProfileUsername1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->textBoxProfileUsername1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfileUsername1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfileUsername1->CausesValidation = false;
			this->textBoxProfileUsername1->ForeColor = System::Drawing::Color::White;
			this->textBoxProfileUsername1->Location = System::Drawing::Point(309, 8);
			this->textBoxProfileUsername1->Name = L"textBoxProfileUsername1";
			this->textBoxProfileUsername1->ReadOnly = true;
			this->textBoxProfileUsername1->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername1->TabIndex = 2;
			this->textBoxProfileUsername1->Text = L"-";
			this->textBoxProfileUsername1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfileUsername1->UseSystemPasswordChar = true;
			this->textBoxProfileUsername1->WordWrap = false;
			// 
			// labelProfileWebsite1
			// 
			this->labelProfileWebsite1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite1->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite1->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite1->Name = L"labelProfileWebsite1";
			this->labelProfileWebsite1->Size = System::Drawing::Size(274, 48);
			this->labelProfileWebsite1->TabIndex = 1;
			this->labelProfileWebsite1->Text = L"-";
			this->labelProfileWebsite1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel2->Controls->Add(this->textBoxProfilePassword2);
			this->panel2->Controls->Add(this->textBoxProfileUsername2);
			this->panel2->Controls->Add(this->labelProfileWebsite2);
			this->panel2->Location = System::Drawing::Point(20, 222);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(860, 48);
			this->panel2->TabIndex = 0;
			// 
			// textBoxProfilePassword2
			// 
			this->textBoxProfilePassword2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxProfilePassword2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfilePassword2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfilePassword2->CausesValidation = false;
			this->textBoxProfilePassword2->ForeColor = System::Drawing::Color::White;
			this->textBoxProfilePassword2->Location = System::Drawing::Point(537, 9);
			this->textBoxProfilePassword2->Name = L"textBoxProfilePassword2";
			this->textBoxProfilePassword2->ReadOnly = true;
			this->textBoxProfilePassword2->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword2->TabIndex = 6;
			this->textBoxProfilePassword2->Text = L"-";
			this->textBoxProfilePassword2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfilePassword2->UseSystemPasswordChar = true;
			this->textBoxProfilePassword2->WordWrap = false;
			// 
			// textBoxProfileUsername2
			// 
			this->textBoxProfileUsername2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->textBoxProfileUsername2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfileUsername2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfileUsername2->CausesValidation = false;
			this->textBoxProfileUsername2->ForeColor = System::Drawing::Color::White;
			this->textBoxProfileUsername2->Location = System::Drawing::Point(309, 9);
			this->textBoxProfileUsername2->Name = L"textBoxProfileUsername2";
			this->textBoxProfileUsername2->ReadOnly = true;
			this->textBoxProfileUsername2->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername2->TabIndex = 5;
			this->textBoxProfileUsername2->Text = L"-";
			this->textBoxProfileUsername2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfileUsername2->UseSystemPasswordChar = true;
			this->textBoxProfileUsername2->WordWrap = false;
			// 
			// labelProfileWebsite2
			// 
			this->labelProfileWebsite2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite2->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite2->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite2->Name = L"labelProfileWebsite2";
			this->labelProfileWebsite2->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite2->TabIndex = 4;
			this->labelProfileWebsite2->Text = L"-";
			this->labelProfileWebsite2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel3->Controls->Add(this->textBoxProfilePassword3);
			this->panel3->Controls->Add(this->textBoxProfileUsername3);
			this->panel3->Controls->Add(this->labelProfileWebsite3);
			this->panel3->Location = System::Drawing::Point(20, 282);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(860, 48);
			this->panel3->TabIndex = 0;
			// 
			// textBoxProfilePassword3
			// 
			this->textBoxProfilePassword3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxProfilePassword3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfilePassword3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfilePassword3->CausesValidation = false;
			this->textBoxProfilePassword3->ForeColor = System::Drawing::Color::White;
			this->textBoxProfilePassword3->Location = System::Drawing::Point(537, 9);
			this->textBoxProfilePassword3->Name = L"textBoxProfilePassword3";
			this->textBoxProfilePassword3->ReadOnly = true;
			this->textBoxProfilePassword3->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword3->TabIndex = 9;
			this->textBoxProfilePassword3->Text = L"-";
			this->textBoxProfilePassword3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfilePassword3->UseSystemPasswordChar = true;
			this->textBoxProfilePassword3->WordWrap = false;
			// 
			// textBoxProfileUsername3
			// 
			this->textBoxProfileUsername3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->textBoxProfileUsername3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfileUsername3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfileUsername3->CausesValidation = false;
			this->textBoxProfileUsername3->ForeColor = System::Drawing::Color::White;
			this->textBoxProfileUsername3->Location = System::Drawing::Point(309, 9);
			this->textBoxProfileUsername3->Name = L"textBoxProfileUsername3";
			this->textBoxProfileUsername3->ReadOnly = true;
			this->textBoxProfileUsername3->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername3->TabIndex = 8;
			this->textBoxProfileUsername3->Text = L"-";
			this->textBoxProfileUsername3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfileUsername3->UseSystemPasswordChar = true;
			this->textBoxProfileUsername3->WordWrap = false;
			// 
			// labelProfileWebsite3
			// 
			this->labelProfileWebsite3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite3->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite3->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite3->Name = L"labelProfileWebsite3";
			this->labelProfileWebsite3->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite3->TabIndex = 7;
			this->labelProfileWebsite3->Text = L"-";
			this->labelProfileWebsite3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel4->Controls->Add(this->textBoxProfilePassword4);
			this->panel4->Controls->Add(this->textBoxProfileUsername4);
			this->panel4->Controls->Add(this->labelProfileWebsite4);
			this->panel4->Location = System::Drawing::Point(20, 342);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(860, 48);
			this->panel4->TabIndex = 0;
			// 
			// textBoxProfilePassword4
			// 
			this->textBoxProfilePassword4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxProfilePassword4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfilePassword4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfilePassword4->CausesValidation = false;
			this->textBoxProfilePassword4->ForeColor = System::Drawing::Color::White;
			this->textBoxProfilePassword4->Location = System::Drawing::Point(537, 6);
			this->textBoxProfilePassword4->Name = L"textBoxProfilePassword4";
			this->textBoxProfilePassword4->ReadOnly = true;
			this->textBoxProfilePassword4->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword4->TabIndex = 12;
			this->textBoxProfilePassword4->Text = L"-";
			this->textBoxProfilePassword4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfilePassword4->UseSystemPasswordChar = true;
			this->textBoxProfilePassword4->WordWrap = false;
			// 
			// textBoxProfileUsername4
			// 
			this->textBoxProfileUsername4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->textBoxProfileUsername4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfileUsername4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfileUsername4->CausesValidation = false;
			this->textBoxProfileUsername4->ForeColor = System::Drawing::Color::White;
			this->textBoxProfileUsername4->Location = System::Drawing::Point(309, 9);
			this->textBoxProfileUsername4->Name = L"textBoxProfileUsername4";
			this->textBoxProfileUsername4->ReadOnly = true;
			this->textBoxProfileUsername4->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername4->TabIndex = 11;
			this->textBoxProfileUsername4->Text = L"-";
			this->textBoxProfileUsername4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfileUsername4->UseSystemPasswordChar = true;
			this->textBoxProfileUsername4->WordWrap = false;
			// 
			// labelProfileWebsite4
			// 
			this->labelProfileWebsite4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite4->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite4->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite4->Name = L"labelProfileWebsite4";
			this->labelProfileWebsite4->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite4->TabIndex = 10;
			this->labelProfileWebsite4->Text = L"-";
			this->labelProfileWebsite4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel5->Controls->Add(this->textBoxProfilePassword5);
			this->panel5->Controls->Add(this->textBoxProfileUsername5);
			this->panel5->Controls->Add(this->labelProfileWebsite5);
			this->panel5->Location = System::Drawing::Point(20, 402);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(860, 48);
			this->panel5->TabIndex = 0;
			// 
			// textBoxProfilePassword5
			// 
			this->textBoxProfilePassword5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxProfilePassword5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfilePassword5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfilePassword5->CausesValidation = false;
			this->textBoxProfilePassword5->ForeColor = System::Drawing::Color::White;
			this->textBoxProfilePassword5->Location = System::Drawing::Point(537, 9);
			this->textBoxProfilePassword5->Name = L"textBoxProfilePassword5";
			this->textBoxProfilePassword5->ReadOnly = true;
			this->textBoxProfilePassword5->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword5->TabIndex = 15;
			this->textBoxProfilePassword5->Text = L"-";
			this->textBoxProfilePassword5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfilePassword5->UseSystemPasswordChar = true;
			this->textBoxProfilePassword5->WordWrap = false;
			// 
			// textBoxProfileUsername5
			// 
			this->textBoxProfileUsername5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->textBoxProfileUsername5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfileUsername5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfileUsername5->CausesValidation = false;
			this->textBoxProfileUsername5->ForeColor = System::Drawing::Color::White;
			this->textBoxProfileUsername5->Location = System::Drawing::Point(309, 9);
			this->textBoxProfileUsername5->Name = L"textBoxProfileUsername5";
			this->textBoxProfileUsername5->ReadOnly = true;
			this->textBoxProfileUsername5->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername5->TabIndex = 14;
			this->textBoxProfileUsername5->Text = L"-";
			this->textBoxProfileUsername5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfileUsername5->UseSystemPasswordChar = true;
			this->textBoxProfileUsername5->WordWrap = false;
			// 
			// labelProfileWebsite5
			// 
			this->labelProfileWebsite5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite5->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite5->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite5->Name = L"labelProfileWebsite5";
			this->labelProfileWebsite5->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite5->TabIndex = 13;
			this->labelProfileWebsite5->Text = L"-";
			this->labelProfileWebsite5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel6
			// 
			this->panel6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel6->Controls->Add(this->textBoxProfilePassword6);
			this->panel6->Controls->Add(this->textBoxProfileUsername6);
			this->panel6->Controls->Add(this->labelProfileWebsite6);
			this->panel6->Location = System::Drawing::Point(20, 462);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(860, 48);
			this->panel6->TabIndex = 0;
			// 
			// textBoxProfilePassword6
			// 
			this->textBoxProfilePassword6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxProfilePassword6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfilePassword6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfilePassword6->CausesValidation = false;
			this->textBoxProfilePassword6->ForeColor = System::Drawing::Color::White;
			this->textBoxProfilePassword6->Location = System::Drawing::Point(537, 9);
			this->textBoxProfilePassword6->Name = L"textBoxProfilePassword6";
			this->textBoxProfilePassword6->ReadOnly = true;
			this->textBoxProfilePassword6->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword6->TabIndex = 18;
			this->textBoxProfilePassword6->Text = L"-";
			this->textBoxProfilePassword6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfilePassword6->UseSystemPasswordChar = true;
			this->textBoxProfilePassword6->WordWrap = false;
			// 
			// textBoxProfileUsername6
			// 
			this->textBoxProfileUsername6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->textBoxProfileUsername6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfileUsername6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfileUsername6->CausesValidation = false;
			this->textBoxProfileUsername6->ForeColor = System::Drawing::Color::White;
			this->textBoxProfileUsername6->Location = System::Drawing::Point(309, 9);
			this->textBoxProfileUsername6->Name = L"textBoxProfileUsername6";
			this->textBoxProfileUsername6->ReadOnly = true;
			this->textBoxProfileUsername6->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername6->TabIndex = 17;
			this->textBoxProfileUsername6->Text = L"-";
			this->textBoxProfileUsername6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfileUsername6->UseSystemPasswordChar = true;
			this->textBoxProfileUsername6->WordWrap = false;
			// 
			// labelProfileWebsite6
			// 
			this->labelProfileWebsite6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite6->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite6->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite6->Name = L"labelProfileWebsite6";
			this->labelProfileWebsite6->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite6->TabIndex = 16;
			this->labelProfileWebsite6->Text = L"-";
			this->labelProfileWebsite6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel7
			// 
			this->panel7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel7->Controls->Add(this->textBoxProfilePassword7);
			this->panel7->Controls->Add(this->textBoxProfileUsername7);
			this->panel7->Controls->Add(this->labelProfileWebsite7);
			this->panel7->Location = System::Drawing::Point(20, 522);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(860, 48);
			this->panel7->TabIndex = 0;
			// 
			// textBoxProfilePassword7
			// 
			this->textBoxProfilePassword7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxProfilePassword7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfilePassword7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfilePassword7->CausesValidation = false;
			this->textBoxProfilePassword7->ForeColor = System::Drawing::Color::White;
			this->textBoxProfilePassword7->Location = System::Drawing::Point(537, 9);
			this->textBoxProfilePassword7->Name = L"textBoxProfilePassword7";
			this->textBoxProfilePassword7->ReadOnly = true;
			this->textBoxProfilePassword7->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword7->TabIndex = 21;
			this->textBoxProfilePassword7->Text = L"-";
			this->textBoxProfilePassword7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfilePassword7->UseSystemPasswordChar = true;
			this->textBoxProfilePassword7->WordWrap = false;
			// 
			// textBoxProfileUsername7
			// 
			this->textBoxProfileUsername7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->textBoxProfileUsername7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfileUsername7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfileUsername7->CausesValidation = false;
			this->textBoxProfileUsername7->ForeColor = System::Drawing::Color::White;
			this->textBoxProfileUsername7->Location = System::Drawing::Point(309, 9);
			this->textBoxProfileUsername7->Name = L"textBoxProfileUsername7";
			this->textBoxProfileUsername7->ReadOnly = true;
			this->textBoxProfileUsername7->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername7->TabIndex = 20;
			this->textBoxProfileUsername7->Text = L"-";
			this->textBoxProfileUsername7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfileUsername7->UseSystemPasswordChar = true;
			this->textBoxProfileUsername7->WordWrap = false;
			// 
			// labelProfileWebsite7
			// 
			this->labelProfileWebsite7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite7->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite7->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite7->Name = L"labelProfileWebsite7";
			this->labelProfileWebsite7->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite7->TabIndex = 19;
			this->labelProfileWebsite7->Text = L"-";
			this->labelProfileWebsite7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel8
			// 
			this->panel8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel8->Controls->Add(this->textBoxProfilePassword8);
			this->panel8->Controls->Add(this->textBoxProfileUsername8);
			this->panel8->Controls->Add(this->labelProfileWebsite8);
			this->panel8->Location = System::Drawing::Point(20, 582);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(860, 48);
			this->panel8->TabIndex = 0;
			// 
			// textBoxProfilePassword8
			// 
			this->textBoxProfilePassword8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxProfilePassword8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfilePassword8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfilePassword8->CausesValidation = false;
			this->textBoxProfilePassword8->ForeColor = System::Drawing::Color::White;
			this->textBoxProfilePassword8->Location = System::Drawing::Point(537, 9);
			this->textBoxProfilePassword8->Name = L"textBoxProfilePassword8";
			this->textBoxProfilePassword8->ReadOnly = true;
			this->textBoxProfilePassword8->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword8->TabIndex = 24;
			this->textBoxProfilePassword8->Text = L"-";
			this->textBoxProfilePassword8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfilePassword8->UseSystemPasswordChar = true;
			this->textBoxProfilePassword8->WordWrap = false;
			// 
			// textBoxProfileUsername8
			// 
			this->textBoxProfileUsername8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->textBoxProfileUsername8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfileUsername8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfileUsername8->CausesValidation = false;
			this->textBoxProfileUsername8->ForeColor = System::Drawing::Color::White;
			this->textBoxProfileUsername8->Location = System::Drawing::Point(309, 9);
			this->textBoxProfileUsername8->Name = L"textBoxProfileUsername8";
			this->textBoxProfileUsername8->ReadOnly = true;
			this->textBoxProfileUsername8->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername8->TabIndex = 23;
			this->textBoxProfileUsername8->Text = L"-";
			this->textBoxProfileUsername8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfileUsername8->UseSystemPasswordChar = true;
			this->textBoxProfileUsername8->WordWrap = false;
			// 
			// labelProfileWebsite8
			// 
			this->labelProfileWebsite8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite8->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite8->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite8->Name = L"labelProfileWebsite8";
			this->labelProfileWebsite8->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite8->TabIndex = 22;
			this->labelProfileWebsite8->Text = L"-";
			this->labelProfileWebsite8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel9
			// 
			this->panel9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel9->Controls->Add(this->textBoxProfilePassword9);
			this->panel9->Controls->Add(this->textBoxProfileUsername9);
			this->panel9->Controls->Add(this->labelProfileWebsite9);
			this->panel9->Location = System::Drawing::Point(20, 642);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(860, 48);
			this->panel9->TabIndex = 0;
			// 
			// textBoxProfilePassword9
			// 
			this->textBoxProfilePassword9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxProfilePassword9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfilePassword9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfilePassword9->CausesValidation = false;
			this->textBoxProfilePassword9->ForeColor = System::Drawing::Color::White;
			this->textBoxProfilePassword9->Location = System::Drawing::Point(537, 6);
			this->textBoxProfilePassword9->Name = L"textBoxProfilePassword9";
			this->textBoxProfilePassword9->ReadOnly = true;
			this->textBoxProfilePassword9->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword9->TabIndex = 27;
			this->textBoxProfilePassword9->Text = L"-";
			this->textBoxProfilePassword9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfilePassword9->UseSystemPasswordChar = true;
			this->textBoxProfilePassword9->WordWrap = false;
			// 
			// textBoxProfileUsername9
			// 
			this->textBoxProfileUsername9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->textBoxProfileUsername9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfileUsername9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfileUsername9->CausesValidation = false;
			this->textBoxProfileUsername9->ForeColor = System::Drawing::Color::White;
			this->textBoxProfileUsername9->Location = System::Drawing::Point(309, 9);
			this->textBoxProfileUsername9->Name = L"textBoxProfileUsername9";
			this->textBoxProfileUsername9->ReadOnly = true;
			this->textBoxProfileUsername9->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername9->TabIndex = 26;
			this->textBoxProfileUsername9->Text = L"-";
			this->textBoxProfileUsername9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfileUsername9->UseSystemPasswordChar = true;
			this->textBoxProfileUsername9->WordWrap = false;
			// 
			// labelProfileWebsite9
			// 
			this->labelProfileWebsite9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite9->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite9->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite9->Name = L"labelProfileWebsite9";
			this->labelProfileWebsite9->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite9->TabIndex = 25;
			this->labelProfileWebsite9->Text = L"-";
			this->labelProfileWebsite9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel10
			// 
			this->panel10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->panel10->Controls->Add(this->textBoxProfilePassword10);
			this->panel10->Controls->Add(this->textBoxProfileUsername10);
			this->panel10->Controls->Add(this->labelProfileWebsite10);
			this->panel10->Location = System::Drawing::Point(20, 702);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(860, 48);
			this->panel10->TabIndex = 0;
			// 
			// textBoxProfilePassword10
			// 
			this->textBoxProfilePassword10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxProfilePassword10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfilePassword10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfilePassword10->CausesValidation = false;
			this->textBoxProfilePassword10->ForeColor = System::Drawing::Color::White;
			this->textBoxProfilePassword10->Location = System::Drawing::Point(537, 9);
			this->textBoxProfilePassword10->Name = L"textBoxProfilePassword10";
			this->textBoxProfilePassword10->ReadOnly = true;
			this->textBoxProfilePassword10->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword10->TabIndex = 30;
			this->textBoxProfilePassword10->Text = L"-";
			this->textBoxProfilePassword10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfilePassword10->UseSystemPasswordChar = true;
			this->textBoxProfilePassword10->WordWrap = false;
			// 
			// textBoxProfileUsername10
			// 
			this->textBoxProfileUsername10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->textBoxProfileUsername10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(114)));
			this->textBoxProfileUsername10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxProfileUsername10->CausesValidation = false;
			this->textBoxProfileUsername10->ForeColor = System::Drawing::Color::White;
			this->textBoxProfileUsername10->Location = System::Drawing::Point(309, 9);
			this->textBoxProfileUsername10->Name = L"textBoxProfileUsername10";
			this->textBoxProfileUsername10->ReadOnly = true;
			this->textBoxProfileUsername10->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername10->TabIndex = 29;
			this->textBoxProfileUsername10->Text = L"-";
			this->textBoxProfileUsername10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxProfileUsername10->UseSystemPasswordChar = true;
			this->textBoxProfileUsername10->WordWrap = false;
			// 
			// labelProfileWebsite10
			// 
			this->labelProfileWebsite10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelProfileWebsite10->ForeColor = System::Drawing::Color::White;
			this->labelProfileWebsite10->Location = System::Drawing::Point(1, 0);
			this->labelProfileWebsite10->Name = L"labelProfileWebsite10";
			this->labelProfileWebsite10->Size = System::Drawing::Size(275, 48);
			this->labelProfileWebsite10->TabIndex = 28;
			this->labelProfileWebsite10->Text = L"-";
			this->labelProfileWebsite10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panelSidebarExtend
			// 
			this->panelSidebarExtend->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->panelSidebarExtend->Controls->Add(this->labelSidebarSettings);
			this->panelSidebarExtend->Controls->Add(this->labelSidebarViewProfiles);
			this->panelSidebarExtend->Controls->Add(this->labelSidebarAddProfiles);
			this->panelSidebarExtend->Location = System::Drawing::Point(75, 75);
			this->panelSidebarExtend->Name = L"panelSidebarExtend";
			this->panelSidebarExtend->Size = System::Drawing::Size(177, 436);
			this->panelSidebarExtend->TabIndex = 13;
			this->panelSidebarExtend->Visible = false;
			// 
			// labelSidebarSettings
			// 
			this->labelSidebarSettings->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->labelSidebarSettings->Enabled = false;
			this->labelSidebarSettings->Font = (gcnew System::Drawing::Font(L"Segoe Print", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSidebarSettings->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->labelSidebarSettings->Location = System::Drawing::Point(0, 330);
			this->labelSidebarSettings->Name = L"labelSidebarSettings";
			this->labelSidebarSettings->Size = System::Drawing::Size(177, 54);
			this->labelSidebarSettings->TabIndex = 14;
			this->labelSidebarSettings->Text = L"Settings";
			this->labelSidebarSettings->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelSidebarViewProfiles
			// 
			this->labelSidebarViewProfiles->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->labelSidebarViewProfiles->Enabled = false;
			this->labelSidebarViewProfiles->Font = (gcnew System::Drawing::Font(L"Segoe Print", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSidebarViewProfiles->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->labelSidebarViewProfiles->Location = System::Drawing::Point(0, 90);
			this->labelSidebarViewProfiles->Name = L"labelSidebarViewProfiles";
			this->labelSidebarViewProfiles->Size = System::Drawing::Size(177, 54);
			this->labelSidebarViewProfiles->TabIndex = 13;
			this->labelSidebarViewProfiles->Text = L"View Profiles";
			this->labelSidebarViewProfiles->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelSidebarAddProfiles
			// 
			this->labelSidebarAddProfiles->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->labelSidebarAddProfiles->Enabled = false;
			this->labelSidebarAddProfiles->Font = (gcnew System::Drawing::Font(L"Segoe Print", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSidebarAddProfiles->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->labelSidebarAddProfiles->Location = System::Drawing::Point(0, 30);
			this->labelSidebarAddProfiles->Name = L"labelSidebarAddProfiles";
			this->labelSidebarAddProfiles->Size = System::Drawing::Size(177, 54);
			this->labelSidebarAddProfiles->TabIndex = 12;
			this->labelSidebarAddProfiles->Text = L"Add Profiles";
			this->labelSidebarAddProfiles->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ProfilesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->ClientSize = System::Drawing::Size(984, 511);
			this->Controls->Add(this->panelSidebarExtend);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelTopbar);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"ProfilesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Profiles";
			this->panelSidebar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxProfiles))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSettings))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAddProfile))->EndInit();
			this->panelTopbar->ResumeLayout(false);
			this->panelTopbar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMenu))->EndInit();
			this->panelContent->ResumeLayout(false);
			this->panelContent->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowingSlot1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHidingSlot1))->EndInit();
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
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panelSidebarExtend->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: PageProperties pageProps;

	private:  System::Drawing::Point firstPanelPoint;

	public: int profileCount;

	public: User^ user = nullptr;

	public: Profiles^ profile = nullptr;
	public: Profiles^ trashProfile = nullptr;

	private: Panels^ panel = nullptr;

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
	private: System::Void pictureBoxDelProf1_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite1->Text != "-" || textBoxProfileUsername1->Text != "-" || textBoxProfilePassword1->Text != "-")
		{
			// current slot
			int slot = 1;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != slot)
			{
				if (currProfile->id < slot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (panel->id != slot)
			{
				if (panel->id < slot)
					panel = panel->next;
				else
					panel = panel->prev;
			}
			// refresh slot labels
			RefreshLabels(panel);

			// hide slot
			//panel->panel->Visible = false;
		}
	}
	private: System::Void pictureBoxDelProf2_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite2->Text != "-" || textBoxProfileUsername2->Text != "-" || textBoxProfilePassword2->Text != "-")
		{
			// current slot
			int slot = 2;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != slot)
			{
				if (currProfile->id < slot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (panel->id != slot)
			{
				if (panel->id < slot)
					panel = panel->next;
				else
					panel = panel->prev;
			}
			// refresh slot labels
			RefreshLabels(panel);

			// hide slot
			//panel->panel->Visible = false;
		}
	}
	private: System::Void pictureBoxDelProf3_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite3->Text != "-" || textBoxProfileUsername3->Text != "-" || textBoxProfilePassword3->Text != "-")
		{
			// current slot
			int slot = 3;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != slot)
			{
				if (currProfile->id < slot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (panel->id != slot)
			{
				if (panel->id < slot)
					panel = panel->next;
				else
					panel = panel->prev;
			}
			// refresh slot labels
			RefreshLabels(panel);

			// hide slot
			//panel->panel->Visible = false;
		}
	}
	private: System::Void pictureBoxDelProf4_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite4->Text != "-" || textBoxProfileUsername4->Text != "-" || textBoxProfilePassword4->Text != "-")
		{
			// current slot
			int slot = 4;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != slot)
			{
				if (currProfile->id < slot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (panel->id != slot)
			{
				if (panel->id < slot)
					panel = panel->next;
				else
					panel = panel->prev;
			}
			// refresh slot labels
			RefreshLabels(panel);

			// hide slot
			//panel->panel->Visible = false;
		}
	}
	private: System::Void pictureBoxDelProf5_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite5->Text != "-" || textBoxProfileUsername5->Text != "-" || textBoxProfilePassword5->Text != "-")
		{
			// current slot
			int slot = 5;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != slot)
			{
				if (currProfile->id < slot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (panel->id != slot)
			{
				if (panel->id < slot)
					panel = panel->next;
				else
					panel = panel->prev;
			}
			// refresh slot labels
			RefreshLabels(panel);

			// hide slot
			//panel->panel->Visible = false;
		}
	}
	private: System::Void pictureBoxDelProf6_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite6->Text != "-" || textBoxProfileUsername6->Text != "-" || textBoxProfilePassword6->Text != "-")
		{
			// current slot
			int slot = 6;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != slot)
			{
				if (currProfile->id < slot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (panel->id != slot)
			{
				if (panel->id < slot)
					panel = panel->next;
				else
					panel = panel->prev;
			}
			// refresh slot labels
			RefreshLabels(panel);

			// hide slot
			//panel->panel->Visible = false;
		}
	}
	private: System::Void pictureBoxDelProf7_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite7->Text != "-" || textBoxProfileUsername7->Text != "-" || textBoxProfilePassword7->Text != "-")
		{
			// current slot
			int slot = 7;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != slot)
			{
				if (currProfile->id < slot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (panel->id != slot)
			{
				if (panel->id < slot)
					panel = panel->next;
				else
					panel = panel->prev;
			}
			// refresh slot labels
			RefreshLabels(panel);

			// hide slot
			//panel->panel->Visible = false;
		}
	}
	private: System::Void pictureBoxDelProf8_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite8->Text != "-" || textBoxProfileUsername8->Text != "-" || textBoxProfilePassword8->Text != "-")
		{
			// current slot
			int slot = 8;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != slot)
			{
				if (currProfile->id < slot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (panel->id != slot)
			{
				if (panel->id < slot)
					panel = panel->next;
				else
					panel = panel->prev;
			}
			// refresh slot labels
			RefreshLabels(panel);

			// hide slot
			//panel->panel->Visible = false;
		}
	}
	private: System::Void pictureBoxDelProf9_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite9->Text != "-" || textBoxProfileUsername9->Text != "-" || textBoxProfilePassword9->Text != "-")
		{
			// current slot
			int slot = 9;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != slot)
			{
				if (currProfile->id < slot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (panel->id != slot)
			{
				if (panel->id < slot)
					panel = panel->next;
				else
					panel = panel->prev;
			}
			// refresh slot labels
			RefreshLabels(panel);

			// hide slot
			//panel->panel->Visible = false;
		}
	}
	private: System::Void pictureBoxDelProf10_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite10->Text != "-" || textBoxProfileUsername10->Text != "-" || textBoxProfilePassword10->Text != "-")
		{
			// current slot
			int slot = 10;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != slot)
			{
				if (currProfile->id < slot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (panel->id != slot)
			{
				if (panel->id < slot)
					panel = panel->next;
				else
					panel = panel->prev;
			}
			// refresh slot labels
			RefreshLabels(panel);

			// hide slot
			//panel->panel->Visible = false;
		}
	}

	private: void RemoveProfile(String^ _web, String^ _user, String^ _pass) {
		// establish connection to database
		try
		{
			String^ connString = "Data Source=localhost;Initial Catalog=passuniteusers;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// build sql query
			String^ sqlQuery = "DELETE FROM profiles " +
				"WHERE ";
			// website
			{
				if (_web == "-")
					sqlQuery += "website IS NULL AND ";
				else
					sqlQuery += "website=\'" + _web + "\' AND ";
			}
			// username
			{
				if (_user == "-")
					sqlQuery += "profileUser IS NULL AND ";
				else
					sqlQuery += "profileUser=\'" + _user + "\' AND ";
			}
			// password
			{
				if (_pass == "-")
					sqlQuery += "profilePass IS NULL";
				else
					sqlQuery += "profilePass=\'" + _pass + "\'";
			}

			SqlCommand command(sqlQuery, % sqlConn);

			// execute
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

		// decrement profile count
		profileCount--;
	}

		   //private: void RefreshProfiles(Profiles^% _profile) {

		   //}

		   //private: void CleanupProfiles()
		   //{
		   //	// loop from first to last profile
		   //	while (profile->prev != nullptr)
		   //		profile = profile->prev;

		   //	while (true)
		   //	{
		   //		// verify next node's id = 1 + curr->id
		   //		if (profile->next == nullptr)
		   //			break;
		   //	}
		   //}

	private: void RefreshLabels(Panels^% _panel)
	{
		while (true)
		{
			if (panel->id <= profileCount)
			{
				panel->labelProfileWebsite->Text = panel->next->labelProfileWebsite->Text;
				panel->textBoxProfileUsername->Text = panel->next->textBoxProfileUsername->Text;
				panel->textBoxProfilePassword->Text = panel->next->textBoxProfilePassword->Text;
			}
			else
			{
				panel->labelProfileWebsite->Text = "-";
				panel->textBoxProfileUsername->Text = "-";
				panel->textBoxProfilePassword->Text = "-";
			}

			if (panel->next == nullptr)
				break;
			else
				panel = panel->next;
		}
	}
	private: System::Void pictureBoxMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		// toggle extended sidebar
		panelSidebarExtend->Visible = !panelSidebarExtend->Visible;
	}
	private: System::Void pictureBoxIcons_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		// show extended sidebar
		panelSidebarExtend->Visible = true;
	}
	private: System::Void pictureBoxIcons_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		// hide extended sidebar
		panelSidebarExtend->Visible = false;
	}
	private: System::Void pictureBoxHidingSlot1_Click(System::Object^ sender, System::EventArgs^ e) {
		// show slot 1
		textBoxProfileUsername1->UseSystemPasswordChar = false;
		textBoxProfilePassword1->UseSystemPasswordChar = false;

		// toggle picture
		pictureBoxHidingSlot1->Visible = false;
		pictureBoxShowingSlot1->Visible = true;
	}
	private: System::Void pictureBoxShowingSlot1_Click(System::Object^ sender, System::EventArgs^ e) {
		// hide slot 1
		textBoxProfileUsername1->UseSystemPasswordChar = true;
		textBoxProfilePassword1->UseSystemPasswordChar = true;

		// toggle picture
		pictureBoxShowingSlot1->Visible = false;
		pictureBoxHidingSlot1->Visible = true;
	}
	};
}

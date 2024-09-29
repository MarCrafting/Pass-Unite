#pragma once
#include "PageProperties.h"
#include "User.h"
#include "Generator.h"
#include "Settings.h"
#include "Profiles.h"
#include "Slots.h"

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

			// save slots into a list in order to access them
			// Slot 1
			slot = gcnew Slots();										// create pointer
			slot->id = 1;												// assign slot1 ID
			slot->panel = panel1;										// assign panel in slot1
			slot->labelProfileWebsite = labelProfileWebsite1;			// assign to website label
			slot->textBoxProfileUsername = textBoxProfileUsername1;		// assign to username textbox
			slot->textBoxProfilePassword = textBoxProfilePassword1;		// assign to password textbox
			slot->hide = pictureBoxHideSlot1;							// hide slot info
			slot->show = pictureBoxShowSlot1;							// show slot info
			slot->clear = pictureBoxDelProf1;							// clear slot info
			// Slot 2
			Slots^ nextSlot = gcnew Slots();							// create pointer
			nextSlot->id = 2;											// assign slot2 ID
			nextSlot->panel = panel2;									// assign panel in slot2
			nextSlot->labelProfileWebsite = labelProfileWebsite2;		// assign to website label
			nextSlot->textBoxProfileUsername = textBoxProfileUsername2;	// assign to username textbox
			nextSlot->textBoxProfilePassword = textBoxProfilePassword2;	// assign to password textbox
			nextSlot->hide = pictureBoxHideSlot2;						// hide slot info
			nextSlot->show = pictureBoxShowSlot2;						// show slot info
			nextSlot->clear = pictureBoxDelProf2;						// clear slot info
			// Link Slots 1 & 2
			slot->next = nextSlot;										// create link between pointers
			nextSlot->prev = slot;

			slot = nextSlot;											// traverse through node list
			// Slot 3
			nextSlot = gcnew Slots();
			nextSlot->id = 3;
			nextSlot->panel = panel3;
			nextSlot->labelProfileWebsite = labelProfileWebsite3;
			nextSlot->textBoxProfileUsername = textBoxProfileUsername3;
			nextSlot->textBoxProfilePassword = textBoxProfilePassword3;
			nextSlot->hide = pictureBoxHideSlot3;
			nextSlot->show = pictureBoxShowSlot3;
			nextSlot->clear = pictureBoxDelProf3;
			// Link Slots 2 & 3
			slot->next = nextSlot;
			nextSlot->prev = slot;

			slot = nextSlot;
			// Slot 4
			nextSlot = gcnew Slots();
			nextSlot->id = 4;
			nextSlot->panel = panel4;
			nextSlot->labelProfileWebsite = labelProfileWebsite4;
			nextSlot->textBoxProfileUsername = textBoxProfileUsername4;
			nextSlot->textBoxProfilePassword = textBoxProfilePassword4;
			nextSlot->hide = pictureBoxHideSlot4;
			nextSlot->show = pictureBoxShowSlot4;
			nextSlot->clear = pictureBoxDelProf4;
			// Link Slots 3 & 4
			slot->next = nextSlot;
			nextSlot->prev = slot;

			slot = nextSlot;
			// Slot 5
			nextSlot = gcnew Slots();
			nextSlot->id = 5;
			nextSlot->panel = panel5;
			nextSlot->labelProfileWebsite = labelProfileWebsite5;
			nextSlot->textBoxProfileUsername = textBoxProfileUsername5;
			nextSlot->textBoxProfilePassword = textBoxProfilePassword5;
			nextSlot->hide = pictureBoxHideSlot5;
			nextSlot->show = pictureBoxShowSlot5;
			nextSlot->clear = pictureBoxDelProf5;
			// Link Slots 4 & 5
			slot->next = nextSlot;
			nextSlot->prev = slot;

			slot = nextSlot;
			// Slot 6
			nextSlot = gcnew Slots();
			nextSlot->id = 6;
			nextSlot->panel = panel6;
			nextSlot->labelProfileWebsite = labelProfileWebsite6;
			nextSlot->textBoxProfileUsername = textBoxProfileUsername6;
			nextSlot->textBoxProfilePassword = textBoxProfilePassword6;
			nextSlot->hide = pictureBoxHideSlot6;
			nextSlot->show = pictureBoxShowSlot6;
			nextSlot->clear = pictureBoxDelProf6;
			// Link Slot 5 & 6
			slot->next = nextSlot;
			nextSlot->prev = slot;

			slot = nextSlot;
			// Slot 7
			nextSlot = gcnew Slots();
			nextSlot->id = 7;
			nextSlot->panel = panel7;
			nextSlot->labelProfileWebsite = labelProfileWebsite7;
			nextSlot->textBoxProfileUsername = textBoxProfileUsername7;
			nextSlot->textBoxProfilePassword = textBoxProfilePassword7;
			nextSlot->hide = pictureBoxHideSlot7;
			nextSlot->show = pictureBoxShowSlot7;
			nextSlot->clear = pictureBoxDelProf7;
			// Link Slot 6 & 7
			slot->next = nextSlot;
			nextSlot->prev = slot;

			slot = nextSlot;
			// Slot 8
			nextSlot = gcnew Slots();
			nextSlot->id = 8;
			nextSlot->panel = panel8;
			nextSlot->labelProfileWebsite = labelProfileWebsite8;
			nextSlot->textBoxProfileUsername = textBoxProfileUsername8;
			nextSlot->textBoxProfilePassword = textBoxProfilePassword8;
			nextSlot->hide = pictureBoxHideSlot8;
			nextSlot->show = pictureBoxShowSlot8;
			nextSlot->clear = pictureBoxDelProf8;
			// Link 7 & 8
			slot->next = nextSlot;
			nextSlot->prev = slot;

			slot = nextSlot;
			// Slot 9
			nextSlot = gcnew Slots();
			nextSlot->id = 9;
			nextSlot->panel = panel9;
			nextSlot->labelProfileWebsite = labelProfileWebsite9;
			nextSlot->textBoxProfileUsername = textBoxProfileUsername9;
			nextSlot->textBoxProfilePassword = textBoxProfilePassword9;
			nextSlot->hide = pictureBoxHideSlot9;
			nextSlot->show = pictureBoxShowSlot9;
			nextSlot->clear = pictureBoxDelProf9;
			// Link 8 & 9
			slot->next = nextSlot;
			nextSlot->prev = slot;

			slot = nextSlot;
			// Slot 10
			nextSlot = gcnew Slots();
			nextSlot->id = 10;
			nextSlot->panel = panel5;
			nextSlot->labelProfileWebsite = labelProfileWebsite10;
			nextSlot->textBoxProfileUsername = textBoxProfileUsername10;
			nextSlot->textBoxProfilePassword = textBoxProfilePassword10;
			nextSlot->hide = pictureBoxHideSlot10;
			nextSlot->show = pictureBoxShowSlot10;
			nextSlot->clear = pictureBoxDelProf10;
			// Link Slots 9 & 10
			slot->next = nextSlot;
			nextSlot->prev = slot;

			// LAST SLOT
			nextSlot->next = nullptr;
			////////////////////////////////////////////////////////////////////////////////////////////

			// set slot pointer to first node
			while (slot->prev != nullptr)
			{
				slot = slot->prev;
			}
			// traversal node
			Slots^ currSlot = slot;

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
						// make next slot visible
						currSlot->next->panel->Visible = true;
						currSlot->next->show->Visible = true;
						currSlot->next->clear->Visible = true;

						// copy label values into next slot
						currSlot->next->labelProfileWebsite->Text = currSlot->labelProfileWebsite->Text;
						currSlot->next->textBoxProfileUsername->Text = currSlot->textBoxProfileUsername->Text;
						currSlot->next->textBoxProfilePassword->Text = currSlot->textBoxProfilePassword->Text;

						if (currSlot != slot)
						{
							// copy previous slots to their next slot
							int i = 0;						// back jump counter
							while (currSlot->prev != slot)
							{
								currSlot = currSlot->prev;	// back jump
								i++;						// increment back jump

								// assigns next slot to the current slot values
								currSlot->next->labelProfileWebsite->Text = currSlot->labelProfileWebsite->Text;
								currSlot->next->textBoxProfileUsername->Text = currSlot->textBoxProfileUsername->Text;
								currSlot->next->textBoxProfilePassword->Text = currSlot->textBoxProfilePassword->Text;
							}

							if (currSlot->prev == slot)
							{
								// assigns current slot to the previous slot values
								currSlot->labelProfileWebsite->Text = currSlot->prev->labelProfileWebsite->Text;
								currSlot->textBoxProfileUsername->Text = currSlot->prev->textBoxProfileUsername->Text;
								currSlot->textBoxProfilePassword->Text = currSlot->prev->textBoxProfilePassword->Text;
							}

							// jump forward to correct position
							for (int j = 0; j < i; j++)
								currSlot = currSlot->next;
						}

						if (currSlot->next != nullptr)
							currSlot = currSlot->next;

					}

					// update first slot
					slot->labelProfileWebsite->Text = profile->website;
					slot->textBoxProfileUsername->Text = profile->username;
					slot->textBoxProfilePassword->Text = profile->password;

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





	private: System::Windows::Forms::PictureBox^ pictureBoxHideSlot1;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowSlot2;




	private: System::Windows::Forms::PictureBox^ pictureBoxHideSlot2;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowSlot3;



	private: System::Windows::Forms::PictureBox^ pictureBoxHideSlot3;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowSlot4;



	private: System::Windows::Forms::PictureBox^ pictureBoxHideSlot4;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowSlot5;



	private: System::Windows::Forms::PictureBox^ pictureBoxHideSlot5;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowSlot6;



	private: System::Windows::Forms::PictureBox^ pictureBoxHideSlot6;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowSlot7;



	private: System::Windows::Forms::PictureBox^ pictureBoxHideSlot7;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowSlot8;



	private: System::Windows::Forms::PictureBox^ pictureBoxHideSlot8;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowSlot9;



	private: System::Windows::Forms::PictureBox^ pictureBoxHideSlot9;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowSlot10;



	private: System::Windows::Forms::PictureBox^ pictureBoxHideSlot10;

	private: System::Windows::Forms::PictureBox^ pictureBoxShowSlot1;
private: System::Windows::Forms::Panel^ panelSidebarExtend;
private: System::Windows::Forms::Label^ labelSidebarSettings;
private: System::Windows::Forms::Label^ labelSidebarViewProfiles;
private: System::Windows::Forms::Label^ labelSidebarAddProfiles;




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
			this->pictureBoxHideSlot10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowSlot10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHideSlot9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowSlot9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHideSlot8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowSlot8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHideSlot7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowSlot7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHideSlot6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowSlot6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHideSlot5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowSlot5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHideSlot4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowSlot4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHideSlot3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowSlot3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHideSlot2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowSlot2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxHideSlot1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxShowSlot1 = (gcnew System::Windows::Forms::PictureBox());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot1))->BeginInit();
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
			this->panelContent->Controls->Add(this->pictureBoxHideSlot10);
			this->panelContent->Controls->Add(this->pictureBoxShowSlot10);
			this->panelContent->Controls->Add(this->pictureBoxHideSlot9);
			this->panelContent->Controls->Add(this->pictureBoxShowSlot9);
			this->panelContent->Controls->Add(this->pictureBoxHideSlot8);
			this->panelContent->Controls->Add(this->pictureBoxShowSlot8);
			this->panelContent->Controls->Add(this->pictureBoxHideSlot7);
			this->panelContent->Controls->Add(this->pictureBoxShowSlot7);
			this->panelContent->Controls->Add(this->pictureBoxHideSlot6);
			this->panelContent->Controls->Add(this->pictureBoxShowSlot6);
			this->panelContent->Controls->Add(this->pictureBoxHideSlot5);
			this->panelContent->Controls->Add(this->pictureBoxShowSlot5);
			this->panelContent->Controls->Add(this->pictureBoxHideSlot4);
			this->panelContent->Controls->Add(this->pictureBoxShowSlot4);
			this->panelContent->Controls->Add(this->pictureBoxHideSlot3);
			this->panelContent->Controls->Add(this->pictureBoxShowSlot3);
			this->panelContent->Controls->Add(this->pictureBoxHideSlot2);
			this->panelContent->Controls->Add(this->pictureBoxShowSlot2);
			this->panelContent->Controls->Add(this->pictureBoxHideSlot1);
			this->panelContent->Controls->Add(this->pictureBoxShowSlot1);
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
			// pictureBoxHideSlot10
			// 
			this->pictureBoxHideSlot10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxHideSlot10->Enabled = false;
			this->pictureBoxHideSlot10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHideSlot10.Image")));
			this->pictureBoxHideSlot10->Location = System::Drawing::Point(869, 718);
			this->pictureBoxHideSlot10->Name = L"pictureBoxHideSlot10";
			this->pictureBoxHideSlot10->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHideSlot10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHideSlot10->TabIndex = 39;
			this->pictureBoxHideSlot10->TabStop = false;
			this->pictureBoxHideSlot10->Visible = false;
			// 
			// pictureBoxShowSlot10
			// 
			this->pictureBoxShowSlot10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxShowSlot10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowSlot10.Image")));
			this->pictureBoxShowSlot10->Location = System::Drawing::Point(869, 718);
			this->pictureBoxShowSlot10->Name = L"pictureBoxShowSlot10";
			this->pictureBoxShowSlot10->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowSlot10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowSlot10->TabIndex = 40;
			this->pictureBoxShowSlot10->TabStop = false;
			this->pictureBoxShowSlot10->Visible = false;
			this->pictureBoxShowSlot10->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxToggleSlot10_Click);
			// 
			// pictureBoxHideSlot9
			// 
			this->pictureBoxHideSlot9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxHideSlot9->Enabled = false;
			this->pictureBoxHideSlot9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHideSlot9.Image")));
			this->pictureBoxHideSlot9->Location = System::Drawing::Point(869, 656);
			this->pictureBoxHideSlot9->Name = L"pictureBoxHideSlot9";
			this->pictureBoxHideSlot9->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHideSlot9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHideSlot9->TabIndex = 37;
			this->pictureBoxHideSlot9->TabStop = false;
			this->pictureBoxHideSlot9->Visible = false;
			// 
			// pictureBoxShowSlot9
			// 
			this->pictureBoxShowSlot9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxShowSlot9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowSlot9.Image")));
			this->pictureBoxShowSlot9->Location = System::Drawing::Point(869, 656);
			this->pictureBoxShowSlot9->Name = L"pictureBoxShowSlot9";
			this->pictureBoxShowSlot9->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowSlot9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowSlot9->TabIndex = 38;
			this->pictureBoxShowSlot9->TabStop = false;
			this->pictureBoxShowSlot9->Visible = false;
			this->pictureBoxShowSlot9->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxToggleSlot9_Click);
			// 
			// pictureBoxHideSlot8
			// 
			this->pictureBoxHideSlot8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxHideSlot8->Enabled = false;
			this->pictureBoxHideSlot8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHideSlot8.Image")));
			this->pictureBoxHideSlot8->Location = System::Drawing::Point(869, 596);
			this->pictureBoxHideSlot8->Name = L"pictureBoxHideSlot8";
			this->pictureBoxHideSlot8->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHideSlot8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHideSlot8->TabIndex = 35;
			this->pictureBoxHideSlot8->TabStop = false;
			this->pictureBoxHideSlot8->Visible = false;
			// 
			// pictureBoxShowSlot8
			// 
			this->pictureBoxShowSlot8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxShowSlot8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowSlot8.Image")));
			this->pictureBoxShowSlot8->Location = System::Drawing::Point(869, 596);
			this->pictureBoxShowSlot8->Name = L"pictureBoxShowSlot8";
			this->pictureBoxShowSlot8->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowSlot8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowSlot8->TabIndex = 36;
			this->pictureBoxShowSlot8->TabStop = false;
			this->pictureBoxShowSlot8->Visible = false;
			this->pictureBoxShowSlot8->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxToggleSlot8_Click);
			// 
			// pictureBoxHideSlot7
			// 
			this->pictureBoxHideSlot7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxHideSlot7->Enabled = false;
			this->pictureBoxHideSlot7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHideSlot7.Image")));
			this->pictureBoxHideSlot7->Location = System::Drawing::Point(869, 537);
			this->pictureBoxHideSlot7->Name = L"pictureBoxHideSlot7";
			this->pictureBoxHideSlot7->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHideSlot7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHideSlot7->TabIndex = 33;
			this->pictureBoxHideSlot7->TabStop = false;
			this->pictureBoxHideSlot7->Visible = false;
			// 
			// pictureBoxShowSlot7
			// 
			this->pictureBoxShowSlot7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxShowSlot7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowSlot7.Image")));
			this->pictureBoxShowSlot7->Location = System::Drawing::Point(869, 537);
			this->pictureBoxShowSlot7->Name = L"pictureBoxShowSlot7";
			this->pictureBoxShowSlot7->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowSlot7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowSlot7->TabIndex = 34;
			this->pictureBoxShowSlot7->TabStop = false;
			this->pictureBoxShowSlot7->Visible = false;
			this->pictureBoxShowSlot7->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxToggleSlot7_Click);
			// 
			// pictureBoxHideSlot6
			// 
			this->pictureBoxHideSlot6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxHideSlot6->Enabled = false;
			this->pictureBoxHideSlot6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHideSlot6.Image")));
			this->pictureBoxHideSlot6->Location = System::Drawing::Point(869, 477);
			this->pictureBoxHideSlot6->Name = L"pictureBoxHideSlot6";
			this->pictureBoxHideSlot6->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHideSlot6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHideSlot6->TabIndex = 31;
			this->pictureBoxHideSlot6->TabStop = false;
			this->pictureBoxHideSlot6->Visible = false;
			// 
			// pictureBoxShowSlot6
			// 
			this->pictureBoxShowSlot6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxShowSlot6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowSlot6.Image")));
			this->pictureBoxShowSlot6->Location = System::Drawing::Point(869, 477);
			this->pictureBoxShowSlot6->Name = L"pictureBoxShowSlot6";
			this->pictureBoxShowSlot6->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowSlot6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowSlot6->TabIndex = 32;
			this->pictureBoxShowSlot6->TabStop = false;
			this->pictureBoxShowSlot6->Visible = false;
			this->pictureBoxShowSlot6->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxToggleSlot6_Click);
			// 
			// pictureBoxHideSlot5
			// 
			this->pictureBoxHideSlot5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxHideSlot5->Enabled = false;
			this->pictureBoxHideSlot5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHideSlot5.Image")));
			this->pictureBoxHideSlot5->Location = System::Drawing::Point(869, 417);
			this->pictureBoxHideSlot5->Name = L"pictureBoxHideSlot5";
			this->pictureBoxHideSlot5->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHideSlot5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHideSlot5->TabIndex = 29;
			this->pictureBoxHideSlot5->TabStop = false;
			this->pictureBoxHideSlot5->Visible = false;
			// 
			// pictureBoxShowSlot5
			// 
			this->pictureBoxShowSlot5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxShowSlot5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowSlot5.Image")));
			this->pictureBoxShowSlot5->Location = System::Drawing::Point(869, 417);
			this->pictureBoxShowSlot5->Name = L"pictureBoxShowSlot5";
			this->pictureBoxShowSlot5->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowSlot5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowSlot5->TabIndex = 30;
			this->pictureBoxShowSlot5->TabStop = false;
			this->pictureBoxShowSlot5->Visible = false;
			this->pictureBoxShowSlot5->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxToggleSlot5_Click);
			// 
			// pictureBoxHideSlot4
			// 
			this->pictureBoxHideSlot4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxHideSlot4->Enabled = false;
			this->pictureBoxHideSlot4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHideSlot4.Image")));
			this->pictureBoxHideSlot4->Location = System::Drawing::Point(869, 355);
			this->pictureBoxHideSlot4->Name = L"pictureBoxHideSlot4";
			this->pictureBoxHideSlot4->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHideSlot4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHideSlot4->TabIndex = 27;
			this->pictureBoxHideSlot4->TabStop = false;
			this->pictureBoxHideSlot4->Visible = false;
			// 
			// pictureBoxShowSlot4
			// 
			this->pictureBoxShowSlot4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxShowSlot4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowSlot4.Image")));
			this->pictureBoxShowSlot4->Location = System::Drawing::Point(869, 355);
			this->pictureBoxShowSlot4->Name = L"pictureBoxShowSlot4";
			this->pictureBoxShowSlot4->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowSlot4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowSlot4->TabIndex = 28;
			this->pictureBoxShowSlot4->TabStop = false;
			this->pictureBoxShowSlot4->Visible = false;
			this->pictureBoxShowSlot4->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxToggleSlot4_Click);
			// 
			// pictureBoxHideSlot3
			// 
			this->pictureBoxHideSlot3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxHideSlot3->Enabled = false;
			this->pictureBoxHideSlot3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHideSlot3.Image")));
			this->pictureBoxHideSlot3->Location = System::Drawing::Point(869, 295);
			this->pictureBoxHideSlot3->Name = L"pictureBoxHideSlot3";
			this->pictureBoxHideSlot3->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHideSlot3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHideSlot3->TabIndex = 25;
			this->pictureBoxHideSlot3->TabStop = false;
			this->pictureBoxHideSlot3->Visible = false;
			// 
			// pictureBoxShowSlot3
			// 
			this->pictureBoxShowSlot3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxShowSlot3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowSlot3.Image")));
			this->pictureBoxShowSlot3->Location = System::Drawing::Point(869, 295);
			this->pictureBoxShowSlot3->Name = L"pictureBoxShowSlot3";
			this->pictureBoxShowSlot3->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowSlot3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowSlot3->TabIndex = 26;
			this->pictureBoxShowSlot3->TabStop = false;
			this->pictureBoxShowSlot3->Visible = false;
			this->pictureBoxShowSlot3->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxToggleSlot3_Click);
			// 
			// pictureBoxHideSlot2
			// 
			this->pictureBoxHideSlot2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxHideSlot2->Enabled = false;
			this->pictureBoxHideSlot2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHideSlot2.Image")));
			this->pictureBoxHideSlot2->Location = System::Drawing::Point(869, 236);
			this->pictureBoxHideSlot2->Name = L"pictureBoxHideSlot2";
			this->pictureBoxHideSlot2->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHideSlot2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHideSlot2->TabIndex = 23;
			this->pictureBoxHideSlot2->TabStop = false;
			this->pictureBoxHideSlot2->Visible = false;
			// 
			// pictureBoxShowSlot2
			// 
			this->pictureBoxShowSlot2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxShowSlot2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowSlot2.Image")));
			this->pictureBoxShowSlot2->Location = System::Drawing::Point(869, 236);
			this->pictureBoxShowSlot2->Name = L"pictureBoxShowSlot2";
			this->pictureBoxShowSlot2->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowSlot2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowSlot2->TabIndex = 24;
			this->pictureBoxShowSlot2->TabStop = false;
			this->pictureBoxShowSlot2->Visible = false;
			this->pictureBoxShowSlot2->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxToggleSlot2_Click);
			// 
			// pictureBoxHideSlot1
			// 
			this->pictureBoxHideSlot1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxHideSlot1->Enabled = false;
			this->pictureBoxHideSlot1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHideSlot1.Image")));
			this->pictureBoxHideSlot1->Location = System::Drawing::Point(869, 176);
			this->pictureBoxHideSlot1->Name = L"pictureBoxHideSlot1";
			this->pictureBoxHideSlot1->Size = System::Drawing::Size(20, 20);
			this->pictureBoxHideSlot1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHideSlot1->TabIndex = 21;
			this->pictureBoxHideSlot1->TabStop = false;
			this->pictureBoxHideSlot1->Visible = false;
			// 
			// pictureBoxShowSlot1
			// 
			this->pictureBoxShowSlot1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxShowSlot1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxShowSlot1.Image")));
			this->pictureBoxShowSlot1->Location = System::Drawing::Point(869, 176);
			this->pictureBoxShowSlot1->Name = L"pictureBoxShowSlot1";
			this->pictureBoxShowSlot1->Size = System::Drawing::Size(20, 20);
			this->pictureBoxShowSlot1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxShowSlot1->TabIndex = 22;
			this->pictureBoxShowSlot1->TabStop = false;
			this->pictureBoxShowSlot1->Click += gcnew System::EventHandler(this, &ProfilesForm::pictureBoxToggleSlot1_Click);
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
			this->pictureBoxDelProf2->Visible = false;
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
			this->pictureBoxDelProf3->Visible = false;
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
			this->pictureBoxDelProf4->Visible = false;
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
			this->pictureBoxDelProf5->Visible = false;
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
			this->pictureBoxDelProf6->Visible = false;
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
			this->pictureBoxDelProf10->Visible = false;
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
			this->pictureBoxDelProf9->Visible = false;
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
			this->pictureBoxDelProf8->Visible = false;
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
			this->pictureBoxDelProf7->Visible = false;
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
			this->textBoxProfilePassword1->PasswordChar = '*';
			this->textBoxProfilePassword1->ReadOnly = true;
			this->textBoxProfilePassword1->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword1->TabIndex = 3;
			this->textBoxProfilePassword1->TabStop = false;
			this->textBoxProfilePassword1->Text = L"-";
			this->textBoxProfilePassword1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->textBoxProfileUsername1->PasswordChar = '*';
			this->textBoxProfileUsername1->ReadOnly = true;
			this->textBoxProfileUsername1->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername1->TabIndex = 2;
			this->textBoxProfileUsername1->TabStop = false;
			this->textBoxProfileUsername1->Text = L"-";
			this->textBoxProfileUsername1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->panel2->Visible = false;
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
			this->textBoxProfilePassword2->PasswordChar = '*';
			this->textBoxProfilePassword2->ReadOnly = true;
			this->textBoxProfilePassword2->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword2->TabIndex = 6;
			this->textBoxProfilePassword2->TabStop = false;
			this->textBoxProfilePassword2->Text = L"-";
			this->textBoxProfilePassword2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->textBoxProfileUsername2->PasswordChar = '*';
			this->textBoxProfileUsername2->ReadOnly = true;
			this->textBoxProfileUsername2->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername2->TabIndex = 5;
			this->textBoxProfileUsername2->TabStop = false;
			this->textBoxProfileUsername2->Text = L"-";
			this->textBoxProfileUsername2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->panel3->Visible = false;
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
			this->textBoxProfilePassword3->PasswordChar = '*';
			this->textBoxProfilePassword3->ReadOnly = true;
			this->textBoxProfilePassword3->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword3->TabIndex = 9;
			this->textBoxProfilePassword3->TabStop = false;
			this->textBoxProfilePassword3->Text = L"-";
			this->textBoxProfilePassword3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->textBoxProfileUsername3->PasswordChar = '*';
			this->textBoxProfileUsername3->ReadOnly = true;
			this->textBoxProfileUsername3->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername3->TabIndex = 8;
			this->textBoxProfileUsername3->TabStop = false;
			this->textBoxProfileUsername3->Text = L"-";
			this->textBoxProfileUsername3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->panel4->Visible = false;
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
			this->textBoxProfilePassword4->PasswordChar = '*';
			this->textBoxProfilePassword4->ReadOnly = true;
			this->textBoxProfilePassword4->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword4->TabIndex = 12;
			this->textBoxProfilePassword4->TabStop = false;
			this->textBoxProfilePassword4->Text = L"-";
			this->textBoxProfilePassword4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->textBoxProfileUsername4->PasswordChar = '*';
			this->textBoxProfileUsername4->ReadOnly = true;
			this->textBoxProfileUsername4->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername4->TabIndex = 11;
			this->textBoxProfileUsername4->TabStop = false;
			this->textBoxProfileUsername4->Text = L"-";
			this->textBoxProfileUsername4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->panel5->Visible = false;
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
			this->textBoxProfilePassword5->PasswordChar = '*';
			this->textBoxProfilePassword5->ReadOnly = true;
			this->textBoxProfilePassword5->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword5->TabIndex = 15;
			this->textBoxProfilePassword5->TabStop = false;
			this->textBoxProfilePassword5->Text = L"-";
			this->textBoxProfilePassword5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->textBoxProfileUsername5->PasswordChar = '*';
			this->textBoxProfileUsername5->ReadOnly = true;
			this->textBoxProfileUsername5->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername5->TabIndex = 14;
			this->textBoxProfileUsername5->TabStop = false;
			this->textBoxProfileUsername5->Text = L"-";
			this->textBoxProfileUsername5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->panel6->Visible = false;
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
			this->textBoxProfilePassword6->PasswordChar = '*';
			this->textBoxProfilePassword6->ReadOnly = true;
			this->textBoxProfilePassword6->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword6->TabIndex = 18;
			this->textBoxProfilePassword6->TabStop = false;
			this->textBoxProfilePassword6->Text = L"-";
			this->textBoxProfilePassword6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->textBoxProfileUsername6->PasswordChar = '*';
			this->textBoxProfileUsername6->ReadOnly = true;
			this->textBoxProfileUsername6->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername6->TabIndex = 17;
			this->textBoxProfileUsername6->TabStop = false;
			this->textBoxProfileUsername6->Text = L"-";
			this->textBoxProfileUsername6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->panel7->Visible = false;
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
			this->textBoxProfilePassword7->PasswordChar = '*';
			this->textBoxProfilePassword7->ReadOnly = true;
			this->textBoxProfilePassword7->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword7->TabIndex = 21;
			this->textBoxProfilePassword7->TabStop = false;
			this->textBoxProfilePassword7->Text = L"-";
			this->textBoxProfilePassword7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->textBoxProfileUsername7->PasswordChar = '*';
			this->textBoxProfileUsername7->ReadOnly = true;
			this->textBoxProfileUsername7->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername7->TabIndex = 20;
			this->textBoxProfileUsername7->TabStop = false;
			this->textBoxProfileUsername7->Text = L"-";
			this->textBoxProfileUsername7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->panel8->Visible = false;
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
			this->textBoxProfilePassword8->PasswordChar = '*';
			this->textBoxProfilePassword8->ReadOnly = true;
			this->textBoxProfilePassword8->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword8->TabIndex = 24;
			this->textBoxProfilePassword8->TabStop = false;
			this->textBoxProfilePassword8->Text = L"-";
			this->textBoxProfilePassword8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->textBoxProfileUsername8->PasswordChar = '*';
			this->textBoxProfileUsername8->ReadOnly = true;
			this->textBoxProfileUsername8->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername8->TabIndex = 23;
			this->textBoxProfileUsername8->TabStop = false;
			this->textBoxProfileUsername8->Text = L"-";
			this->textBoxProfileUsername8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->panel9->Visible = false;
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
			this->textBoxProfilePassword9->PasswordChar = '*';
			this->textBoxProfilePassword9->ReadOnly = true;
			this->textBoxProfilePassword9->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword9->TabIndex = 27;
			this->textBoxProfilePassword9->TabStop = false;
			this->textBoxProfilePassword9->Text = L"-";
			this->textBoxProfilePassword9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->textBoxProfileUsername9->PasswordChar = '*';
			this->textBoxProfileUsername9->ReadOnly = true;
			this->textBoxProfileUsername9->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername9->TabIndex = 26;
			this->textBoxProfileUsername9->TabStop = false;
			this->textBoxProfileUsername9->Text = L"-";
			this->textBoxProfileUsername9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->panel10->Visible = false;
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
			this->textBoxProfilePassword10->PasswordChar = '*';
			this->textBoxProfilePassword10->ReadOnly = true;
			this->textBoxProfilePassword10->Size = System::Drawing::Size(247, 31);
			this->textBoxProfilePassword10->TabIndex = 30;
			this->textBoxProfilePassword10->TabStop = false;
			this->textBoxProfilePassword10->Text = L"-";
			this->textBoxProfilePassword10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->textBoxProfileUsername10->PasswordChar = '*';
			this->textBoxProfileUsername10->ReadOnly = true;
			this->textBoxProfileUsername10->Size = System::Drawing::Size(179, 31);
			this->textBoxProfileUsername10->TabIndex = 29;
			this->textBoxProfileUsername10->TabStop = false;
			this->textBoxProfileUsername10->Text = L"-";
			this->textBoxProfileUsername10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			this->panelSidebarExtend->TabIndex = 14;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHideSlot1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowSlot1))->EndInit();
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

	private: Slots^ slot = nullptr;

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
			int profSlot = 1;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != profSlot)
			{
				if (currProfile->id < profSlot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (slot->id != profSlot)
			{
				if (slot->id < profSlot)
					slot = slot->next;
				else
					slot = slot->prev;
			}
			// refresh slot labels
			RefreshLabels(slot);
		}
	}
	private: System::Void pictureBoxDelProf2_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite2->Text != "-" || textBoxProfileUsername2->Text != "-" || textBoxProfilePassword2->Text != "-")
		{
			// current slot
			int profSlot = 2;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != profSlot)
			{
				if (currProfile->id < profSlot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (slot->id != profSlot)
			{
				if (slot->id < profSlot)
					slot = slot->next;
				else
					slot = slot->prev;
			}
			// refresh slot labels
			RefreshLabels(slot);
		}
	}
	private: System::Void pictureBoxDelProf3_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite3->Text != "-" || textBoxProfileUsername3->Text != "-" || textBoxProfilePassword3->Text != "-")
		{
			// current slot
			int profSlot = 3;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != profSlot)
			{
				if (currProfile->id < profSlot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (slot->id != profSlot)
			{
				if (slot->id < profSlot)
					slot = slot->next;
				else
					slot = slot->prev;
			}
			// refresh slot labels
			RefreshLabels(slot);
		}
	}
	private: System::Void pictureBoxDelProf4_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite4->Text != "-" || textBoxProfileUsername4->Text != "-" || textBoxProfilePassword4->Text != "-")
		{
			// current slot
			int profSlot = 4;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != profSlot)
			{
				if (currProfile->id < profSlot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (slot->id != profSlot)
			{
				if (slot->id < profSlot)
					slot = slot->next;
				else
					slot = slot->prev;
			}
			// refresh slot labels
			RefreshLabels(slot);
		}
	}
	private: System::Void pictureBoxDelProf5_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite5->Text != "-" || textBoxProfileUsername5->Text != "-" || textBoxProfilePassword5->Text != "-")
		{
			// current slot
			int profSlot = 5;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != profSlot)
			{
				if (currProfile->id < profSlot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (slot->id != profSlot)
			{
				if (slot->id < profSlot)
					slot = slot->next;
				else
					slot = slot->prev;
			}
			// refresh slot labels
			RefreshLabels(slot);
		}
	}
	private: System::Void pictureBoxDelProf6_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite6->Text != "-" || textBoxProfileUsername6->Text != "-" || textBoxProfilePassword6->Text != "-")
		{
			// current slot
			int profSlot = 6;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != profSlot)
			{
				if (currProfile->id < profSlot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (slot->id != profSlot)
			{
				if (slot->id < profSlot)
					slot = slot->next;
				else
					slot = slot->prev;
			}
			// refresh slot labels
			RefreshLabels(slot);
		}
	}
	private: System::Void pictureBoxDelProf7_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite7->Text != "-" || textBoxProfileUsername7->Text != "-" || textBoxProfilePassword7->Text != "-")
		{
			// current slot
			int profSlot = 7;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != profSlot)
			{
				if (currProfile->id < profSlot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (slot->id != profSlot)
			{
				if (slot->id < profSlot)
					slot = slot->next;
				else
					slot = slot->prev;
			}
			// refresh slot labels
			RefreshLabels(slot);
		}
	}
	private: System::Void pictureBoxDelProf8_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite8->Text != "-" || textBoxProfileUsername8->Text != "-" || textBoxProfilePassword8->Text != "-")
		{
			// current slot
			int profSlot = 8;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != profSlot)
			{
				if (currProfile->id < profSlot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (slot->id != profSlot)
			{
				if (slot->id < profSlot)
					slot = slot->next;
				else
					slot = slot->prev;
			}
			// refresh slot labels
			RefreshLabels(slot);
		}
	}
	private: System::Void pictureBoxDelProf9_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite9->Text != "-" || textBoxProfileUsername9->Text != "-" || textBoxProfilePassword9->Text != "-")
		{
			// current slot
			int profSlot = 9;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != profSlot)
			{
				if (currProfile->id < profSlot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (slot->id != profSlot)
			{
				if (slot->id < profSlot)
					slot = slot->next;
				else
					slot = slot->prev;
			}
			// refresh slot labels
			RefreshLabels(slot);
		}
	}
	private: System::Void pictureBoxDelProf10_Click(System::Object^ sender, System::EventArgs^ e) {
		// if slot not empty
		if (labelProfileWebsite10->Text != "-" || textBoxProfileUsername10->Text != "-" || textBoxProfilePassword10->Text != "-")
		{
			// current slot
			int profSlot = 10;
			// traversal profile
			Profiles^ currProfile = profile;

			// go to current profile
			while (currProfile->id != profSlot)
			{
				if (currProfile->id < profSlot)
					currProfile = currProfile->next;
				else
					currProfile = currProfile->prev;
			}

			// remove profile from database
			RemoveProfile(currProfile->website, currProfile->username, currProfile->password);

			// go to current slot
			while (slot->id != profSlot)
			{
				if (slot->id < profSlot)
					slot = slot->next;
				else
					slot = slot->prev;
			}
			// refresh slot labels
			RefreshLabels(slot);
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

	private: void RefreshLabels(Slots^% _slot)
	{
		while (true)
		{
			if (slot->id <= profileCount)
			{
				slot->labelProfileWebsite->Text = slot->next->labelProfileWebsite->Text;
				slot->textBoxProfileUsername->Text = slot->next->textBoxProfileUsername->Text;
				slot->textBoxProfilePassword->Text = slot->next->textBoxProfilePassword->Text;
			}
			else
			{
				slot->labelProfileWebsite->Text = "-";
				slot->textBoxProfileUsername->Text = "-";
				slot->textBoxProfilePassword->Text = "-";
			}

			if (slot->next == nullptr)
				break;
			else
				slot = slot->next;
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
	private: System::Void pictureBoxToggleSlot1_Click(System::Object^ sender, System::EventArgs^ e) {

		ToggleHideSlot(1);

		// toggle showing picture
		pictureBoxHideSlot1->Visible = !pictureBoxHideSlot1->Visible;
	}
	private: void ToggleHideSlot(int _slot)
	{
		// go to slot
		while (slot->id != _slot)
		{
			if (slot->id > _slot)
				slot = slot->prev;
			else
				slot = slot->next;
		}

		// if hidden username
		if (slot->textBoxProfileUsername->PasswordChar == '*')
		{
			// show username and password
			slot->textBoxProfileUsername->PasswordChar = false;
			slot->textBoxProfilePassword->PasswordChar = false;
		}
		else
		{
			// hide username and password
			slot->textBoxProfileUsername->PasswordChar = '*';
			slot->textBoxProfilePassword->PasswordChar = '*';
		}
	}
	private: System::Void pictureBoxToggleSlot2_Click(System::Object^ sender, System::EventArgs^ e) {

		ToggleHideSlot(2);

		// toggle showing picture
		pictureBoxHideSlot2->Visible = !pictureBoxHideSlot2->Visible;
	}
	private: System::Void pictureBoxToggleSlot3_Click(System::Object^ sender, System::EventArgs^ e) {

		ToggleHideSlot(3);

		// toggle showing picture
		pictureBoxHideSlot3->Visible = !pictureBoxHideSlot3->Visible;
	}
	private: System::Void pictureBoxToggleSlot4_Click(System::Object^ sender, System::EventArgs^ e) {

		ToggleHideSlot(4);

		// toggle showing picture
		pictureBoxHideSlot4->Visible = !pictureBoxHideSlot4->Visible;
	}
	private: System::Void pictureBoxToggleSlot5_Click(System::Object^ sender, System::EventArgs^ e) {

		ToggleHideSlot(5);

		// toggle showing picture
		pictureBoxHideSlot5->Visible = !pictureBoxHideSlot5->Visible;
	}
	private: System::Void pictureBoxToggleSlot6_Click(System::Object^ sender, System::EventArgs^ e) {

		ToggleHideSlot(6);

		// toggle showing picture
		pictureBoxHideSlot6->Visible = !pictureBoxHideSlot6->Visible;
	}
	private: System::Void pictureBoxToggleSlot7_Click(System::Object^ sender, System::EventArgs^ e) {

		ToggleHideSlot(7);

		// toggle showing picture
		pictureBoxHideSlot7->Visible = !pictureBoxHideSlot7->Visible;
	}
	private: System::Void pictureBoxToggleSlot8_Click(System::Object^ sender, System::EventArgs^ e) {

		ToggleHideSlot(8);

		// toggle showing picture
		pictureBoxHideSlot8->Visible = !pictureBoxHideSlot8->Visible;
	}
	private: System::Void pictureBoxToggleSlot9_Click(System::Object^ sender, System::EventArgs^ e) {

		ToggleHideSlot(9);

		// toggle showing picture
		pictureBoxHideSlot9->Visible = !pictureBoxHideSlot9->Visible;
	}
	private: System::Void pictureBoxToggleSlot10_Click(System::Object^ sender, System::EventArgs^ e) {

		ToggleHideSlot(10);

		// toggle showing picture
		pictureBoxHideSlot10->Visible = !pictureBoxHideSlot10->Visible;
	}
	};
}

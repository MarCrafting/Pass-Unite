#include "Login.h"
#include "Register.h"
#include "Home.h"
#include "AddProfiles.h"
#include "ProfilesForm.h"
#include "User.h"
#include "Profiles.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PassUnite::Login loginPage;

	System::Windows::Forms::FormWindowState windowState = System::Windows::Forms::FormWindowState::Normal;

	while (true)
	{
		loginPage.ShowDialog();

		if (loginPage.switchToRegister)
		{
			// open register form
			PassUnite::Register registerPage;
			registerPage.ShowDialog();

			if (registerPage.switchToLogin)
			{
				loginPage.switchToRegister = false;
				continue;
			}
		}

		// initialize pages
		PassUnite::Home^ homePage = nullptr;
		PassUnite::AddProfiles^ addProfilesPage = nullptr;
		PassUnite::ProfilesForm^ profilesPage = nullptr;

		// set starting screen
		PageProperties pageProps;
		pageProps.page = loginPage.pageProps.page;

		// run application until logout or terminate request
		while (pageProps.page > 0)
		{
			// update pages
			PassUnite::Home home(loginPage.user);
			homePage = % home;

			PassUnite::AddProfiles addProfiles(loginPage.user);
			PassUnite::ProfilesForm profiles(loginPage.user, addProfiles.profile, addProfiles.profileCount);
			addProfilesPage = % addProfiles;
			profilesPage = % profiles;

			// switch between pages
			switch (pageProps.page)
			{
			case 1:
				// display page
				homePage->WindowState = windowState;
				homePage->ShowDialog();

				// save next page
				pageProps.page = homePage->pageProps.page;
				windowState = homePage->WindowState;
				break;
			case 2:
				// display page
				addProfilesPage->WindowState = windowState;
				addProfilesPage->ShowDialog();

				// save next page
				pageProps.page = addProfilesPage->pageProps.page;
				windowState = addProfilesPage->WindowState;
				break;
			case 3:
				// display page
				profilesPage->WindowState = windowState;
				profilesPage->ShowDialog();

				// save next page
				pageProps.page = profilesPage->pageProps.page;
				windowState = profilesPage->WindowState;
				break;
			}
		}
		// closing application
		if (pageProps.page == -1)
			break;
	}
}
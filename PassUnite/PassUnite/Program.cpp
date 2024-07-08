#include "Login.h"
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

	while (true)
	{
		loginPage.ShowDialog();

		if (loginPage.pageProps.page != 1)
			break;

		// initialize pages
		PassUnite::Home homePage;			// Page 1
		PassUnite::AddProfiles addProfilesPage(loginPage.user);	// Page 2
		PassUnite::ProfilesForm profilesPage(loginPage.user, addProfilesPage.profile, addProfilesPage.profileCount);	// Page 3
		// set starting screen
		PageProperties pageProps;
		pageProps.page = 1;

		// run application until logout or close
		while (true)
		{
			// switch between pages
			switch (pageProps.page)
			{
			case 1:
				// display page
				homePage.ShowDialog();

				// save next page
				pageProps.page = homePage.pageProps.page;

				break;
			case 2:
				// display page
				addProfilesPage.ShowDialog();

				// save next page
				pageProps.page = addProfilesPage.pageProps.page;

				break;
			case 3:
				// display page
				profilesPage.ShowDialog();

				// save next page
				pageProps.page = profilesPage.pageProps.page;
				break;
			case 0:
				// if page = 0, show login form
				break;
			case -1:
				// if page = -1, terminate application
				break;
			}
			// exit cases
			if (pageProps.page == 0 || pageProps.page == -1)
				break;
		}
		// closing application
		if (pageProps.page == -1)
			break;
	}
}
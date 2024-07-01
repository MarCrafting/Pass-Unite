#include "Login.h"
#include "Home.h"
#include "AddProfiles.h"
#include "Profiles.h"
#include "User.h"

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

		// setup user verification before opening the app

		//

		// amount of saved profiles
		int profileCount = 1;

		// initialize pages
		PageProperties pageProps;
		PassUnite::Home homePage;			// Page 1
		PassUnite::AddProfiles addProfilesPage;	// Page 2
		PassUnite::Profiles profilesPage(profileCount);	// Page 3


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

				// check if proile was saved
				if (addProfilesPage.user.website != "" || addProfilesPage.user.username != "" || addProfilesPage.user.password != "")
				{
					profileCount++;
				}

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
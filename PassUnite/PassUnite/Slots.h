#pragma once

using namespace System;

public ref class Slots {
public:
	int id;														// slot position
	System::Windows::Forms::Panel^ panel = nullptr;				// panel holding user info
	System::Windows::Forms::Label^ labelProfileWebsite;			// website label pointer
	System::Windows::Forms::TextBox^ textBoxProfileUsername;	// username textbox pointer
	System::Windows::Forms::TextBox^ textBoxProfilePassword;	// password textbox pointer
	System::Windows::Forms::PictureBox^ hide;					// hidden info indicator
	System::Windows::Forms::PictureBox^ show;					// shown info indicator
	System::Windows::Forms::PictureBox^ clear;					// clear slot
	Slots^ prev = nullptr;										// previous slot
	Slots^ next = nullptr;										// next slot
};
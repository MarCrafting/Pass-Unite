#pragma once

using namespace System;

public ref class Slots {
public:
	int id;														// slot position
	System::Windows::Forms::Panel^ panel = nullptr;				// panel holding user info
	Slots^ prev = nullptr;										// previous slot
	Slots^ next = nullptr;										// next slot
	System::Windows::Forms::PictureBox^ Hide;					// hidden info indicator
	System::Windows::Forms::PictureBox^ Show;					// shown info indicator
	System::Windows::Forms::PictureBox^ Delete;					// delete slot
};
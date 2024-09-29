#pragma once

using namespace System;

public ref class Panels {
public:
	int id;
	System::Windows::Forms::Panel^ panel = nullptr;
	System::Windows::Forms::Label^ labelProfileWebsite = nullptr;
	System::Windows::Forms::TextBox^ textBoxProfileUsername = nullptr;
	System::Windows::Forms::TextBox^ textBoxProfilePassword = nullptr;
	Panels^ next = nullptr;
	Panels^ prev = nullptr;
};
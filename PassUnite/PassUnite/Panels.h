#pragma once

using namespace System;

public ref class Panels {
public:
	System::Windows::Forms::Panel^ panel = nullptr;
	System::Windows::Forms::Label^ labelProfileWebsite = nullptr;
	System::Windows::Forms::Label^ labelProfileUsername = nullptr;
	System::Windows::Forms::Label^ labelProfilePassword = nullptr;
	Panels^ next = nullptr;
	Panels^ prev = nullptr;
};
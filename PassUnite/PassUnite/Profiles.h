#pragma once

using namespace System;

public ref class Profiles {
public:
	int id;
	String^ website = "-";
	String^ username = "-";
	String^ password = "-";

	Profiles^ next = nullptr;
	Profiles^ prev = nullptr;
};
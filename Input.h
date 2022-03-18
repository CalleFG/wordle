#pragma once
#include <iostream>

class Input
{

public:

	bool GetInput();

	bool GetChoiceInput();

	const std::string& GetFormattedInput();

private:

	std::string CurrentInput;

	void FormatInput();

};

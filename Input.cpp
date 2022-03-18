#include "Input.h"
#include "Settings.h"
#include <algorithm>

bool Input::GetInput()
{
	std::cin >> CurrentInput;

	if (CurrentInput.length() > Settings::MAX_LETTERS || CurrentInput.length() < Settings::MAX_LETTERS)
	{
		return false;
	}
	if (!std::all_of(CurrentInput.begin(), CurrentInput.end(), isalpha))
	{
		return false;
	}

	return true;
}

bool Input::GetChoiceInput()
{
	char Choice;
	std::cin >> Choice;

	if (Choice == 'y' || Choice == 'Y')
	{
		return true;
	}
	else if (Choice == 'n' || Choice == 'N')
	{
		return false;
	}
}

const std::string& Input::GetFormattedInput()
{
	FormatInput();
	return CurrentInput;
}

void Input::FormatInput()
{
	std::for_each(CurrentInput.begin(), CurrentInput.end(), [](char& c){ c = ::toupper(c); });
}

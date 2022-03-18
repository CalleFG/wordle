#pragma once

#include <string>
#include <vector>

class WordList
{

public:

	WordList();

	std::string GetRandomWord();

private:

	std::vector<std::string> Strings;

	void InitializeList();

};

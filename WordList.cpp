#include "WordList.h"

#include <fstream>
#include <iostream>
#include <string>
#include <random>

WordList::WordList()
{
	InitializeList();
}

std::string WordList::GetRandomWord()
{
	std::random_device Device;
	std::default_random_engine Engine(Device());
	std::uniform_int_distribution<int> Distribution(0, Strings.size());

	int Random = Distribution(Engine);

	return Strings[Random];
}

void WordList::InitializeList()
{
	std::ifstream File;

	File.open("words.txt");

	if (!File)
	{
		std::cout << "Couldn't read from words file." << std::endl;
		return;
	}

	std::string Line;
	while (std::getline(File, Line))
	{
		Strings.push_back(Line);
	}
}

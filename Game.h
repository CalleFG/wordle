#pragma once

#include "ConsolePrinter.h"
#include <string>

enum class GameResult
{
	Lose = 0,
	Win = 1
};

class Game
{

public:

	Game();
	Game(const std::string& WordIn);

	void PlayRound(const std::string& InputIn, Row& RowOut);

	bool CompareWord(const char* Start, Row& RowOut);

	bool IsRunning();

	GameResult GetGameResult();

	int GetRound();

	const std::string& GetWord();

private:

	void NextRound();

	bool Running;

	int Round;

	GameResult Result;

	std::string CurrentWord;
	
	bool ContainsLetter(const char& Letter);

	bool IsGameOver();

};


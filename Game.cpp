#include "Game.h"
#include "Settings.h"

Game::Game()
{
	Running = true;
	Round = 0;
	CurrentWord = "CRANE";
}

Game::Game(const std::string& WordIn)
{
	Running = true;
	Round = 0;
	CurrentWord = WordIn;
}

void Game::PlayRound(const std::string& InputIn, Row& RowOut)
{
	if (CompareWord(&InputIn[0], RowOut))
	{
		Result = GameResult::Win;
		Running = false;
	}
	NextRound();
}

bool Game::CompareWord(const char* Start, Row& RowOut)
{
	bool IsMatch = true;

	for (int i = 0; i < Settings::MAX_LETTERS; i++)
	{
		const char& Letter = Start[i];

		RowOut.Letters[i].Character = Letter;

		if (Letter == CurrentWord[i])
		{
			RowOut.Letters[i].Color = BackgroundColor::Green;
		}
		else if (ContainsLetter(Letter))
		{
			RowOut.Letters[i].Color = BackgroundColor::Yellow;
			IsMatch = false;
		}
		else
		{
			RowOut.Letters[i].Color = BackgroundColor::BrightBlack;
			IsMatch = false;
		}
	}

	return IsMatch;
}

bool Game::IsRunning()
{
	return Running;
}

GameResult Game::GetGameResult()
{
	return Result;
}

bool Game::IsGameOver()
{
	return Round >= Settings::MAX_ROUNDS;
}

int Game::GetRound()
{
	return Round;
}

const std::string& Game::GetWord()
{
	return CurrentWord;
}

void Game::NextRound()
{
	Round++;
	if (IsGameOver())
	{
		Result = GameResult::Lose;
		Running = false;
	}
}

bool Game::ContainsLetter(const char& Letter)
{
	for (int i = 0; i < Settings::MAX_LETTERS; i++)
	{
		if (Letter == CurrentWord[i])
		{
			return true;
		}
	}

	return false;
}

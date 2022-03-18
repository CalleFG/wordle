#include "ConsolePrinter.h"
#include <iostream>

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"

ConsolePrinter::ConsolePrinter()
{
	Round = 1;
}

void ConsolePrinter::Update()
{
	system("CLS");
	PrintHeader();
	PrintRows();
	PrintFooter();
}

void ConsolePrinter::PrintWinScreen(const std::string& Word)
{
	system("CLS");
	PrintHeader();
	PrintRows();
	std::cout << "Congratulations, you won. The word was: " << Word << std::endl;
}

void ConsolePrinter::PrintLoseScreen(const std::string& Word)
{
	system("CLS");
	PrintHeader();
	PrintRows();
	std::cout << "You lose. You did not manage to guess the words in six tries. The correct word was: " << Word << std::endl;
}

void ConsolePrinter::PrintInputError()
{
	system("CLS");
	PrintHeader();
	PrintRows();
	std::cout << "Invalid input. Please enter a valid five letter word:" << std::endl;
}

void ConsolePrinter::PrintPlayAgainPrompt()
{
	std::cout << std::endl << "Would you like to play again (y/n)?" << std::endl;
}

void ConsolePrinter::PrintHeader()
{
	std::cout << "Round " << Round << "/" << Settings::MAX_ROUNDS << std::endl << std::endl;
}

void ConsolePrinter::PrintRows()
{
	for (const Row& row : Rows)
	{
		PrintRow(row);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void ConsolePrinter::PrintRow(const Row& RowIn)
{
	for (const Letter& letter : RowIn.Letters)
	{
		std::cout << BACKGROUND(letter.Color, letter.Character);
	}
}

void ConsolePrinter::PrintFooter()
{
	std::cout << "Enter a valid five letter word: " << std::endl;
}

void ConsolePrinter::EditRow(int RowIndex, const char* String)
{
	Row& EditRow = Rows[RowIndex];
	for (int i = 0; i < Settings::MAX_LETTERS; i++)
	{
		EditRow.Letters[i].Character = String[i];
	}
}

void ConsolePrinter::SetRound(int Value)
{
	Round = Value + 1;
}

Row& ConsolePrinter::GetRow(int Index)
{
	return Rows[Index];
}

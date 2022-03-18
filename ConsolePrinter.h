#pragma once

#include "Settings.h"
#include <string>

enum class ForegroundColor : int
{
    Red = 31,
    Green = 32,
    Yellow = 33,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93
};

enum class BackgroundColor : int
{
    Red = 41,
    Green = 42,
    Yellow = 43,
    Black = 40,
    BrightRed = 101,
    BrightGreen = 102,
    BrightYellow = 103,
    BrightBlack = 100
};

struct Letter
{
    char Character;
    BackgroundColor Color;

    Letter()
    {
        Character = '#';
        Color = BackgroundColor::Black;
    }
};

struct Row
{
    Letter Letters[Settings::MAX_LETTERS];
};

class ConsolePrinter
{

public:

    ConsolePrinter();

	void Update();

    void PrintWinScreen(const std::string& Word);

    void PrintLoseScreen(const std::string& Word);

    void PrintInputError();

    void PrintPlayAgainPrompt();

    void EditRow(int Row, const char* String);

    void SetRound(int Value);

    Row& GetRow(int Index);

private:

    Row Rows[Settings::MAX_ROUNDS];

    int Round;

    void PrintHeader();
    void PrintRows();
    void PrintRow(const Row& RowIn);
    void PrintFooter();

};


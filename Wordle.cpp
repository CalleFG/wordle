#include "Wordle.h"
#include "Input.h"
#include "Game.h"
#include "ConsolePrinter.h"
#include "WordList.h"

void Wordle::Run()
{
	Input InputHandler;
	WordList List;

	bool Running = true;

	while (Running)
	{
		Game NewGame(List.GetRandomWord());
		ConsolePrinter Printer;

		Printer.Update();

		while (NewGame.IsRunning())
		{
			if (InputHandler.GetInput())
			{
				NewGame.PlayRound(InputHandler.GetFormattedInput(), Printer.GetRow(NewGame.GetRound()));
				if (NewGame.IsRunning())
				{
					Printer.SetRound(NewGame.GetRound());
				}
				Printer.Update();
			}
			else
			{
				Printer.PrintInputError();
			}
		}

		switch (NewGame.GetGameResult())
		{
		case GameResult::Lose:
			Printer.PrintLoseScreen(NewGame.GetWord());
			break;
		case GameResult::Win:
			Printer.PrintWinScreen(NewGame.GetWord());
			break;
		}

		Printer.PrintPlayAgainPrompt();
		Running = InputHandler.GetChoiceInput();
	}
}

// Program written in Microsoft Visual Studio using Windows

#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <string>

// global method that runs the game
void playFlip()
{
	// make deck and shuffle three times
	Deck deck;
	for (int i = 0; i < 3; i++) deck.shuffle();

	// print instructions to screen
	std::cout << "Welcome to Flip! To deal a card type a number > 0, and press enter. To stop type 0.\n";

	// init deal card boolean and points to 0
	bool takeCard = true;
	int points = 0;
	// while player wants another card
	while (takeCard)
	{
		Card c;
		// deal card
		try
		{
			c = deck.deal();
		}
		// if no more cards in deck
		catch (std::out_of_range e)
		{
			std::cout << e.what() << " game ending!\n";
			// break out of dealing loop, and end game
			break;
		}
		std::cout << "You have been dealt: " << c;
		// add or remove points based on suit and value
		switch (c.getValue())
		{
		// add 10 for ace
		case 14:
			points += 10;
			std::cout << "You won 10 points! Your score is now: " << points << std::endl;
			break;
		// add 5 for K, Q, J
		case 13:
		case 12:
		case 11:
			points += 5;
			std::cout << "You won 5 points! Your score is now: " << points << std::endl;
			break;
		// noop for 10, 9, 8
		case 10:
		case 9:
		case 8:
			std::cout << "You won 0 points. Your score is still: " << points << std::endl;
			break;
		// lose half for 7
		case 7:
			points /= 2;
			std::cout << "You lost half your points. Your score is now: " << points << std::endl;
			break;
		// lose all for 6, 5, 4, 3, 2
		case 6:
		case 5:
		case 4:
		case 3:
		case 2:
			std::cout << "Oh no! You lost all your points!\n";
			points = 0;
			break;
		default:
			break;
		}
		// if suit is a heart
		if (c.getSuit() == 2)
		{
			// add one point
			points++;
			std::cout << "Heart bonus! You recieved 1 extra point! Your score is now: " << points << std::endl;
		}

		// init bool for checking valid input
		bool isValid = false;
		// init input variable
		std::string input;
		do
		{
			// prompt user
			std::cout << "Deal another card: ";
			// take input
			std::cin >> input;
			try
			{
				// try to cast string to boolean
				takeCard = std::stoi(input);
				// if successful, input is valid
				isValid = true;
			}
			catch (std::exception e)
			{
				// else, send err message and try again
				std::cout << "Type a number > 0 for yes, or 0 for no. Try again.\n";
			}
		// repeat until input is validated
		} while (!isValid);
	}

	// if no more cards are to be dealt, cout final score
	std::cout << "-----\nFinal Score: " << points << "!\n-----\n";
}

// main program entry point
int main()
{
	// init game
	playFlip();
	return 0;
}


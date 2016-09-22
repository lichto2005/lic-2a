// Program written in Microsoft Visual Studio using Windows

#include "Card.h"
#include "Deck.h"
#include <iostream>

// main program entry point
int main()
{
	// create deck d with def constructor which inits 52 card deck
	Deck d;
	// print the deck, which in turn prints the cards
	std::cout << d;
	//exit
	return 0;
}
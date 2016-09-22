#include "Deck.h"
#include <iterator>
#include <list>
#include "Card.h"


Deck::Deck()
{
	// init cards 2-A for each suit, catch domain errors if i, j out of bounds of acceptable input
	try
	{
		// for each suit
		for (int i = 0; i < 4; i++)
		{
			// init a card of suit i with value j
			for (int j = 2; j < 15; j++)
			{
				// create card i,j and add to cards list
				cards.push_back(Card(i, j));
			}
		}
	}
	// if card is out of range
	catch (std::domain_error e)
	{
		// catch error and print to console
		std::cout << e.what();
	}
}


Deck::~Deck()
{
}

// overloaded print operator to print every card in the deck
std::ostream& operator<<(std::ostream& os, const Deck& d)
{
	// iterate over the entire list
	for (std::list<Card>::const_iterator it = d.cards.begin(); it != d.cards.end(); it++)
	{
		// call the overloaded print operator for Card, which prints value and suit
		os << *it;
	}
	return os;
}
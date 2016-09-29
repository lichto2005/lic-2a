#include "Deck.h"
#include <iterator>
#include <list>
#include "Card.h"


Deck::Deck()
{
		// for each suit
		for (int i = 0; i < 4; i++)
		{
			// init a card of suit i with value j
			for (int j = 2; j < 15; j++)
			{
				// create card i,j and add to cards list
				try
				{
					cards.push_back(Card(i, j));
				}
				catch (std::domain_error e)
				{
					std::cout << e.what();
				}
			}
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
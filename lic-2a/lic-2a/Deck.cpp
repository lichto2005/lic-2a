#include "Deck.h"
#include <iterator>
#include <list>
#include "Card.h"


Deck::Deck()
{
	try
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 2; j < 15; j++)
			{
				cards.push_back(Card(i, j));
			}
		}
	}
	catch (std::domain_error e)
	{
		std::cout << e.what();
	}
}


Deck::~Deck()
{
}

std::ostream& operator<<(std::ostream& os, const Deck& d)
{
	for (std::list<Card>::const_iterator it = d.cards.begin(); it != d.cards.end(); it++)
	{
		os << *it;
	}
	return os;
}
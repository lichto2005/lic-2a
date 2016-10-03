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

Deck::Deck(Deck & d)
{
	// copy parameter deck list into this deck list
	cards = d.cards;
}


Deck::~Deck()
{
	// list.clear removes and calls destructor for all cards in list
	cards.clear();
}

Card Deck::deal()
{
	if (cards.size() == 0) throw std::out_of_range("No more cards in deck!");
	// save value of first element of deck list
	Card c = cards.front();
	// remove first element of deck list
	cards.pop_front();
	// return saved element
	return c;
}

void Deck::replace(const Card c)
{
	// add card to the back
	cards.push_back(Card(c));
}

void Deck::shuffle()
{
	// init random seed
	srand(time(NULL));
	// declare new list obj
	std::list<Card> newList;
	// while still cards to be shuffled
	while (cards.size() != 0)
	{
		// pick a random card in old deck
		int cardNum = rand() % cards.size();
		// advance iterator to that card
		std::list<Card>::iterator it = cards.begin();
		for (int i = 0; i < cardNum; i++)
		{
			it++;
		}
		// add that card to new deck front
		newList.push_back(*it);
		// erase old card
		cards.erase(it);
	}
	// set deck to the new shuffled list of cards
	cards = newList;
}

void Deck::operator=(const Deck & d)
{
	// set this deck of cards to param deck of cards
	cards = d.cards;
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
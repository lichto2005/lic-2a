#pragma once
#include "Card.h"
#include <list>
#include <time.h>

// class that describes a deck of cards
class Deck
{
public:
	// default constructors inits 52 card deck in order
	Deck();
	Deck(Deck& d);
	~Deck();

	Card deal();
	void replace(const Card c);
	void shuffle();

	// print operator overload
	friend std::ostream& operator<<(std::ostream& os, const Deck& d);
	// assignment operator overload
	void operator=(const Deck& d);
private:
	// linked list of cards
	std::list<Card> cards;
};
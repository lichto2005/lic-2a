#pragma once
#include "Card.h"
#include <list>

// class that describes a deck of cards
class Deck
{
public:
	// default constructors inits 52 card deck in order
	Deck();
	~Deck();
	// print operator overload
	friend std::ostream& operator<<(std::ostream& os, const Deck& d);
private:
	// linked list of cards
	std::list<Card> cards;
};
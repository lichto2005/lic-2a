#pragma once

#include "Card.h"
#include <list>

class Deck
{
public:
	Deck();
	~Deck();
	friend std::ostream& operator<<(std::ostream& os, const Deck& d);
private:
	std::list<Card> cards;
};


#include "Card.h"

Card::Card()
{
}

Card::~Card()
{
}

// init a card with suit and value
Card::Card(int suit, int value)
{
	// if suit out of bounds throw domain error
	if (suit < 0 || suit > 3)
	{
		throw std::domain_error("Suit must be in range [0,3]\n");
		return;
	}
	// if value out of bounds throw domain error
	if (value < 2 || value > 14)
	{
		throw std::domain_error("Value must be in range [2,14] (2-A)\n");
		return;
	}

	// else init card values
	this->suit = suit;
	this->value = value;
}

int const Card::getSuit()
{
	return this->suit;
}

int const Card::getValue()
{
	return this->value;
}

void Card::setSuit(int suit)
{
	// throw domain error if out of bounds
	if (suit < 0 || suit > 3)
	{
		throw std::domain_error("Suit must be in range [0,3]\n");
		return;
	}
	this->suit = suit;
}

void Card::setValue(int value)
{
	// throw domain error if out of bounds
	if (value < 2 || value > 14)
	{
		throw std::domain_error("Value must be in range [2,14] (2-A)\n");
		return;
	}
	this->value = value;
}

// overloaded print operator prints the suit and value of card
std::ostream& operator<<(std::ostream& os, const Card& c)
{
	os << "Value: " << c.value << " Suit: " << c.suit << std::endl;
	return os;
}
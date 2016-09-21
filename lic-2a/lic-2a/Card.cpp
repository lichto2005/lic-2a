#include "Card.h"

Card::Card()
{
}

Card::~Card()
{
}

Card::Card(int suit, int value)
{
	if (suit < 0 || suit > 3)
	{
		throw std::domain_error("Suit must be in range [0,3]");
		return;
	}
	if (value < 2 || value > 14)
	{
		throw std::domain_error("Value must be in range [2,14] (2-A)");
		return;
	}

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
	if (suit < 0 || suit > 3)
	{
		throw std::domain_error("Suit must be in range [0,3]");
		return;
	}
	this->suit = suit;
}

void Card::setValue(int value)
{
	if (value < 2 || value > 14)
	{
		throw std::domain_error("Value must be in range [2,14] (2-A)");
		return;
	}
	this->value = value;
}

std::ostream& operator<<(std::ostream& os, const Card& c)
{
	os << "Value: " << c.value << " Suit: " << c.suit << std::endl;
	return os;
}
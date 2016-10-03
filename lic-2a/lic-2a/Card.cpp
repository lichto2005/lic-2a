#include "Card.h"
#include <string>

Card::Card()
{
}

Card::Card(const Card & card)
{
	// if suit out of bounds throw domain error
	if (card.suit < 0 || card.suit > 3)
	{
		throw std::domain_error("Suit must be in range [0,3]\n");
		return;
	}
	// if value out of bounds throw domain error
	if (card.value < 2 || card.value > 14)
	{
		throw std::domain_error("Value must be in range [2,14] (2-A)\n");
		return;
	}
	suit = card.suit;
	value = card.value;
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
	// switch statement maps the value of suit to its corresponding name for readability
	std::string suitName = "";
	switch (c.suit)
	{
	case 0:
		suitName = "Clubs";
		break;
	case 1:
		suitName = "Diamonds";
		break;
	case 2:
		suitName = "Hearts";
		break;
	case 3:
		suitName = "Spades";
		break;
	default:
		throw std::domain_error("Suit not in range [0,3]");
		break;
	}

	// switch statement maps the value of value to its corresponding name for readability (for JQKA)
	std::string valueName = "";
	switch (c.value)
	{
	case 11:
		valueName = "Jack";
		break;
	case 12:
		valueName = "Queen";
		break;
	case 13:
		valueName = "King";
		break;
	case 14:
		valueName = "Ace";
		break;
	case 10:
	case 9:
	case 8:
	case 7:
	case 6:
	case 5:
	case 4:
	case 3:
	case 2:
		//casts int to string
		valueName = std::to_string(c.value);
		break;
	default:
		throw std::domain_error("Value must be in range [2,14]");
		break;
	}
	os << valueName << " of " << suitName << std::endl;
	return os;
}

void Card::operator=(const Card & c)
{
	value = c.value;
	suit = c.suit;
}

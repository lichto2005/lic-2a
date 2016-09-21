#pragma once

#include <iostream>
class Card
{
public:
	Card();
	~Card();
	Card(int suit, int value);
	int const getSuit();
	int const getValue();
	void setSuit(int suit);
	void setValue(int value);
	friend std::ostream& operator<<(std::ostream& ostream, const Card& c);

protected:
	int suit, value;
};
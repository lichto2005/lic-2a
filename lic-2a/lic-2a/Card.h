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
	//overloaded print operator
	friend std::ostream& operator<<(std::ostream& ostream, const Card& c);

private:
	int suit, value;
};
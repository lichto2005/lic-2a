#pragma once

#include <iostream>
class Card
{
public:
	Card();
	Card(const Card& card);
	~Card();
	Card(int suit, int value);
	int const getSuit();
	int const getValue();
	void setSuit(int suit);
	void setValue(int value);
	//overloaded print operator
	friend std::ostream& operator<<(std::ostream& ostream, const Card& c);
	//overloaded assignment operator
	void operator=(const Card& c2);

private:
	int suit, value;
};
#pragma once
#include <iostream>
#include <string>

class Card
{
private:
	std::string suit, face;
	int value;
public:
	Card(std::string face, std::string suit, int value) {
		this->face = face;
		this->suit = suit;
		this->value = value;
	}

	int getValue() {
		return this->value;
	}

	std::string getFace()
	{
		return this->face;
	}

	std::string getSuit()
	{
		return this->suit;
	}

	void setValue(int value)
	{
		this->value = value;
	}
};

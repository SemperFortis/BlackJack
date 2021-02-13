#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

class Deck 
{
private:
	std::vector<Card> cards;

	void shuffle() {
		auto rng = std::default_random_engine{ std::random_device{}() };

		std::shuffle(std::begin(this->cards), std::end(this->cards), rng);
	}
public:
	Deck() {
		std::string faces[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
		std::string suits[4] = { "SPADES", "HEARTS", "DIAMONDS", "CLUBS" };
		int values[13] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

		for (int i = 0; i < 13; i++) {
			for (std::string suit : suits) {
				Card card = Card(faces[i], suit, values[i]);

				this->cards.push_back(card);
			}
		}

		this->shuffle();
	}

	Card deal() {
		Card card = this->cards.back();

		this->cards.pop_back();

		return card;
	}
};

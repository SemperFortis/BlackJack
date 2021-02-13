#pragma once
#include <vector>
#include "Deck.h"
#include "Card.h"

class Player
{
private:
	Deck* deck;
	std::vector<Card> hand;
public:
	Player(Deck* deck) {
		this->deck = deck;
	}

	void hit() {
		if (!this->lost()) {
			// or (*deck).deal();
			Card card = this->deck->deal();

			this->hand.push_back(card);
			this->calculateAce();
		}
	}

	void stand() {
		int total = this->total();

		while (total < 17) {
			this->hit();

			total = this->total();
		}
	}

	// Do we have the biggest possible 21
	bool hasAceSpade() {
		if (this->hand.size() != 2 || this->total() != 21) return false;

		for (Card card : this->hand) {
			if (card.getFace() == "A" && card.getSuit() == "SPADES") {
				return true;
			}
		}

		return false;
	}

	// Total value of our hand
	int total() {
		int total = 0;

		for (Card card : this->hand) {
			total += card.getValue();
		}

		return total;
	}

	bool lost() {
		return this->total() > 21;
	}

	void displayPartial() {
		Card card = this->hand.at(0);

		std::cout << card.getSuit() << " " << card.getFace() << std::endl;

		std::cout << "Hand value: " << card.getValue() << std::endl;
	}

	void display() {
		for (size_t i = 0; i < this->hand.size(); i++) {
			Card card = this->hand.at(i);

			std::cout << card.getSuit() << " " << card.getFace() << ", ";
		}

		std::cout << "\nHand value: " << this->total() << std::endl;
	}
private:
	// Sets ace to 1 when necessary
	void calculateAce() {
		int total = this->total();

		if (total > 21) {
			for (Card& card : this->hand) {
				if (card.getFace() == "A") {
					card.setValue(1);

					// Edge Case: if we have 2 aces, we only want to set 1 of the aces to a value of
					// 1, keeping the other ace a 11

					// Edge Case: we have 2 aces, but we have other cards too, the total goes over
					// 21, we want both aces to be a 1

					total = this->total();

					if (total > 21) {
						continue;
					}
					else {
						break;
					}
				}
			}
		}
	}
};

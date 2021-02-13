#pragma once
#include <string>
#include "Deck.h"
#include "Player.h"

class Game
{
private:
	Deck deck;
	Player player = Player(&deck);
	Player dealer = Player(&deck);
public:
	Game() {
		for (int i = 0; i < 2; i++) {
			player.hit();
			dealer.hit();
		}
	}

	void play() {
		std::string option;

		while (true) {
			this->output(true);

			std::cout << "\nDo you want to hit or stand?" << std::endl;
			std::cin >> option;
			std::cout << "\n" << std::endl;

			if (option == "hit") {
				this->player.hit();

				if (this->player.lost()) {
					break;
				}
			}
			else if (option == "stand") {
				this->player.stand();
				this->dealer.stand();
				break;
			}
			else {
				std::cout << "Not a valid option!\n" << std::endl;
			}
		}

		int playerValue = this->player.total();
		int dealerValue = this->dealer.total();

		this->output(false);

		if (this->player.lost() || dealerValue > playerValue) {
			std::cout << "You lost" << std::endl;
		}
		else if (this->dealer.lost() || playerValue > dealerValue) {
			std::cout << "You won" << std::endl;
		}
		else if (playerValue == dealerValue) {
			if (this->player.hasAceSpade()) {
				std::cout << "You won" << std::endl;
			}
			else if (this->dealer.hasAceSpade()) {
				std::cout << "You lost" << std::endl;
			}
			else {
				std::cout << "Push" << std::endl;
			}
		}
	}
private:
	void output(bool partial) {
		std::cout << "Your hand:" << std::endl;
		this->player.display();

		std::cout << "\n" << std::endl;

		std::cout << "Dealer hand:" << std::endl;

		partial ? this->dealer.displayPartial() : this->dealer.display();
	}
};

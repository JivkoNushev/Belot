#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

class CardGame {
private:
    std::vector<std::string> deck;
    std::vector<std::string> player1;
    std::vector<std::string> player2;
    int currentPlayer;

public:
    CardGame() : currentPlayer(1) {
        // Initialize deck
        std::string suits = "SHDC";
        std::string ranks = "A23456789TJQK";
        for (char suit : suits) {
            for (char rank : ranks) {
                deck.push_back(std::string(1, rank) + suit);
            }
        }
        std::srand(std::time(0));
        std::random_shuffle(deck.begin(), deck.end());

        // Deal cards
        for (int i = 0; i < 5; ++i) {
            player1.push_back(deck.back());
            deck.pop_back();
            player2.push_back(deck.back());
            deck.pop_back();
        }
    }

    void playTurn() {
        std::string card = (currentPlayer == 1) ? player1.back() : player2.back();
        std::cout << "Player " << currentPlayer << " plays " << card << std::endl;
        if (currentPlayer == 1) player1.pop_back();
        else player2.pop_back();

        currentPlayer = 3 - currentPlayer;  // Switch player
    }

    bool isGameOver() {
        return player1.empty() || player2.empty();
    }
};

int main() {
    CardGame game;
    while (!game.isGameOver()) {
        game.playTurn();
    }
    std::cout << "Game over!" << std::endl;
    return 0;
}

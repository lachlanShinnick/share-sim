#include "Game.h"
#include <iostream>

int main() {
    double initial_balance;

    std::cout << "Enter initial balance: ";
    std::cin >> initial_balance;

    Game game(initial_balance);
    game.start();

    return 0;
}

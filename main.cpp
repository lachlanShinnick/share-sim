#include "Game.h"
#include "Menu.h"
#include <iostream>

int main() {
    Menu menu;
    Investor* investor = menu.chooseInvestorType();
    Game game(investor);
    game.start();
    delete investor; // Remember to delete the dynamically allocated investor
    return 0;
}

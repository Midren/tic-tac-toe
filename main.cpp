#include <iostream>
#include "game.h"

using std::endl;
using std::cin;
using std::cout;
using std::string;

Player* choose_player(int num) {
    cout << "Choose " << num << " player: " << endl
         << "1. Human " << endl
         << "2. Weak Computer" << endl
         << "3. Strong Computer" << endl;
    string stp;
    while (true) {
        cout << ">> ";
        cin >> stp;
        if (stp.length() > 1 || !isdigit(stp[0]) || stoi(stp) > 3) {
            cout << "Invalid input! Write only number in range [1; 3]" << endl;
            continue;
        }
        break;
    }

    switch(stoi(stp)) {
        case 1:
            return new HumanPlayer();
        case 2:
            return new LowSkillBotPlayer();
        case 3:
            return new HighSkillBotPlayer();
    }

    return nullptr;
}

int main() {
    auto pl1 = choose_player(1);
    auto pl2 = choose_player(2);
    Game game = Game(pl1, pl2);
    game.play();
}
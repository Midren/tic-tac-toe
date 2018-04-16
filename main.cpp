#include <iostream>
#include "game.h"

using namespace std;

int choose_player(int num) {
    cout << "Choose " << num << " player: " << endl
         << "1. Human " << endl
         << "2. Weak Computer" << endl
         << "3. Strong Computer" << endl;
    while (true) {
        cout << ">> ";
        string stp;
        cin >> stp;
        if (stp.length() > 1 || !isdigit(stp[0]) || stoi(stp) > 3) {
            cout << "Invalid input! Write only number in range [1; 3]" << endl;
            continue;
        }
        return stoi(stp);
    }
}

int main() {
    cout << "Choose your opponent: " << endl
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
            Game<HumanPlayer, HumanPlayer>(HumanPlayer(), HumanPlayer()).play();
            break;
        case 2:
            Game<LowSkillBotPlayer, HumanPlayer>(LowSkillBotPlayer(), HumanPlayer()).play();
            break;
        case 3:
            Game<HighSkillBotPlayer, HumanPlayer>(HighSkillBotPlayer(), HumanPlayer()).play();
            break;
        default:
            cout << "OOOps" << endl;
    }
    return 0;
}
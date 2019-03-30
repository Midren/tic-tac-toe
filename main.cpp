#include <iostream>
#include "game.h"
#include "menu.h"

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "Use --tui to run in ncurses interface and --tty in terminal" << endl;
        return 0;
    }
    int mod = 0;
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--tui") {
            mod = Menu::nCursesMod;
            break;
        } else if (arg == "--tty") {
            mod = Menu::classicalMod;
            break;
        } else {
            cout << "Invalid interface parameter" << endl;
            cout << "Use --tui to run in ncurses interface and --tty in terminal" << endl;
            return 0;
        }
    }
    Menu menu = Menu(mod);
    menu.start();
}

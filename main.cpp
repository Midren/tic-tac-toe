#include <iostream>
#include "game.h"
#include "menu.h"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
    int mod = 0;
    for(int i =1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--tui") {
            mod = Menu::nCursesMod;
            break;
        } else if (arg == "--tty") {
            mod = Menu::classicalMod;
            break;
        }
    }
    Menu menu = Menu(mod);
    menu.start();
}
#include "players.h"
#include "menu.h"
#include "game.h"
#include <ncurses.h>

Menu::Menu(int m) : mod(m) {
    if (mod == 1) {
        initscr();
        curs_set(0);
        noecho();
    }
}

Menu::~Menu() {
    if (mod == 1) {
        endwin();
    }
}

int choose_option(std::vector<std::string> options) {
    int yMax, xMax;
    getmaxx(stdscr);
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *menuwin = newwin(yMax / 2, xMax / 2, yMax / 6, xMax / 4);
    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);
    int option = 0;
    while (true) {
        box(menuwin, 0, 0);
        for (int i = 0; i < options.size(); i++) {
            if (i == option + 3) wattron(menuwin, A_STANDOUT);
            mvwprintw(menuwin, i + 1, (getmaxx(menuwin) - static_cast<int>(options[i].size())) / 2, options[i].c_str());
            if (i == option + 3) wattroff(menuwin, A_STANDOUT);
        }
        wrefresh(menuwin);
        int opt_num = static_cast<int>(options.size()) - 3;
        switch (wgetch(menuwin)) {
            case KEY_UP:
                option = (opt_num + --option) % opt_num;
                break;
            case KEY_DOWN:
                option = ++option % opt_num;
                break;
            case 10:
                return option;
        }
    }
}

Player *Menu::choose_player(int num) {
    if (mod == 0) {
        std::cout << "Choose " << num << " player: " << std::endl
                  << "1. Human " << std::endl
                  << "2. Weak Computer" << std::endl
                  << "3. Strong Computer" << std::endl;
        std::string stp;
        while (true) {
            std::cout << ">> ";
            std::cin >> stp;
            if (stp.length() > 1 || !isdigit(stp[0]) || stoi(stp) > 3) {
                std::cout << "Invalid input! Write only number in range [1; 3]" << std::endl;
                continue;
            }
            break;
        }

        switch (stoi(stp)) {
            case 1:
                if (mod == 0) return new HumanPlayerClassical();
                else if (mod == 1) return new HumanPlayerNcurses();
            case 2:
                return new LowSkillBotPlayer();
            case 3:
                return new HighSkillBotPlayer();
            default:
                return nullptr;
        }
    } else if (mod == 1) {
        std::vector<std::string> lines = {"", "Choose " + std::to_string(num) + " player", "", "Human",
                                          "Weak Computer", "Strong Computer"};
        int option = choose_option(lines);
        switch (option + 1) {
            case 1:
                if (mod == 0) return new HumanPlayerClassical();
                else if (mod == 1) return new HumanPlayerNcurses();
            case 2:
                return new LowSkillBotPlayer();
            case 3:
                return new HighSkillBotPlayer();
            default:
                return nullptr;
        }
    }
}

void Menu::start() {
    if (mod == Menu::classicalMod) {
        std::cout << "Welcome to Tic-Tac-Toe" << std::endl;
        play();
    } else if (mod == Menu::nCursesMod) {
        while (true) {
            std::vector<std::string> lines = {"", "Welcome to Tic-Tac-Toe game", "", "Play", "Rules",
                                              "About Author", "Exit"};
            int option = choose_option(lines);
            switch (option) {
                case 0:
                    clear();
                    play();
                    break;
                case 1:
                    rules();
                    break;
                case 2:
                    author();
                    break;
                case 3:
                    return;
            }
        }
    }
}

void Menu::play() {
    auto pl1 = choose_player(1);
    auto pl2 = choose_player(2);
    Game game = Game(pl1, pl2, mod);
    auto end = game.play();
    if (end.first) {
        print_winner(end.second);
    } else {
        print_draw();
    }
}

void Menu::rules() {

}

void Menu::author() {

}

void Menu::end() {

}

void print_message(std::string line) {
    clear();
    int yMax, xMax;
    getmaxx(stdscr);
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *menuwin = newwin(yMax / 2, xMax / 2, yMax / 6, xMax / 4);
    box(menuwin, 0, 0);
    mvwprintw(menuwin, getmaxy(menuwin)/2, (getmaxx(menuwin) - static_cast<int>(line.length()))/2, line.c_str());
    refresh();
    wrefresh(menuwin);
    wgetch(menuwin);
}

void Menu::print_winner(bool winner) {
    std::string winner_text = "Congratulations to Player #" + std::to_string(winner + 1);
    if (mod == 0) {
        std::cout << std::endl << winner_text << std::endl;
    } else if (mod == 1) {
        print_message(winner_text);
    }
}

void Menu::print_draw() {
    std::string draw_text = "Oh! It's a draw";
    if (mod == 0) {
        std::cout << draw_text << std::endl;
    } else if (mod == 1) {
        print_message(draw_text);
    }
}
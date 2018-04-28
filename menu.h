#ifndef TIC_TAC_TOE_MENU_H
#define TIC_TAC_TOE_MENU_H


class Menu {
public:
    static constexpr int classicalMod = 0;
    static constexpr int nCursesMod = 1;

    Menu(int);
    ~Menu();
    void start();
    void end();
private:
    void play();
    void rules();
    void author();
    void print_winner(bool);
    Player* choose_player(int);
    void print_draw();
    int mod;
};


#endif //TIC_TAC_TOE_MENU_H

#include <iostream>

using namespace std;

//Drawing the game board (test)
void board_drawTest(char arrboard[]) {
    system("cls");
    cout << " " << arrboard[0] << "| " << arrboard[1] << " |" << arrboard[2] << "\n";
    cout << "---------" << "\n";
    cout << " " << arrboard[3] << "| " << arrboard[4] << " |" << arrboard[5] << "\n";
    cout << "---------" << "\n";
    cout << " " << arrboard[6] << "| " << arrboard[7] << " |" << arrboard[8] << "\n";
}

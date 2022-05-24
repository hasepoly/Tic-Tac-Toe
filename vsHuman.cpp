#include "check.h"
#include "ae_tasks.h"
#include "boardDraw.h"

#include <iostream>

using namespace std;

void drawTTTvshuman() { // human vs human

    char ox = 88;     // 79 (O) or 88(X)      
    int id = 0;       // the cells from 1 to 9
    int winhuman = 0; // judge winner

    // array to discribe the board
    char board[9] = {};

    cout << "\nGame Start!" << endl;

    //game system is from here
    while (1) {
        while (1) { // user input move
            cout << "\nPlease enter the cell ID for your move: ";
            while (!(cin >> id) || (id < 1 || id >= 10) || (board[id - 1] == 79 || board[id - 1] == 88)) { //reject user input except int
                cin.clear();
                cin.ignore(1024, '\n');
                cout << "Error: we accept only integer 1 - 9" << "\n";
                cout << "       and there must be nothing put in the cell" << "\n";
                cout << "\nPlease enter again: ";
            }
            break;
        }

        board[id - 1] = ox; // put O or X
        boardDraw(board);

        winhuman = check(board, 9); //jump to the check function

        if (winhuman == 1) { //case O won
            cout << "\nO won! Congratulations!!" << "\n";
            break;
        }
        else if (winhuman == 2) { //case X won
            cout << "\nX won! Congratulations!!" << "\n";
            break;
        }
        else if (winhuman == 3) { //case draw
            cout << endl;
            cout << "Draw Game" << "\n";
            break;
        }

        // change O <-> X
        if (ox == 79) {
            ox = 88;
        }
        else if (ox == 88) {
            ox = 79;
        }
    }
    ae_tasks(); // go back to main function
}

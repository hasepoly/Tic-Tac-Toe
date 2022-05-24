#include "check.h"
#include "turn.h"
#include "cpu.h"
#include "cpuEasy.h"
#include "boardDraw.h"
#include "ae_tasks.h"

#include "comp_moveTest.h"

#include <iostream>

using namespace std;


void drawTTTvscomp(int m) { // human vs computer

    char oxhuman = 0; // O or X for human
    char oxcpu = 0;   // O or X for cpu
    int id = 1;       // the cells from 1 to 9
    int winhuman = 0;

    //display the board
    char board[9] = {};

    int tn = 0;// 
    tn = turn(); // determine play order 1->firstX, 2->secondO

    // assign O/X for each player
    if (tn == 1) {
        oxhuman = 88;
        oxcpu = 79;
    }
    else if (tn == 2) {
        oxhuman = 79;
        oxcpu = 88;
    }

    cout << "\nGame Start!" << endl;

    //game system is from here
    while (1) {

        if (tn == 2) { //case start from computer

            if (m == 0) {
                //id = moveTest(board); // stub
                id = cpuEasy(board, 9); // jump to the function which determine computer's movement (Easy)
            }
            else if (m == 1) {
                id = cpu(board, 9); // jump to the function which determine computer's movement (Hard)
            }

            cout << endl;
            cout << "\ncomputer turn: " << "\n";

            board[id - 1] = oxcpu;
            boardDraw(board);

            winhuman = check(board, 9); //jump to the check function

            if (winhuman == 1) {
                cout << "\nComputer O won!" << "\n";
                break;
            }
            else if (winhuman == 2) {
                cout << "\nComputer X won!" << "\n";
                break;
            }
            else if (winhuman == 3) {
                cout << endl;
                cout << "Draw Game" << "\n";
                break;
            }
        }


        while (1) { // user turn and ask user to input his move
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

        board[id - 1] = oxhuman;
        boardDraw(board);

        winhuman = check(board, 9); //jump to the check function

        if (winhuman == 1) {
            cout << "\nYou O won!" << "\n";
            break;
        }
        else if (winhuman == 2) {
            cout << "\nYou X won!" << "\n";
            break;
        }
        else if (winhuman == 3) {
            cout << endl;
            cout << "Draw Game" << "\n";
            break;
        }

        if (tn == 1) { //case start from computer

            if (m == 0) {
                //id = moveTest(board); // stub
                id = cpuEasy(board, 9); // jump to the function which determine computer's movement (Easy)
            }
            else if (m == 1) {
                id = cpu(board, 9); // jump to the function which determine computer's movement (Hard)
            }

            cout << endl;
            cout << "\ncomputer turn: " << "\n";

            board[id - 1] = oxcpu;
            boardDraw(board);

            winhuman = check(board, 9); //jump to the check function

            if (winhuman == 1) {
                cout << "\nComputer O won!" << "\n";
                break;
            }
            else if (winhuman == 2) {
                cout << "\nComputer X won!" << "\n";
                break;
            }
            else if (winhuman == 3) {
                cout << endl;
                cout << "Draw Game" << "\n";
                break;
            }
        }

    }
    ae_tasks(); // go back to main function
}

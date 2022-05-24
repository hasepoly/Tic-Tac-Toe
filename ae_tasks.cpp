/*--------------------------
Assignment Extra
Name: HASEGAWA Kenta
ID: 19085694D
----------------------------*/

#include "check.h"
#include "turn.h"
#include "vsHuman.h"
#include "vsComp.h"
#include "cpu.h"
#include "cpuEasy.h"
#include "boardDraw.h"

#include <iostream>
#include <time.h> // for dice

using namespace std;

void f() { // This function is called only once at first

    // Welcome message and explanation of the game
    cout << "Welcome to TTT game!" << "\n";
    cout << endl;
    cout << "Here is what the game board looks like with the IDs of each cell:" << "\n";
    cout << " 1| 2 |3 " << "\n";
    cout << "---------" << "\n";
    cout << " 4| 5 |6 " << "\n";
    cout << "---------" << "\n";
    cout << " 7| 8 |9 " << "\n";

}

int ae_tasks() {

    //call explanation just one time
    static bool IsFirst = true;

    if (IsFirst) {
        f(); // go to explanation part
        IsFirst = false;
    }

    // manage to control continue game or not
    int cont1 = 0;

    while (1)
    {
        //　Explain and provide the system commands to the user
        cout << endl;
        cout << "\nSystem Command       Action" << endl;
        cout << "----------------     --------" << endl;
        cout << "      0              Exit the system" << endl;
        cout << "      1              Begin entering a new game" << endl;

        cout << "\nStart game? If yes, input 1, if no input 0: ";
        cin >> cont1; // user input

        if ((!cin.fail()) && cont1 == 1) {// got int 1 and continue
            break;
        }
        if ((!cin.fail()) && cont1 == 0) {// got int 0 and finish
            return 0;
        }
        // got other than int or 0 / 1
        cout << "Invalid value";
        cin.clear();
        cin.ignore(1024, '\n');
    }

    // manage to control game mode
    int cont2 = 0;

    while (1)
    {
        //　Explain and provide the system commands to the user
        cout << endl;
        cout << "\nGame Mode Command Command       Action" << endl;
        cout << "---------------------------     --------" << endl;
        cout << "      0                         The human player plays against the computer player (easy)" << endl;
        cout << "      1                         The human player plays against the computer player (hard)" << endl;
        cout << "      2                         The human player plays against each other" << endl;

        cout << "\nSelect game mode. Input 0, 1 or 2: ";
        cin >> cont2; // user input
        if ((!cin.fail()) && (cont2 == 0 || cont2 == 1 || cont2 == 2)) {// got int 0, 1 or 2 and continue
            break;
        }

        // got other than int, or 0, 1 or 2
        cout << "Invalid value";
        cin.clear();
        cin.ignore(1024, '\n');
    }

    if (cont2 == 0) { // go to vs computer mode (Easy)
    //turn(); // determine play order
        drawTTTvscomp(0);
    }

    if (cont2 == 1) { // go to vs computer mode (Hard)
        //turn(); // determine play order
        drawTTTvscomp(1);
    }

    if (cont2 == 2) { // go to vs human mode
        turn(); // determine play order
        drawTTTvshuman();
    }

    return 0;
}

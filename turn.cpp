#include <iostream>
#include <time.h> // for dice

using namespace std;

// decide playing order throwing dice
int turn() {

    cout << endl;
    cout << "\nLet's throw the dice!" << "\n";
    cout << "* even number -> you play first as X" << "\n";
    cout << "* odd number -> you play second as O" << "\n";

    int face = 0;
    srand(time(0));          // random seed
    unsigned int i = rand(); // random number
    face = i % 6 + 1;        // face of dice

    cout << "\nFace is # " << face << "\n";

    int pt = 0; // manage player's turn

    if (face % 2 == 0) { //case even
        cout << "\nIt's even number and you play first as X" << "\n";
        pt = 1;
    }
    if (face % 2 == 1) { //case odd
        cout << "\nIt's odd number and you play second as O" << "\n";
        pt = 2;
    }

    return pt;
}

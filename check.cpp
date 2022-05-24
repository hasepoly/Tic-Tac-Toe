
// here checking whether there is a winner or not
int check(char arr[], int size) {

    int win = 0; // 0; continue, 1; o won, 2; x won, 3;draw
    static int counter = 0;

    if ((arr[0] == arr[1] && arr[1] == arr[2] && arr[0] == 79) || (arr[3] == arr[4] && arr[4] == arr[5] && arr[3] == 79) || (arr[6] == arr[7] && arr[7] == arr[8] && arr[6] == 79)) { // horizontal line
        win = 1;
        counter = 0;
    }
    if ((arr[0] == arr[1] && arr[1] == arr[2] && arr[0] == 88) || (arr[3] == arr[4] && arr[4] == arr[5] && arr[3] == 88) || (arr[6] == arr[7] && arr[7] == arr[8] && arr[6] == 88)) { // horizontal line
        win = 2;
        counter = 0;
    }

    if ((arr[0] == arr[3] && arr[3] == arr[6] && arr[0] == 79) || (arr[1] == arr[4] && arr[4] == arr[7] && arr[1] == 79) || (arr[2] == arr[5] && arr[5] == arr[8] && arr[2] == 79)) { // vertical line
        win = 1;
        counter = 0;
    }
    if ((arr[0] == arr[3] && arr[3] == arr[6] && arr[0] == 88) || (arr[1] == arr[4] && arr[4] == arr[7] && arr[1] == 88) || (arr[2] == arr[5] && arr[5] == arr[8] && arr[2] == 88)) { // vertical line
        win = 2;
        counter = 0;
    }

    if ((arr[0] == arr[4] && arr[4] == arr[8] && arr[0] == 79) || (arr[2] == arr[4] && arr[4] == arr[6] && arr[2] == 79)) { // diagonal line
        win = 1;
        counter = 0;
    }
    if ((arr[0] == arr[4] && arr[4] == arr[8] && arr[0] == 88) || (arr[2] == arr[4] && arr[4] == arr[6] && arr[2] == 88)) { // diagonal line
        win = 2;
        counter = 0;
    }

    counter += 1;
    //cout << "This is step " << counter << "; there are " << 9 - counter << " more steps." << "\n";
    if (counter == 9) {
        win = 3; //set draw
        counter = 0;
    }

    return win;
}

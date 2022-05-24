// priority -> cell id 5 -> 1,3,7,9 -> 2,4,6,8
//if there are any line having two in a row, choose the last one to win / avoid to lose
int cpu(char arrCpu[], int sizeCpu) {

    int put = 0; //computer's move
    int c[8][3] = { {0,1,2}, {3,4,5}, {6,7,8},{0,3,6}, {1,4,7}, {2,5,8},{0,4,8}, {2,4,6} }; // all patterns of line
    int priority[9] = { 7,5,3,1,8,6,2,0,4 }; //the latter has more priority than the previous one

    for (int i = 0; i < 8; i++) { // check all lines if there is any line having two in a row
        if ((arrCpu[c[i][0]] == arrCpu[c[i][1]]) && (arrCpu[c[i][0]] == 79) || (arrCpu[c[i][0]] == arrCpu[c[i][1]]) && (arrCpu[c[i][0]] == 88)) {
            if (arrCpu[c[i][2]] != 79 && arrCpu[c[i][2]] != 88) {
                put = c[i][2] + 1;
            }
        }
        if ((arrCpu[c[i][0]] == arrCpu[c[i][2]]) && (arrCpu[c[i][0]] == 79) || (arrCpu[c[i][0]] == arrCpu[c[i][2]]) && (arrCpu[c[i][0]] == 88)) {
            if (arrCpu[c[i][1]] != 79 && arrCpu[c[i][1]] != 88) {
                put = c[i][1] + 1;
            }
        }
        if ((arrCpu[c[i][1]] == arrCpu[c[i][2]]) && (arrCpu[c[i][1]] == 79) || (arrCpu[c[i][1]] == arrCpu[c[i][2]]) && (arrCpu[c[i][1]] == 88)) {
            if (arrCpu[c[i][0]] != 79 && arrCpu[c[i][0]] != 88) {
                put = c[i][0] + 1;
            }
        }
    }

    if (put == 0) { // if there is no line having two in a row, determine the move according to the priority
        for (int j = 0; j < 9; j++) {
            if (arrCpu[priority[j]] != 79 && arrCpu[priority[j]] != 88) {
                put = priority[j] + 1;
            }
        }
    }

    return put; //return determined move
}

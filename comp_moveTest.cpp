// used for blackbox testing; determine the move starting from 1 to 9 and finalized if there is still no piece put
int moveTest(char arrCpuEasy[]) {

    int putTest = 0; //computer's move

        for (int j = 0; j < 9; j++) {
            if (arrCpuEasy[j] != 79 && arrCpuEasy[j] != 88) {
                putTest = j + 1;
                break;
            }
        }

    return putTest; //return determined move
}

// priority -> cell id 2,4,6,8 -> 1,3,7,9 -> 5
int cpuEasy(char arrCpuEasy[], int sizeCpuEasy) {

    int putEasy = 0; //computer's move
    int priorityEasy[9] = { 4,0,2,6,8,1,3,5,7 }; //the latter has more priority than the previous one

    if (putEasy == 0) { // if there is no line having two in a row, determine the move according to the priority
        for (int j = 0; j < 9; j++) {
            if (arrCpuEasy[priorityEasy[j]] != 79 && arrCpuEasy[priorityEasy[j]] != 88) {
                putEasy = priorityEasy[j] + 1;
            }
        }
    }

    return putEasy; //return determined move
}

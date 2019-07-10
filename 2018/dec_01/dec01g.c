#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FRQ_CHANGELIST_LENGTH 1024
#define MAX_FRQLIST_LENGTH 200000

int frqInArray(int frq, int* frqArray, int lenght) {
    for (int i  = 0; i < lenght; i++) {
        if (frq == frqArray[i]) {
            printf("\nFound duplicate at position %d in frequency change list.\n", i);
            return 1;
        }
    }

    return 0;
}

int main(int argc, char* argv[]) {
    FILE *fp;
    char buff[8];
    int freqChange[MAX_FRQ_CHANGELIST_LENGTH] = { 0 };
    int freqList[MAX_FRQLIST_LENGTH] = { 0 };
    int nbrOfFreqCh = 0;
    int result = 0;
    int lenFrqList = 0;
    int currFrq = 0;

    fp = fopen("input", "r");

    // Read input from file and store in array
    while(fgets(buff, 1024, fp) != NULL) {
        freqChange[nbrOfFreqCh] = atoi(buff);
        nbrOfFreqCh++; 
    }

    // The task
    lenFrqList = 0;
    currFrq = 0;
    while (lenFrqList < MAX_FRQLIST_LENGTH){
        // Calculate next frequency
        currFrq += freqChange[lenFrqList % nbrOfFreqCh];
        freqList[lenFrqList] = currFrq;

        // Check if frequency is duplicate
        if (frqInArray(currFrq, freqList, lenFrqList)) {
            result = currFrq;
            break;
        }
        lenFrqList++;

        // Print something to indicate that we are still alive
        if (lenFrqList % nbrOfFreqCh == 0) {
            fflush(stdout);
            printf(".");
        }
        
    }

    printf("The answer is %d\nThe lenght of the frequency list is: %d\n", result, lenFrqList);
}
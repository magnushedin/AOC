#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NBROFFREQCH 1024

int main(int argc, char* argv[]) {
    FILE *fp;
    char buff[8];
    int freqChange[NBROFFREQCH] = { 0 };
    int nbrOfFreqCh = 0;
    int result = 0;

    fp = fopen("input", "r");

    // Read input from file and store in array
    while(fgets(buff, 1024, fp) != NULL) {
        //printf("%d, %s\n", nbrOfFreqCh, buff);
        freqChange[nbrOfFreqCh] = atoi(buff);
        nbrOfFreqCh++; 
    }

    // Check input
    for (int j=0; j < nbrOfFreqCh; j++) {
        printf("%d, %d\n", j, freqChange[j]);
    }

    for (int i = 0; i < nbrOfFreqCh; i++) {
        result += freqChange[i];
    }

    printf("The answer is %d\n", result);
}
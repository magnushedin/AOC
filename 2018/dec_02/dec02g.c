#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NBR_OF_INPUT 1024
#define MAX_SIZE_OF_INPUT 60

int compareStrings(char* a1, char* a2, int arrayLength) {
    int cnt = 0;
    for (int i=0; i<arrayLength; i++) {
        if (a1[i] != a2[i]) {
            cnt++;
        }
    }
    return cnt;
}

void printArray(char* a1, char* a2, int arrayLength) {
    printf("Answer: ");
    for (int i=0; i<arrayLength; i++) {
        if (a1[i] == a2[i]) {
            printf("%c", a1[i]);
        }
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    FILE *fp;
    char buff[30];
    char inputArray[MAX_NBR_OF_INPUT][MAX_SIZE_OF_INPUT];
    int nbrOfInput = 0;

    fp = fopen("input", "r");

    // Read input from file and store in array
    while(fgets(buff, 30, fp) != NULL) {
        strncpy(inputArray[nbrOfInput], buff, 26);
        //printf(">%s-%s\n", buff, inputArray[nbrOfInput]);
        nbrOfInput++;
    }

    // Check input
    for (int i = 0; i < nbrOfInput; i++) {
        //printf("%d: %s\n", i, inputArray[i]);
    }

    // The task
    for (int i=0; i<nbrOfInput; i++) {
        for (int j=i+1; j<nbrOfInput; j++) {
            if (compareStrings(inputArray[i], inputArray[j], 26) == 1) {
                printf(">%s\n-%s\n", inputArray[i], inputArray[j]);
                printArray(inputArray[i], inputArray[j], 26);
            }
        }
    }


}
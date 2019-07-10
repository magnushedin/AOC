#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NBR_OF_INPUT 1024
#define MAX_SIZE_OF_INPUT 60

int nbrOfSame(char inputChar, char *inputString) {
    //printf("%c, %s\n", inputChar, inputString);
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        //printf("%c - %c\n", inputChar, inputString[i]);
        if (inputChar == inputString[i]) {
            cnt++;
        }
    }
    //printf("cnt = %d\n", cnt);
    return cnt;
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
    int cnt;
    int two = 0;
    int three = 0;
    int foundTwo = 0;
    int foundThree = 0;
    for (int i=0; i < nbrOfInput; i++) {
        for (int j=0; j < 26; j++) {
            cnt = nbrOfSame(inputArray[i][j], inputArray[i]);
            if (cnt == 2) {
                foundTwo++;
            }
            if (cnt == 3) {
                foundThree++;
            }
        }
        if (foundTwo > 0) {
            two++;
        }
        if (foundThree > 0) {
            three++;
        }
        foundTwo = 0;
        foundThree = 0;
    }

    printf("code = %d\n", two*three);

}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 1060
#define MAX_GUARDS 1000

typedef struct guards{
    int id;
    int day;
    int hour;
    char schedule[64];
    int sleep[59];
} guards;

int compare( const void* a, const void* b)
{
     guards int_a = * ( (guards*) a );
     guards int_b = * ( (guards*) b );

     if ( int_a.day == int_b.day ) {
         if (int_a.hour == int_b.hour) {
             return 0;
         } else if (int_a.hour < int_b.hour) {
            return -1;
         }
         else {
            return 1;
         }
     }
     else if ( int_a.day < int_b.day ) {
         return -1;
     }
     else {
         return 1;
     }
}

int main(int argc, char* argv[]) {
    FILE *fp;
    char buff[64];
    guards inputArray[MAX_ROWS];
    guards guardArray[MAX_GUARDS];
    int nbrOfInput = 0;
    int nbrOfGuards = 0;

    char *token;

    int x = 0, y = 0, dx = 0, dy = 0;
    int answer = 0;

    fp = fopen("input", "r");

    // Read input from file and store in array
    while(fgets(buff, 64, fp) != NULL) {
        nbrOfInput++;
        strncpy(inputArray[nbrOfInput].schedule, buff, 64);
   
        printf("%s", buff);
        /* get the first token */
        token = strtok(buff, "-");

        // Find date
        token = strtok(NULL, "-");
        inputArray[nbrOfInput].day = atoi(token)*100;
        token = strtok(NULL, " ");
        inputArray[nbrOfInput].day += atoi(token);
        printf("%d\n", inputArray[nbrOfInput].day);

        // Find hour
        token = strtok(NULL, ":");
        inputArray[nbrOfInput].hour = atoi(token)*100;
        if (inputArray[nbrOfInput].hour == 0) {
            inputArray[nbrOfInput].hour += 2400;
        }
        token = strtok(NULL, "]");
        inputArray[nbrOfInput].hour += atoi(token);
        printf("%d\n", inputArray[nbrOfInput].hour);
        //printf( " %s\n", token);
    
        //token = strtok(NULL, s);
    }

    // Sort the list
    qsort(inputArray, nbrOfInput, sizeof(guards), compare);

    int guardId = 0;
    int guardArrayId = 0;
    int sleeps = 0;
    int wakes = 0;
    // The algorithm
    for (int i=0;i<nbrOfInput;i++) {

        if (strstr(inputArray[i].schedule, "Guard") != NULL) {
            printf("%s", inputArray[i].schedule);
            strncpy(buff, inputArray[i].schedule, 64);
            token = strtok(buff, "#");
            guardId = atoi(strtok(NULL, " "));
            
            while ((guardArray[guardArrayId].id != 0) && (guardArray[guardArrayId].id != guardId)) {
                guardArrayId++;
            }
            guardArray[guardArrayId].id = guardId;
            nbrOfGuards++;
        }
        else if (strstr(inputArray[i].schedule, "falls") != NULL) {
            if (inputArray[i].hour > 2359) {
                inputArray[i].hour -= 2400;
            }
            sleeps = inputArray[i].hour;
        } 
        else if (strstr(inputArray[i].schedule, "wakes") != NULL) {
            if (inputArray[i].hour > 2359) {
                inputArray[i].hour -= 2400;
            }
            wakes = inputArray[i].hour;
            for (int ii=sleeps; ii<wakes; ii++) {
                guardArray[guardArrayId].sleep[ii]++;
            }
        }
    }

    // The answer
    for (int i=0; i<nbrOfInput; i++) {
        //printf("%s",inputArray[i].schedule);
    }
    for (int i=0; i<nbrOfGuards; i++) {
        printf("%d: ", guardArray[i].id);
        for (int ii=0;ii<59;ii++) {
            printf("%d",guardArray[i].sleep[ii]);
        }
        printf("\n");
    }

    /*for (int i=0; i<MAX_X; i++) {
        for (int j=0; j<MAX_Y; j++) {
            printf("%d", inputArray[i][j]);
        }
        printf("\n");
    }*/

    printf("The answer is: %d\n", answer);

}
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
        
        strncpy(inputArray[nbrOfInput].schedule, buff, 64);
   
        //printf("%s", buff);
        /* get the first token */
        token = strtok(buff, "-");

        // Find date
        token = strtok(NULL, "-");
        inputArray[nbrOfInput].day = atoi(token)*100;
        token = strtok(NULL, " ");
        inputArray[nbrOfInput].day += atoi(token);
        //printf("%d\n", inputArray[nbrOfInput].day);

        // Find hour
        token = strtok(NULL, ":");
        inputArray[nbrOfInput].hour = atoi(token)*100;
        /*if (inputArray[nbrOfInput].hour == 0) {
            inputArray[nbrOfInput].hour += 2400;
        }*/
        token = strtok(NULL, "]");
        inputArray[nbrOfInput].hour += atoi(token);
        //printf("%d\n", inputArray[nbrOfInput].hour);
        //printf( " %s\n", token);
    
        //token = strtok(NULL, s);
        nbrOfInput++;
    }

    // Sort the list
    qsort(inputArray, nbrOfInput, sizeof(guards), compare);

    for (int i=0; i<nbrOfInput; i++) {
        printf("qsort %s",inputArray[i].schedule);
    }

    int guardId = 0;
    int guardArrayId = 0;
    int sleeps = 0;
    int wakes = 0;
    // The algorithm
    for (int i=0;i<nbrOfInput;i++) {
        printf("%s", inputArray[i].schedule);

        if (strstr(inputArray[i].schedule, "Guard") != NULL) {
            strncpy(buff, inputArray[i].schedule, 64);
            token = strtok(buff, "#");
            guardId = atoi(strtok(NULL, " "));

            printf("guardId: %d, ", guardId);
            
            for (int j=0; j<=nbrOfGuards;j++) {
                //printf("%d - %d\n", guardArray[j].id, guardId);
                if (guardArray[j].id == guardId) {
                    guardArrayId = j;
                    //printf("found duplicate\n");
                    break;                    
                }
                else if (guardArray[j].id == 0) {
                    guardArrayId = j;
                    nbrOfGuards++;
                    break;
                    //printf("no duplicate\n");
                }
            }
            guardArray[guardArrayId].id = guardId;
            printf("guardArrayId: %d\n", guardArrayId);

            if (guardId == 2239) {
                //printf("2239: i:%d, id:%d\n", i, guardId);
            }

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
            printf("GuardArrayId: %d, sleeps: %d, wakes: %d\n", guardArrayId, sleeps, wakes);
            for (int ii=sleeps; ii<wakes; ii++) {
                guardArray[guardArrayId].sleep[ii]++;
            }
        }
    }


    // The answer

    
    int minutesAsleep = 0;
    int mostSleep = 0;
    for (int i=0; i<nbrOfGuards; i++) {
        minutesAsleep = 0;
        mostSleep = 0;
        printf("%d: ", guardArray[i].id);
        for (int ii=0;ii<59;ii++) {
            if (guardArray[i].sleep[ii] > guardArray[i].sleep[mostSleep]) {
                mostSleep = ii;
            }
            minutesAsleep += guardArray[i].sleep[ii];
            if (guardArray[i].sleep[ii] > 9) {
                printf(";%d;",(guardArray[i].sleep[ii]));
            }
            else {
                //printf("%d",(guardArray[i].sleep[ii]));
                printf("*");
            }
        }
        printf(", minutes asleep: %d, minute: %d, guardId: %d, mult: %d\n", minutesAsleep, mostSleep, guardArray[i].id, guardArray[i].id*mostSleep);
    }


    for (int i=0; i<nbrOfGuards; i++) {
        //printf("%d - %d\n",i, guardArray[i].id);
    }

    printf("The answer is: %d\n", answer);

}
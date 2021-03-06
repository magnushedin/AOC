#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 50003
#define MAX_GUARDS 1000

int comparePoly(char c1, char c2) {
    if ((c1 - c2 == 32) || (c2 - c1 == 32)) {
        return 1;
    }
    else {
        return 0;
    }
}

void removePoly(int from, char* polyArray, int n) {

    //printf("read: %d, removing: %c, writing: %c\n", from, polyArray[from], polyArray[from+2]);
    //printf("(%c, %c), ", polyArray[from], polyArray[from+1]);
    for (int i=from; i<n+2; i++) {
        polyArray[i] = polyArray[i+2];
    }
}

int searchPoly(char * polyArray, int n) {
    int found = 0;
    int i = 0;
    while ((found == 0) && (i <= n)) {
        //printf("searchPoly: %d\n", i);
        if (comparePoly(polyArray[i],polyArray[i+1])) {
            //printf("%d - %d, (%c - %c)\n", polyArray[i], polyArray[i+1], polyArray[i], polyArray[i+1]);
            removePoly(i, polyArray, n);
            found = 1;
        }
        i++;
    }
    return found;
}

int main(int argc, char* argv[]) {
    FILE *fp;
    char buff[64];
    char polym[MAX_CHAR];
    int nbrOfInput = 0;
    char *token;

    int answer = 0;

    fp = fopen("input", "r");

    // Read input from file and store in array
    while(fgets(polym, MAX_CHAR, fp) != NULL) {
    }



    printf("strlen: %ld\n", strlen(polym));

    int found = 1;
    while (found == 1) {
        //printf("%s\n", polym);
        found = searchPoly(polym, strlen(polym));
        //printf("strlen: %ld\n", strlen(polym));
        //printf(".");
    }
    //printf("\n");


    //printf("%s\n", polym);
    printf("The answer is: %ld\n", strlen(polym));

}
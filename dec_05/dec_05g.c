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

// Remove char from array at given index
void removePoly(int from, char* polyArray, int n) {
    for (int i=from; i<n+2; i++) {
        polyArray[i] = polyArray[i+2];
    }
}

// Removes all instances of a character from the array by reading and writing in the same array.
void removeChar(char c, char* polyArray) {
    int write = 0;
    printf("Removing: %c\n", c);

    for (int read=0; read<(strlen(polyArray)+1); read++) {
        if ((polyArray[read] != c) && (polyArray[read] != (c+32)) && polyArray[read] != (c-32)) {
            polyArray[write] = polyArray[read];
            write++;
        }
    }
}

// Searches the polymer for reduction possibilities, ie a char next to it's capitalised version.
int searchPoly(char * polyArray, int n) {
    int found = 0;
    int i = 0;
    while ((found == 0) && (i <= n)) {
        if (comparePoly(polyArray[i], polyArray[i+1])) {
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
    char testArray[MAX_CHAR];
    int nbrOfInput = 0;
    char *token;
    long int min = 100000;

    int answer = 0;

    fp = fopen("input", "r");

    // Read input from file and store in array
    while(fgets(polym, MAX_CHAR, fp) != NULL) {
    }

    for (char c_remove = 'A'; c_remove <= 'Z'; c_remove++)
    {
        // Copy to test array because removing letters will destroy the array
        memcpy(testArray, polym, sizeof(char) * MAX_CHAR);

        // Search for each letter and removes it
        removeChar(c_remove, testArray);

        // Reduce the polymer
        int found = 1;
        while (found == 1)
        {
            found = searchPoly(testArray, strlen(testArray));
        }

        // Store minimum length of polymer
        if (min > strlen(testArray)) {
            min = strlen(testArray);
            printf("New min: %ld\n", min);
        }
    }
    printf("Shortest array is: %ld\n", min);
}
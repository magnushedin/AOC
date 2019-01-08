#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FILENAME "testinput"
#define CREATURES_MAX 20
#define Y_MAX 10
#define X_MAX 10

typedef struct creature {
    char type;
    int hp;
    int power;
    int x;
    int y;
} creature;

// Read input from file and store in array
int read_input(char* filename, char map[Y_MAX][X_MAX])
{
    FILE *fp;
    char buff[X_MAX];
    int y = 0;

    fp = fopen(filename, "r");

    while(fgets(buff, 300, fp) != NULL) {
        for (int x=0; x < strlen(buff); x++) {
            map[y][x] = buff[x];
        }
        y++;
    }
    fclose(fp);

    return y;
}

// Print the map
void print_map(char map[Y_MAX][X_MAX], int y_max)
{
    for (int y=0; y<y_max; y++) {
        for (int x=0; x<X_MAX; x++) {
            if (map[y][x] == 'G') {
                printf(KRED "%c" KNRM, map[y][x]);
            }
            else if (map[y][x] == 'E') {
                printf(KCYN "%c" KNRM, map[y][x]);
            }
            else {
                printf("%c", map[y][x]);
            }
        }
        //printf("\n");
    }
    printf("\n====================================\n");
}

// Main function
int main(int argc, char* argv[])
{
    char map[Y_MAX][X_MAX] = {'.'};
    creature creatures[CREATURES_MAX];
    
    int y_max;

    y_max = read_input(FILENAME, map);
    print_map(map, y_max);
}
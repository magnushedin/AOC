#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define FILENAME "testinput"
#define X_MAX 20
#define Y_MAX 20

// Read input from file and store in array
int read_input(char* filename, char map[Y_MAX][X_MAX])
{
    FILE *fp;
    char buff[X_MAX];
    int y = 0;

    fp = fopen(filename, "r");

    while(fgets(buff, 128, fp) != NULL) {
        for (int x=0; x < strlen(buff)-1; x++) {
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
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
    printf("====================================\n");
}

// Next tick
int next_tick(char map[Y_MAX][X_MAX]) {

    for (int y=0; y<Y_MAX; y++) {
        for (int x=0; x<X_MAX; x++) {
            switch(map[y][x]) {
                case '>' :
                map[y][x] = 'X';
                break;
                case '<' :
                break;
                case '^' :
                break;
                case 'v' :
                break;
                default :
                break;
            }
        }
    }

    return 1;
}

// Main function
int main(int argc, char argv[])
{
    int y_max = 0;
    int crach = 0;
    char map[Y_MAX][X_MAX] = {'\0'};

    // Read file
    y_max = read_input(FILENAME, map);
    
    // Run simulation
    print_map(map, y_max);
    while (!crach) {
        crach = next_tick(map);
        print_map(map, y_max);
    }
}
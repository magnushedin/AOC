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

#define EVER (int i=0;i<1;){}
#define ONES (int i=0;i<i;i++){}

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define FILENAME "testinput2"
#define CREATURES_MAX 20
#define Y_MAX 10
#define X_MAX 10
#define HP_START 200
#define POWER_START 3
#define IN_RANGE_MAX (CREATURES_MAX*8)
#define REACHABLE_MAX IN_RANGE_MAX

typedef struct creature {
    char type;
    int hp;
    int power;
    int x;
    int y;
} creature;

typedef struct square {
    int x;
    int y;
    int dist;
} square;

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

int is_in_array(int x, int y, square in_range[IN_RANGE_MAX], int nbrof_in_range)
{
    for (int i=0; i<nbrof_in_range; i++) {
        if ((in_range[i].x == x) && (in_range[i].y == y)) {
            return 1;
        }
    }
    return 0;
}

void print_map_in_range(char map[Y_MAX][X_MAX], int y_max, square in_range[IN_RANGE_MAX], int nbrof_in_range)
{
    //printf("nbrof_in_range: %d\n", nbrof_in_range);
    for (int y=0; y<y_max; y++) {
        for (int x=0; x<X_MAX; x++) {
            if (is_in_array(x, y, in_range, nbrof_in_range)) {
                printf(KYEL "?" KNRM);
                //printf("---%d,%d---\n",x, y);
            }
            else if (map[y][x] == 'G') {
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

void print_map_reachable(char map[Y_MAX][X_MAX], int y_max, square reachable[REACHABLE_MAX], int nbrof_reachable)
{
    //printf("nbrof_in_range: %d\n", nbrof_in_range);
    for (int y=0; y<y_max; y++) {
        for (int x=0; x<X_MAX; x++) {
            if (is_in_array(x, y, reachable, nbrof_reachable)) {
                printf(KYEL "@" KNRM);
                //printf("---%d,%d---\n",x, y);
            }
            else if (map[y][x] == 'G') {
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

int find_creatures(char map[Y_MAX][X_MAX], creature creatures[CREATURES_MAX])
{
    int nbrof_creatures = 0;

    for (int y=0; y<Y_MAX; y++) {
        for (int x=0; x<X_MAX; x++) {
            if (map[y][x] == 'G') {
                creatures[nbrof_creatures].type = 'G';
                creatures[nbrof_creatures].hp = HP_START;
                creatures[nbrof_creatures].power = POWER_START;
                creatures[nbrof_creatures].x = x;
                creatures[nbrof_creatures].y = y;
                nbrof_creatures++;
            }
            else if (map[y][x] == 'E') {
                creatures[nbrof_creatures].type = 'E';
                creatures[nbrof_creatures].hp = HP_START;
                creatures[nbrof_creatures].power = POWER_START;
                creatures[nbrof_creatures].x = x;
                creatures[nbrof_creatures].y = y;
                nbrof_creatures++;
            }
        }
    }
    
    return nbrof_creatures;
}

void print_creatures(creature creatures[CREATURES_MAX])
{
    int i = 0;
    
    printf("--- Creatures ---\n");
    while (creatures[i].type == 'G' || creatures[i].type == 'E') {
        printf("(%d,%d) - %c, hp: %d, power: %d\n", creatures[i].x, creatures[i].y, creatures[i].type, creatures[i].hp, creatures[i].power);
        i++;
    }
}

void print_in_range(square in_range[IN_RANGE_MAX], int nbrof_in_range)
{
    printf("--- Squares in range ---\n");
    for (int i=0; i<nbrof_in_range; i++) {
        printf("%d: (%d,%d)\n", i, in_range[i].x, in_range[i].y);
    }
}

void print_reachable(square reachable[REACHABLE_MAX], int nbrof_reachable)
{
    printf("--- Squares that are reachable ---\n");
    for (int i=0; i<nbrof_reachable; i++) {
        printf("%d: (%d,%d)\n", i, reachable[i].x, reachable[i].y);
    }
}

int compare_creatures(const void* in_a, const void* in_b)
{
    creature c_a = * ((creature*) in_a);
    creature c_b = * ((creature*) in_b);

     if ( c_a.y == c_b.y ) {
        if (c_a.x < c_b.x) {
            return -1;
        }
        else {
            return 1;
        }
     }
     else if ( c_a.y < c_b.y ) {
         return -1;
     }
     else {
        return 1;
     }
}

void sort_creatures(creature creatures[CREATURES_MAX], int nbrof_creatures)
{
    qsort(creatures, nbrof_creatures, sizeof(creature), compare_creatures);
}

int find_in_range(square in_range[IN_RANGE_MAX], char map[Y_MAX][X_MAX], creature creatures[CREATURES_MAX], int this_creature, int nbrof_creatures)
{
    int nbrof_in_range = 0;
    int x, y;

    for (int i=0; i<nbrof_creatures; i++) {
        x = creatures[i].x;
        y = creatures[i].y;
        if (i != this_creature) {
            if (map[MAX(y-1,0)][x] == '.') {
                //printf("(%d,%d) - %d, %d\n", creatures[i].x, creatures[i].y, x, y);
                in_range[nbrof_in_range].x = x;
                in_range[nbrof_in_range].y = y-1;
                nbrof_in_range++;
            }
            if (map[y][MAX(0,x-1)] == '.') {
                //printf("(%d,%d) - %d, %d\n", creatures[i].x, creatures[i].y, x, y);
                in_range[nbrof_in_range].x = x-1;
                in_range[nbrof_in_range].y = y;
                nbrof_in_range++;
            }
            if (map[y][MIN(x+1,X_MAX)] == '.') {
                //printf("(%d,%d) - %d, %d\n", creatures[i].x, creatures[i].y, x, y);
                in_range[nbrof_in_range].x = x+1;
                in_range[nbrof_in_range].y = y;
                nbrof_in_range++;
            }
            if (map[MIN(y+1,Y_MAX)][x] == '.') {
                //printf("(%d,%d) - %d, %d\n", creatures[i].x, creatures[i].y, x, y);
                in_range[nbrof_in_range].x = x;
                in_range[nbrof_in_range].y = y+1;
                nbrof_in_range++;
            }
        }
    }
    
    return nbrof_in_range;
}

int find_reachable(square reachable[REACHABLE_MAX], char map[Y_MAX][X_MAX], square in_range[IN_RANGE_MAX], int nbrof_in_range, int x, int y)
{
    int nbrof_reachable = 0;

    for (int i=0; i<nbrof_in_range; i++) {

    }

    reachable[0].x = 3;
    reachable[0].y = 1;
    nbrof_reachable++;
    
    return nbrof_reachable;
}

// Main function
int main(int argc, char* argv[])
{
    char map[Y_MAX][X_MAX] = {'.'};
    creature creatures[CREATURES_MAX];
    square in_range[IN_RANGE_MAX];
    square reachable[REACHABLE_MAX];
    
    int y_max;
    int nbrof_creatures = 0;
    int nbrof_in_range = 0;
    int nbrof_reachable = 0;
    int this_creature = 0;

    y_max = read_input(FILENAME, map);
    print_map(map, y_max);
    
    nbrof_creatures = find_creatures(map, creatures);
    sort_creatures(creatures, nbrof_creatures);
    print_creatures(creatures);

    // The game, should be a loop though all creatures
    for ONES

    // Squares that are in range
    nbrof_in_range = find_in_range(in_range, map, creatures, this_creature, nbrof_creatures);
    print_in_range(in_range, nbrof_in_range);
    print_map_in_range(map, y_max, in_range, nbrof_in_range);

    // Squares that are reachable
    nbrof_reachable = find_reachable(reachable, map, in_range, nbrof_in_range, creatures[this_creature].x, creatures[this_creature].y);
    print_reachable(reachable, nbrof_reachable);
    print_map_reachable(map, y_max, reachable, nbrof_reachable);

    // Nearest rechable square
    // Just sort?

    // Chosen reachable square
    // According to rule in task description

    // Reset variables
    nbrof_in_range = 0;
    nbrof_reachable = 0;
}
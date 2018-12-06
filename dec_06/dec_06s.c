#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_X 10
#define MAX_Y 10
#define MAX_AREAS 50

typedef struct coord {
    int x;
    int y;
    int area;
}coord;

// Read input from file and store in array
int read_input(char* filename, coord* coords) {
    FILE *fp;
    char buff[8];
    char *token;
    int i = 0;
    fp = fopen(filename, "r");

    while(fgets(buff, 64, fp) != NULL) {
        // get the first token
        token = strtok(buff, ", ");
        coords[i].x = atoi(token);

        token = strtok(NULL, "\n");
        coords[i].y = atoi(token);
        
        //printf("%d: (%d, %d)\n", i, coords[i].x, coords[i].y);
        i++;
    }
    fclose(fp);

    return i;
}

int calculate_dist(int x1, int y1, int x2, int y2) {
    return (abs(x1-x2) + abs(y1-y2));
}

int min_distance(coord* coords, int i, int nbr_of_input) {
    for (int i=0; i<nbr_of_input; i++) {
        printf("distance: (%d, %d) = %d\n", calculate_dist(x, y, coords[i].x, coords[i].y), coords[i].x, coords[i].y);
    }
    // Return index of shortest distance
    return 0;
}

void calculate_areas(int * area_array, coord* coords, int nbr_of_input) {
    for (int x=0; x<MAX_X; x++){
        for (int y=0; y<MAX_Y; y++) {
            printf("(%d, %d)\n", x, y);
             area_array[x][y] = min_distance(coords, i, nbr_of_input);
        }
    }

}

void remove_infinite( int * aoa_array) {

}

int find_largest_area(int * aoa_array) {

    return 0;
}

void print_area(int* area_array, int x, int y) {

}

int main(int argc, char* argv[]) {
    char buff[64];
    int area_array[MAX_X][MAX_Y];
    int aoa_array[MAX_AREAS];
    int answer = 0;
    int largest_area = 0;
    int nbr_of_input = 0;
    coord coords[MAX_AREAS];

    nbr_of_input = read_input("testinput", coords);
    for (int i=0; i< nbr_of_input; i++) {
        //printf("%d: (%d, %d)\n", i, coords[i].x, coords[i].y);
    }

    calculate_areas((int *)area_array, coords, nbr_of_input);
    print_area((int *)area_array, MAX_X, MAX_Y);
    remove_infinite(aoa_array);
    largest_area = find_largest_area(aoa_array);

    printf("Largest area: %d\n", largest_area);
}
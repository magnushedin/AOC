#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_X 400
#define MAX_Y 400
#define MAX_AREAS 50

typedef struct coord {
    int x;
    int y;
    int area;
}coord;

// Read input from file and store in array
int read_input(char* filename, coord* coords) {
    FILE *fp;
    char buff[16];
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

int sum_distance(int x, int y, coord* coords, int nbr_of_input) {
    int min = INT_MAX;
    int min_i = -1;
    int dist = 0;
    int nbr_of_min = 0;
    
    for (int i=0; i<nbr_of_input; i++) {
        dist += calculate_dist(x, y, coords[i].x, coords[i].y);
    }

    if (dist < 10000) {
        return 1;
    }
    else {
        return 0;
    }
}

void calculate_map(int area_array[MAX_Y][MAX_X], coord* coords, int nbr_of_input) {
    for (int y=0; y<MAX_Y; y++){
        for (int x=0; x<MAX_X; x++) {
            //printf("map(%d, %d)\n", y, x);
            area_array[y][x] = sum_distance(x, y, coords, nbr_of_input);
        }
    }

}

void remove_infinite(int area_array[MAX_Y][MAX_X], int * aoa_array)
{
    for (int x=0; x<MAX_X; x++) {
        if (area_array[0][x] >= 0) {
            aoa_array[area_array[0][x]] = 0;
        }
    }
    for (int x=0; x<MAX_X; x++) {
        if (area_array[MAX_X-1][x] >= 0) {
            aoa_array[area_array[MAX_Y-1][x]] = 0;
        }
    }
    for (int x=0; x<MAX_X; x++) {
        if (area_array[x][0] >= 0) {
            aoa_array[area_array[x][0]] = 0;
        }
    }
    for (int x=0; x<MAX_X; x++) {
        if (area_array[x][MAX_Y-1] >= 0) {
            aoa_array[area_array[x][MAX_Y-1]] = 0;
        }
    }
}

int find_largest_area(int * aoa_array, int nbr_of_input)
{
    int max = 0;

    for (int i=0; i<nbr_of_input; i++) {
        if (max < aoa_array[i]) {
            max = aoa_array[i];
        }
    }
    return max;
}

void print_map(int area_array[MAX_Y][MAX_X])
{
    for (int y=0; y<MAX_Y; y++) {
        for (int x=0; x<MAX_X; x++) {
            if (area_array[y][x] >= 0) {
                printf("%d", area_array[y][x]);
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int calculate_area(int area_array[MAX_Y][MAX_X])
{
    int area = 0;
    for (int y=0;y<MAX_Y;y++) {
        for (int x=0; x<MAX_X; x++) {
            area += area_array[y][x];
        }
    }

    return area;
}

void print_aoa_array(int *aoa_array, int nbr_of_input)
{
    for (int i=0; i<nbr_of_input; i++) {
        printf("id: %d: %d\n", i, aoa_array[i]);
    }
}

int main(int argc, char* argv[]) {
    char buff[64];
    int area_array[MAX_Y][MAX_X];
    int aoa_array[MAX_AREAS];
    int answer = 0;
    int largest_area = 0;
    int nbr_of_input = 0;
    coord coords[MAX_AREAS];

    for (int i=0; i<MAX_AREAS; i++) {
        aoa_array[i] = 0;
    }

    nbr_of_input = read_input("input", coords);
    for (int i=0; i< nbr_of_input; i++) {
        //printf("%d: (%d, %d)\n", i, coords[i].x, coords[i].y);
    }
    //printf("%d\n", nbr_of_input);
    calculate_map(area_array, coords, nbr_of_input);
    //print_map(area_array);
    largest_area = calculate_area(area_array);
    
    //largest_area = find_largest_area(aoa_array, nbr_of_input);

    

    printf("Largest area: %d\n", largest_area);
}
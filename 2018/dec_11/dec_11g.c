#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SERIAL 7857

int power_level(int x, int y, int serial) {
    int power;

    power = ((x+10)*y+serial)*(x+10);
    power = power/100;
    power = (power - (power/10)*10)-5;

    return power;
}

void print_map(int x_start, int y_start, int array[301][301]) {

    for (int y=MAX(y_start-1,0);y<MIN(y_start+4,300);y++) {
        for (int x=MAX(x_start-1,0);x<MIN(x_start+4,300);x++){
            if (array[x][y] >= 0)
                printf(" %d ", array[x][y]);
            else
                printf("%d ", array[x][y]);
        }
        printf("\n");
    }
}

int grid_power_level(int x, int y, int s, int array[301][301]) {
    int power = 0;
    for (int xx=x; xx<(x+s); xx++) {
        for (int yy=y;yy<(y+s); yy++) {
            power += array[xx][yy];
        }
    }

    return power;
}

int main(int argc, char* argv[])
{
    int array[301][301];
    int max_grid_power = INT_MIN;
    int grid_power, x_max, y_max;
    int size_max = 1;

    for (int x=1;x<301;x++) {
        for (int y=1;y<301;y++){
            array[x][y] = power_level(x,y,SERIAL);
        }
    }

    //printf("Fuel cell at  122,79, grid serial number 57: power level -5 (%d)\n", power_level(122,79,57));
    //printf("Fuel cell at 217,196, grid serial number 39: power level  0 (%d)\n", power_level(217,196,39));
    //printf("Fuel cell at 101,153, grid serial number 71: power level  4 (%d)\n", power_level(101,153,71));


    for (int s=1;s<301;s++) {
        if (s%100 == 0) {
            printf("Trying size %d\n", s);
        }
        for (int x=1;x<=(301-s);x++) {
            for (int y=1;y<=(301-s);y++) {
                grid_power = grid_power_level(x,y,s,array);
                if (max_grid_power < grid_power) {
                    max_grid_power = grid_power;
                    x_max = x;
                    y_max = y;
                    size_max = s;
                }
            }
        }
    }

    printf("Largest power_level at (%d,%d,%d) with value %d\n", x_max, y_max, size_max, max_grid_power);
    //print_map(x_max, y_max, array);
}
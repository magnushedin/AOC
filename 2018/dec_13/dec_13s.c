#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FILENAME "input"
#define X_MAX 300
#define Y_MAX 300
#define CARTS 300

typedef enum direction {
    WEST,
    NORTH,
    EAST,
    SOUTH
} direction_t;

typedef enum turn {
    LEFT,
    STRAIGHT,
    RIGHT
} turn_t;

typedef struct cart {
    int x;
    int y;
    turn_t next_turn;
    direction_t direction;
    char trail;
} cart;


int is_cart(char cart)
{
    if (cart == '>' || cart == '<' || cart == '^' || cart == 'v') {
        return 1;
    }
    else {
        return 0;
    }
}

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
            if (is_cart(map[y][x])) {
                printf(KRED "%c" KNRM, map[y][x]);
            }
            else {
                printf("%c", map[y][x]);
            }
        }
        printf("\n");
    }
    printf("====================================\n");
}

void next_xy(cart this_cart, int *next_x, int *next_y)
{
    switch(this_cart.direction) {
        case NORTH:
            *next_x = this_cart.x;
            *next_y = (this_cart.y) -1;
            //printf("moving north to (%d, %d)\n", *next_x, *next_y);
            break;
        case EAST:
            *next_x = (this_cart.x) +1;
            *next_y = this_cart.y;
            //printf("moving east to (%d, %d)\n", *next_x, *next_y);
            break;
        case WEST:
            *next_x = (this_cart.x) -1;
            *next_y = this_cart.y;
            //printf("moving west to (%d, %d)\n", *next_x, *next_y);
            break;
        case SOUTH:
            *next_x = this_cart.x;
            *next_y = (this_cart.y) +1;
            //printf("moving south to (%d, %d)\n", *next_x, *next_y);
            break;
        default:
            break;
    }
}

direction_t cart_next_direction(cart this_cart, char next_char)
{
    if (next_char == '+') {
        switch (this_cart.direction) {
            case NORTH:
                if (this_cart.next_turn == LEFT) {
                    return WEST;
                }
                else if (this_cart.next_turn == RIGHT) {
                    return EAST;
                }
                else {
                    return NORTH;
                }
                break;
            case EAST:
                if (this_cart.next_turn == LEFT) {
                    return NORTH;
                }
                else if (this_cart.next_turn == RIGHT) {
                    return SOUTH;
                }
                else {
                    return EAST;
                }
                break;
            case SOUTH:
                if (this_cart.next_turn == LEFT) {
                    return EAST;
                }
                else if (this_cart.next_turn == RIGHT) {
                    return WEST;
                }
                else {
                    return SOUTH;
                }
                break;
            case WEST:
                if (this_cart.next_turn == LEFT) {
                    return SOUTH;
                }
                else if (this_cart.next_turn == RIGHT) {
                    return NORTH;
                }
                else {
                    return WEST;
                }
                break;
            default:
                return -1;
                break;
        }
    }
    else if (next_char == '\\') {
        switch (this_cart.direction) {
            case NORTH:
                return WEST;
                break;
            case EAST:
                return SOUTH;
                break;
            case SOUTH:
                return EAST;
                break;
            case WEST:
                return NORTH;
                break;
            default:
                return -1;
                break;
        }
    }
    else if (next_char == '/') {
        switch (this_cart.direction) {
            case NORTH:
                return EAST;
                break;
            case EAST:
                return NORTH;
                break;
            case SOUTH:
                return WEST;
                break;
            case WEST:
                return SOUTH;
                break;
            default:
                return -1;
                break;
        }
    }
}

char get_cart_marker(cart this_cart)
{
    switch (this_cart.direction) {
        case NORTH:
            return '^';
            break;
        case EAST:
            return '>';
            break;
        case SOUTH:
            return 'v';
            break;
        case WEST:
            return '<';
            break;
        default:
            return 'N';
            break;
    }
}

// Next tick
int next_tick(char map[Y_MAX][X_MAX], cart* carts, int cart_max) {

    int x, y, next_x, next_y;
    char next_char;
    char next_trail;

    for (int cart=0; cart<cart_max; cart++) {
        x = carts[cart].x;
        y = carts[cart].y;
        next_xy(carts[cart], &next_x, &next_y);
        printf("cart: %d - (%d, %d), next: (%d, %d)\n", cart, x, y, next_x, next_y);
        carts[cart].x = next_x;
        carts[cart].y = next_y;
        

        next_char = map[next_y][next_x];
        if (next_char == '<' || next_char == '>' || next_char == '^' || next_char == 'v') {
            printf("Crach (%d, %d) (%d, %d)\n", x, y, next_x, next_y);
            return 1;
        }
        else {
            switch(map[next_y][next_x]) {
                case '-':
                case '|':
                    next_trail = map[next_y][next_x];
                    map[next_y][next_x] = map[y][x];
                    map[y][x] = carts[cart].trail;
                    carts[cart].trail = next_trail;
                    break;
                case '/':
                    next_trail = map[next_y][next_x];
                    map[y][x] = carts[cart].trail;
                    carts[cart].trail = next_trail;
                    carts[cart].direction = cart_next_direction(carts[cart], map[next_y][next_x]);
                    map[next_y][next_x] = get_cart_marker(carts[cart]);
                    break;
                case '\\':
                    next_trail = map[next_y][next_x];
                    map[y][x] = carts[cart].trail;
                    carts[cart].trail = next_trail;
                    carts[cart].direction = cart_next_direction(carts[cart], map[next_y][next_x]);
                    map[next_y][next_x] = get_cart_marker(carts[cart]);
                    break;
                case '+':
                    next_trail = map[next_y][next_x];
                    map[y][x] = carts[cart].trail;
                    carts[cart].trail = next_trail;
                    carts[cart].direction = cart_next_direction(carts[cart], map[next_y][next_x]);
                    carts[cart].next_turn = (carts[cart].next_turn +1)%3;
                    map[next_y][next_x] = get_cart_marker(carts[cart]);
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}

int cart_direction(char cart) {
    switch(cart) {
        case '<':
            return WEST;
            break;
        case '>' :
            return EAST;
            break;
        case '^':
            return NORTH;
            break;
        case 'v':
            return SOUTH;
            break;
        default:
            return -1;
            break;
    }
}

int find_carts(char map[Y_MAX][X_MAX], cart carts[CARTS])
{
    int cart_id = 0;

    for (int x=0; x<X_MAX; x++) {
        for (int y=0; y<Y_MAX; y++) {
            if (is_cart(map[y][x])) {
                carts[cart_id].x = x;
                carts[cart_id].y = y;
                carts[cart_id].next_turn = LEFT;
                carts[cart_id].direction = cart_direction(map[y][x]);
                if (carts[cart_id].direction == EAST || carts[cart_id].direction == WEST){
                    carts[cart_id].trail = '-';
                }
                else {
                    carts[cart_id].trail = '|';
                }
                cart_id++;
            }
        }
    }
    return cart_id;
}

void print_carts(cart carts[CARTS], int cart_max)
{
    printf("---  Carts found on map ---\n");
    for (int i=0; i<cart_max; i++) {
        printf("%d: (%d, %d), dir: %d, next_turn: %d, trail: %c\n", i, carts[i].x, carts[i].y, carts[i].direction, carts[i].next_turn, carts[i].trail);
    }
    printf("---\n");
}

int compare_carts(const void* in_a, const void* in_b)
{
     cart cart_a = * ( (cart*) in_a );
     cart cart_b = * ( (cart*) in_b );

     if ( cart_a.y == cart_b.y ) {
        if (cart_a.x == cart_b.y) {
            return 0;
        }
        else if (cart_a.x < cart_b.x) {
            return -1;
        }
        else {
            return 1;
        }
     }
     else if ( cart_a.y < cart_b.y ) {
         return -1;
     }
     else {
        return 1;
     }
         
}

// Main function
int main(int argc, char argv[])
{
    int y_max = 0;
    int cart_max = 0;
    int crach = 0;
    int tick_id = 0;
    cart carts[CARTS];
    char map[Y_MAX][X_MAX] = {'\0'};

    // Read file
    y_max = read_input(FILENAME, map);
    
    // Find carts and print them
    cart_max = find_carts(map, carts);
    print_carts(carts, cart_max);

    // Run simulation
    printf("Tick: %d\n", tick_id);
    print_map(map, y_max);
    tick_id++;

    while (!crach) {
        qsort( carts, cart_max, sizeof(cart), compare_carts);
        print_carts(carts, cart_max);
        printf("Tick: %d\n", tick_id);
        crach = next_tick(map, carts, cart_max);
        print_map(map, y_max);
        tick_id++;
    }
}
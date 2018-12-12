#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define FILENAME "testinput"
#define NODES 31

typedef struct node {
    int x;
    int y;
    int xv;
    int yv;
}node;

// Read input from file and store in array
int read_input(char* filename, node* node_array) {
    FILE *fp;
    char buff[128];
    char *token;
    int nbr_of_inputs = 0;

    fp = fopen(filename, "r");

    while(fgets(buff, 128, fp) != NULL) {
        // get the first token
        token = strtok(buff, ","); 
        node_array[nbr_of_inputs].x = atoi(token);
        token = strtok(NULL, ","); 
        node_array[nbr_of_inputs].y = atoi(token);
        token = strtok(NULL, ","); 
        node_array[nbr_of_inputs].xv = atoi(token);
        token = strtok(NULL, ","); 
        node_array[nbr_of_inputs].yv = atoi(token);

        nbr_of_inputs++;
    }
    fclose(fp);

    return nbr_of_inputs;
}

int have_neghbour(int nbr_of_nodes, int node_id, node* node_array)
{
    for (int n=0; n<nbr_of_nodes; n++) {
        if (n != node_id) {
            if ((abs(node_array[n].x - node_array[node_id].x) <= 1) && (abs(node_array[n].y - node_array[node_id].y) <= 1)) {
                return 1;
            }
        }
    }
    return 0;
}

int all_have_neghbours(int nbr_of_nodes, node* node_array)
{
    for (int n=0; n<nbr_of_nodes; n++) {
        if (!have_neghbour(nbr_of_nodes, n, node_array)) {
            return 0;
        }
    }
    return 1;
}

void update_all_nodes(int nbr_of_nodes, node *node_array)
{
    for (int n=0; n<nbr_of_nodes; n++) {
        node_array[n].x += node_array[n].xv;
        node_array[n].y += node_array[n].yv;
    }
}

void print_map(int nbr_of_nodes, node *node_array)
{
    char str[50] = {'\0'};

    for (int x=0; x<nbr_of_nodes; x++) {
        for (int y=0; y<nbr_of_nodes; y++) {
            if (x == node_array[x].y) {
                str[node_array[y].x] = '#';
            }
            else {
                str[node_array[y].x] = '.';
            }
        }
        printf("%s\n", str);
        for (int i=0; i<50; i++) {
            str[i] = '\0';
        }
    }
}

int main(int argc, char* argv[]) {
    int nbr_of_nodes = 0;
    int count = 0;
    node node_array[NODES];

    nbr_of_nodes = read_input(FILENAME, node_array);

    for (int i=0; i<nbr_of_nodes; i++){
        printf("(%d,%d) - (%d,%d)\n", node_array[i].x, node_array[i].y, node_array[i].xv, node_array[i].yv);
    }

    while (!all_have_neghbours(nbr_of_nodes, node_array)) {
        update_all_nodes(nbr_of_nodes, node_array);
        count++;
    }

    print_map(nbr_of_nodes, node_array);

    printf("Number of nodes = %d\n", nbr_of_nodes);
    printf("Count = %d\n", count);

}
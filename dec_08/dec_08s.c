#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_INPUTS 33000

// Read input from file and store in array
int read_input(char* filename, int* node_array) {
    FILE *fp;
    char buff[33000];
    char *token;
    int idx = 0;
    int nbr_of_inputs = 0;

    fp = fopen(filename, "r");

    while(fgets(buff, 33000, fp) != NULL) {
        // get the first token
        token = strtok(buff, " ");
        
        while (token != NULL) {
            node_array[idx] = atoi(token);
            token = strtok(NULL, " ");
            idx++;
            nbr_of_inputs++;
        }

    }
    fclose(fp);

    return nbr_of_inputs;
}

// Sum the metadata
int sum_metadata(int *node_array, int* idx_ptr, int depth)
{
    int nbr_of_nodes;
    int nbr_of_metadata;
    int sum_of_metadata = 0;
    
    depth++;
    nbr_of_nodes = node_array[*idx_ptr];
    nbr_of_metadata = node_array[(*idx_ptr)+1];

    for (int i=0; i<depth; i++) {
        printf("  ");
    }
    printf("New node, nbr_of_nodes: %d, nrb_of_metadata: %d\n", nbr_of_nodes, nbr_of_metadata);

    for (int i=0; i<nbr_of_nodes; i++) {
        (*idx_ptr) += 2;
        for (int i=0; i<depth; i++) {
            printf("  ");
        }
        printf("Jmp to new function, idx_ptr: %d, node_array[%d]: %d\n",*idx_ptr, *idx_ptr, node_array[*idx_ptr]);
        sum_of_metadata += sum_metadata(node_array, idx_ptr, depth);
    }

    for (int i=0; i<nbr_of_metadata; i++) {
        sum_of_metadata += node_array[(*idx_ptr)+2];
        for (int i=0; i<depth; i++) {
            printf("  ");       
        }
        printf("metadata: %d\n", node_array[(*idx_ptr)+2]);
        (*idx_ptr)++;
        
    }

    for (int i=0; i<depth; i++) {
        printf("  ");       
    }
    printf("metadata sum: %d\n", sum_of_metadata);

    //printf("In function, idx_ptr: %d, node_array[%d]: %d\n",*idx_ptr, *idx_ptr, node_array[*idx_ptr]);
    return sum_of_metadata;
}

// Main function
int main(int argc, char* argv[]) {
    int node_array[MAX_INPUTS];
    int nbr_of_inputs = 0;
    int sum_of_metadata = 0;
    int idx = 0;
    int* idx_ptr;

    idx_ptr = &idx;

    nbr_of_inputs = read_input("testinput", node_array);

    for (int i=0; i<nbr_of_inputs;i++) {
        printf("%d ", node_array[i]);
    }
    printf("\n");

    sum_of_metadata = sum_metadata(node_array, idx_ptr, 0);

    printf("In main, idx_ptr: %d\n", *idx_ptr);

    printf("The sum is: %d\n", sum_of_metadata);

}
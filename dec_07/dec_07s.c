#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define AB_LENGTH 6
#define MAX_NODES 6

typedef struct node {
    char before[AB_LENGTH];
    char after[AB_LENGTH];
    char name;
    int used;
}node;

// Read input from file and store in array
void read_input(char* filename, node* node_array) {
    FILE *fp;
    char buff[16];
    char *token;
    char before;
    char after;

    fp = fopen(filename, "r");

    // Initialize node_array
    for (int i=0; i<AB_LENGTH; i++) {
        node_array[i].name = 'A'+i;
        node_array[i].used = 0;
        //printf("idx: %d: %c\n", i, node_array[i].name);
        for (int j=0; j<AB_LENGTH-1; j++) {
            node_array[i].before[j] = '\0';
            node_array[i].after[j] = '\0';
            //strncpy(node_array[i].before[j], "\0", 1);
            //strncpy(node_array[i].after[j], "\0", 1);
        }
    }

    while(fgets(buff, 64, fp) != NULL) {
        // get the first token

        token = strtok(buff, ",");
        before = *token;

        token = strtok(NULL, "\n");
        after = *token;
        
        node_array[before-65].before[strlen(node_array[before-65].before)] = after;
        node_array[after-65].after[strlen(node_array[after-65].after)] = before;

        /*
        printf(" -- %c before %c --\n", before, after);
        printf("before idx: %d, after idx: %d\n", before-65, after-65);
        printf("%c.after: %s\n", node_array[before-65].name, node_array[before-65].before);
        printf("%c.before: %s\n", node_array[before-65].name, node_array[before-65].after);
        printf("%c.after: %s\n", node_array[after-65].name, node_array[after-65].before);
        printf("%c.before: %s\n", node_array[after-65].name, node_array[after-65].after);
        */
    }
    fclose(fp);
}

void print_node_array(node* node_array)
{
    for (int i=0; i<MAX_NODES; i++) {
        printf("%c - before: %s, after: %s\n", node_array[i].name, node_array[i].before, node_array[i].after);
    }

}

char find_next_node(node* node_array)
{
    int shortest_node = 0;

    for (int i=0; i<AB_LENGTH; i++) {
        if ((strlen(node_array[shortest_node].before) > strlen(node_array[i].before)) && (node_array[i].used == 0)) {
            shortest_node = i;
        }
    }

    if (strlen(node_array[shortest_node].before) == 0) {
        node_array[shortest_node].used = 1;
    }
    return node_array[shortest_node].name;
}

// Removes all instances of a character from the array by reading and writing in the same array.
void remove_char(char* char_array, char char_to_remove) {
    int write = 0;

    for (int read=0; read<(strlen(char_array)+1); read++) {
        if (char_array[read] != char_to_remove) {
            char_array[write] = char_array[read];
            write++;
        }
        else {
            printf("Removing: %c\n", char_to_remove);
        }
    }
}

void remove_char_from_node(node* node_array, char char_to_remove)
{
    for (int i=0; i<AB_LENGTH; i++) {
        remove_char(node_array[i].before, char_to_remove);
        //remove_char(node_array[i].after, char_to_remove);
    }
}

int main(int argc, char* argv[]) {
    char buff[64];
    node node_array[MAX_NODES];
    char next_node;
    int answer = 0;

    read_input("testinput", node_array);

    print_node_array(node_array);

    for (int i=0; i<AB_LENGTH; i++) {
        next_node = find_next_node(node_array);
        printf("Next node: %c\n", next_node);
        remove_char_from_node(node_array, next_node);
        print_node_array(node_array);
    }

    // find node that doesn't need do be after any other, alphabetically. remove from all other 

    printf("Largest area: %d\n", answer);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

<<<<<<< HEAD
#define AB_LENGTH 26
#define MAX_NODES 26

typedef struct node {
    int used;
    char parent[AB_LENGTH];
    char child[AB_LENGTH];
    char name;
=======
#define AB_LENGTH 6
#define MAX_NODES 6

typedef struct node {
    char before[AB_LENGTH];
    char after[AB_LENGTH];
    char name;
    int used;
>>>>>>> 30f288986c05a1cbaf2dd19e2637dcb184d9ee2e
}node;

// Read input from file and store in array
void read_input(char* filename, node* node_array) {
    FILE *fp;
    char buff[16];
    char *token;
<<<<<<< HEAD
    char tmp_parent;
    char tmp_child;
=======
    char before;
    char after;
>>>>>>> 30f288986c05a1cbaf2dd19e2637dcb184d9ee2e

    fp = fopen(filename, "r");

    // Initialize node_array
    for (int i=0; i<AB_LENGTH; i++) {
        node_array[i].name = 'A'+i;
<<<<<<< HEAD
        node_array[i].used = 1;
        //printf("idx: %d: %c\n", i, node_array[i].name);
        for (int j=0; j<AB_LENGTH-1; j++) {
            node_array[i].parent[j] = '\0';
            node_array[i].child[j] = '\0';
            //strncpy(node_array[i].parent[j], "\0", 1);
            //strncpy(node_array[i].child[j], "\0", 1);
=======
        node_array[i].used = 0;
        //printf("idx: %d: %c\n", i, node_array[i].name);
        for (int j=0; j<AB_LENGTH-1; j++) {
            node_array[i].before[j] = '\0';
            node_array[i].after[j] = '\0';
            //strncpy(node_array[i].before[j], "\0", 1);
            //strncpy(node_array[i].after[j], "\0", 1);
>>>>>>> 30f288986c05a1cbaf2dd19e2637dcb184d9ee2e
        }
    }

    while(fgets(buff, 64, fp) != NULL) {
        // get the first token

        token = strtok(buff, ",");
<<<<<<< HEAD
        tmp_parent = *token;

        token = strtok(NULL, "\n");
        tmp_child = *token;
        
        node_array[tmp_child-65].parent[strlen(node_array[tmp_child-65].parent)] = tmp_parent;
        node_array[tmp_parent-65].child[strlen(node_array[tmp_parent-65].child)] = tmp_child;
        node_array[tmp_parent-65].used = 0;
        node_array[tmp_child-65].used = 0;

        /*
        printf(" --parent: %c, child %c --\n", tmp_parent, tmp_child);
        printf("parent idx: %d, child idx: %d\n", tmp_parent-65, tmp_child-65);
        printf("%c.child: %s\n", node_array[tmp_parent-65].name, node_array[tmp_parent-65].child);
        printf("%c.parent: %s\n", node_array[tmp_parent-65].name, node_array[tmp_parent-65].parent);
        printf("%c.child: %s\n", node_array[tmp_child-65].name, node_array[tmp_child-65].child);
        printf("%c.parent: %s\n", node_array[tmp_child-65].name, node_array[tmp_child-65].parent);
=======
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
>>>>>>> 30f288986c05a1cbaf2dd19e2637dcb184d9ee2e
        */
    }
    fclose(fp);
}

void print_node_array(node* node_array)
{
    for (int i=0; i<MAX_NODES; i++) {
<<<<<<< HEAD
        printf("%c - parent: %s, child: %s, used: %d\n", node_array[i].name, node_array[i].parent, node_array[i].child, node_array[i].used);
=======
        printf("%c - before: %s, after: %s\n", node_array[i].name, node_array[i].before, node_array[i].after);
>>>>>>> 30f288986c05a1cbaf2dd19e2637dcb184d9ee2e
    }

}

char find_next_node(node* node_array)
{
<<<<<<< HEAD
    int shortest_node = -1;

    //printf("shortest: %c --- %d\n", node_array[shortest_node].name, node_array[shortest_node].used);
    for (int i=0; i<AB_LENGTH; i++) {
        //printf("shortest: %c --- %d\n", node_array[shortest_node].name, node_array[shortest_node].used);
        if (shortest_node == -1) {
            if (node_array[i].used != 1) {
                shortest_node = i;
            }
        }
        else {
            if (strlen(node_array[shortest_node].parent) > strlen(node_array[i].parent)) {
                if  (node_array[i].used != 1) {
                    shortest_node = i;
                    //printf("shortest: %c --- %d\n", node_array[shortest_node].name, node_array[shortest_node].used);
                }
            }
        }
    }

    if (strlen(node_array[shortest_node].parent) == 0) {
        node_array[shortest_node].used = 1;
        //printf("Will not use %c again\n", node_array[shortest_node].name);
    }
    if (shortest_node != -1) {
        return node_array[shortest_node].name;
    }
    else {
        return '\0';
    }
=======
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
>>>>>>> 30f288986c05a1cbaf2dd19e2637dcb184d9ee2e
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
<<<<<<< HEAD
            //printf("Removing: %c\n", char_to_remove);
=======
            printf("Removing: %c\n", char_to_remove);
>>>>>>> 30f288986c05a1cbaf2dd19e2637dcb184d9ee2e
        }
    }
}

void remove_char_from_node(node* node_array, char char_to_remove)
{
    for (int i=0; i<AB_LENGTH; i++) {
<<<<<<< HEAD
        remove_char(node_array[i].parent, char_to_remove);
        //remove_char(node_array[i].child, char_to_remove);
=======
        remove_char(node_array[i].before, char_to_remove);
        //remove_char(node_array[i].after, char_to_remove);
>>>>>>> 30f288986c05a1cbaf2dd19e2637dcb184d9ee2e
    }
}

int main(int argc, char* argv[]) {
    char buff[64];
    node node_array[MAX_NODES];
    char next_node;
<<<<<<< HEAD
    char answer[AB_LENGTH] = { '\0' };

    read_input("input", node_array);

    for (int i=0; i<AB_LENGTH; i++) {
        //print_node_array(node_array);
        next_node = find_next_node(node_array);
        //printf("Next node: %c\n", next_node);
        remove_char_from_node(node_array, next_node);
        answer[i] = next_node;
    }

    printf("Answer: %s\n", answer);
=======
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
>>>>>>> 30f288986c05a1cbaf2dd19e2637dcb184d9ee2e
}
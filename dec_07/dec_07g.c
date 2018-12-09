#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define AB_LENGTH 26
#define MAX_NODES 26
#define WORKERS 4
#define MAX_TIME 1000

typedef struct node {
    int used;
    char parent[AB_LENGTH];
    char child[AB_LENGTH];
    char name;
    int processing;
}node;

typedef struct worker {
    int id;
    int available;
    char working_with;
}worker;

// Read input from file and store in array
void read_input(char* filename, node* node_array) {
    FILE *fp;
    char buff[16];
    char *token;
    char tmp_parent;
    char tmp_child;

    fp = fopen(filename, "r");

    // Initialize node_array
    for (int i=0; i<AB_LENGTH; i++) {
        node_array[i].name = 'A'+i;
        node_array[i].used = 1;
        node_array[i].processing = 0;
        //printf("idx: %d: %c\n", i, node_array[i].name);
        for (int j=0; j<AB_LENGTH-1; j++) {
            node_array[i].parent[j] = '\0';
            node_array[i].child[j] = '\0';
            //strncpy(node_array[i].parent[j], "\0", 1);
            //strncpy(node_array[i].child[j], "\0", 1);
        }
    }

    while(fgets(buff, 64, fp) != NULL) {
        // get the first token

        token = strtok(buff, ",");
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
        */
    }
    fclose(fp);
}

void print_node_array(node* node_array)
{
    for (int i=0; i<MAX_NODES; i++) {
        printf("%c - parent: %s, child: %s, used: %d\n", node_array[i].name, node_array[i].parent, node_array[i].child, node_array[i].used);
    }

}

char find_next_node(node* node_array)
{
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
    if ((shortest_node != -1) && (strlen(node_array[shortest_node].parent) == 0) && (node_array[shortest_node].processing == 0)) {
        return node_array[shortest_node].name;
    }
    else {
        return '\0';
    }
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
            //printf("Removing: %c\n", char_to_remove);
        }
    }
}

void remove_char_from_node(node* node_array, char char_to_remove)
{
    for (int i=0; i<AB_LENGTH; i++) {
        remove_char(node_array[i].parent, char_to_remove);
        //remove_char(node_array[i].child, char_to_remove);
    }
}

int main(int argc, char* argv[]) {
    char buff[64];
    node node_array[MAX_NODES];
    char next_node;
    char answer[AB_LENGTH] = { '\0' };
    worker  workers[WORKERS];
    int time = 0;

    // Init workers
    for (int i=0; i<WORKERS; i++) {
        workers[i].id = i;
        workers[i].available = 1;
        workers[i].working_with = '\0';
    }

    // Read input
    read_input("input", node_array);

    // Schedule
    printf("time worker1 worker2 worker3 worker4 done\n");
    while (time < MAX_TIME) {
        // Update workers
        for (int i=0; i<WORKERS; i++) {
            workers[i].available--;
            //printf("worker: %d, avail: %d, working_with: %c\n", workers[i].id, workers[i].available, workers[i].working_with);
        }

        // Scheule work
        for (int i=0; i<WORKERS; i++) {
            if (workers[i].available <= 0) {
                answer[strlen(answer)] = workers[i].working_with;
                remove_char_from_node(node_array, workers[i].working_with);
                next_node = find_next_node(node_array);
                node_array[next_node-65].processing = 1;
                
                //printf("next node: %c, %d\n", next_node, next_node-64);
                
                workers[i].working_with = next_node;
                workers[i].available = (next_node-64) + 60;
                //printf("worker: %d deployed, working with: %c, available in: %d\n", workers[i].id, workers[i].working_with, workers[i].available);
            }
        }

        printf("%d\t%c\t%c\t%c\t%c\t%s\n", time, workers[0].working_with, workers[1].working_with, workers[2].working_with, workers[3].working_with, answer);

        // Update time
        time++;
    }

    // Print answer
    printf("Answer: %s\n", answer);
}
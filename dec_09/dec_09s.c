#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define PLAYERS 9
#define MARBLES 29

typedef struct node {
    int nbr;
    int current;
    struct node* next;
    struct node* prev;
} node;

int main(int argc, char* argv[])
{
    node* current;
    node* new;
    node* first;
    node* tmp;
    int nbr_of_players = PLAYERS;
    int nbr_of_marbles = MARBLES;

    current = (node *) malloc(sizeof(node));
    current->nbr = 0;
    first = current;

    for (int marble=1; marble<=nbr_of_marbles; marble++) {
        new = (node *) malloc(sizeof(node));
        new->nbr = marble;
        current->next = new;
        new->prev = current;
        current->current = 0;
        current = new;
        current->current = 1;
        
        printf("[%d] ", marble);
        tmp = first;
        while (tmp != NULL) {
            if (tmp->current == 1) {
                printf(" (%d)", tmp->nbr);
            }
            else {
                printf(" %d ", tmp->nbr);
            }
            tmp = tmp->next;
        }
        printf("\n");
    }

  

    // free all memory
    while (first->next != NULL) {
        first = first->next;
        free(first->prev);
    }
    free(first);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define PLAYERS 447
#define MARBLES 7151000

typedef struct node {
    long int nbr;
    int current;
    struct node* next;
    struct node* prev;
} node;

void print_ring(int marble, node *node_ptr)
{
    printf("[%d] ", marble%PLAYERS);
    for(long int i=0; i<=marble;i++) {
        if (node_ptr->current == 1) {
            printf(" (%ld)", node_ptr->nbr);
        }
        else {
            printf(" %ld ", node_ptr->nbr);
        }
        node_ptr = node_ptr->next;
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    node* current;
    node* new;
    node* first;
    node* tmp;
    long int player_score[PLAYERS] = {0};
    int nbr_of_players = PLAYERS;
    long int nbr_of_marbles = MARBLES;

    // initialize the ring
    current = (node *) malloc(sizeof(node));
    current->nbr = 0;
    current->current = 1;
    current->next = current;
    current->prev = current;
    first = current;
    long int highscore = 0;

    //print_ring(0, first);

    for (long int marble=1; marble<=nbr_of_marbles; marble++) {
        // create new node
        if (marble%23 == 0) {
            
            for (int i=0; i<7; i++) {
                current->current = 0;
                current = current->prev;
                current->current = 1;
            }
            player_score[marble%PLAYERS] += (marble + current->nbr);
            //printf("marble: %d, player: %d\n", marble, marble%PLAYERS);
            current->next->prev = current->prev;
            current->prev->next = current->next;
            tmp = current;
            current = current->next;
            current->current = 1;
            free(tmp);
        }
        else {
            new = (node *) malloc(sizeof(node));
            new->nbr = marble;
    
            // insert new node in ring
            for (int i=0; i<1; i++) {
                current->current = 0;
                current = current->next;
                current->current = 1;
            }
            new->next = current->next;
            current->next = new;
            new->prev = current;
            new->next->prev = new;
            current->current = 0;
            current = new;
            current->current = 1;
        }

        // print the ring
        //print_ring(marble, first);
    }

    for (long int i=0; i<PLAYERS; i++) {
        if (highscore < player_score[i]) {
            highscore = player_score[i];
        }
    }
    printf("Highscore: %ld\n", highscore);

    // free all memory
    for (long int i = 0; i<=nbr_of_marbles; i++) {
        first = first->next;
        free(first->prev);
    }
    
}
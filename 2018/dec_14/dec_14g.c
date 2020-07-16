#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define NBR_REC 704321
#define LENGTH 6

typedef struct node{
    int nbr;
    int first;
    int elf;
    struct node *next;
    struct node *prev;
} node;

void print_list(node* first)
{
    if (first->elf == 1) {
        printf("(%d) ", first->nbr);
    }
    else if (first->elf == 2) {
        printf("[%d] ", first->nbr);
    }
    else {
        printf(" %d  ", first->nbr);
    }
    first = first->next;
    while (first->first != 1) {
        if (first->elf == 1) {
            printf("(%d) ", first->nbr);
        }
        else if (first->elf == 2) {
            printf("[%d] ", first->nbr);
        }
        else {
            printf(" %d  ", first->nbr);
        }
        first = first->next;
    }
    printf("\n");
}

int sum_nodes(node *current, int cnt)
{
    int sum = 0;
    int mult = 1;

    sum += current->nbr * mult;
    mult *= 10;
    for (int i=0; i<cnt-1; i++) {
        
        current = current->prev;
        sum += current->nbr * mult;
        mult *= 10;
    }
    return sum;
}

int count_recepies(node *first)
{
    long int nbr = 0;

    while (first->first != 1) {
        nbr++;
        first = first->prev;
    }
    return nbr;
}

int main(int argc, char *argv[])
{
    node* current;
    node* first;
    node* new;
    node* elf_1;
    node* elf_2;
    node* last;
    int sum = 0;
    int tmp;
    int jumps;
    int nbr_rec = 0;
    int done = 0;

    first = (node *) malloc(sizeof(node));
    current = (node *) malloc(sizeof(node));
    first->nbr = 3;
    first->next = current;
    first->prev = current;
    first->first = 1;
    first->elf = 1;
    current->nbr = 7;
    current->next = first;
    current->prev = first;
    current->first = 0;
    current->elf = 2;

    elf_1 = first;
    elf_2 = current;

    last = current;
    while (done != 1) {
        sum = elf_1->nbr + elf_2->nbr;
        while (sum > 9) {
            tmp = sum - ((sum / 10)*10);
            new = (node *) malloc(sizeof(node));
            new->nbr = tmp;
            new->next = current->next;
            new->prev = current;
            new->first = 0;
            current->next->prev = new;
            current->next = new;
            sum = sum/10;
            nbr_rec++;
        }
        new = (node *) malloc(sizeof(node));
        new->nbr = sum;
        new->next = current->next;
        new->prev = current;
        new->first = 0;
        current->next->prev = new;
        current->next = new;
        current = first->prev;
        nbr_rec++;

        elf_1->elf = 0;
        jumps = (elf_1->nbr) +1;
        for (int i=0; i < jumps; i++) {
            elf_1 = elf_1->next;
        }
        elf_1->elf = 1;
        elf_2->elf = 0;
        jumps = (elf_2->nbr) +1;
        for (int i=0; i < jumps; i++) {
            elf_2 = elf_2->next;
        }
        elf_2->elf = 2;

        while ((last->next->first != 1) && (done != 1)) {
            if(sum_nodes(last, LENGTH) == NBR_REC) {
                done = 1;
            }
            last = last->next;
        }
    }
    printf("Number of recepies: %d\n", count_recepies(last) - LENGTH);

}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define NBR_REC 704321

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

int sum_list(node *first)
{
    int sum = 0;

    sum += first->nbr;
    first = first->next;
    while (first->first != 1) {
        sum += first->nbr;
        first = first->next;
    }
    return sum;
}

long int count_recepies(node *first)
{
    long int nbr = 1;

    first = first->next;
    while (first->first != 1) {
        nbr++;
        first = first->next;
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
    int sum = 0;
    int tmp;
    int jumps;
    int nbr_rec = 0;

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
    
    print_list(first);

    //while (count_recepies(first) < (NBR_REC +10)) {
    while (nbr_rec < (NBR_REC +10)) {
        printf("Number of recepies: %d\n", nbr_rec);
        sum = elf_1->nbr + elf_2->nbr;
        //printf("sum: %d\n", sum);
        while (sum > 9) {
            tmp = sum - ((sum / 10)*10);
            //printf("%d\n", tmp);
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
        //printf("%d\n", sum);
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
        //printf("elf 1 jumps: (%d)\n", jumps);
        for (int i=0; i < jumps; i++) {
            elf_1 = elf_1->next;
            //printf("jump, nbr: %d\n", elf_1->nbr);
        }
        elf_1->elf = 1;
        elf_2->elf = 0;
        jumps = (elf_2->nbr) +1;
        //printf("elf 2 jumps: [%d]\n", jumps);
        for (int i=0; i < jumps; i++) {
            elf_2 = elf_2->next;
        }
        elf_2->elf = 2;

        sum = 0;
        //print_list(first);
    }
    //print_list(first);

    current = first;
    for (int i=0;i<NBR_REC;i++) {
        current = current->next;
    }
    for (int i=0;i<10;i++) {
        printf("%d", current->nbr);
        current = current->next;
    }
    printf("\n");
}
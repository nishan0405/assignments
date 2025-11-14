#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertend(struct Node **head, int value);
void insertfront(struct Node **head, int value);
void InsertInBetween(struct Node **head, int value, int pos);
void deletfront(struct Node **head);
void deletEnd(struct Node **head);
void deletPosition(struct Node **head, int pos);
void print(struct Node *head);

#endif


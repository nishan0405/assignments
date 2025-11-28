#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **head,struct Node **tail,int value)
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    if(*tail==NULL)
    {
        *tail=newnode;
        *head=newnode;
    }
    else
    {
        (*tail)->next=newnode;
        *tail=newnode;
    }
}
void pop(struct Node **head,struct Node **tail)
{
    if(*head==NULL)
    {
        printf("there is no element in queue\n");
        return;
    }
    struct Node *temp=*head;
    *head=(*head)->next;
    free(temp);
}
int peek(struct Node *head)
{
    return head->data;
}
void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("the queue is empty");
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    push(&head, &tail, 9);
    push(&head, &tail, 8);
    push(&head, &tail, 7);
    push(&head, &tail, 6);
    push(&head, &tail, 5);

    printf("Peek: %d\n", peek(head));
    display(head);

    pop(&head, &tail);
    printf("Peek: %d\n", peek(head));

    pop(&head, &tail);
    printf("Peek: %d\n", peek(head));

    pop(&head, &tail);
    printf("Peek: %d\n", peek(head));

    display(head);

    return 0;
}
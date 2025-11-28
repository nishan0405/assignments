#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
};
void push(struct Node **tail,struct Node **head,int value)
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    if(*tail==NULL)
    {
        *tail=newnode;
        *head=newnode;
    }
    else{
        (*tail)->next=newnode;
        *tail=newnode;
    }
}
void pop(struct Node **head,struct Node **tail)
{
    struct Node *temp=*head;
    if(*head==NULL)
    {
        printf("no elements to print");
        return;
    }
    while(temp->next!=*tail)
    {
        temp=temp->next;
    }
    free(*tail);
    *tail=temp;
    (*tail)->next=NULL;

}
int peek(struct Node *tail)
{
    if(tail==NULL)
    {
        printf("stack is empty");
        return 0;
    }
    return tail->data;
}
void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("the stack is empty");
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
void main()
{
    struct Node *head=NULL;
    struct Node *tail=NULL;
    push(&tail,&head,9);
    push(&tail,&head,8);
    push(&tail,&head,7);
    push(&tail,&head,6);
    push(&tail,&head,5);
      printf("Peek: %d\n", peek(tail));
    display(head);
    pop(&head,&tail);
     printf("Peek: %d\n", peek(tail));
    pop(&head,&tail);
      printf("Peek: %d\n", peek(tail));
    pop(&head,&tail);
      printf("Peek: %d\n", peek(tail));
    display(head);


}
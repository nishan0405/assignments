#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define length 50
struct Node
{
    int id;
    char name[50];
    int age;
    char type[50];
    struct Node *next;
};
struct Node *hashmap[length];
struct stack
{
    int id;
    struct stack *next;
};
struct queue
{
    int id;
    struct queue *next;
};
struct stack *shead=NULL;
struct stack *stail=NULL;
struct queue *qhead = NULL;
struct queue *qtail = NULL;
struct Node *head=NULL;
struct Node *tail=NULL;

void push(int id)
{
struct stack *newnode=(struct stack*)malloc(sizeof(struct stack));
newnode->id=id;
newnode->next=NULL;
if(shead==NULL)
{
    shead=stail=newnode;
}
else{
    stail->next=newnode;
    stail=newnode;
}
}

void pop()
{
    if (shead == NULL) {
        printf("No emergency patients.\n");
        return;
    }

    struct stack *temp = shead;

    if (shead == stail) { 
        free(shead);
        shead = stail = NULL;
        return;
    }

    while (temp->next != stail)
        temp = temp->next;

    struct stack *del = stail;
    stail = temp;
    stail->next = NULL;
    free(del);
}
int peek()
{
if(shead==NULL)
 {
    printf("no elements in stack");
    return -1;
 }
 return stail->id;
}
void add(int id)
{
struct queue *newnode=(struct queue*)malloc(sizeof(struct queue));
newnode->id=id;
newnode->next=NULL;
if(qhead==NULL)
{
    qhead=qtail=newnode;
}
else{
    qtail->next=newnode;
    qtail=newnode;
}
}

void removes()
{
if(qhead==NULL)
{
 printf("no elements");
 return;
}
struct queue *temp=qhead;
qhead=qhead->next;
if (qhead == NULL)   
        qtail = NULL;

free(temp);
}
int top()
{
if(qhead==NULL)
{
 printf("no elements");
 return -1;
}
return qtail->id;
}

int hash(int id)
{
    return id%length;
}
void prepare()
{
    for(int i=0;i<length;i++)
    {
        hashmap[i]=NULL;
    }
}

struct Node *create(int id,char *name,int age,char *type)
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->id=id;
    strcpy(newnode->name,name);
    newnode->age=age;
    strcpy(newnode->type,type);
    newnode->next=NULL;
    return newnode;
}
void insert(int id,char *name,int age,char *type)
{
    struct Node *temp=create(id,name,age,type);
    if(head==NULL)
    {
        head=tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
    int index=hash(id);
    if(hashmap[index]==NULL)
    {
        hashmap[index]=temp;
    }
    else{
        int start=index;
        while(hashmap[index]!=NULL)
        {
           index=(index+1)%length;
           if(index==start)
           {
            printf("full");
            return;
           }
        }
       hashmap[index]=temp; 
    }
}
void search(int id)
{
    int index=hash(id);
    int start=index;
    while (hashmap[index] != NULL && hashmap[index]->id != id) {
    index = (index + 1) % length;
    if (index == start) {
        printf("Patient not found.\n");
        return;
    }
}

    printf("the details of the patients are\n");
    printf("id: %d\n", hashmap[index]->id);
    printf("Name: %s\n", hashmap[index]->name);
    printf("age: %d\n", hashmap[index]->age);
    printf("Type: %s\n", hashmap[index]->type);
}
void update(int id,char *name,int age,char *type)
{
    int index=hash(id);
    int start=index;
    while(hashmap[index]->id!=id)
    {
        index=(index+1)%length;
        if(start==index)
        {
            break;
        }
    }
    strcpy(hashmap[index]->name,name);
    hashmap[index]->age=age;
    strcpy(hashmap[index]->type,type);
    printf("the patient details updated sucessfully");

}
int main() {
    prepare();   

    int choice, id, age;
    char name[50], type[50];

    while (1) {
        printf("\n===============================\n");
        printf(" Patient Management System\n");
        printf("===============================\n");
        printf("1. Add Patient\n");
        printf("2. Search Patient\n");
        printf("3. Update Patient\n");
        printf("4. Process Emergency Patient (Stack POP)\n");
        printf("5. Process Normal Patient (Queue REMOVE)\n");
        printf("6. View Next Emergency Patient (Stack PEEK)\n");
        printf("7. View Next Normal Patient (Queue TOP)\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter Patient ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Age: ");
            scanf("%d", &age);
            printf("Enter Type (Emergency/Normal): ");
            scanf("%s", type);

            insert(id, name, age, type);

            if (strcmp(type, "Emergency") == 0 || strcmp(type, "emergency") == 0) {
                push(id);
                printf("Emergency patient added to STACK\n");
            } else {
                add(id);
                printf("Normal patient added to QUEUE\n");
            }
            break;

        case 2:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            search(id);
            break;

        case 3:
            printf("Enter ID to update: ");
            scanf("%d", &id);
            printf("Enter New Name: ");
            scanf("%s", name);
            printf("Enter New Age: ");
            scanf("%d", &age);
            printf("Enter New Type (Emergency/Normal): ");
            scanf("%s", type);
            update(id, name, age, type);
            break;

        case 4:
            printf("Processing Emergency Patient:\n");
            pop();
            break;

        case 5:
            printf("Processing Normal Patient:\n");
            removes();
            break;

        case 6:
            printf("Next Emergency Patient ID: %d\n", peek());
            break;

        case 7:
            printf("Next Normal Patient ID: %d\n", top());
            break;

        case 8:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}

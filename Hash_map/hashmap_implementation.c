#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define length 10

struct Node {
    char str[50];
    int data;
    struct Node *next;
};

struct Node *hashtabel[length];

int hash(char *key);
struct Node* search1(char *key);
void put(char *key, int value);
void delet(char *key);
int search(char *key);
void get(char *key);
void display();
int main()
{
    for (int i = 0; i < length; i++)
        hashtabel[i] = NULL;

    put("apple", 40);
    put("elppa", 50);
    put("banana", 20);
    put("grapes", 90);
    put("orange", 60);

    display();

    if (search("apple"))
        printf("Key found\n");
    else
        printf("Key not found\n");

    delet("apple");
    display();
    
    get("banana");
    put("banana", 50);
    get("banana");

    display();

    return 0;
}

int hash(char *key)
{
    int sum = 0;
    for (int i = 0; i < strlen(key); i++)
        sum += key[i];

    return sum % length;
}

struct Node *search1(char *key)
{
    unsigned int index = hash(key);
    struct Node *temp = hashtabel[index];
    
    while (temp != NULL)
    {
        if (strcmp(temp->str, key) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void put(char *key, int value)
{
    unsigned int index = hash(key);

    struct Node *node = search1(key);

    if (node != NULL)
    {
        node->data = value;
        printf("Value updated\n");
        return;
    }

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newnode->str, key);
    newnode->data = value;
    newnode->next = hashtabel[index];

    hashtabel[index] = newnode;

    printf("Inserted (%s, %d)\n", key, value);
}

void delet(char *key)
{
    unsigned int index = hash(key);
    struct Node *temp = hashtabel[index];
    struct Node *prev = NULL;

    if (temp == NULL)
    {
        printf("Key not found\n");
        return;
    }

    if (strcmp(temp->str, key) == 0)
    {
        hashtabel[index] = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->str, key) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Key not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int search(char *key)
{
    unsigned int index = hash(key);
    struct Node *temp = hashtabel[index];

    while (temp != NULL)
    {
        if (strcmp(temp->str, key) == 0)
            return 1;

        temp = temp->next;
    }

    return 0;
}

void get(char *key)
{
    struct Node *temp = search1(key);
    if (temp != NULL)
        printf("the value at the key is %d\n", temp->data);
    else
        printf("the key not found\n");
}

void display()
{
    for (int i = 0; i < length; i++)
    {
        struct Node *temp = hashtabel[i];
        printf("Bucket %d: ", i);

        while (temp != NULL)
        {
            printf("(%s, %d) -> ", temp->str, temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}



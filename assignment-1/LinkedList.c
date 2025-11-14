#include "ssl.h"


int main()
{
    struct Node *head = NULL;
    int choice, value, pos, size;
    struct Node *temp = NULL, *newnode = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    do
    {
        printf("\n------ MENU ------\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertfront(&head, value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertend(&head, value);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &value);
            InsertInBetween(&head, value, pos);
            break;
        case 4:
            deletfront(&head);
            break;
        case 5:
            deletEnd(&head);
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletPosition(&head, pos);
            break;
        case 7:
            print(head);
            break;
        case 8:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 8);

    return 0;
}

void insertend(struct Node **head, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertfront(struct Node **head, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = *head;
    *head = newnode;
}

void InsertInBetween(struct Node **head, int value, int pos)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    newnode->data = value;
    newnode->next = NULL;

    if (pos == 1)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deletfront(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The Linked List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deletEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The Linked List is empty\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deletPosition(struct Node **head, int pos)
{
    if (*head == NULL)
    {
        printf("The Linked List is empty\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (pos == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void print(struct Node *head)
{
    if (head == NULL)
    {
        printf("The Linked List is empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

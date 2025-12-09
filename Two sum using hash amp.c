#include <stdio.h>
#include <stdlib.h>

#define size 10

struct Node {
    int data;
    int index;
    struct Node *next;
};

struct Node* hashmap[size];   

int hash(int data) {
    return data % size;
}

void put(int data, int index) {
    int i = hash(data);
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->index = index;
    newnode->next = hashmap[i];
    hashmap[i] = newnode;  
}

int get(int data) {
    int i = hash(data);
    struct Node *temp = hashmap[i];
    while(temp!=NULL) {
        if(temp->data == data)
        {
            return temp->index;
        }
        temp = temp->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    for(int i = 0; i < size; i++)
    {
        hashmap[i] = NULL;
    }
    for(int i = 0; i < numsSize; i++)
    {
        put(nums[i], i);
    }
    int *res = (int*)malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize; i++) {
        int a = target - nums[i];
        int j = get(a);
        if(j != -1 && j != i) {
            res[0] = i;
            res[1] = j;
            *returnSize = 2;
            return res;
        }
    }

    *returnSize = 0;
    return NULL;
}

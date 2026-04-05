// Runtime: 0ms, beats: 100.00%

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10007

typedef struct Node {
    int key;
    int index;
    struct Node* next;
} Node;

int hashFunc(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

void insert(Node** table, int key, int index) {
    int h = hashFunc(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->index = index;
    newNode->next = table[h];
    table[h] = newNode;
}

Node* find(Node** table, int key) {
    int h = hashFunc(key);
    Node* curr = table[h];
    while (curr) {
        if (curr->key == key) return curr;
        curr = curr->next;
    }
    return NULL;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[TABLE_SIZE] = {0};

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        Node* node = find(table, complement);

        if (node) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = node->index;
            result[1] = i;
            *returnSize = 2;
            return result;
        }

        insert(table, nums[i], i);
    }

    *returnSize = 0;
    return NULL;
}

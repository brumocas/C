#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
} HashItem;

typedef struct {
    HashItem* items[TABLE_SIZE];
} HashTable;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(HashTable* table, int key, int value) {
    int hashIndex = hashFunction(key);
    HashItem* item = (HashItem*)malloc(sizeof(HashItem));
    item->key = key;
    item->value = value;
    table->items[hashIndex] = item;
}

int search(HashTable* table, int key) {
    int hashIndex = hashFunction(key);
    if (table->items[hashIndex] != NULL)
        return table->items[hashIndex]->value;
    return -1;
}

int main() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 42, 30);

    printf("Value for key 1: %d\n", search(hashTable, 1));
    printf("Value for key 2: %d\n", search(hashTable, 2));
    printf("Value for key 42: %d\n", search(hashTable, 42));
    
    return 0;
}

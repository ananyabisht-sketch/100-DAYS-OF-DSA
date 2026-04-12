#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hashTable[100];

// Hash function with quadratic probing
int hash(int key, int i, int m) {
    return (key % m + i * i) % m;
}

// Insert key
void insert(int key, int m) {
    for (int i = 0; i < m; i++) {
        int idx = hash(key, i, m);

        if (hashTable[idx] == EMPTY) {
            hashTable[idx] = key;
            return;
        }
    }
}

// Search key
void search(int key, int m) {
    for (int i = 0; i < m; i++) {
        int idx = hash(key, i, m);

        if (hashTable[idx] == key) {
            printf("FOUND\n");
            return;
        }

        if (hashTable[idx] == EMPTY) {
            break;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}
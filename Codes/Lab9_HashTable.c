//ShreyaGawhane-IT-B-120
/*Assume that you have a seven-slot closed hash table (the slots are numbered o through 6) Write program to final hash table that would result 
if you used the hash function h(k) - k mod 7.*/
#include <stdio.h>

#define SIZE 7 

int main() {
    int hashTable[SIZE];
    int keys[20], n, i, j, index;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &keys[i]);
    for (i = 0; i < n; i++) {
        index = keys[i] % SIZE;

        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }

        hashTable[index] = keys[i];
    }

    printf("\nFinal Hash Table (index : value):\n");
    for (i = 0; i < SIZE; i++) {
        printf("[%d] : ", i);
        if (hashTable[i] != -1)
            printf("%d\n", hashTable[i]);
        else
            printf("EMPTY\n");
    }

    return 0;
}

/*7. Write a program to store following numbers with table size 10 using Hashing 
129, 115, 161, 136, 212, 553, 914, 307, 608 */

#include <stdio.h>

int main() {
    int hashTable[10];   // Table size = 10
    int numbers[9] = {129, 115, 161, 136, 212, 553, 914, 307, 608};
    int i, j, key, index;

    // Step 1: Make all places empty (-1 means empty)
    for(i = 0; i < 10; i++) {
        hashTable[i] = -1;
    }

    // Step 2: Insert each number into hash table
    for(i = 0; i < 9; i++) {
        key = numbers[i];
        index = key % 10;  // Hash function (divide by 10 and take remainder)

        // If the place is already full, move to the next
        while(hashTable[index] != -1) {
            index = (index + 1) % 10;  // Go to next slot
        }

        // Store the number in the hash table
        hashTable[index] = key;
    }

    // Step 3: Display the hash table
    printf("Hash Table (size 10):\n");
    for(i = 0; i < 10; i++) {
        if(hashTable[i] == -1)
            printf("[%d] : Empty\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }

    return 0;
}

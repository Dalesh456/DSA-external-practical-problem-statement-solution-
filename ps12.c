/* 12. Write a program to simulate double-ended queue (deque) with following 
functions to add and delete elements from the deque [10, 20, 30, 40, 50]. 
addFront(5), addRear(60), deleteFront(), deleteRear(), addFront(7), 
addRear(55), deleteFront(), deleteRear() */

#include <stdio.h>
#define MAX 20

int deque[MAX];
int front = 0, rear = -1; // initially empty

// Add element at rear
void addRear(int x) {
    if (rear == MAX - 1) {
        printf("Deque is full! Cannot add %d at rear.\n", x);
        return;
    }
    rear++;
    deque[rear] = x;
    printf("Added %d at rear.\n", x);
}

// Add element at front
void addFront(int x) {
    if (front == 0) {
        printf("No space at front! Cannot add %d.\n", x);
        return;
    }
    front--;
    deque[front] = x;
    printf("Added %d at front.\n", x);
}

// Delete element from front
void deleteFront() {
    if (front > rear) {
        printf("Deque is empty! Nothing to delete from front.\n");
        return;
    }
    printf("Deleted %d from front.\n", deque[front]);
    front++;
}

// Delete element from rear
void deleteRear() {
    if (front > rear) {
        printf("Deque is empty! Nothing to delete from rear.\n");
        return;
    }
    printf("Deleted %d from rear.\n", deque[rear]);
    rear--;
}

// Display deque
void display() {
    if (front > rear) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Current Deque: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    // Initial elements
    int initial[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++)
        addRear(initial[i]);

    display();

    // Perform given operations
    addFront(5);
    addRear(60);
    deleteFront();
    deleteRear();
    addFront(7);
    addRear(55);
    deleteFront();
    deleteRear();

    display();

    return 0;
}

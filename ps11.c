/*11. Write a program to simulate the Queues for jobs of an operating system that 
does not use priorities, write functions to add jobs and delete jobs from the queue. */

#include <stdio.h>
#define MAX 100

int queue[MAX];  // array to store queue elements
int front = -1;  // front of queue
int rear = -1;   // rear of queue

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot add job %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Job %d added to the queue\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. No jobs to delete\n");
        return -1;
    }
    int job = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;  // reset queue when empty
    }
    printf("Job %d removed from the queue\n", job);
    return job;
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Jobs in the queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, job;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Add Job\n");
        printf("2. Delete Job\n");
        printf("3. Display Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter job number to add: ");
                scanf("%d", &job);
                enqueue(job);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
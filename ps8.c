/*8. Write a program to perform the following Stack (of size=10) operations: push(): 
20, 15, 61,  36,  pop(), peek(), pop(), push(): 12, 53, 14, 30,  pop(), pop(), peek(), 
isEmpty(), isFull(). */

#include <stdio.h>
#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1)
        printf("Stack is full! Cannot push %d.\n", value);
    else {
        stack[++top] = value;
        printf("Pushed %d onto stack.\n", value);
    }
}

void pop() {
    if (top == -1)
        printf("Stack is empty! Cannot pop.\n");
    else {
        printf("Popped %d from stack.\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1)
        printf("Stack is empty! Nothing to peek.\n");
    else
        printf("Top element is: %d\n", stack[top]);
}

void isEmpty() {
    if (top == -1)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");
}

void isFull() {
    if (top == SIZE - 1)
        printf("Stack is full.\n");
    else
        printf("Stack is not full.\n");
}

void display() {
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Current Stack: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n\n");
    }
}

int main() {
    // Perform given sequence of operations
    printf("Performing stack operations step by step:\n\n");

    push(20);
    push(15);
    push(61);
    push(36);
    display();

    pop();
    peek();
    pop();
    display();

    push(12);
    push(53);
    push(14);
    push(30);
    display();

    pop();
    pop();
    peek();

    isEmpty();
    isFull();

    return 0;
}

/* 10. Write a program to check the well form-ness of ( ), [ ], { } parenthesis :- whether 
a given expression is balanced or unbalanced. */

#include <stdio.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top == SIZE - 1)
        printf("Stack overflow!\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int main() {
    char expr[SIZE];
    int i;
    int balanced = 1;  // assume balanced initially

    printf("Enter an expression: ");
    scanf("%s", expr);  // reads a string without pointers

    for (i = 0; expr[i] != '\0'; i++) {
        char curr = expr[i];

        // Push opening brackets
        if (curr == '(' || curr == '[' || curr == '{') {
            push(curr);
        }
        // For closing brackets
        else if (curr == ')' || curr == ']' || curr == '}') {
            char popped = pop();

            if ((curr == ')' && popped != '(') ||
                (curr == ']' && popped != '[') ||
                (curr == '}' && popped != '{')) {
                balanced = 0;
                break;
            }
        }
    }

    // If stack not empty, also unbalanced
    if (!isEmpty())
        balanced = 0;

    if (balanced == 1)
        printf("Expression is Balanced.\n");
    else
        printf("Expression is NOT Balanced.\n");

    return 0;
}

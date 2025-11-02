/*9.   Write a program to convert Infix expression A + ( B * C ) / D to Postfix 
expression. */

#include <stdio.h>
#include <ctype.h>   // for isalnum()
#define SIZE 50

char stack[SIZE];
int top = -1;

// push function
void push(char c) {
    stack[++top] = c;
}

// pop function
char pop() {
    return stack[top--];
}

// function for precedence
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[SIZE], postfix[SIZE];
    int i, k = 0;
    char ch;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // if operand
        if (isalnum(ch))
            postfix[k++] = ch;

        // if '(' push
        else if (ch == '(')
            push(ch);

        // if ')' pop till '('
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }

        // if operator
        else {
            while (top != -1 && prec(stack[top]) >= prec(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    // pop remaining operators
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}

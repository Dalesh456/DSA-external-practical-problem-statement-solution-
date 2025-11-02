#include <stdio.h> 
#include <ctype.h>   // for isalnum() 
#include <string.h>  // for strlen() 
#define MAX 30 
char stack[MAX]; 
int top = -1; 
void push(char c) { 
    if (top == MAX - 1) { 
        prin ("Stack Overflow\n"); 
    } else { 
        stack[++top] = c; 
    } 
} 
char pop() { 
    if (top == -1) { 
        return -1; // stack empty 
    } else { 
        return stack[top--]; 
    } 
} 
int precedence(char c) { 
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
    char infix[MAX], postfix[MAX]; 
    printf("Enter Infix Expression: "); 
    scanf("%s", infix); 
    int i, k = 0; 
    char symbol; 
    for (i = 0; i < strlen(infix); i++) { 
        symbol = infix[i]; 
        if (isalnum(symbol)) { 
            postfix[k++] = symbol;  // operand -> output 
        }  
        else if (symbol == '(') { 
            push(symbol); 
        }  
        else if (symbol == ')') { 
            while ((symbol = pop()) != '(') { 
                postfix[k++] = symbol; 
            } 
        }  
        else { // operator 
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) { 
                postfix[k++] = pop(); 
            } 
            push(symbol); 
        } 
    } 
    // pop remaining operators 
    while (top != -1) { 
        postfix[k++] = pop(); 
    } 
    postfix[k] = '\0'; 
    printf("Postfix Expression: %s\n", postfix); 
    return 0; 
} 
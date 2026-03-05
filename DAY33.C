
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    stack[++top] = c;
}


char pop() {
    return stack[top--];
}


int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        
        char ch = infix[i];

        
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        
        else if (ch == '(') {
            push(ch);
        }

        
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }

        
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    
    printf("%s", postfix);

    return 0;
}
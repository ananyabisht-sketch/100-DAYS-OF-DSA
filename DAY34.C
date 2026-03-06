
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int evaluatePostfix(char* exp)
{
    int i = 0;

    while(exp[i] != '\0')
    {
        if(exp[i] == ' ')
        {
            i++;
            continue;
        }

        if(isdigit(exp[i]))
        {
            int num = 0;

            while(isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }
        else
        {
            int b = pop();
            int a = pop();

            switch(exp[i])
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }

            i++;
        }
    }

    return pop();
}

int main()
{
    char exp[1000];

    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d", result);

    return 0;
}
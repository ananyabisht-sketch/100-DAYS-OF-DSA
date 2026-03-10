
#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int x)
{
    if((rear + 1) % MAX == front)
    {
        printf("Deque Full\n");
        return;
    }

    if(front == -1)
        front = rear = 0;

    else if(front == 0)
        front = MAX - 1;

    else
        front--;

    deque[front] = x;
}

void push_back(int x)
{
    if((rear + 1) % MAX == front)
    {
        printf("Deque Full\n");
        return;
    }

    if(front == -1)
        front = rear = 0;

    else if(rear == MAX - 1)
        rear = 0;

    else
        rear++;

    deque[rear] = x;
}

void pop_front()
{
    if(front == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if(front == rear)
        front = rear = -1;

    else if(front == MAX - 1)
        front = 0;

    else
        front++;
}

void pop_back()
{
    if(front == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;

    else if(rear == 0)
        rear = MAX - 1;

    else
        rear--;
}

void getFront()
{
    if(front == -1)
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

void getBack()
{
    if(front == -1)
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

void size()
{
    if(front == -1)
        printf("0\n");

    else if(rear >= front)
        printf("%d\n", rear - front + 1);

    else
        printf("%d\n", MAX - front + rear + 1);
}

void empty()
{
    if(front == -1)
        printf("1\n");
    else
        printf("0\n");
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);

    getFront();
    getBack();

    pop_front();
    pop_back();

    size();
    empty();

    return 0;
}

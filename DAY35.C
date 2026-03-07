
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *queue;
    int front = 0, rear = -1;

    scanf("%d", &n);

    queue = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        rear++;
        queue[rear] = x;
    }

    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    free(queue);

    return 0;
}

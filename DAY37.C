

#include <stdio.h>

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x)
{
    pq[size] = x;
    size++;
}

void deletePQ()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int min = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[min])
            min = i;
    }

    printf("%d\n", pq[min]);

    for(int i = min; i < size-1; i++)
    {
        pq[i] = pq[i+1];
    }

    size--;
}

void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int min = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[min])
            min = i;
    }

    printf("%d\n", pq[min]);
}

int main()
{
    int n, op, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &op);

        if(op == 1)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(op == 2)
        {
            deletePQ();
        }
        else if(op == 3)
        {
            peek();
        }
    }

    return 0;
}
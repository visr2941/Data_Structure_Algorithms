#include <stdio.h>
#define Q_SIZE 5

#define SUCCESS  0
#define FAILED  -1

#define TRUE  1
#define FALSE 0

#define INVALID_INDEX -2

typedef struct QUEUE {
    int queue[Q_SIZE];
    int top;
    int bottom;
    int size;
} Q;

Q que;

void InitQueue( void )
{
    que.top = -1;
    que.bottom = 0;
    que.size  = 0;
}

int IsQueueEmpty( void )
{
    if(que.bottom == Q_SIZE || que.size == 0)
        return TRUE;
    else
        return FALSE;
}

int IsQueueFull( void )
{
    if(que.top+1 == Q_SIZE || que.size == Q_SIZE)
        return TRUE;
    else
        return FALSE;
}

int Enque(int val)
{
    if( IsQueueFull() == FALSE )
    {
        que.queue[++que.top] = val;
        que.size++;
        return SUCCESS;
    }
    else
        return FAILED;
}

int Dequeue( void )
{
    int val;
    if( IsQueueEmpty())
    {
        return FAILED;
    }
    else
    {
        val = que.queue[(que.bottom)++];
        que.size--;
        return SUCCESS;
    }
}

int main()
{
    InitQueue();
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d\n", que.top, IsQueueFull());
    printf("%d %d %d\n", que.top, que.bottom, Dequeue());
    printf("%d %d %d\n", que.top, que.bottom, Dequeue());
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d\n", que.top, IsQueueFull());
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d %d\n", que.top, que.bottom, Enque(5));
    printf("%d %d %d\n", que.top, que.bottom, Dequeue());
    printf("%d %d %d\n", que.top, que.bottom, Dequeue());
    printf("%d %d %d\n", que.top, que.bottom, Dequeue());
    printf("%d %d %d\n", que.top, que.bottom, Dequeue());
    printf("%d %d %d\n", que.top, que.bottom, Dequeue());

    return 0;
}

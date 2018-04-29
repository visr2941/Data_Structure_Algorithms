
#include <stdio.h>
#define Q_SIZE 100;

#define SUCCESS  0
#define FAILED  -1

#define TRUE  1
#define FALSE 0

typedef struct QUEUE {
    int queue[Q_SIZE];
    int top;
    int bottom;
    int size;
} Q;

void InitQueue()
{
    Q que;
    que.top = -1;
    que.bottom = 0;
    que.size  = 0;
}

int IsQueueEmpty( void )
{
    if(size == 0)
        return TRUE;
    else
        return FALSE;
}

int IsQueueFull( void )
{
    if(size == Q_SIZE)
        return TRUE;
    else
        return FALSE;
}

int Enque(int val)
{
    if( size < Q_SIZE )
    {
        if(++top==Q_SIZE)
            top = 0;
        
        que.queue[top] = val;
        size++;
    }
    else
        return FAILED;
}

int Dequeue( void )
{
    int val;
    if( IsQueueEmpty() )
    {
        return FAILED;
    }
    else
    {
        val = que.queue[bottom++];
        size--;
        if(bottom == Q_SIZE)
            bottom = 0;
    }
}

int main()
{
    InitQueue
    return 0;
}

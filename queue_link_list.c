
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

typedef struct node node_t;


typedef struct {
    node_t * head;
    node_t * tail;
} queue_t;


queue_t * queue_init( void )
{
    queue_t * q = (queue_t *) malloc (sizeof(queue_t));
    q->head = NULL;
    q->tail = NULL;
    
    return q;
}

void enqueue(queue_t * user_q, int data)
{
    node_t * temp = (node_t *) malloc(sizeof(node_t));
    temp->data = data;
    
    if(user_q->tail == NULL || user_q->head == NULL)
    {
        user_q->tail = temp;
        user_q->head = user_q->tail;
    }
    else
    {
        user_q->tail->next = temp;
        user_q->tail = user_q->tail->next;
    }
    
    user_q->tail->next = NULL;
}


int dequeue(queue_t * user_q)
{
    int retval;
    
    node_t * temp = NULL;
    if(user_q->head == NULL)
    {
        retval = -1;
        return retval;
    }
    else
    {
        retval = user_q->head->data;
        temp = user_q->head;
        user_q->head = user_q->head->next;
        free(temp);
    }
    
    return retval;
}

int main()
{
    queue_t *q = queue_init();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    
    int n = dequeue(q);
    
    printf("Dequeued item is %d\n", n);
    
    n = dequeue(q);
    
    printf("Dequeued item is %d\n", n);
    
    n = dequeue(q);
    
    printf("Dequeued item is %d\n", n);
    
    n = dequeue(q);
    
    printf("Dequeued item is %d\n", n);
    
    n = dequeue(q);
    
    printf("Dequeued item is %d\n", n);
    
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    n = dequeue(q);
    
    printf("Dequeued item is %d\n", n);
    
    n = dequeue(q);
    
    printf("Dequeued item is %d\n", n);
    
    n = dequeue(q);
    
    printf("Dequeued item is %d\n", n);
    
    n = dequeue(q);
    
    printf("Dequeued item is %d\n", n);    
    return 0;
}

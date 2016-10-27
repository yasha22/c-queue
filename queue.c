#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define EMPTY_QUEUE -1001
#define FULL_QUEUE -1002

queue* CreateQueue(int dim)
{
    queue* q = (queue *)malloc(sizeof(queue));
    q->que = (int *)malloc(dim * sizeof(int));
    q->size = dim;
    q->off_in = 0;
    q->off_out = 0;

}

//eliminazione
void DeleteQueue(queue* q)
{
    free(q->que);
    free(q);
}

//test di coda piena
int isFullQueue(queue* q)
{
    int next_in = (q->off_in + 1) % q-> size;
    return (next_in == q->off_out);

}
//test di coda vuota
int isEmptyQueue(queue* q)
{
    return (q->off_in == q->p_out);
}

//inserimento
void enque(queue* q, int value)
{
    if(!isFullQueue(q))
    {
        int in = (q->off_in)%q->size;
        q->off_in++;
        return q->que+in;
    }
    else
        exit(FULL_QUEUE);
}

//estrazione
int dequeue(queue* q)
{
    int tmp=0;
    if(!isEmptyQueue(q))
    {
        int out = (q->off_out)%q->size;
        q->off_out++;
        return q->que+out;

    }
    else
        exit(EMPTY_QUEUE);
}

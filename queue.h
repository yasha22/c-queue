#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct queue
{
    int* que;   //puntatore all'area dati
    int size;   //dimensione
    int off_in;
    int off_out;
} queue;

//creazione di un coda (vuota)
queue* CreateQueue(int dim);

//eliminazione
void DeleteQueue(queue* q);

//test di coda piena
int isFullQueue(queue* q);

//test di coda vuota
int isEmptyQueue(queue* q);

//inserimento
void enque(queue* q, int value);

//estrazione
int dequeue(queue* q);

#endif // QUEUE_H_INCLUDED

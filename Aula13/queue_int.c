#include <stdlib.h>

#include "queue_int.h"

struct _node
{
    int value;
    struct _node *next;
};

typedef struct _node node;

struct _queue_int
{
    node *first;
    node *last;
};

queue_int *queue_int_new(void)
{
    queue_int *q = malloc(sizeof(queue_int));
    q->first = NULL;
    q->last = NULL;
    return q;
}

void queue_int_delete(queue_int **_q)
{
    queue_int *q = *_q;
    node *n = q->last;
    while (n != NULL)
    {
        node *next = n->next;
        free(n);
        n = next;
    }
    free(q);
    *_q = NULL;
}

int queue_int_empty(queue_int *q)
{
    return q->first == NULL;
}

void queue_int_put(queue_int *q, int value)
{
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    if (q->last == NULL)
    {
        q->first = n;
    }
    else
    {
        q->last->next = n;
    }
    q->last = n;
}

int queue_int_get(queue_int *q)
{
    node *n = q->first;
    q->first = n->next;
    int value = n->value;
    if (queue_int_empty(q))
    {
        q->last = NULL;
    }
    free(n);
    return value;
}

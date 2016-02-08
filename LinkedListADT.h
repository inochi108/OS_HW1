#ifndef LINKLISTADT_H
#define LINKLISTADT_H
#include "PCB.h"

typedef struct FIFO_queue * FIFO_queue_p;

struct node {
	PCB_p data;
	struct node* next;
};

struct FIFO_queue {
	struct node * frontNode_ptr;
	struct node * endNode_ptr;
	int size;
};

FIFO_queue_p createLinkedList(void);
int is_empty(FIFO_queue_p l);
void enqueue(FIFO_queue_p l, PCB_p data);
struct node * dequeue(FIFO_queue_p l);
void printList(FIFO_queue_p l);
void freeAll(FIFO_queue_p l);

//void destroy(ListType l);
//void make_empty(ListType l);
//int is_full(ListType l);
//void delete(ListType l, ItemType item);

#endif




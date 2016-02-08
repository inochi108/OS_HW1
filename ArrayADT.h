#ifndef ARRAYADT_H
#define ARRAYADT_H
#include "LinkedListADT.h"

struct Priority_queue {
	FIFO_queue_p Queue_List[16];
	int topPriority;
};

typedef struct Priority_queue * Priority_queue_p;

Priority_queue_p createPQ();
void addPCB(Priority_queue_p pq, PCB_p pcb);
int peek(Priority_queue_p pq);
int checkTopPriority(Priority_queue_p pq);
PCB_p search(Priority_queue_p pq);
void freePriority_queue(Priority_queue_p pq);

#endif



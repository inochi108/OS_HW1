#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArrayADT.h"

const int PRIORITY_COUNT = 16;

// returns the pointer to the list; NULL if list not created
Priority_queue_p createPQ() {
	int i = 0;
	Priority_queue_p pq_ptr = malloc(sizeof(struct Priority_queue));
	for (i = 0; i < PRIORITY_COUNT; i++) {
		pq_ptr->Queue_List[i] = createLinkedList();
	}
	pq_ptr->topPriority = 16;
	return pq_ptr;
}

PCB_p search(Priority_queue_p pq) {
	if(pq) {
		int i = pq->topPriority;
	        if(i > 15 || i < 0) return NULL;
		FIFO_queue_p tempList = pq->Queue_List[i];

		//printf("Printf in search(), before dequeue.\n");
		struct node* temp = dequeue(tempList);
		if(temp == NULL) return NULL;
		//printf("Printf in search(), before return.\n");
		pq->topPriority = checkTopPriority(pq);
		return temp->data;
	} else {
		printf("!!!pq in search is NULL\n");
		return NULL;
	}
}

int checkTopPriority(Priority_queue_p pq) {
	if(pq) {
		int i = 0;
		FIFO_queue_p tempList;
		for(; i < PRIORITY_COUNT; i++) {
			tempList = pq->Queue_List[i];
			if(size_is(tempList) > 0) {
				return i;
			}
		}
		return -1;
	} else {
		printf("!!!pq in checkTopPriority is Null");
	}
}

void addPCB(Priority_queue_p pq, PCB_p pcb) {
	if(pq && pcb) {
		int tempPrio = pcb->priority;
		if(tempPrio < pq->topPriority) pq->topPriority = tempPrio;
		enqueue(pq->Queue_List[tempPrio], pcb);
	} else {
		printf("Error 358742: Added PCB is NULL.\n");
	}
}	
int peek(Priority_queue_p pq) {
	return pq->topPriority;
}

void freePriority_queue(Priority_queue_p pq) {
	int i = 0;
	for(i = 0; i < PRIORITY_COUNT; i++) {
		freeAll(pq->Queue_List[i]);
	}
	free(pq);
	pq = NULL;
}

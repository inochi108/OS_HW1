#include <stdio.h>
#include "LinkedListADT.h"
//#include "PCB.h"

int main(void) {
	int i = 0;

	// Create different PCBs for testing
	//----------------------------------------------------------
	PCB_p tempProcess1 = create("Process1", 1, 1);
	PCB_p tempProcess2 = create("Process2", 2, 2);
	PCB_p tempProcess3 = create("Process3", 3, 3);
	PCB_p tempProcess4 = create("Process4", 4, 4);
	PCB_p tempProcess5 = create("Process5", 5, 5);

	toString(tempProcess1);
	toString(tempProcess2);
	toString(tempProcess3);
	toString(tempProcess4);
	toString(tempProcess5);
	//--------------------------------------------------------

	// Test (1) : Add all the PCBs to the list
	//--------------------------------------------------------
	// Method "createLinkedList"(in linkListADT.c) will return a empty link list.
	FIFO_queue_p LinkedList = createLinkedList();

	enqueue(LinkedList, tempProcess1);
	enqueue(LinkedList, tempProcess2);
	enqueue(LinkedList, tempProcess3);
	enqueue(LinkedList, tempProcess4);
	enqueue(LinkedList, tempProcess5);

	printList(LinkedList);
	//-------------------------------------------------------

	// Test (2) : Dequeue a PCB from the list
	//-------------------------------------------------------
	//You need to create a node pointer so that you can have a place
	//to save the node that the dequeue method(in linkListADT.c) return
	struct node* dequeueNode = dequeue(LinkedList);

	printf("Dequeued node name : %s\nId is : %d\nPriority : %d\n",
			dequeueNode->data->name,
			dequeueNode->data->pid,
			dequeueNode->data->priority);
	//-------------------------------------------------------

	// Test (2.5) : Perform the dequeue operation multiple times
	for (i = 0; i < 2; i++) {
		dequeueNode = dequeue(LinkedList);

		printf("\nDequeued node name : %s\nId is : %d\nPriority : %d\n",
			dequeueNode->data->name,
			dequeueNode->data->pid,
			dequeueNode->data->priority);
	}

	printList(LinkedList);
	//-------------------------------------------------------

	// Test(3) : Dequeue a PCB from an empty list
	//-------------------------------------------------------

	FIFO_queue_p LinkedList2 = createLinkedList();
	struct node* dequeueNode2 = dequeue(LinkedList2);

	if (dequeueNode == NULL) {
		printf("The node is null\n");
	}
	else {
			printf("\nDequeued node name : %s\nId is : %d\nPriority : %d\n",
				dequeueNode->data->name,
				dequeueNode->data->pid,
				dequeueNode->data->priority);
	}

	printList(LinkedList2);
	//-------------------------------------------------------

	// Remember to deallocate all the PCBs that we just created at the beginning
	freePCB(tempProcess1);
	freePCB(tempProcess2);
	freePCB(tempProcess3);
	freePCB(tempProcess4);
	freePCB(tempProcess5);
	// Also the variable "dequeueNode"
	free(dequeueNode2);
	
	// "freeAll"(in linkListADT.c) method will deallocate all the node in the list
	freeAll(LinkedList);

	// The while loop in here doesn't really matter, you can take it out
	// or just leave it.

//	while (1) {}

	return 0;
}

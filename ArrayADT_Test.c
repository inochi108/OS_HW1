#include <stdio.h>
#include "ArrayADT.h"
#include "time.h"


int main(void) {
	int i = 0;
	PCB_p temp, PCBs[13];
	Priority_queue_p testPQ = createPQ();
	
	printf("\n\n\n\n\n-----TESTING OF PRIORITY QUEUE-----\n\n");
	//Create different PCBs for testing
	//----------------------------------------------------------
	PCBs[1] = create("PCB_Prio_13_A", 1, 13);
	PCBs[2] = create("PCB_Prio_13_B", 2, 13);
	PCBs[3] = create("PCB_Prio_4_A", 3, 4);
	PCBs[4] = create("PCB_Prio_4_B", 4, 4);
	PCBs[5] = create("PCB_Prio_7_A", 5, 7);
	PCBs[6] = create("PCB_Prio_15_A", 6, 15);
	PCBs[7] = create("PCB_Prio_13_C", 7, 13);
	PCBs[8] = create("PCB_Prio_2_A", 8, 2);
	PCBs[9] = create("PCB_Prio_1_A", 9, 1);
	PCBs[10] = create("PC_Prio_2_B", 10, 2);
	PCBs[11] = create("PCB_Prio_1_B", 11, 1);
	PCBs[12] = create("PCB_Prio_4_C", 12, 4);
	
	printf("PCBs data is printed in the form: name, pid, priority.\n");
	printf("The pid represents the order the PCBs go into the \n");
	printf("Priority Queue.\n");
	printf("\nNAME          PID   PRIO\n");
	for(i=1; i<13; i++) {
		printf("%s,  %d,  %d.\n", PCBs[i]->name, PCBs[i]->pid, PCBs[i]->priority);
	}

	printf("\nAdding PCBs to Priority Queue...\n\n");
	
	for(i = 1; i<13; i++) {
		addPCB(testPQ, PCBs[i]);
	}
	
	//Trying to spit them all out and make sure they come out in correct order.
	printf("Now note the order in which the PCBs are dequeued.\n");
	printf("The names of the PCBs represent the correct order the\n");
	printf("PCBs should be dequeued. Given they are in order of \n");
	printf("priority first then FIFO order for each priority.\n");
	printf("\nDequeued PCBs\n\n");

	printf("NAME         PID   PRIO\n");
	for(i=1; i<13; i++) {
		temp = search(testPQ);
		printf("%s,  %d,  %d.\n", temp->name, temp->pid, temp->priority);
	}

	printf("Notice that the names are now in the correct order.\n");

	printf("\nNow let's try adding a NULL item to the Priority Queue.\n");
	printf("An error should be printed when the NULL is passed...\n\n");
	addPCB(testPQ, NULL);

	printf("\nLet's also test that items cannot be removed from\n");
	printf("an empty Priority Queue. Nothing should be dequeued.\n");

	Priority_queue_p emptyQ = createPQ();

	temp = search(emptyQ);
	if(!temp) printf("Returned PCB:\n");

	printf("\nTest Complete!\n\n");
	freePriority_queue(testPQ);

	return 0;
}

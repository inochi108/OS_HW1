#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PCB.h"

// returns the pointer to the list; NULL if list not created
PCB_p create(char* newName, int newPid, int newPriority) {
	if (newPriority > 15 || newPriority < 0) {
		printf("Error: Priority must be 0 - 15. PCD not Created.");
	}
	//struct control_block_type testing;
	PCB_p pcb = malloc(sizeof(struct PCB));
	// if allocation was succesfull
	if (pcb != NULL) {
		//if(isdigit(newPid)) {
		//	printf("PID was not digit.\n");
		//	pcb = NULL;
		//}
		//else if(isdigit(newPriority)) {
		//	printf("Priority is not int.\n");
		//	pcb = NULL;
		strcpy(pcb->name, newName);
		pcb->pid= newPid;
		pcb->priority = newPriority;
	}
	return pcb;
}

char* getName(PCB_p pcb) {
	return pcb->name;
}

int getPid(PCB_p pcb) {
	return pcb->pid;
}

int getPriority(PCB_p pcb) {
	return pcb->priority;
}


void setName(PCB_p pcb, char* newName) {
	strcpy(pcb->name, newName);
}

void setPid(PCB_p pcb, int newPid) {
	pcb->pid = newPid;
}

void setPriority(PCB_p pcb, int newPriority) {
	pcb->priority = newPriority;
}

void freePCB(PCB_p pcb) {
	free(pcb);
	pcb = NULL;
}

void toString(PCB_p pcb) {
	printf("Name: %s, PID: %d, Priority: %d\n",
		pcb->name, pcb->pid, pcb->priority);
}

#ifndef PCB_H
#define PCB_H

struct PCB {
	char name[20];
	int pid;
	int priority;
};

typedef struct PCB* PCB_p;

PCB_p create(char* name, int newPid, int newPriority);
char* getName(PCB_p pcb);
int getPid(PCB_p pcb);
int getPriority(PCB_p pcb);
void freePCB(PCB_p pcb);
void toString(PCB_p pcb);
void setName(PCB_p pcb, char* newName);
void setPid(PCB_p pcb, int newPid);
void setPriority(PCB_p pcb, int newPriority);

#endif

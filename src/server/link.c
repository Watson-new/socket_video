#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*print all links*/
void print_links(LINKS *head,DLINKS *dhead)
{
	LINKS *move = NULL;
	DLINKS *dmove = NULL;
	move = head;
	dmove = dhead;

	//point to head
	while(move != NULL){
		printf("ONE_LINKSThe ipaddr: %s and the port is %d\n",move->ipaddr,move->port);
		if (move->next == NULL){
			break;
		}
		move = move->next;//next link
	}
	//right list for links
	while(dmove != NULL){
		printf("RIGHT_DLINKS The ipaddr: %s, and the port is %d, and the id index is %d\n",dmove->ipaddr,dmove->port,dmove->index);
		if (dmove->rnext == NULL){
			break;
		}
		dmove = dmove->rnext;//right list
	}
	//left list for links
	while(dmove != NULL){
		printf("LEFT_DLINKS The ipaddr: %s, and the port is %d, and the id index is %d\n",dmove->ipaddr,dmove->port,dmove->index);
		if (dmove->lnext == NULL){
			break;
		}
		dmove = dmove->lnext;//left list
	}
}

/*add links for restoring ipaddr and port*/
void create_links(LINKS **head, LINKS *input, char *ipaddr, unsigned int port)
{
	int len = 0;
	input = (LINKS *)malloc(sizeof(LINKS));
	//memcpy(input->ipaddr,ipaddr,strlen(ipaddr));
	/*self-defined func mystrlen*/
	len = mystrlen(ipaddr);
	mystrncpy(ipaddr,input->ipaddr,len);
	input->port = port;

	LINKS *move = *head;
	if (*head == NULL){
		*head = input;
		input->next = NULL;
	}
	else{
		printf("create the next link\n");
		/*#1 BUG-Used if it returns the only one pointer,while using while, it runs in a list of pointer.*/
		while(move->next != NULL){
			move = move->next;
		}
		move->next = input;
		input->next = NULL;//the end of link
	}
}

void double_create_links(DLINKS **dhead, DLINKS *dinput, char *ipaddr, unsigned int port, unsigned int index)
{
	int len = 0;
	dinput = (DLINKS *)malloc(sizeof(DLINKS));
	//memcpy(dinput->ipaddr,ipaddr,strlen(ipaddr));
	/*self-defined func mystrlen*/
	len = mystrlen(ipaddr);
	mystrncpy(ipaddr,dinput->ipaddr,len);
	dinput->port = port;
	dinput->index = index;

	DLINKS *dmove = *dhead;

	
	/*lnext--dhead--rnext*/
	if (*dhead == NULL){
		*dhead = dinput;
		//left and right should be null
		dinput->lnext = NULL;
		dinput->rnext = NULL;
	}
	else{
		/*#1 BUG-Used if it returns the only one pointer,while using while, it runs in a list of pointer.*/
		while(dmove->rnext != NULL){
			dmove = dmove->rnext;
		}
		//move--input-rnext(NULL)
		dmove->rnext = dinput;
		dinput->lnext = dmove;
		dinput->rnext = NULL;//the end of link
	}
}




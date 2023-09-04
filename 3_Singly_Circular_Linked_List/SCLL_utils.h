#ifndef __SCLL_UTILS_H_
#define __SCLL_UTILS_H_

#include<stdio.h>
#include<stdlib.h>
/*==========creating a structure for node========*/
typedef struct node
{
	int data; // storing integer data in the linked list
	//creating a pointer of type structure as it is used to point to the next node, which itself is of struct type
	struct node *next; // we cannot user type name of the structure here
}node_t;
/*===============================================*/

/*========creating a structure to hold list attributes===========*/
typedef struct list
{
	node_t* head;	//head pointer of type node_t to point to the first element of the list
	node_t* tail;	//tail pointer of type node_t to point to the last element of the node
	int count;		// we also take a count variable to keep ta track of number of nodes in out list.
}list_t;
/*===============================================================*/

//Function definitions
void list_init(list_t *l);							//function declaration to initialize the linked list.
int is_list_empty(list_t*);							//function declaration to check if the linked list is empty	

void add_node_first(list_t*, int data);				//function declaration to add a node in the first position
void add_node_last(list_t* , int data);				//function declaration to add a node in the last position
void add_node_pos(list_t* l, int pos,int data);		//function declaration to add a node in a given position

void delete_node_first(list_t* l);					//function declaration to delete the first node
void delete_node_last(list_t* l);					//function declaration to delete the last node
void delete_node_pos(list_t* l, int pos);			//function declaration to delete a from from given position.

void display_list(list_t*);							//function to display all the nodes of the linked list.
void free_list(list_t*);							//function to free the memory allocated to the complete linked list.
#endif

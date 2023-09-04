
#ifndef __SLL_UTILS_H_
#define __SLL_UTILS_H_

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



/*=================================Function Declarations=================================================*/
node_t* create_node(int);			//function prototype to create a new node.
void list_init(void);				//function prototype to initialize the linked list.
int is_list_empty();				//function prototype to check if the list is empty.

void add_node_first(int);			//function prototype to add node at the first.
void add_node_last(int);			//function prototype to add node at the last.
void add_node_position(int, int);	//function prototype to add node at a given position.

void del_first(void);				//function prototype to delete the first node.
void del_last(void);				//function prototype to delete a node at the last.
void del_pos(int);					//function prototype to delete a node at a given position.

void free_list(void);				//function prototype to free the memory allocated to the linked list.
void display_list(void);			//function prototype to display contents of linked list.
void display_reverse(node_t*);		//function prototype to print contents of a linked list in reverse.
void reverse_list(node_t*);			//function prototype to reverse the entire linkedlist.
/*=======================================================================================================*/

#endif

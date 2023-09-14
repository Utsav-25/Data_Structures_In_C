#ifndef __DLLL_H_
#define __DLLL_H_
#include<stdio.h>
#include<stdlib.h>

//structure declaration to create a node
typedef struct node
{
	int data;
	struct node* prev;
	struct node* next;
}node_t;

//structure to hold the link list properties
typedef struct lists
{
	node_t* head;
	int count;
}list_t;


/*=====Function Declarations=====*/
node_t* create_node(int data);
void list_init(list_t* l);
int is_list_empty(list_t *l);
void free_list(list_t* l);
void forward_display_list(list_t* l);
void backward_display_list(list_t* l);

void add_node_first(list_t* l, int data);
void add_node_last(list_t* l, int data);
void add_node_pos(list_t* l, int data, int pos);

void delete_node_first(list_t* l);
void delete_node_last(list_t* l);
void delete_node_pos(list_t* l, int pos);
/*===============================*/

#endif

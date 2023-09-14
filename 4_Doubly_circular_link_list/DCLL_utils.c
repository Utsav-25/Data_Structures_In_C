#include "DCLL_utils.h"
//function definitions for all the operations

//function definition to create a new node
 node_t* create_node(int data)
 {
	//1. allocate memory dynamically to single node
	node_t* newnode=(node_t*)malloc(sizeof(node_t));

	//2. fill the created node with data
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	//3. return address of created node
	return newnode;
 }


//function definition to initialise the list
void list_init(list_t* l)
{
	l->head = NULL;
	l->count = 0;
}

//function definition to check if the list is empty
int is_list_empty(list_t *l)
{
	return l->head == NULL;
}

//function definition to add a node in the first place
void add_node_first(list_t* l, int data)
{
	//create a new node first
	node_t* newnode = create_node(data);
	//check if the list is empty, then the new node will be the first node.
	if(is_list_empty(l))
	{
		//make the head pointer point to it.
		l->head = newnode;
		//make the list circular
		newnode->prev = newnode;
		newnode->next = newnode;
	}
	else//list is not empty
	{
		//add the current first node into next of newnode
		newnode->next = l->head;
		//add the last node into the previous of newnode
		newnode->prev = l->head->prev;
		//add newnode into next of last node
		l->head->prev->next = newnode;
		//add newnode into the previous of first node
		l->head->prev = newnode;
		//move the head to the newnode
		l->head = newnode;
	}
	//increment the node counter
	l->count++;
}
//function to add the node at the last
void add_node_last(list_t* l, int data)
{
	//create a new node first
	node_t* newnode = create_node(data);
	//check if the list is empty, then the new node will be the first node.
	if(is_list_empty(l))
	{
		//make the head pointer point to it.
		l->head = newnode;
		//make the list circular
		newnode->prev = newnode;
		newnode->next = newnode;
	}
	else // the list is not empty.
	{
		//add the last node into the previous of newnode
		newnode->prev = l->head->prev;
		//add the first node into the next of newnode
		newnode->next = l->head;
		//add newnode into the next of last node
		l->head->prev->next = newnode;
		//add newnode into the previous of first node
		l->head->prev = newnode;
	}
	//increment the node counter
	l->count++;
}

//function to add a node at given position
void add_node_pos(list_t* l, int data, int pos)
{
	//first we check the constraints
	if(pos<1 | pos > l->count+1)	//if given position is beyond valid range
		return;
	if(pos ==1 )					//if pos value =1 then add node at 1st position
	{
		add_node_first(l, data);
		return;
	}
	if(pos = l->count+1)			//if position is one more than latest count, add node at the last.
	{
		add_node_last(l, data);
		return;
	}

	//create a node with the given data
	node_t* newnode = create_node(data);
	//if list is empty
	if(is_list_empty(l))
	{
		// add newnode into head
		l->head = newnode;
		// make it circular
		newnode->next = newnode;
		newnode->prev = newnode;
	}
	//if list is not empty
	else
	{
		//traverse till the pos -1 node
			//create a traversal pointer initialised to head
		node_t *trav = l->head; 
		for(int i=1;i< pos -1;i++)
			trav = trav->next;
		//trav now points to the pos-1 node
		//add pos-1 node to the prev of newnode
		newnode->prev = trav;
		//add pos node to the next of newnode
		newnode->next = trav->next;
		//add newnode to the previous of pos-1 node
		trav->next = newnode;
		//add the newnode to the previous of the pos node
		newnode->next->prev = newnode;	
	}
	//increment the count
	l->count++;
}

//function to delete the node from the first position
void delete_node_first(list_t* l)
{
	//check if the list if empty
	if(is_list_empty(l))
		printf("The list is empty, nothing to delete...");
	//check if the list has only one node
	if(l->head->next == l->head)
		{
			free(l->head);
			l->head = NULL;
		}
	else // the list has multiple nodes
	{	
		//take backup of the first node
		node_t* temp = l->head;
		//add the node after nead node into next of last node
		l->head->prev->next = l->head->next;
		//add last node into previous of second node
		l->head->next->prev = l->head->prev;
		//move the head on the second node
		l->head = l->head->next;
		//free the memory of the backup node
		free(temp);
	}			
	//decrement the node count
	l->count--;
}

void delete_node_last(list_t* l)
{
	//check if the list if empty
	if(is_list_empty(l))
		printf("The list is empty, nothing to delete...");
	//check if the list has only one node
	if(l->head->next == l->head)
		{
			free(l->head);
			l->head = NULL;
		}
	else	//list contains multiple nodes
	{
		//add the second last node into the previous of head node
		l->head->prev = l->head->prev->prev;
		//free the memory of the last node
		free(l->head->prev->next);
		//add head node to the next of second last node
		l->head->prev->next = l->head;
	}
	//decrement the node count
	l->count--;
}
//function definiton to delete node at a given position
void delete_node_pos(list_t* l, int pos)
{
	//if entered position is outside the link list bound
	if(pos<1 || pos>l->count)
		return;
	//if position is equal to 1 then delete the 1st node
	if(pos==1)
	{
		delete_node_first(l);
		return;
	}
	//if position is equal to count, delete the last node
	if(pos==l->count)
	{
		delete_node_last(l);
		return;
	}
	//check if list is empty
	if(is_list_empty(l))
		printf("The list is empty\n");
	//check if there is only one node
	else if(l->head->next==l->head)
	{
		//free the memory pointed by head pointer
		free(l->head);
		l->head=NULL; 	//assign null to avoid dangling pointer
	}
	else // the list has multiple nodes
	{
		//create a traversal pointer to go to pos node
		node_t* trav=l->head;
		int i=1;
		for(i=1;i<pos;i++, trav = trav->next);
		//trav now points to the pos node
		//assigning previous of pos+1 node with address of pos-1 node
		trav->next->prev = trav->prev;
		//assigning next of pos-1 node with address of pos+1 node
		trav->prev->next = trav->next;
		//free the allocated memory of the node pointed by trav
		free(trav);
	}
	//decrement the link count
	l->count--;
}

//function to display the complete link list from the beginning
void forward_display_list(list_t* l)
{
//if the list is empty, print message to user
if(is_list_empty(l))
	printf("The list is empty\n ");
//else list contains nodes	
else
	{
	//we need to traverse to the end of the list
	//create a pointer and start from 1st node
		node_t* trav=l->head;
		do
		{
			printf("%-4d",trav->data);
			trav=trav->next;
		}while(trav!=l->head);	//print the data of the nodes until trav again stores the address of head
		printf("\n");
	}
}

//function to display the list from the last
void backward_display_list(list_t* l)
{
//check if list is empty
if(is_list_empty(l))
	printf("The list is empty\n ");
else
{
//we create a pointer to start with the last node
	node_t* trav=l->head->prev;
	do
	{
		printf("%-4d",trav->data);
		trav=trav->prev;
	}while(trav!=l->head->prev);
	printf("\n");
}
}


//function definition to free the list
void free_list(list_t* l)
{
	//if list is empty
	if(is_list_empty(l))
		printf("The list is empty\n");
	//if there is are multiple nodes
	else
	{
		//create a traversal pointer
		node_t* trav = l->head;
		do
		{
			//take backup of the current node
			node_t* temp = trav;
			//move trav pointer to the next node
			trav = trav->next;
			//free the node memory pointed by temp
			free(temp);
		} while (trav!=l->head);
		//make the head pointer point to null
		l->head = NULL;
	}
}	
//C program containing the function implementation of the linked list operations
#include "SCLL_utils.h"

//function definition to initialise the list
void list_init(list_t *l)
{
	//initially declaring the head and tail pointers to null
	l->head = l->tail = NULL;
	l->count =0;	//initialising the count value to 0.
}

int is_list_empty(list_t* l)
{

	return (l->head ==NULL && l->tail ==NULL);
}

//Function definition to create a new node
node_t* create_node(int data)
{
	node_t* newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

//Function definition to add a node in the first position
void add_node_first(list_t* l, int data)
{
	//1. Create a new node
	node_t* newnode = create_node(data);
	//2. check if the list is empty, if yes, make this the head node
	if(is_list_empty(l))
		{
			//add new node into head and tail
			l->head = l->tail = newnode;
			//the next of this node should point to itself to make it circular
			newnode->next = newnode;
		}
	//else the list is not empty.
	else
	{
		//add the first node into the next of the newnode
		newnode->next = l->head;
		//add the new node into the next of the last node
		l->tail->next = newnode;
		//assign the head pointer to point to this newnode
		l->head = newnode;
	}
	//since we are adding a newnode, we also increment the count variable by 1
	l->count++;

}

//Function definition to add a node at the last position
void add_node_last(list_t* l, int data)
{
	//First we create a new node
	node_t* newnode = create_node(data);
	//check if the list is empty
	if(is_list_empty(l))
	{
		//a. add newnode into head and tail
		l->head = l->tail = newnode;
		//b. make list circular
		newnode->next = newnode;
	}
	//else the list is not empty
	else
	{
		//we add the first node to the next of the new node
		newnode->next = l->head;
		//we add the new node to the next of the current last node
		l->tail->next = newnode;
		//the tail pointer will now point to the last node(the newnode)
		l->tail = newnode;
	}
	//increment the counter of the number of nodes
	l->count++;
}

//function definition to add a node at a given position
void add_node_pos(list_t* l, int pos,int data)
{
	//check if the position is invalid, if invalid then return
	if(pos<1 || pos>(l->count+1))	//if position value is beyond the valid range
		return;
	if(pos==1)	//if position is equal to 1 then the nodes should be added in the first place
	{
		add_node_first(l,data);		
		return;	
	}
	if(pos == l->count+1)	//if the position value is 1 more than the total nodes, add the node to the last
	{
			add_node_last(l,data);
			return;
	}
	//if the above if statements are invalid then create a new node
	node_t* newnode = create_node(data);
	//check if the list is empty
	if(is_list_empty(l))
		{
			//a. add newnode into head and tail
			l->head = l->tail = newnode;
			//b. make it circular
			newnode->next = newnode;
		}
	//else the list is not empty.
	else
	{
		//create a traveral pointer till pos -1 node
		node_t* trav = l->head;
		int i=0;
		while(i<pos-1)
			{
				trav = trav->next;
				i++;
			}
		//trav will now point to the pos -1 node
		//the next of new node should point to the current node at pos index.
		newnode->next = trav->next;
		//the next of pos-1 node should point to the new node
		trav->next = newnode;	
	}
	//increment the count value after the node has been added
	l->count++;
}

//function definition to delete the first node
void delete_node_first(list_t* l)
{
	//first check if the list is empty
	if(is_list_empty(l))
		printf("The list is empty, no nodes to delete...");
	//else a list can have a single node
	else if(l->head->next == l->head)
	{
		//release the memory of that node
		free(l->head);
		//make the head and tail pointer to NULL
		l->head = l->tail = NULL;
	}
	//else the list has multiple nodes.
	else
	{
		//move the head on the second node
		l->head = l->head->next;
		//release the memory allocated to the first node
		free(l->tail->next);
		//point the next of last node to this new node
		l->tail->next = l->head;
	}
	//decrement the count value of the total number of nodes
	l->count--;	
}

//function definition to delete the last node
void delete_node_last(list_t* l)
{
	//first check if the list is empty
	if(is_list_empty(l))
		printf("The list is empty, no nodes to delete...");
	//else the list can have only one node
	else if(l->head->next == l->head)
		{
			//free the memory allocated to that node
			free(l->head);
			//the head and tail pointers should now point to null
			l->head = l->tail = NULL;
		}
	//else the list has multiple nodes
	else
	{
		//create a traveral pointer to reach to 2nd last node
		node_t* trav = l->head;
		while(trav->next->next != l->head)
			trav = trav->next;
		//trav will now point to 2nd last node
		//free the memory of the last node
		free(l->tail);
		//move the tail pointer on 2nd last node
		l->tail = trav;
		//assign the next of the 2nd last node(now the last node)to the head
		trav->next = l->head;		
	}
	//decrement the total node count		
	l->count--;
}

//function definition to delete a node from a given position.
void delete_node_pos(list_t* l, int pos)
{
	//if given position count is beyond valid range
	if(pos < 1 || pos > l->count)
		return;
	if(pos == 1) //if position is equal to 1 then the nodes should be deleted from the first place
	{
		delete_node_first(l);
		return;
	}
	if(pos == l->count) //if position is equal to count then the nodes should be deleted from the last place
	{
		delete_node_last(l);
		return;
	}
	//check if the list is empty
	if(is_list_empty(l))
		printf("The list is empty, no nodes to delete..");
	//if the list has only one node
	else if(l->head->next == l->head)
	{
		//free the memory allocated to that node
		free(l->head);
		//the head and tail pointers should now point to null
		l->head = l->tail = NULL;
	}
	//else the list has multiple nodes
	else
	{
		//create a traversal pointer to point to the pos -1 node
		node_t* trav = l->head;
		int i=1;
		while(i<pos-1)
			{
				trav = trav->next;
				i++;
			}
		//trav now points to pos-1 node.
		//take backup of pos node
		node_t* temp = trav->next;
		//add pos+1 node into next of pos-1 node
		trav->next = temp->next;
		//free the node pointed by temp
		free(temp);		
	}
	//decrement the node count value
	l->count--;
}



//function definition to display the entire linked list.
void display_list(list_t* l)
{
//1. if list is empty
	if(is_list_empty(l))
		// give msg to user
		printf("List is empty\n");
	//2. if list is not empty
	else
	{
		//create a pointer and start from head.
		node_t* trav = l->head;
		do
		{
			printf("%d\t",trav->data);
			trav = trav->next;
		}while(trav != l->head);	//repeat until the last node
		printf("\n");
	}

}
void free_list(list_t *l)
{
	//1. if list is empty
	if(is_list_empty(l))
		// give msg to user
		printf("List is empty\n");
	//2. if list is not empty
	else
	{
		//a. create one pointer and start from head
		node_t *trav = l->head;
		do
		{
			//b. take backup of current node
			node_t *temp = trav;
			//c. go on next node
			trav = trav->next;
			//d. release memory of backuped node
			free(temp);
		}while(trav != l->head);//d. repeat step b and c till last node
		l->head = l->tail = NULL;
	}
}

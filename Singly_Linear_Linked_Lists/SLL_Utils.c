//C program containing function defintions for operations to be performed on the Singly linked list.
#include "SLL_Utils.h"

extern node_t* head;

//function to create a new node
node_t* create_node(int data)
{
	//we use malloc to allocate a memory block equal to the size of the node structure.
	node_t* newnode=(node_t*)malloc(sizeof(node_t));
	newnode->data = data;	//assign the data member with the function argument that is given by user
	newnode->next = NULL;	//assign the pointer to currently NULL as it is not pointing to any other node.
	return newnode;
}



//function to initialize the list
void list_init(void)
{
	//initially the head pointer will not be pointing to any node. This is the initialization.
	head = NULL;
}

//function to check if the list is empty
int is_list_empty(void)
{
	//we check if the head pointer is NULL or not, if it is NULL, it means the list is empty so we return true, else we return false.
	return head==NULL;
}


//function to add a node at the start
void add_node_first(int data)
{
	//first we create a new node.
node_t* newnode=create_node(data); // creating a new node that we want to add

// we check if linked list if empty or not
	if(is_list_empty())
	{
	head=newnode; //if list is empty then the node that we add will be the first node of the linked list.
	//So head will contain the address to this node
	}
//else the linked list is not empty
	else
	{
		//take backup of the remaining list into the next of new node
		newnode->next=head;
		head=newnode; // the new node is now being pointed by head.
		//Note: if we assign new node as head first then the next part of this new node contains null.
		// in this case entire linked list will be lost, so first we take backup of the current head in the next of new node, then assign new node as head
	}
}


//function to add a node at the last of the linked list
void add_node_last(int data)
{
	//first we create a new node
	node_t* newnode=create_node(data);	//creating a node that we want to add

//we then check if the linked list is empty or not
	if(is_list_empty())
	{
	head=newnode;	//if list is empty the new node will be the 1st node in the LL
	}
	else // the linked list is not empty
	{
		// we then traverse the list till the last node
		node_t* trav=head; //we create a traversal pointer that contains the address of head
		while(trav->next!=NULL)
		{
			//go to the next node
			trav=trav->next;
		}
		//once we reach a node whose next address is NULL, we add the element
		trav->next=newnode;
	}

}

//function to add a node in a given position
void add_node_position(int pos, int data)
{
	int i=0;
	node_t* temp;	//creating a temp variable
	node_t* newnode=create_node(data);	//create a node with the given data
	temp=head;
	//we traverse to the node after which we want to add a new node
	//check if the list is empty
	if(is_list_empty())	// if the list is empty then made the new node as head
	{
		head=newnode;
	}
	//if position number is 1 or less then we cannot directly add a node in the beginning.
	// we first free the pointer created above for new node and then add note at the starting
	else if(pos<=1)
	{
		free(newnode);
		add_node_first(data);
	}
	else
	{
		while(i<pos-1)
		{
			temp=temp->next;	//fist we traverse the array till the position number entered by user
			i++;
		}
		//temp contains the data and the addtess to the next node.
		//newnode->data=data;
		//the next section of the new node will contain the addtess of the next node
		newnode->next=temp->next;
		temp->next=newnode;
	}	

}

//function to delete the first node
void del_first(void)
{
	//first we check if the list is empty
	if( is_list_empty() )
		printf("The list is empty, no nodes to delete..\n");
	//else take backup of the node after the head node and free the memory allocated to head node
	else
	{
	node_t* temp = head;	//take backup of 1st node.
	head = head->next;		//move head to the 2nd node.
	free(temp);				//free the first node.
	printf("The fist node has been deleted\n");
	display_list();
	printf("\n");
	}
}

//function to delete the last node.
void del_last(void)
{
	//fist check if the list is empty
	if( is_list_empty() )
		printf("The list is empty, no nodes to delete..\n");
	//check if the list has a single node
	else if(head->next == NULL)
	{
		//free memory allocated to head node.
		free(head);
		head = NULL; 	//to avoid dangling pointer.
	}
	//else the list has multiple nodes
	else
	{
		//traverse till the second last node
		node_t* trav;
		for(trav = head; trav->next->next != NULL; trav= trav->next);	//this for loop will iterate till trav reaches 2nd last node.
		//release the memory of the last node
		free(trav->next);
		//make the next of the 2nd last node to NULL as it has now become the last node
		trav->next = NULL;
		printf("The last node has been deleted\n");
		display_list();
		printf("\n");
	}
}


//function to delete a node at a given position
void del_pos(int pos)
{
	//first check if the list is empty
	if( is_list_empty() )
		printf("The list is empty, no nodes to delete..\n");
	//check if position is 1
	else if(pos == 1)
		del_first();
	//check if position is less than 1, in that case it is invalid and the function returns.
	else if(pos<0)
		return;
	//else check if the list has only one node
	else if(head->next == NULL)
		{
			//free memory of the head node
			free(head);
			head = NULL;	//avoid dangling pointer.
		}
	//else the list has nultiple nodes
	else
		{
			//traverse to pos-1 node
			node_t* trav;
			int i;
			//if list has 2 nodes then trav->next->next will be null, we need to check that condition as well.
			for(i=1,trav = head;trav->next->next != NULL; trav = trav->next,i++);	//for loop iterates till trav points to pos -1 node.
			//take backup of node at pos index
			node_t* temp = trav->next;
			//add pos+1 node into next of pos-1 node
			trav->next = temp->next;
			//free the node at pos
			free(temp);
		}
}

//function to free the memory allocated to the linked list.
void free_list(void)
{
	//first we check if the list is empty, in that case we dont have anything to free
	if( is_list_empty() )
		printf("The list is already empty..\n");
	//else the list is not empty
	else
		{
			//create a traversal pointer and assign it with head;
			node_t* trav = head;
			while(trav !=NULL)
				{
					//take backup of the current node
					node_t* temp = trav;
					//go to the next node
					trav = trav->next;	//trav now points to the next node.
					//free the current node
					free(temp);
				}
			//above process is repeated until the end of the list.
			//once done we need to set head as NULL to avoid dangling pointer.
			head = NULL;
		}
}


//function to display entire linked list.
void display_list(void)
{
	// check if the list is empty
	if(is_list_empty())
	printf("The list is empty!\n");
	else 	// the list is not empty
	{
		//create a traversal pointer and assign it with head
		node_t* trav=head;
		while(trav!=NULL)
		{
			printf("%d\t",trav->data);
			trav=trav->next;
		}
		printf("\n");	
	}	
}

//function to display the linked list in reverse. We have implemented recussion to implement this
void display_reverse(node_t* trav)
{
	if(trav == NULL)
		return;
	display_reverse(trav->next);
	printf("%d\t", trav->data);
}

//function to reverse the single linked list.
void reverse_list(node_t* trav)
{
/*
To reverse a singly linked list, we need to take 3 pointers.
1st pointer points to the previous node.
2nd pointer points to the current node.
3rd pointer points to the next node after the current node.
*/
node_t* previous=NULL;
node_t* current = head;	//we start from the head node
node_t* next = NULL;

while(current != NULL) //until we reach the end of the linked list.
	{
		//next pointer points to the next node of the current node.
		next = current->next;
		//the next of the current node will point to the previous node
		current->next = previous;
		//now the next node will become the current node and the current node becomes the previous node for the next iteration
		previous = current;
		current = next;
	}
//once the condition of the while loop gets over , i.e, the current pointer is pointing to NULL, we need to shift the head pointer ot last node.
head = previous;
}

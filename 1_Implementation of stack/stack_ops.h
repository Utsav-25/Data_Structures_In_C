#ifndef __STACKOPS_H_
#define __STACKOPS_H_

#define SIZE 3

/*====defining a stack structure====*/
typedef struct stack
{
	int arr[SIZE];
	int top;	//variable to keep track of last stored value in stack
}stack_t;
/*=================================*/

/*==defining an enum to store true and false contions status====*/
typedef enum boolean
{FALSE, TRUE}bool_t;

/*=====Function Declarations for stack operations=====*/

void stack_init(stack_t*);		//to initialize the stack.
void stack_push(stack_t*, int);	//to add data into the stack.
void stack_pop(stack_t*);		//to pop out the topmost element of the stack.
int  stack_peek(stack_t*);		//to read the topmost element of the stack.

bool_t if_stack_full(stack_t*);	//to check if stack is full.
bool_t if_stack_empty(stack_t*);	//to check if the stack is empty.

/*====================================================*/

#endif

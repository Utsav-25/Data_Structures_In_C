#include "SLL_Utils.h"

node_t *head = NULL;	//creating a head pointer;

int main(void)
{

list_init();	//first we initialize the list.
int choice;
int num;
int pos;
	do
	{

	printf("Enter your choice:\n");
	printf("0.EXIT\n1.Display linked list\n2.Add node to front\n3.Add node to last\n4.Add node at position\n5.Delete the first node\n6.Delete the last node\n7.Delete node at positioni\n");
	printf("8.Display linked list in reverse\n9.Reverse the list\n");
	scanf("%d",&choice);
	switch(choice)
		{
			case 1:
				display_list();
				break;
			case 2:
				{
				printf("Enter the number you want to add:\n");
				scanf("%d",&num);
				add_node_first(num);
				}
				break;
			case 3:
				{
				printf("Enter the number you want to add:\n");
				scanf("%d",&num);
				add_node_last(num);
				}
				break;
			case 4:
				{
					printf("Enter the number that you want to add\n");
					scanf("%d",&num);
					printf("Enter the position at which you want to add this number:\n");
					scanf("%d",&pos);
					add_node_position(pos,num);
				}
				break;
			case 5:
				del_first();
				break;
			case 6:
				del_last();
				break;
			case 7:
				{
					printf("Enter the position at which you want to add this number:\n");
					scanf("%d",&pos);
					del_pos(pos);
				}
				break;
			case 8:
				display_reverse(head);
				printf("\n");
				break;
			case 9:
				reverse_list(head);
				printf("\n");
				break;
					
		}
	}while(choice!=0);

free_list();
return 0;
}

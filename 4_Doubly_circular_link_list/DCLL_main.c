// Main C program containing a menu driven approach to perform operations on the doubly circular linked list.
#include"DCLL_utils.h"

int main(void)
{
list_t l;
list_init(&l);
int choice;
int num;
int pos;
	do
	{

	printf("Enter your choice:\n");
	printf("0.EXIT\n1.Display linked list in forward\n2.Display linked list in reverse\n3.Add node to front\n4.Add node to last\n5.Add node at position\n6.Delete the first node\n7.Delete the last node\n8.Delete node at position\n");
	scanf("%d",&choice);
	switch(choice)
		{
			case 1:
				forward_display_list(&l);
				break;
			case 2:
				backward_display_list(&l);
				break;	
			case 3:
				{
				printf("Enter the number you want to add:\n");
				scanf("%d",&num);
				add_node_first(&l, num);
				}
				break;
			case 4:
				{
				printf("Enter the number you want to add:\n");
				scanf("%d",&num);
				add_node_last(&l,num);
				}
				break;
			case 5:
				{
					printf("Enter the number that you want to add\n");
					scanf("%d",&num);
					printf("Enter the position at which you want to add this number:\n");
					scanf("%d",&pos);
					add_node_pos(&l,num,pos);
				}
				break;
			case 6:
				delete_node_first(&l);
				break;
			case 7:
				delete_node_last(&l);
				break;
			case 8:
				{
					printf("Enter the position at which you want to add this number:\n");
					scanf("%d",&pos);
					delete_node_pos(&l,pos);
				}
				break;
			
		}
	}while(choice!=0);
free_list(&l);	
return 0;
}

// Main C program containing a menu driven approach to perform operations on the singly circular linked list.
#include"SCLL_utils.h"

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
	printf("0.EXIT\n1.Display linked list\n2.Add node to front\n3.Add node to last\n4.Add node at position\n5.Delete the first node\n6.Delete the last node\n7.Delete node at position\n");
	scanf("%d",&choice);
	switch(choice)
		{
			case 1:
				display_list(&l);
				break;
			case 2:
				{
				printf("Enter the number you want to add:\n");
				scanf("%d",&num);
				add_node_first(&l, num);
				}
				break;
			case 3:
				{
				printf("Enter the number you want to add:\n");
				scanf("%d",&num);
				add_node_last(&l,num);
				}
				break;
			case 4:
				{
					printf("Enter the number that you want to add\n");
					scanf("%d",&num);
					printf("Enter the position at which you want to add this number:\n");
					scanf("%d",&pos);
					add_node_pos(&l,pos,num);
				}
				break;
			case 5:
				delete_node_first(&l);
				break;
			case 6:
				delete_node_last(&l);
				break;
			case 7:
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

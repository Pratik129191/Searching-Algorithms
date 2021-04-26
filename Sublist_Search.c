#include<stdio.h>
#include<stdlib.h>

typedef struct node_structure
{
	int data;
	struct node_structure* next;
}node;

node* create_linked_list(int n);
void sublist_search(node* first, node* second);
int main()
{
	printf("\n-:Number of nodes in the first list must be smaller than the second list:-\n\n");
	printf("For FIRST-LIST ----------\n\n");
	int flength;
	printf("How many nodes you want to create:- ");
	scanf("%d",&flength);
	node* first_head = create_linked_list(flength);

	printf("For SECOND-LIST ----------\n\n");
	int slength;
	printf("How many nodes you want to create:- ");
	scanf("%d", &slength);
	node* second_head = create_linked_list(slength);

	sublist_search(first_head, second_head);
}

node* create_linked_list(int n)
{
	node* head = NULL;
	node* temp = NULL;
	node* ptr = NULL;
	for (int i = 0; i < n; i++)
	{
		// creating isolated node --------
		temp = (node*)malloc(sizeof(node));
		if (temp==NULL)
		{
			printf("Memory can't be allocated.");
			exit(1);
		}
		else
		{
			printf("Enter data for node %d:- ", i + 1);
			scanf("%d", &temp->data);
			temp->next = NULL;
		}

		// assigning first node to head --------
		if (head==NULL)
		{
			head = temp;
		}
		// linking rest nodes to head --------
		else
		{
			ptr = head;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = temp;
		}
	}
	return head;
}

void sublist_search(node* first, node* second)
{
	node* fptr = first;
	node* sptr = second;
	int status = -1;
	while (sptr!=NULL)
	{
		while (fptr!=NULL)
		{
			if (fptr->data == sptr->data)
			{
				fptr = fptr->next;
				sptr = sptr->next;
			}
			else
			{
				fptr = first;
				break;
			}
		}
		if (fptr==NULL)
		{
			status = 1;
			break;
		}
		else
		{
			sptr = sptr->next;
		}
	}

	if (status==1)
	{
		printf("Sublist found.");
	}
	else
	{
		printf("Sublist not found.");
	}
}

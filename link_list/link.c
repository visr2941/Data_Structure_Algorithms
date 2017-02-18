#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
//#include <link.h>


typedef struct node
{
	int16_t data;
	struct node * nxtptr;
} Node;


void insert_node(Node **head, uint8_t pos, uint16_t data)
{
	uint8_t i=0;
	Node * temp=*head;
	Node * temp1=NULL;
	Node * node = (Node *) malloc(sizeof(Node));
	if(node==NULL)
		printf("Memory Error!");
	node->data = data;

	while(i<pos-1 && temp!=NULL)
	{
		temp1 = temp;
		temp = temp->nxtptr;
		i++;
	}
	node->nxtptr = temp;
	if(temp1==NULL)
	{
		*head = node;
	}
	else
		temp1->nxtptr = node;
	printf("Node inserted at location i=%d, position input %d\n", ++i, pos);
}

void print_list(Node ** head)
{
	Node * temp = *head;	
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->nxtptr;
	}
	printf("\n");
}

void delete_node(Node ** head, uint8_t pos)
{
	uint8_t i=1;
	Node * temp1 = *head;
	Node * temp = NULL;
	while(i!=pos)
	{
		temp = temp1;
		temp1 = temp1->nxtptr;
		i++;
	}
	if(pos==1)
		*head=temp1->nxtptr;
	else
		temp->nxtptr=temp1->nxtptr;
	free(temp1);
}

main()
{
    	Node ** head = (Node **)malloc(sizeof(*head));
    	*head = NULL;
	insert_node(head, 1, -34);
	insert_node(head, 2, 7);
	insert_node(head, 3, -7);
	insert_node(head, 4, 8);
	insert_node(head, 5, 100);
	insert_node(head, 6, -800);
	print_list(head);
	delete_node(head, 6);
	delete_node(head, 5);
	print_list(head);
}

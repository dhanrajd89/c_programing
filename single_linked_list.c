#include<stdio.h>
#include<stdlib.h>
#include"single_linked_list.h"

int main()
{
	int ch, ret = FAILURE;

	printf("\nSingle Linked List:\n");	

	while(1) {

		printf("\n\t1.Add node\n\t2.Delete node\n\t3.Display nodes\n\t4.Reverse Link\n\t5.Sort nodes\n\t6.Exit\nEnter you choice:");	
		scanf("%d",&ch);
	
		switch(ch) {
			
			case 1: ret = add_node(); 
					break;
			case 2: ret = delete_node(); 
					break;
			case 3: ret = display();
					break;
			case 4: ret = reverse_link();
					break;
			case 5: ret = sort();
					break;
			case 6: exit(0);

			default:
				printf("Enter the valid option !!!\n");
		}	
	}

	return ret;
}

node_t *getnode()
{
	node_t *node=NULL;
	node = (node_t *)calloc(1,sizeof(node_t));
	if(node == NULL) {

		printf("Unable to allocate memory for Node !!! \n");
		return NULL;
	}
	printf("Enter the node data: ");
	scanf("%d",&node->data);
	node->next = NULL;

	return node;
}

int sort()
{
	int data;
	node_t *temp1 = start, *temp2 = temp1->next;
	
	if(start == NULL)
	{
		printf("List is Empty !!!\n");
		return SUCCESS;
	}

	while((temp1 != NULL)&&(temp2 != NULL))
	{
		while(temp2 != NULL)
		{
			if(temp1->data > temp2->data)
			{
				data = temp1->data;
				temp1->data = temp2->data;
				temp2->data = data;
				printf("\nElse case\n");	
			}
			temp2 = temp2->next;
			printf("\nInside while2\n");	
		}	
		temp1 = temp1->next;
		temp2 = temp1->next;
		printf("\nInside While1\n");
	}

	return display();
}

int add_node()
{
	int ch, ret = FAILURE;
	node_t *nn = NULL;

	nn = getnode();
	if(nn == NULL) {
		printf("Error in node memory allocation !!!\n");
		return ret;
	}
	
	printf("\n\nIn Add node:\n\t1.Add node at front\n\t2.Add node at middle\n\t3.Add node at end\nEnter your choice:");
	scanf("%d",&ch);

	switch(ch) {
		
		case 1: ret = add_node_front(nn);
				break;
		case 2: ret = add_node_middle(nn);
				break;
		case 3: ret = add_node_end(nn);
				break;
		
		default:
			printf("Enter the valid option !!!\n");
			free(nn);
			nn = NULL;
			return ret; 
	}
	
	count++;
	return ret;		
}

int add_node_front(node_t *nn)
{
	int ret = SUCCESS;

	if(start == NULL) {
		start = nn;
	}
	else {
		nn->next = start;
		start = nn;
	}
	
	return ret;
}

int add_node_middle(node_t *nn)
{
	int i, pos, ret = SUCCESS;
	node_t *temp1 = start, *temp2 = NULL;

	if(start == NULL) {
		start = nn;
		return ret;
	}
	else {
		printf("\nEnter the position:");
		scanf("%d",&pos);
		if((0 < pos)&&(pos <= count)) {
			for(i=0;i<pos;i++) {
				temp2 = temp1;
				temp1 = temp1->next;
			}
			temp2->next = nn;
			nn->next = temp1;
			printf("Inserted after %dth node\n",pos);				
		}
		else {
			printf("Node not inserted, Enter the valid position !!!\n");
			free(nn);
			nn = NULL;
			--count;
		}
	}

	return ret;
}

int add_node_end(node_t *nn)
{
	int i, ret = SUCCESS;
	node_t *temp1 = start; // *temp2 = NULL;

	if(start == NULL) {
		start = nn;
		return ret;
	}
	else {
/*
		for(i=0;i<count;i++) {
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = nn;
		nn->next = temp1;	//Comment: temp1 would be NULL.
*/
		while(temp1->next != NULL)
			temp1 = temp1->next;
	
		temp1->next = nn;
	}

	return ret;
} 

int delete_node()
{
	int ch, ret = SUCCESS;

	if(start == NULL) {
		printf("The list is empty can't able to delete !!!\n");
		return ret;
	}

	printf("\n\nIn Delete node:\n\t1.Delete node at front\n\t2.Delete node at middle\n\t3.Delete node at end\nEnter your choice:");
	scanf("%d",&ch);

	switch(ch) {
		case 1: ret = delete_node_front();
				break;
		case 2: ret = delete_node_middle();
				break;
		case 3: ret = delete_node_end();
				break;
		default:
				printf("Enter valid option !!!\n");
	}

	return ret;	
}

int delete_node_front()
{
	int ret = SUCCESS;
	node_t *temp1 = start, *temp2 = NULL;

	if(start != NULL) {
		temp2 = temp1->next;
		start = temp2;
	}
	free(temp1);
	temp1 = NULL;

	--count;
	return ret;
}

int delete_node_middle()
{
	int i, pos, ret = SUCCESS;
	node_t *temp1 = start, *temp2 = NULL;

	if(count == 1) {
		free(start);
		start = NULL;
	}
	else {
		printf("Enter the node position to delete: ");
		scanf("%d",&pos);

		if((0<pos)&&(pos<count)) {
			for(i=0;i<pos;i++) {
				temp2 = temp1;
				temp1 = temp1->next;
			}
			temp2->next = temp1->next;
			free(temp1);
			temp1 = NULL;
		}
		else {
			printf("Enter the valid postion!!!\n");
			return ret;
		}
	}
	
	--count;
	return ret;
}

int delete_node_end()
{
	int i, ret = SUCCESS;
	node_t *temp1 = start, *temp2 = NULL;
	
	if(count == 1) {
		free(start);
		start = NULL;
	}
	else {
		for(i=0; i<count-1; i++) {
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = NULL;
		free(temp1);
		temp1 = NULL;
	}

	--count;
	return ret;
}

int display()
{
	int ret = SUCCESS;
	node_t *node = start;
	printf("\nIn Display node:\nTotal Number of nodes: %d\n",count);

	if(start == NULL) {
		printf("Single Linked List is empty !!!\n");
		return ret;
	}

	while(node != NULL) {
		printf(" %d->",node->data);
		if(node->next == NULL) {
			printf("\n");
			return ret;
		}
		else {
			node = node->next;
		}		
	}
}

int reverse_link()
{
	int ret = SUCCESS;
	node_t *temp1 = NULL, *temp2 = NULL;
	printf("\nIn Reverse the Linked List:\n");

	if(start == NULL) {
		printf("Single Linked List is empty !!!\n");
		return ret;
	}	

	while(start != NULL) {
		temp1 = start;
		start = start->next;
		temp1->next = temp2;
		temp2 = temp1;
	}
	start = temp2;

	printf("Reversed List:\n");
	while(temp2 != NULL) {
		printf(" %d->",temp2->data);
		if(temp2->next == NULL) {
			printf("\n");
			return ret;
		}
		else {
			temp2 = temp2->next;
		}
	}	
}


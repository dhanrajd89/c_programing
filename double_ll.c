#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define FAILURE 0

struct dlist
{
	void *data;
	struct dlist *next;
	struct dlist *prev;
};

struct dlist *head = NULL;
struct dlist *tail = NULL;


int add_list(void *data)
{
	struct dlist *new_node = calloc(1,sizeof(struct dlist));
	if(new_node == NULL)
	{
		return FAILURE;
	}

	new_node->data = data;
	if(head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->prev = tail;
		tail->next = new_node;
	}

	return SUCCESS;
}

void print_int(void *data)
{
	int *ptr = data;
	printf("%d->\n",*ptr);
}

void print_forward(void (*callback)(void *))
{
	struct dlist *temp = head;
	
	while(temp != NULL)
	{
		callback(temp->data);
		temp = temp->next;
	}

}

int main()
{
	int a1 = 10; 
	int a2 = 20;
	int ret;

	ret = add_list(&a1);
	ret = add_list(&a2);

	print_forward(print_int);
}


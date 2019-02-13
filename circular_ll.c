#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

struct clist 
{
	void *data;
	struct clist *next;
};

struct clist *head = NULL;
struct clist *tail = NULL;


int add_clist(void *data)
{
	struct clist *new_node = calloc(1,sizeof(struct clist));
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
		tail->next = new_node;
		tail = new_node;
		new_node->next = head;
	}

	return SUCCESS;
}

void print_int(void *data)
{
	int *ptr = data;
	printf("%d->\n",*ptr);
}

void print_clist(void (*callback)(void *data))
{
	struct clist *temp = head;

	do
	{
		callback(temp->data);
		temp = temp->next;

	}while(temp != head);

}


int main()
{
	int a1 = 10, a2 = 20;
	int ret;

	ret = add_clist(&a1);
	ret = add_clist(&a2);

	print_clist(print_int);
	

	return 0;
}

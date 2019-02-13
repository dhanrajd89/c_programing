#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define FAILURE 0

struct list {
    void *data;
    struct list *next;
};
struct list *head = NULL;
struct list *tail = NULL;

int add_tail(void *data)
{
	struct list *new_node = calloc(1,sizeof(struct list));
	if(new_node == NULL)
	{
		printf("error in memory allocation.......\n");
		return 0;
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
	}
	

	return SUCCESS;
}

void print_list(void (*callback)(void *))
{
	struct list *temp = head;

	while(temp!=NULL)
	{
		callback(temp->data);
		temp = temp->next;
	}
}

/*
void del_item(void *data, void (*callback)(void *data))
{
}
*/



void *find_item(void *data, int (*callback)(void *, void *))
{
	struct list *temp = head;
	
	if(head == NULL)
	{
		printf("List is empty .......\n");
		return NULL;
	}

	while(temp != NULL)
	{
		if(callback(temp->data,data) == SUCCESS)
		{
			return temp->data;
		}
		temp = temp->next;
	}

	return NULL;
}

struct types
{
	int int_item;
	int int_set;
	int str_set;
	char *str_item;
};

int compare_types(void *item, void *data)
{
	if(item == data)
		return SUCCESS;
	else
		return FAILURE;	
}

void print_types(void *data)
{
	struct types *ptr = data;
	
	if(ptr->int_set)
	{
		printf("%d->\n",ptr->int_item);
	}
	else if(ptr->str_set)
	{
		printf("%s->\n",ptr->str_item);
	}
}

int main()
{
	int ret, a1 = 1,a2 = 2;
	char *str1 = "print123";
	char *str2 = "data123";	
	void *address = NULL;
	
	struct types data1,data2,data3,data4;
	data1.int_item = a1;
	data1.int_set = 1;
	data1.str_set = 0;

	data2.int_item = a2;
	data2.int_set = 1;
	data2.str_set = 0;
	
	data3.str_item = str1;
	data3.str_set = 1;
	data3.int_set = 0;
	
	data4.str_item = str2;
	data4.str_set = 1;
	data4.int_set = 0;

	
	ret = add_tail(&data1);
	ret = add_tail(&data2);
	ret = add_tail(&data3);
	ret = add_tail(&data4);

	print_list(print_types);
	
	address = find_item(str1,compare_types);
	printf("%p\n",address);

}


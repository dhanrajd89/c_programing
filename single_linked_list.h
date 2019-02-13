/*Header file*/
#define SUCCESS 0
#define FAILURE -1

struct node{
    int     	data;
    struct node	*next;
};
typedef struct node node_t;

node_t *start = NULL;
int count; 

node_t *getnode();
int add_node();
int delete_node();
int display();
int add_node_front();
int add_node_middle();
int add_node_end();
int delete_node_front();
int delete_node_middle();
int delete_node_end();
int reverse_link();
int sort();


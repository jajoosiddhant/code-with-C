#include <stdint.h>
#include <stdbool.h>

struct Node
{
 int data;
 struct Node *next;
};

// Linked_list_base functions
bool push(struct Node **head, int data);
bool push_after(struct Node *prev_node, int data);
bool push_last(struct Node **head, int data);
void delete_all(struct Node **head);
void print_all(struct Node *head);
void reverse(struct Node **head);

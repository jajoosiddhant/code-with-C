#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


// Double pointer is only required in functions if the function involves changes to 
// the linked list which involves the head pointer.


/**
 * @brief Function to add a node at the start and make it the head of linked list.
 * 
 * @param head Linked list head pointer address
 * @param data The data to be stored in the new linked list node  
 * 
 * @return true for success
 * @return false for failure
 *
 * @note If Double pointer is not used, the data inside the structure cannot be accessed
 * from the main loop using the head pointer.
 */
bool push(struct Node **head, int data)
{
    bool status = true;
    struct Node *new_node = (struct Node *)(malloc(sizeof(struct Node)));
    if (new_node != NULL)
    {
        new_node->data = data;
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        printf("malloc failed\n");
        status = false;
    }

    return status;
}


/**
 * @brief Insert a node after the specified node
 * 
 * @param prev_node Linked list previous node pointer
 * @param data The data to be inserted in the new node
 * 
 * @return true for success
 * @return false for failure
 */
bool push_after(struct Node *prev_node, int data)
{
    bool status = true;
    if(prev_node == NULL)
    {
        printf("Cannot insert new node after NULL\n");
        status = false;
    }
    else
    {
        struct Node *new_node = (struct Node *)(malloc(sizeof(struct Node)));
        if (new_node != NULL)
        {
            new_node->data = data;
            new_node->next = prev_node->next;   
            prev_node->next = new_node;
        }
        else
        {
            printf("Malloc() failed\n");
            status = false;
        }
    }

    return status;   
}


/**
 * @brief Insert a node at the last
 * 
 * @param prev_node Linked list head pointer address
 * @param data The data to be inserted in the new node
 * 
 * @return true for success
 * @return false for failure
 */ 
bool push_last(struct Node **head, int data)
{

    bool status = true;
    struct Node *last_node = *head;
    struct Node *new_node = (struct Node *)(malloc(sizeof(struct Node)));
    if (new_node != NULL)
    {
        new_node->data = data;
        new_node->next = NULL;
        while(last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
    else
    {
        printf("Malloc() failed\n");
        status = false;        
    }
    return status;
}


/**
 * @brief Function to delete all the elements of linked List
 * 
 * @param head Linked list head pointer address
 */
void delete_all(struct Node **head)
{
    struct Node *current = *head;
    while(current != NULL)
    {
        *head = current->next;
        free(current);
        current = *head;
    }
    *head = NULL;
}


/**
 * @brief Function to display all the data in the linked list
 * 
 * @param head Linked list head pointer
 */
void print_all(struct Node *head)
{
   struct Node *current = head;

   while(current != NULL)
   {
        printf("Print Data: %d\n", current->data);
        current = current->next;
   }
}


/**
 * @brief Function to reverse the linked list
 * 
 * @param head Linked List head pointer address
 */
void reverse(struct Node **head)
{
    struct Node *current = *head;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
    *head = prev;
}

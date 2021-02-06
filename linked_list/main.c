#include <stdio.h>
#include <stdlib.h>

#include "src/linked_list.h"


int main() 
{
    printf("Linked List Implementation\n");
    struct Node *head = NULL;

    push(&head, 3);
    push(&head, 5);
    push(&head, 7);
    push(&head, 9);
    print_all(head);
    // Linked list here should be 9->7->5->3
    printf("\n");
    
    delete_all(&head);
    //Linked list here should be empty

    push(&head, 12);   
    push(&head, 14);
    push_last(&head, 10);
    push_after(head->next, 11);
    print_all(head);
    // Linked list here should be 14->12->11->10
    printf("\n");

    reverse(&head);
    print_all(head);
    // Linked list here should be 10->11->12->14
    
    
    //This printf would give segmentation fault if double pointer is not used.
    //If Double pointer is not used, printfs can be done inside respective functions.
    //printf("Data: %d", head->data);
    

	return 0;
}
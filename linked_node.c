#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_node.h"

int add_to_list(linked_node** head, char* content)
{
	//Creation of a node that holds the data we're passing through
	//allocate memory on the heap for the node
	linked_node* node = malloc(sizeof(linked_node));
    //if malloc returns null then we ran into a problem and need to return -1
	if(node == NULL) {
		printf("error: could not allocate memory\n");
		return -1;
	}

	node->content = content;

	if(*head == NULL){
		*head = node;
		return 0;
	}

  linked_node* current_node = *head;

  // traverse until the end of the linked list
	while(current_node->next != NULL){
	 	current_node = current_node->next;
	}

	current_node->next = node;
	return 0;
}


void print_list (linked_node* head)
{
	if(head == NULL) printf("head is null\n");
	linked_node* current_node = head;
    printf("linked_node -> content\n");
	while(current_node != NULL) {
      printf("%x, %s\n", current_node, current_node->content);
		  current_node = current_node->next;
	}
	return ;
}


int delete_list(linked_node** head)
{
	if(*head == NULL) return -1;
	linked_node* current_node = *head;
	linked_node* next_node = current_node->next;
	while(next_node != NULL){
    printf("Current node to delete: %s\n", current_node->content);
    free(current_node->content);
		free(current_node);
		current_node = next_node;
		next_node = next_node->next;
	}
	*head = NULL;
	return 0 ;
}

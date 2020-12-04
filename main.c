#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_node.h"

int main() {
  // getchar();

  /*
    Dynamic memory versus static memory

    Different data structures - arrays versus linked lists
  */

  char array1[100] = "This string is not malloced.";
  for(int i  = 0; i < 10 /*array1[i] != 0*/; i++ ) {
    printf("Address of %c: %x\n", array1[i], &array1[i]);
    // printf("Address of %c: %s\n", array1[i], &array1[i]);
    // We get a fun output when we change the %x to an %s
    // Why is that the ouput?
  }


  /*
  It's a waste of space to always create a string using: char string[100]
  If the string will not be 99 characters long right?
  So we use malloc (memory allocate) to allocate space in the HEAP
  */

  // TODO: Go over sizeof, malloc
  char* list1 = malloc(sizeof(char)*11);
  list1 = "FARMER2024";
  printf("list1: %x, &list1: %x\n", list1, &list1);
  for(int i = 0; i < 11; i++){
    printf("Address in list: %c, %x\n", list1[i], &list1[i]);
  }

  linked_node* head = NULL;


  // TODO: Why am I passing a  &head instead of just head?
  add_to_list(&head, array1);

  //passing in a string from the stack
  print_list(head);


  //passing in a string from the heap
  add_to_list(&head, list1);

  print_list(head);

  delete_list(&head);

  print_list(head);

  // TODO: Delete the list
  return 0;
}

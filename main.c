#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"


int main() {

    // Init linked List    
    struct Linked_List list1 = LL_init("Hello World", (void*) "Hello World");
    LL_print(&list1);
    printf("\n");


    // insert into linked list
    int a = 123;
    LL_insert(&list1, "int a", (void*) &a);
    LL_print(&list1);
    printf("\n");


    int length1 = LL_length(&list1);
    printf("%d", length1);
    printf("\n");


    // find a Node in the linked list
    struct Node** node_list = LL_find(&list1, "Hello World");
    LL_insert_position(&list1, node_list[0], "Hello Update", (void*) "abc");
    LL_print(&list1);
    printf("\n");


    // update a Node from the linked list
    LL_update(&list1, node_list[0], "int b", NULL);
    LL_print(&list1);
    printf("\n");


    // Remove element from the list
    LL_remove(&list1, node_list[0]);
    LL_print(&list1);


    // free the linked list
    LL_free(&list1);


    return 0;
    
}
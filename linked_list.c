#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Linked_List LL_init(char* label, void* object) {

    struct Linked_List list;

    list.head = (struct Node*)malloc(sizeof(struct Node));

    if (list.head == NULL) {

        printf("List.head allocation error\n");
        exit(1);

    }

    list.head->label = label;
    list.head->object = object;

    return list;

}



void LL_free(struct Linked_List* list) {

    struct Node* current = list->head;
    struct Node* next;

    while (current != NULL) {

        next = current->next;
        free(current);
        current = next;

    }

    list->head = NULL;

}



void LL_print(struct Linked_List* list) {

    if (list->head == NULL) {
        printf("list.head == NULL\n");
        exit(1);
    }

    struct Node* current = list->head;

    while ( current != NULL) {

        char* label = (char*) current->label;

        printf("%s -> ", label);
        current = current->next;
    }

    printf("NULL");

}



void LL_insert(struct Linked_List* list, char* label, void* object) {

    if (list->head == NULL) {

        printf("List->head == NULL\n");
        exit(1);

    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {

        printf("NewNode allocation error\n");
        exit(1);

    }

    newNode->label = label;
    newNode->object = object;

    struct Node* current = list->head;

    while (current->next != NULL) {

        current = current->next;

    }

    current->next = newNode;

}



struct Node** LL_find(struct Linked_List* list,char* label) {

    int elements = 2;

    struct Node** results = NULL;

    struct Node* current =  list->head;

    while (current != NULL) {

        if ((strcmp(current->label, label) == 0)) {

            struct Node** temp_results = results;
            results = (struct Node**)malloc(elements * sizeof(struct Node*));

            if (results == NULL) {

                printf("Memory allocation error\n");
                exit(1);

            }

            for (int i = 0; i < elements-2; i++) {
    
                results[i] = temp_results[i]; 
            }

            results[elements-2] = current;
            results[elements-1] = NULL;

            free(temp_results);

            elements++;

        }

        current = current->next;

    }
    
    return results;
}



void LL_remove(struct Linked_List* list, struct Node* node) {

    struct Node* current = list->head;
    struct Node* previous = NULL;

    if (current == node) {

        struct Node* removed_node = list->head;
        list->head = list->head->next;
        free(removed_node);
        return;
    }

    previous = current;
    current = current->next;

    while (current != NULL) {

        if (current == node) {
            
            previous->next = current->next;
            free(current);
            return;
        }
    
        previous = current;
        current = current->next;

    }

    printf("Node not found\n");

}



void LL_update(struct Linked_List* list, struct Node* node, char* label, void* object) {

    struct Node* current = list->head;

    while (current != NULL) {

        if (current == node) {

            if (label != NULL) {
            
                current->label = label;
            
            }
            
            if (object != NULL) {
            
            current->object = object;
            
            }

            return;

        }

        current = current->next;
    
    }

    printf("Node not found\n");

}



int LL_length(struct Linked_List* list) {

    if (list->head == NULL) {
    
        return 0;
    }

    struct Node* current = list->head;
    int count = 0;


    while (current != NULL) {

        count++;


        current = current->next;
    }

    return count;

}


void LL_insert_position(struct Linked_List* list, struct Node* node, char* label, void* object) {

    struct Node* current = list->head;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        
        printf("Memory allocation error\n");
        return;

    }

    newNode->label = label;
    newNode->object = object;

    while (current != NULL) {

        if (current == node) {

            newNode->next = current->next;
            current->next = newNode;

        }

        current = current->next;

    }

}
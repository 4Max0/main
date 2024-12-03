#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {

    char* label;
    void* object;
    struct Node* next;

};


struct Linked_List {

    struct Node* head;

};


// returns struct type 'Linked_List', an object as a void* can be put in List
struct Linked_List LL_init(char* label, void* object);

// Free the memory allocated
void LL_free(struct Linked_List* list);

// print out the labels of the List
void LL_print(struct Linked_List* list);

// insert a new node into the list
void LL_insert(struct Linked_List* list, char* label, void* object);

// returns an array of void pointers pointing to Nodes with the fitting label
struct Node** LL_find(struct Linked_List* list,char* label);

// remove a Node from the List by providing a Node from the List
void LL_remove(struct Linked_List* list, struct Node* node);

// update a Node if provided Label or Object is NULL it doesn't change the element
void LL_update(struct Linked_List* list, struct Node* node, char* label, void* object);

// return the length of the linked list
int LL_length(struct Linked_List* list);

// insert at a certain position after a provided node
void LL_insert_position(struct Linked_List* list, struct Node* node, char* label, void* object);

#endif // LINKED_LIST_H
#include<stdio.h>
#include<stdlib.h>

/*
    Due to create a basic linked list and test it, there are at least 5 things we've to define:abort
    1. Define Linked List (Linked List Node & Linked List)
    2. Create a node
    3. Insert a new node at the end of the linked list
    4. Delete a node
    5. Print out
*/


// Define a linked list node
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Define a linked list
typedef struct List {
    Node *head;
} List;


// Create a New Node
Node* create_node(int value) {

    Node* new_node = (Node*)malloc(sizeof(Node));

    if(!new_node) {
        printf("Memory Allocation Failed");
        exit(1);
    }

    new_node->value = value;
    new_node->next = NULL;

    return new_node;
};

// Insert a new node at the end of the linked list
void insert_node(List *list, int value) {
    Node *new_node = create_node(value);

    if(list->head == NULL) {
        list->head = new_node;
    }else {
        Node *current = list->head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = new_node;
    }
};

// Delete a specific node
void remove_list_node(List *list, Node *target) {
    // Edge Case
    // Check if the list itself is NULL (i.e., it does not exist)
    if(list == NULL) {
        printf("Error: The linked list does not exist!\n");
        return;
    }
    // Check if the list is empty (i.e., it has no nodes)
    if(list->head == NULL) {
        printf("Error: The linked list is empty, nothing to remove!\n");
        return;
    }
    // Check if the target node is NULL
    if(target == NULL) {
        printf("Error: Cannot remove a NULL node!\n");
        return;
    }

    // Define two pointer to assist to delete the node
    Node *prev = NULL;
    Node *curr = list->head;

    // Traverse the node to find the target node
    while(curr != NULL && curr != target) {
        prev = curr;
        curr = curr->next;
    }

    // If the target node is not found in the list
    if(curr == NULL) {
        printf("Error: The target node is not in the linked list!\n");
        return;
    }

    // Remove the target node
    if(!prev) {
        // The target is the head node
        list->head = target->next;
    }else {
        // Bypass the target node
        prev->next = target->next;
    }

    // Free the memory of the removed node
    free(target);
};

// Print the Linked List
void print_list(List *list) {
    Node *curr = list->head;
    while(curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}


int main() {
    // Initialize the List Node
    List list;
    list.head = NULL;
    

    // Insert the node
    insert_node(&list, 1);
    insert_node(&list, 2);
    insert_node(&list, 3);
    insert_node(&list, 4);

    printf("Original Linked List:\n");
    print_list(&list);

    // Delete in the middle of the node such as node 3
    // Define a pointer to point node 3
    Node *target = list.head->next->next;
    printf("\n Delete the node 3: %d\n", target->value);
    remove_list_node(&list, target);
    print_list(&list);

    // Delete the first node (head)
    target = list.head;
    printf("\n Delete the first node: %d\n", target->value);
    remove_list_node(&list, target);
    print_list(&list);


    // Delete the last node
    // Because we have already delete two node, which means that our linked list looks like this:
    // 2 -> 4
    target = list.head->next;
    if (target->next != NULL) {
        printf("\n Delete the last node: %d\n", target->next->value);
        remove_list_node(&list, target->next);
    } else {
        printf("\n No node to delete!\n");
    }

    return 0;
}



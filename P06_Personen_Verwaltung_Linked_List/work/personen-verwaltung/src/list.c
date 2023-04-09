#include "person.h"
#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void addNode(node_t *root, const person_t personToAdd);
void removeNode(node_t *root, const person_t personToRemove);
void printNodes();
int getListSize();


static int size;

void addNode(node_t *root, const person_t personToAdd) {
    assert(root);    //necessary to check
    node_t *p = root;

    while(p->next) { //the root has value 0 and is therefore false, so the while loop works until the next element is the root
        if(person_compare(&personToAdd, &p->next->content) < 0) { //if the content of the next node is bigger then the content to add insert new element
            node_t *next = p->next; //save the address of the node which was previously after the current node
            p->next = malloc(sizeof(node_t));
            if(p->next) {                             
                *(p->next) = (node_t) {personToAdd, next}; //assign the address of the above saved address as next element
            }
            size++;
            printf("Person added successfully.");
            return; //exit the function
        } else {
            p = p->next;
        }
    }
    p->next = malloc(sizeof(node_t)); //memory space for the new node is reserved/allocated
        if(p->next) {                     //check if space was available, since it can be possible that there is not enough space
            *(p->next) = (node_t) {personToAdd, NULL}; //saving the value in the allocated memory space
            size++;
            printf("Person added successfully.");
        }
}

void removeNode(node_t *root, const person_t personToRemove) {
    assert(root);
    node_t *p = root;
    while(p->next) {
        if(person_compare(&personToRemove, &p->next->content) == 0) {
            node_t *next = p->next->next;
            free(p->next);
            p->next = next;
            size--;
            printf("Person deleted successfully!");
            return;
        } else {
            p = p->next;
        }
    }
    printf("Person is not in the list!");
    return;
}

void clearList(node_t *root) {
    assert(root);
    node_t *p = root->next;
    node_t *pP = root->next;

    while(p->next) {
        pP = p->next;
        free(&p->content);
        p = pP;      
    }
    root->next = NULL;
    size=0;
    printf("List cleared successfully!");
}


void printNodes(node_t *root) {
    node_t *p = root;

    while(p->next) {
        printf("Name: %s, Surname: %s, Age: %d \n",
            p->next->content.name,
            p->next->content.first_name,
            p->next->content.age);
        p = p->next;
    }
}

int getListSize() {
    return size;
}

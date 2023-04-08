#include "person.h"
#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void addNode(person_t person);
bool isListEmpty();
void printNodes();

void addNode(person_t person) {
    node_t currentNode = anchor;
    isListEmpty();
    if(isListEmpty()) {
        anchor.next = malloc(sizeof(node_t));
        *anchor.next = (node_t) {person, NULL};
        printf("%s", anchor.next->content.name); //anchor.next is a pointer
    } 
}

bool isListEmpty() {
    printf("anchor.next pointer: %d, anchor pointer: %d", anchor.next, &anchor);
    if(anchor.next == &anchor) {
        printf("worksbool");
        return true;
    } else {
        return false;
    }
}

void printNodes() {
    node_t currentNode = anchor;
    /*while(currentNode.next != &anchor) {
        printf("Name: %s, Surname: %s, Age: %d ", 
            currentNode.content.first_name, 
            currentNode.content.name, 
            currentNode.content.age);
    }*/
}

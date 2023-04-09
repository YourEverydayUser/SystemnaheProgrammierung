#ifndef _CONTROL_H_
#define _CONTROL_H_
#include "person.h"

typedef struct node {
  person_t     content;        
  struct node *next;           
} node_t;

void addNode(node_t *root, const person_t person);
void printNodes(node_t *root);
void removeNode(node_t *root, const person_t personToRemove);
void clearList(node_t *root);
int getListSize();

#endif
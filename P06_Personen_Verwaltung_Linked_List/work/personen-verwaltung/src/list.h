#ifndef _CONTROL_H_
#define _CONTROL_H_
#include "person.h"

typedef struct node {
  person_t     content;        
  struct node *next;           
} node_t;

static node_t anchor = {NULL, &anchor};

void addNode(person_t person);
void printNodes();

#endif
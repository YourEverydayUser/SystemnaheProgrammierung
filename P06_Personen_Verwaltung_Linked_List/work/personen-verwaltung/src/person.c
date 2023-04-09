#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "person.h"

int person_compare(const person_t *a, const person_t *b);
void print_Person(const person_t *p);


int person_compare(const person_t *a, const person_t *b) {
    person_t p1 = *a;
    person_t p2 = *b;

    if(strncmp(p1.name, p2.name, 20) == 0) {
        if(strncmp(p1.first_name, p2.first_name, 20) == 0) {
            if(p1.age == p2.age) {
                return 0;
            } else {
                if(p1.age > p2.age) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            return strncmp(p1.first_name, p2.first_name, 20);
        }
    } else {
        return strncmp(p1.name, p2.name, 20);
    }
}

void print_Person(const person_t *p) {
    assert(p);
    
    printf("Name: %s, Surname: %s, Age: %d \n",
            p->name,
            p->first_name,
            p->age);
}
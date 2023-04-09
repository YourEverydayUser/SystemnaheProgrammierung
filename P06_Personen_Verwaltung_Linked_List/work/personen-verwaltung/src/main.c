/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "person.h"
#include <assert.h>
#include <string.h>

static node_t anchor;

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */


int main(int argc, char* argv[])
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	node_t *aP = 0; //we need a pointer which shows to the adress of the anchor
	aP = &anchor;  //and since the anchor is initialized above, we set the address here
	
	char c;

	while(c = getchar() != 'e') {
		c = getchar();
		
		switch (c)
		{
		case 'i':
			person_t *personToAdd = malloc(sizeof(person_t));
			if(personToAdd) {
				printf("Please enter the name: \n");
				scanf("%20s", personToAdd->name);
				printf("Please enter the surname: \n");
				scanf("%20s", personToAdd->first_name);
				printf("Please enter the age: \n");
				scanf("%u", &personToAdd->age); //why is there a segmentation fault (core dumped) when i don't put the & before personToAdd
				addNode(aP, *personToAdd);
			}
			break;
		
		case 'r':
			char name[NAME_LEN], surname[NAME_LEN];
			unsigned int age;
			printf("Please enter the name: \n");
			scanf("%20s", name);
			printf("Please enter the surname: \n");
			scanf("%20s", surname);
			printf("Please enter the age: \n");
			scanf("%u", &age);
			person_t personToRemove = {name, surname, age};
			removeNode(aP, personToRemove);
			break;

		case 's':
			printf("Content of the List: \n");
			printNodes(aP);
			break;

		case 'c':
			clearList(aP);
			break;

		case 'e':
			printf("Bye");
			return EXIT_SUCCESS;

		default:
			printf("Please enter one of the following commands: \n");
			printf("i = insert a new person into the list \nr = remove a person from the list \n");
			printf("s = print the whole list \nc = clear the list \ne = end the program");
			break;
		}
	}
}

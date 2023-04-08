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

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
void test(node_t node);

int main(int argc, char* argv[])
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	test(anchor);

	person_t p1 = {"Kuster", "Fabian", 28};
	person_t p2 = {"Fritz", "Sybille", 30};
	person_t p3 = {"Hansmann", "Danai", 28};

	addNode(p1);
	addNode(p2);
	addNode(p3);
	printNodes();
    
	// END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}

void test(node_t node) {
	
	if(*node.content.name != '\0') { //dereference pointer and get element @ node.content.name
		printf("%s", node.content.name);
	} else {
		printf("This is the root");
	}
}

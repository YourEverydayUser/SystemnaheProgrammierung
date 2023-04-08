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

node_t anchor;

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
	person_t person = {"Kuster", "Fabian", 28};
	node_t anchor = {person, 1250};
	test(anchor);
    
	// END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}

void test(node_t node) {
	printf("%s", node.content.name);
}

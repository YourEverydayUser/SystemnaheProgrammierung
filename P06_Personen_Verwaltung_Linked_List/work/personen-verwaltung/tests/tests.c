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
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <assert.h>
#include <CUnit/Basic.h>
#include "test_utils.h"
#include "/home/vagrant/snp_solutions/git@github.com:YourEverydayUser/SystemnaheProgrammierung.git/P06_Personen_Verwaltung_Linked_List/work/personen-verwaltung/src/person.h"
#include "/home/vagrant/snp_solutions/git@github.com:YourEverydayUser/SystemnaheProgrammierung.git/P06_Personen_Verwaltung_Linked_List/work/personen-verwaltung/src/list.h"



#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief alias for EXIT_SUCCESS
#define OK   EXIT_SUCCESS
/// @brief alias for EXIT_FAILURE
#define FAIL EXIT_FAILURE

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

#define TRACE_INDENT "\n                " ///< allow for better stdout formatting in case of error

static node_t anchor;

// setup & cleanup
static int setup(void)
{

    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    return 0; // success
}

static int teardown(void)
{
    // Do nothing.
    // Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
    return 0; // success
}

// tests
static void test_person_compare(void)
{
	// arrange
	person_t p1 = {"Kuster", "Fabian", 28};
	person_t p2 = {"Fritz", "Sybille", 30};
	// act
	CU_FAIL("missing test");
	int test = person_compare(&p1, &p2);
	// assert
	assert(test < 0);
}

static void test_list_insert(void)
{
	// arrange
	person_t p5 = {"Clemens", "Karl", 20};
	person_t p6 = {"Reinhard", "Michael", 30};
	node_t *aP = 0;
	aP = &anchor;

	// act
	CU_FAIL("missing test");
	addNode(aP, p5);
	addNode(aP, p6);
	// assert
	assert(getListSize() == 2);
	
}

static void test_list_remove(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	person_t p5 = {"Clemens", "Karl", 20};
	person_t p6 = {"Reinhard", "Michael", 30};
	node_t *aP = 0;
	aP = &anchor;

	// act
	CU_FAIL("missing test");
	addNode(aP, p5);
	addNode(aP, p6);
	removeNode(aP, p5);
	
	// assert
	assert(getListSize() == 1);
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_clear(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	person_t p1 = {"Kuster", "Fabian", 28};
	person_t p2 = {"Fritz", "Sybille", 30};
	person_t p3 = {"Hansmann", "Danai", 28};
	person_t p4 = {"Steiner", "Tobias", 25};
	person_t p5 = {"Clemens", "Karl", 20};
	person_t p6 = {"Kuster", "Michael", 30};
	node_t *aP = 0;
	aP = &anchor;

	// act
	CU_FAIL("missing test");
	addNode(aP, p1);
	addNode(aP, p2);
	addNode(aP, p3);
	addNode(aP, p4);
	addNode(aP, p5);
	addNode(aP, p6);
	clearList(aP);
	
	// assert
	assert(getListSize()==0);
	// END-STUDENTS-TO-ADD-CODE
}

/**
 * @brief Registers and runs the tests.
 * @returns success (0) or one of the CU_ErrorCode (>0)
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("lab test", setup, teardown
                  , test_person_compare
                  , test_list_insert
                  , test_list_remove
                  , test_list_clear
                  );
}

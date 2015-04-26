/**
 * \file    formats.h
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Definitions for test results formats
 * 
 */

#ifndef FORMATS_H_
#define	FORMATS_H_

#include "outputs.h"
#include "testbench.h"


/**
 * \brief Write test result
 * 
 * \param[in] test_name String describing the test
 * \param[in] result    Result of the test 0 = failed, 1 = passed 
 */
void testbench_log(
    const char * test_name,
    int result
);

/**
 * \brief Print header of a test
 * 
 * This function will cause the header to be printed, if the name parameter is 
 * zero-pointer, the initial message will be printed out.
 * 
 * \param[in] name Name of the test
 */
void testbench_begin_test(
    const char * name
);

/**
 * \brief Print footer of a test
 * 
 * This function will cause the footer to be printed, if the name parameter is 
 * zero-pointer, the summary message will be printed out.
 * 
 * \param[in] name      Name of the test
 * \param[in] passed    Number of passed tests
 * \param[in] failed    number of failed tests
 */
void testbench_end_test(
    const char * name,
    unsigned passed,
    unsigned failed
);


#endif	/* FORMATS_H_ */


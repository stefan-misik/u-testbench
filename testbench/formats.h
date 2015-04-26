/**
 * \file    formats.h
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Definitions for test results formats
 * 
 */

#ifndef FORMATS_H_
#define	FORMATS_H_

#include "outputs.h"


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


#endif	/* FORMATS_H_ */


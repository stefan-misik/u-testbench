/**
 * \file    testbench.h
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Main header file of the u-testbench
 * 
 */

#ifndef TESTBENCH_H_
#define	TESTBENCH_H_

#include "formats.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
/**
 * \brief Compare two numbers
 */
#define testbench_eq(test_name, a, b)               \
    testbench_result(                               \
        this_test,                                  \
        test_name,                                  \
        (a) == (b))         

/**
 * \brief Compare two numbers
 */
#define testbench_neq(test_name, a, b)              \
    testbench_result(                               \
        this_test,                                  \
        test_name,                                  \
        (a) != (b))         

/**
 * \brief Compare two floating point numbers
 */
#define testbench_eq_tol(test_name, a, b, tol)      \
    testbench_eq_tol_hidden(                        \
        this_test,                                  \
        test_name,                                  \
        a, b, tol)
   
/**
 * \brief Compare two floating point numbers
 */
#define testbench_neq_tol(test_name, a, b, tol)     \
    testbench_neq_tol_hidden(                       \
        this_test,                                  \
        test_name,                                  \
        a, b, tol)

/**
 * \brief Macro to create test function and its structure
 */
#define TESTBENCH_TEST(test_name, test_name_str)    \
    static void test_name ## _testbench_fcn(        \
        testbench_test_t * this_test                \
    );                                              \
    testbench_test_t testbenchtest_ ## test_name =  \
    {                                               \
        .name = (test_name_str),                    \
        .passed = 0,                                \
        .failed = 0,                                \
        .test_fcn = test_name ## _testbench_fcn     \
    };                                              \
    static void test_name ## _testbench_fcn(        \
        testbench_test_t * this_test                \
    )                                               
    

/**
 * \brief Structure containing information on each test
 */    
typedef struct testbench_test
{
    const char *    name;
    unsigned        passed;
    unsigned        failed;    
    void (*test_fcn)(struct testbench_test *);
} testbench_test_t;


/**
 * \brief write test result directly
 * 
 * \param[in] test_name String describing the test
 * \param[in] result    Result of the test 0 = failed, 1 = passed 
 */
void testbench_result(
    testbench_test_t * this_test,
    const char * test_name,
    int result
);

/**
 * \brief Compare two floating point numbers with tolerance
 * 
 * \param[in] test_name String describing the test
 * \param[in] a         Number A
 * \param[in] b         Number B
 * \param[in] tol       Tolerance, must be positive number
 */
void testbench_eq_tol_hidden(
    testbench_test_t * this_test,
    const char * test_name,
    double a,
    double b,
    double tol
);

/**
 * \brief Compare two floating point numbers with tolerance
 * 
 * \param[in] test_name String describing the test
 * \param[in] a         Number A
 * \param[in] b         Number B
 * \param[in] tol       Tolerance
 */
void testbench_neq_tol_hidden(
    testbench_test_t * this_test,
    const char * test_name,
    double a,
    double b,
    double tol
);

#ifdef	__cplusplus
}
#endif

#endif	/* TESTBENCH_H_ */


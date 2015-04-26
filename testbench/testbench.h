/**
 * \file    testbench.h
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Main header file of the u-testbench
 * 
 */

#ifndef TESTBENCH_H_
#define	TESTBENCH_H_

#ifdef	__cplusplus
extern "C" {
#endif
    
/**
 * \brief Macro to create test function and its structure
 */
#define TESTBENCH_TEST(test_name)                   \
    static void test_name ## _fcn(                  \
        testbench_test_t * this_test                \
    );                                              \
    testbench_test_t testbenchtest_ ## test_name =  \
    {                                               \
        .name = #test_name,                         \
        .passed = 0,                                \
        .failed = 0,                                \
        .test_fcn = test_name ## _fcn               \
    };                                              \
    static void test_name ## _fcn(                  \
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





#ifdef	__cplusplus
}
#endif

#endif	/* TESTBENCH_H_ */


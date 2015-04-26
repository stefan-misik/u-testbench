/**
 * \file    testbench.c
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Testbench core
 * 
 */

#include "testbench.h"


extern testbench_test_t * testbench_testlist[];


/******************************************************************************/
int main(
    int     argc,
    char ** argv)
{
    testbench_test_t ** pos = testbench_testlist;
    unsigned passed, failed;
    passed = 0;
    failed = 0;
    
    /* Iterate through all the tests */
    while(0 != (*pos))
    {
        /* Perform test */
        (*pos)->test_fcn(*pos);
        
        /* Count results */
        passed += (*pos)->passed;
        failed += (*pos)->failed;
        
        /* Move to another test */
        pos ++;
    }
    
    return 0;
}

/******************************************************************************/
void testbench_result(
    testbench_test_t * this_test,
    const char * test_name,
    int result
)
{
    testbench_log(test_name, result);
    
    if(result)
    {
        this_test->passed++;
    }
    else
    {
        this_test->failed++;
    }
}

/******************************************************************************/
void testbench_eq_tol(
    testbench_test_t * this_test,
    const char * test_name,
    double a,
    double b,
    double tol
)
{
    double res;
    
    /* Calculate distance */
    res = a - b;
    
    /* Log results */
    testbench_result(
        this_test,
        test_name,
        (res <= tol) && (res >= -tol)
    );    
}

/******************************************************************************/
void testbench_neq_tol(
    testbench_test_t * this_test,
    const char * test_name,
    double a,
    double b,
    double tol
)
{
    double res;
    
    /* Calculate distance */
    res = a - b;
    
    /* Log results */
    testbench_result(
        this_test,    
        test_name,
        (res > tol) || (res < -tol)
    );    
}
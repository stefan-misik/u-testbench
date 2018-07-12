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
    
    /* Initialize output */
    testbench_output_init();
    
    /* Initialize format */
    testbench_format_init();
    
    /* Print header */
    testbench_begin_test(
        (const char *)0
    );
    
    /* Iterate through all the tests */
    while(0 != (*pos))
    {
        /* Print header */
        testbench_begin_test(
            (*pos)->name
        );
        
        /* Perform test */
        (*pos)->test_fcn(*pos);
        
        /* Print footer */
        testbench_end_test(
            (*pos)->name,
            (*pos)->passed,
            (*pos)->failed
        );
        
        /* Count results */
        passed += (*pos)->passed;
        failed += (*pos)->failed;        
        
        /* Move to another test */
        pos ++;
    }
    
    /* Print footer */
    testbench_end_test(
        (const char *)0,
        passed,
        failed
    );
    
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
void testbench_eq_tol_hidden(
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
void testbench_neq_tol_hidden(
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
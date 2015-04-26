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
    
    while(0 != (*pos))
    {
        (*pos)->test_fcn(*pos);
        pos ++;
    }
    
    return 0;
}

/******************************************************************************/
void testbench_result(
    const char * test_name,
    int result
)
{
    testbench_log(test_name, result);
}

/******************************************************************************/
void testbench_eq_tol(
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
    testbench_log(
        test_name,
        (res <= tol) && (res >= -tol)
    );    
}

/******************************************************************************/
void testbench_neq_tol(
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
    testbench_log(
        test_name,
        (res > tol) || (res < -tol)
    );    
}
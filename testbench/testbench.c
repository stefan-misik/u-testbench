/**
 * \file    testbench.c
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Testbench core
 * 
 */

#include "testbench.h"
#include "formats.h"
#include "outputs.h"

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
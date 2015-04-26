/**
 * \file    standard.h
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Implementation of stdout test results output
 * 
 */

#include "../outputs.h"
#include <stdio.h>

/******************************************************************************/
void testbench_output_init(
    void
)
{
    
}

/******************************************************************************/
void testbench_write(
    const char * buf,
    unsigned len
)
{
    while(len > 0)
    {
        putchar(*(buf++));
        len--;
    }
}

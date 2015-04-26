/**
 * \file    text.c
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Test results formatter into plain text
 * 
 */

#include "../formats.h"

/**
 * \brief Width of console in characters
 */
#define CONSOLE_WIDTH 80

/**
 * \brief Passed string
 */
static const char output_passed[] = "PASS";

/**
 * \brief Failed string
 */
static const char output_failed[] = "FAIL";

/**
 * \brief 
 */
static char output_separator[CONSOLE_WIDTH + 1];


/******************************************************************************/
unsigned testbench_strlen(
    const char * str
)
{
    unsigned ret = 0;
    
    while(*str)
    {
        ret++;
        str++;
    }
    
    return ret;
}

/******************************************************************************/
void testbench_format_init(
    void
)
{
    unsigned i;
    
    /* Initialize separator */
    for(i = 0; i < ((sizeof(output_separator) / sizeof(char)) - 1); i++)
    {
        output_separator[i] = '*';
    }
    output_separator[i] = '\n';
}

/******************************************************************************/
void testbench_log(
    const char * test_name,
    int result
)
{
    
}

/******************************************************************************/
void testbench_begin_test(
    const char * name
)
{
    if(name)
    {
        testbench_write(
            name, 
            testbench_strlen(name)
        );
        
        testbench_write("\n", 1);
    
        testbench_write(
            output_separator,
            (sizeof(output_separator) / sizeof(char))
        );
    }    
}

/******************************************************************************/
void testbench_end_test(
    const char * name,
    unsigned passed,
    unsigned failed
)
{
    
}
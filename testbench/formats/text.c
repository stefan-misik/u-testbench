/**
 * \file    text.c
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Test results formatter into plain text
 * 
 */

#include "../formats.h"
#include <stdio.h>
#include <string.h>

/**
 * \brief Width of console in characters
 */
#define CONSOLE_WIDTH 80

/**
 * \brief Maximum digits of PASS/FAIL counts
 */
#define PASS_FAIL_CNT_LEN 10


/**
 * \brief Passed string
 */
static const char output_passed[] = "PASS";
/**
 * \brief Failed string
 */
static const char output_failed[] = "FAIL";

/**
 * \brief Output separator 1
 * 
 * The first character of the initializer will be repeated over the whole
 * console width.
 */
static char output_separator_1[CONSOLE_WIDTH + 1] = "=";

/**
 * \brief Output separator 2
 * 
 * The first character of the initializer will be repeated over the whole
 * console width.
 */
static char output_separator_2[CONSOLE_WIDTH + 1] = "-";

/**
 * \brief Passed string length
 */
static unsigned output_passed_len;
/**
 * \brief Failed string length
 */
static unsigned output_failed_len;



/******************************************************************************/
void testbench_format_init(
    void
)
{
    unsigned i;
    
    /* Initialize separator */
    for(i = 1; i < CONSOLE_WIDTH; i++)
    {
        output_separator_1[i] = output_separator_1[0];
        output_separator_2[i] = output_separator_2[0];
    }
    output_separator_1[i] = '\n';
    output_separator_2[i] = '\n';
    
    /* String lengths */
    output_passed_len = strlen(output_passed);
    output_failed_len = strlen(output_failed);
}

/******************************************************************************/
void testbench_log(
    const char * test_name,
    int result
)
{
    unsigned test_name_len, result_str_len;
    int spaces_count, i;
    const char * result_str;
    
    /* String lengths */
    test_name_len = strlen(test_name);
    result_str_len = result ? output_passed_len : output_failed_len;
    /* Result string */
    result_str = result ? output_passed : output_failed;

    if((test_name_len + result_str_len + 1) > CONSOLE_WIDTH)
    {
        test_name_len = CONSOLE_WIDTH - result_str_len - 1;
    }
    
    /* Print test name, or portion of it */
    testbench_write(test_name, test_name_len);
    
    /* Print spaces */
    spaces_count = CONSOLE_WIDTH - (test_name_len + result_str_len);
    for(i = 0; i < spaces_count; i++)
        testbench_write(" ", 1);
    
    /* Print result */
    testbench_write(result_str, result_str_len);
    
    /* Print new line */
    testbench_write("\n", 1);
}

/******************************************************************************/
void testbench_begin_test(
    const char * name
)
{
    if(name)
    {
        /* Print first separator */
        testbench_write(
            output_separator_1,
            (sizeof(output_separator_1) / sizeof(char))
        );
    
        /* Print test name */
        testbench_write(
            name, 
            strlen(name)
        );
        testbench_write("\n", 1);
        
        /* Print second separator */
        testbench_write(
            output_separator_2,
            (sizeof(output_separator_2) / sizeof(char))
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
    char buffer[PASS_FAIL_CNT_LEN + 8];
    int buffered_chars;
    
    /* Print separator */
    if(name)
    {
        testbench_write(
            output_separator_1,
            (sizeof(output_separator_1) / sizeof(char))
        );
    }
    else
    {
        testbench_write(
            output_separator_1,
            (sizeof(output_separator_1) / sizeof(char))
        );
        testbench_write(
            output_separator_1,
            (sizeof(output_separator_1) / sizeof(char))
        );
    }
    
    /* Print summary */
    testbench_write(output_passed, output_passed_len);
    buffered_chars = sprintf(buffer, ":  %u\n", passed);
    testbench_write(buffer, buffered_chars);
    testbench_write(output_failed, output_failed_len);
    buffered_chars = sprintf(buffer, ":  %u\n", failed);
    testbench_write(buffer, buffered_chars);
    
    if(name)
    {
        testbench_write("\n", 1);
    }
}
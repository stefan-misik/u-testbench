#include "../testbench/testbench.h"

/* Test begins here */
TESTBENCH_TEST(empty_test, "An empty test")
{
        
    testbench_eq("Passed test test", 5, 5);
    testbench_neq("Failed test", 5, 5);
    
    testbench_eq_tol("Failed FP test", 5.5, 5.6, 0.01);
    testbench_neq_tol("Passed FP test", 5.5, 5.6, 0.01);
}

/* Test begins here */
TESTBENCH_TEST(empty_test_2, "An empty test 2")
{
        
    testbench_eq("Passed test test", 5, 5);
    testbench_neq("Failed test", 5, 5);
    
    testbench_eq_tol("Failed FP test", 5.5, 5.6, 0.01);
    testbench_neq_tol("Passed FP test", 5.5, 5.6, 0.01);
    
    testbench_eq_tol("Failed FP test", 5.5, 5.6, 0.01);
    testbench_neq_tol("Passed FP test", 5.5, 5.6, 0.01);
}
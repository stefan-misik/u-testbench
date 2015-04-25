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
    
typedef struct
{
    const char * name;
    unsigned passed;
    unsigned failed;    
    void (*test_fcn)(void);
} testbench_test_t;




#ifdef	__cplusplus
}
#endif

#endif	/* TESTBENCH_H_ */


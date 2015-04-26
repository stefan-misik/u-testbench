/**
 * \file    outputs.h
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Definitions for test results outputs (file, serial, etc.)
 * 
 */

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

/**
 * \brief Write single byte to the test result output stream
 * 
 * \param[in] c Character to be written
 */
void testbench_putchar(
    char c
);

#endif /* OUTPUTS_H_ */
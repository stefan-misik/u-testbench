/**
 * \file    outputs.h
 * \author  Stefan Misik (mail@stefanmisik.eu)
 * \brief   Definitions for test results outputs (file, serial, etc.)
 * 
 */

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

/**
 * \brief Output stream initializer
 */
void testbench_output_init(
    void
);

/**
 * \brief Write buffer into output stream
 * 
 * \param[in] buf   Buffer containig data to be written
 * \param[in] len   Number of characters to be written
 */
void testbench_write(
    const char * buf,
    unsigned len
);

#endif /* OUTPUTS_H_ */
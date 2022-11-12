/*
 * dbg_print.h
 *
 *  Created on: Nov 12, 2022
 *      Author: almaz
 */

#ifndef DBGOUT_H_
#define DBGOUT_H_


#define DBGOUT_TX_BUFFER_SIZE   (64U) // transmit buffer size

int dbgout_init(void);

void dbgout_print(const char* format, ...);


#endif /* APP_DBG_PRINT_H_ */

/*
 * supporting_functions.h
 *
 *  Created on: Aug 4, 2023
 *      Author: WON1COB
 */

#ifndef INC_SUPPORTING_FUNCTIONS_H_
#define INC_SUPPORTING_FUNCTIONS_H_

void vPrintString( const char *pcString );
void vPrintStringAndNumber( const char *pcString, uint32_t ulValue );
void vPrintTwoStrings( const char *pcString1, const char *pcString2 );
void vApplicationMallocFailedHook( void );
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
void vApplicationTickHook( void );
void vAssertCalled( uint32_t ulLine, const char * const pcFile );

#endif /* INC_SUPPORTING_FUNCTIONS_H_ */

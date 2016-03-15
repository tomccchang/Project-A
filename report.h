/*
 * Output sensor value for debug
 *
 * report.h
 *
 * Created: 2015/10/8 下午 01:54:41
 *  Author: TomCCChang
 */ 


#ifndef REPORT_H_
#define REPORT_H_
#include "strain.h"
//#include <asf.h>
#include "MDL_Config.h"

//inline void SensorReport(StrainSensorSet *SensorSet);

// sensor report for one sensor
void SensorReport(StrainSensorSet *SensorSet, int SensorIndex);

// sensor report for all sensors
void SensorSetReport(StrainSensorSet *SensorSet);

/*
void SensorReport(StrainSensorSet *SensorSet){

uint8_t string[] = "Hello World!\r\n";
usart_write_buffer_job(&usart_instance, string, sizeof(string));
}
*/
/*
	char string[20]=" ";
	//snprintf(string, 10, "%i\r\n", 10);
	sprintf(string,"A B C D%d\n CDEF",15);
	usart_write_buffer_job(&usart_instance, (uint8_t*)string, sizeof(string));
*/


#endif /* REPORT_H_ */

/*
* report.c
*
* Created: 2015/10/8 下午 01:56:19
*  Author: TomCCChang
*/

#include "report.h"
#include <stdio.h>

uint8_t string_ID[] = "ID\n";
uint8_t string_NEXT[] = "NEXT\n";

void SensorReport(StrainSensorSet *SensorSet, int SensorIndex){
	/*
	uint8_t string[] = "Hello World!\r\n";
	//usart_write_buffer_job(&usart_instance, string, sizeof(string));
	usart_write_buffer_wait(&usart_instance, string, sizeof(string));
	*/
	char string[6] = " ";
	char string_IDvalue[6] = " ";
	char string_strain0[6] = " ";
	char string_strain45[6] = " ";
	char string_strain90[6] = " ";
	char string_strain_max[6] = " ";
	char string_strain_min[6] = " ";
	char string_angle_deg[6] = " ";
	
	usart_write_buffer_wait(&usart_instance, string_ID, sizeof(string_ID)-1);

	sprintf(string_IDvalue,"%05d\n",SensorSet->p[SensorIndex].ID);
	usart_write_buffer_wait(&usart_instance, (uint8_t*)string_IDvalue, sizeof(string_IDvalue));
	
	sprintf(string,"%05d\n",0);
	usart_write_buffer_wait(&usart_instance, (uint8_t*)string, sizeof(string));
	
	sprintf(string,"%05d\n",0);
	usart_write_buffer_wait(&usart_instance, (uint8_t*)string, sizeof(string));
	
	sprintf(string_strain0,"%05d\n",SensorSet->p[SensorIndex].strain0);
	usart_write_buffer_wait(&usart_instance, (uint8_t*)string_strain0, sizeof(string_strain0));
	
	sprintf(string_strain45,"%05d\n",SensorSet->p[SensorIndex].strain45);
	usart_write_buffer_wait(&usart_instance, (uint8_t*)string_strain45, sizeof(string_strain45));
	
	sprintf(string_strain90,"%05d\n",SensorSet->p[SensorIndex].strain90);
	usart_write_buffer_wait(&usart_instance, (uint8_t*)string_strain90, sizeof(string_strain90));
	
	sprintf(string_strain_max,"%05d\n",SensorSet->p[SensorIndex].strain_max);
	usart_write_buffer_wait(&usart_instance, (uint8_t*)string_strain_max, sizeof(string_strain_max));
	
	sprintf(string_strain_min,"%05d\n",SensorSet->p[SensorIndex].strain_min);
	usart_write_buffer_wait(&usart_instance, (uint8_t*)string_strain_min, sizeof(string_strain_min));
	
	sprintf(string_angle_deg,"%05d\n",(int)(SensorSet->p[SensorIndex].angle_deg));
	usart_write_buffer_wait(&usart_instance, (uint8_t*)string_angle_deg, sizeof(string_angle_deg));

	usart_write_buffer_wait(&usart_instance, string_NEXT, sizeof(string_NEXT)-1);
	//printf(string_angle_deg);
	
}

void SensorSetReport(StrainSensorSet *SensorSet){
	
	for (int i = 0 ; i < SensorSet->SensorNum ; i++)
	SensorReport(SensorSet, i);
	
}

// original version
/*
Serial.println("ID");
Serial.println(int(p->ID));
Serial.println(p->PositionX);
Serial.println(p->PositionY);
Serial.println(int(p->strain0));
Serial.println(int(p->strain45));
Serial.println(int(p->strain90));
Serial.println(int(p->strain_max));
Serial.println(int(p->strain_min));
Serial.println(int(p->angle_deg));
Serial.println("NEXT");
Serial.println(int(p->AbsMaxStrain));
//Serial.println("Debug");//debug
//Serial.println(int(p->AbsMaxStrain));//debug
*/

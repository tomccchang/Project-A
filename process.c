/*
* process.c
*
* Created: 2015/10/14 下午 02:00:27
*  Author: TomCCChang
*/
#include "process.h"
#include <asf.h>
#include "MDL_Config.h"


void sofware_init(){
	//@ sensor set configuration
	SensorSet.SensorNum = 5;
	StrainSensorsInit(&SensorSet);
	
	//@ moving average configuration
	//set delay time
	Noise_Freq = 240;// power frequency 60 HZ
	SampleNum = 16;// sampling number for smooth window
	DelayTime_us = (uint32_t)(1000000 /(Noise_Freq*SampleNum));
	
	for (int i = 0 ; i < 3 ; i++ ){
		MA[i].SampleNum = SampleNum;
		MovingAverageInit(&MA[i]);
	}
	
	//@ Kalman filter setting
	for (int i = 0 ; i < 3 ; i++ ){
		KM[i].P_prev = 1;
		KM[i].Q = 0.000001;
		KM[i].R = 0.000008;
	}
	
}

void MA_UpdateAllAndOutput(void){
	SensorValue = 0;
	for(int i=0; i < MA[0].SampleNum ; i++){
		adc_read(&adc_instance, &SensorValue);
		//MovingAverageUpdate(&MA[0], SensorValue);
		MovingAverageUpdate2(&MA[0], SensorValue, 65535*0.45 , 65535*0.55);
		delay_us(DelayTime_us);
	}
	MovingAverageOut(&MA[0]);
}

void MA_UpdateAllAndOutput3(void){
	SensorValue = 0;
	
	adc_set_positive_input(&adc_instance,ADC_POSITIVE_INPUT_PIN18);
	delay_ms(5);
	adc_flush(&adc_instance);
	for(int i=0; i < MA[0].SampleNum ; i++){
		while (adc_read(&adc_instance, &SensorValue) == STATUS_BUSY){}
		//adc_read(&adc_instance, &SensorValue);	
		//MovingAverageUpdate2(&MA[0], SensorValue, 65535*0.45 , 65535*0.55);
		MovingAverageUpdate(&MA[0], SensorValue);
		delay_us(DelayTime_us);
	}
	

	adc_set_positive_input(&adc_instance,ADC_POSITIVE_INPUT_PIN1);
	delay_ms(5);
	adc_flush(&adc_instance);
	for(int i=0; i < MA[1].SampleNum ; i++){
		while (adc_read(&adc_instance, &SensorValue) == STATUS_BUSY){}
		//adc_read(&adc_instance, &SensorValue);
		//MovingAverageUpdate2(&MA[1], SensorValue, 65535*0.45 , 65535*0.55);
		MovingAverageUpdate(&MA[1], SensorValue);
		delay_us(DelayTime_us);
	}
	

	adc_set_positive_input(&adc_instance,ADC_POSITIVE_INPUT_PIN2);
	delay_ms(5);
	adc_flush(&adc_instance);
	for(int i=0; i < MA[2].SampleNum ; i++){
		while (adc_read(&adc_instance, &SensorValue) == STATUS_BUSY){}
		//adc_read(&adc_instance, &SensorValue);	
		//MovingAverageUpdate2(&MA[2], SensorValue, 65535*0.45 , 65535*0.55);
		MovingAverageUpdate(&MA[2], SensorValue);
		delay_us(DelayTime_us);
	}
	
	for(int n = 0; n < 3; n++)
	MovingAverageOut(&MA[n]);
}

void MA_UpdateAllAndOutput2(void){
	SensorValue = 0;
	
	for(int n = 0; n < 3; n++){
		adc_set(n);
		for(int i=0; i < MA[n].SampleNum ; i++){
			while (adc_read(&adc_instance, &SensorValue) == STATUS_BUSY){}
			MovingAverageUpdate2(&MA[n], SensorValue, 65535*0.45 , 65535*0.55);
			delay_us(DelayTime_us);
		}
		adc_disable(&adc_instance);
	}
	
	for(int n = 0; n < 3; n++)
	MovingAverageOut(&MA[n]);
}

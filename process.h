/*
 * process.h
 *
 * Created: 2015/10/14 下午 01:58:52
 *  Author: TomCCChang
 */ 


#ifndef PROCESS_H_
#define PROCESS_H_

#include "MovingAverage.h"
#include "strain.h"
#include "KalmanFilter.h"

uint16_t Noise_Freq;// power frequency 60 HZ
uint16_t SampleNum;// sample pts number for smooth window
uint32_t DelayTime_us;
uint16_t SensorValue; 

volatile KalmanFilter KM[3];

StrainSensorSet SensorSet;
MovingAverage MA[3];


void sofware_init(void);

void MA_UpdateAllAndOutput(void);
void MA_UpdateAllAndOutput2(void);
void MA_UpdateAllAndOutput3(void);

#endif /* PROCESS_H_ */

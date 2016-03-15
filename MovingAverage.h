/*
 * MovingAverage.h
 *
 * Created: 2015/10/14 上午 10:03:34
 *  Author: TomCCChang
 */ 


#ifndef MOVINGAVERAGE_H_
#define MOVINGAVERAGE_H_
#include <asf.h>

typedef struct{
	  uint16_t SampleNum;
	  uint16_t *RingBuffer;
	  uint16_t BufferIndex;
	  uint16_t DelayTime_us;
	  uint16_t input;
	  uint16_t output; 
}MovingAverage;

//@ initialize
void MovingAverageInit(MovingAverage *MA);
//@ add new value to ring buffer
void MovingAverageUpdate(MovingAverage *MA, uint16_t input);
void MovingAverageUpdate2(MovingAverage *MA, uint16_t input,
uint16_t limit_L, uint16_t limit_H);
//@ output average value
void MovingAverageOut(MovingAverage *MA);

#endif /* MOVINGAVERAGE_H_ */

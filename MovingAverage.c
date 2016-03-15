/*
* MovingAverage.c
*
* Created: 2015/10/14 上午 10:51:14
*  Author: TomCCChang
*/
# include "MovingAverage.h"

void MovingAverageInit(MovingAverage *MA){
	MA->BufferIndex = 0;
	MA->RingBuffer = (uint16_t*)calloc((size_t)(MA->SampleNum) ,sizeof(uint16_t));
}

void MovingAverageUpdate(MovingAverage *MA, uint16_t input){
	// save data in buffer
	MA->RingBuffer[MA->BufferIndex] = input;
	MA->BufferIndex++;
	// bufferIndex is looping within 0 ~ SampleNum
	if(MA->BufferIndex == MA->SampleNum)
	MA->BufferIndex = 0;
}

void MovingAverageUpdate2(MovingAverage *MA, uint16_t input,
uint16_t limit_L, uint16_t limit_H){
	MA->input = input;
	// save data in buffer
	if (input <= limit_H && input >= limit_L ){ // reduce singularity
		MA->RingBuffer[MA->BufferIndex] = input;
		MA->BufferIndex++;
	}
	// bufferIndex is looping within 0 ~ SampleNum
	if(MA->BufferIndex == MA->SampleNum)
	MA->BufferIndex = 0;
}


void MovingAverageOut(MovingAverage *MA){
	uint32_t sum = 0;
	for(int i=0; i < MA->SampleNum ; i++){
		sum += (uint32_t)(MA->RingBuffer[i]);
	}
	uint32_t output = sum / (uint32_t)MA->SampleNum;
	MA->output = (uint16_t)output;
}

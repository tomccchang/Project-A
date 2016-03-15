/**
* \file
*
* \brief Empty user application template
*
*/

/**
* \mainpage User Application template doxygen documentation
*
* \par Empty user application template
*
* This is a bare minimum user application template.
*
* For documentation of the board, go \ref group_common_boards "here" for a link
* to the board-specific documentation.
*
* \par Content
*
* -# Include the ASF header files (through asf.h)
* -# Minimal main function that starts with a call to system_init()
* -# Basic usage of on-board LED and button
* -# "Insert application code here" comment
*
*/

/*
* Include header files for all drivers that have been imported from
* Atmel Software Framework (ASF).
*/
/**
* Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
*/
#include <asf.h>

#include "MDL_Config.h"
#include "MovingAverage.h"
#include "strain.h"
#include "process.h"
#include "report.h"



/* buffer */
static uint16_t adc_result0;
static uint16_t adc_result1;
static uint16_t adc_result2;

// reference
uint16_t SensorsetREF[3];


int main (void)
{
	
	
	//@ Hardware Initialize
	system_init();
	App_Init();
	/*
	//@ Configuring Instrument AMP
	configure_Instrument_AMP_v2();// Connect OPAMP
	dac_chan_write(&dac_instance, DAC_CHANNEL_0, ((uint16_t)2047)); // Boost neutral level
	dac_chan_write(&dac_instance, DAC_CHANNEL_1, ((uint16_t)2047)); // test (negative input for instrument Amp.)
	*/
	dac_chan_write(&dac_instance, DAC_CHANNEL_0, ((uint16_t)2047)); // Boost neutral level

	//@ Software Initialize
	sofware_init();
	delay_ms(100);
	
	//@ calculate references of sensors
	//MA_UpdateAllAndOutput();
	//MA_UpdateAllAndOutput2();// multi-sensor initialization
	MA_UpdateAllAndOutput3();// multi-sensor initialization
	SensorsetREF[0] = MA[0].output;
	SensorsetREF[1] = MA[1].output;
	SensorsetREF[2] = MA[2].output;
	
	volatile char timer = 0;
	const uint16_t limit_lower = 65535*0.45;
	const uint16_t limit_top = 65535*0.55;
	
	KM[0].X_Est_prev = SensorsetREF[0];
	KM[1].X_Est_prev = SensorsetREF[1];
	KM[2].X_Est_prev = SensorsetREF[2];
	
	//adc_set_positive_input(&adc_instance,ADC_POSITIVE_INPUT_PIN18);
	// This skeleton code simply sets the LED to the state of the button.
	while (1) {

		//delay_ms(5);
		//adc_set(0);
		//adc_read(&adc_instance, &adc_result0);

		//@ acquire data from the ADC
		//adc_read(&adc_instance, &adc_result);
		/*
		//delay_us(DelayTime_us);
		adc_set_positive_input(&adc_instance,ADC_POSITIVE_INPUT_PIN18);
		//delay_ms(5);
		//adc_read(&adc_instance, &adc_result0);
		while (adc_read(&adc_instance, &adc_result0) == STATUS_BUSY){}
		adc_flush(&adc_instance);
		adc_set_positive_input(&adc_instance,ADC_POSITIVE_INPUT_PIN1);
		delay_ms(5);
		//adc_read(&adc_instance, &adc_result1);
		while (adc_read(&adc_instance, &adc_result1) == STATUS_BUSY){}
		adc_flush(&adc_instance);
		adc_set_positive_input(&adc_instance,ADC_POSITIVE_INPUT_PIN2);
		delay_ms(5);
		adc_read(&adc_instance, &adc_result2);
		adc_flush(&adc_instance);
		*/

		//MA[0].output = adc_result0;
		
		//@ filter
		// push data in ring buffer
		//MovingAverageUpdate(&MA[0], adc_result);
		//MovingAverageUpdate2(&MA[0], adc_result0, limit_lower , limit_top);
		//MovingAverageUpdate2(&MA[1], adc_result1, limit_lower , limit_top);
		//MovingAverageUpdate2(&MA[2], adc_result2, limit_lower , limit_top);
		/*
		//@ adjust report rate
		if (timer == 4){
		timer = 0;
		}
		else
		{
		timer++;
		continue;
		}
		*/
		// pop new data
		//MovingAverageOut(&MA[0]);
		//MovingAverageOut(&MA[1]);
		//MovingAverageOut(&MA[2]);
		
		MA_UpdateAllAndOutput3();
		//@ time update
		KalmanFilterPrdict(&KM[0]);
		KalmanFilterPrdict(&KM[1]);
		KalmanFilterPrdict(&KM[2]);
		//@ measurement update
		//KalmanFilterCorrect(&KM, (int)adc_result);
		KalmanFilterCorrect(&KM[0], (int)MA[0].output);
		KalmanFilterCorrect(&KM[1], (int)MA[1].output);
		KalmanFilterCorrect(&KM[2], (int)MA[2].output);
		
		//@ assign measurement to sensor's structure
		//SensorSet.p[0].strain0 = (int)((adc_result -SensorsetREF[0])/8);
		//SensorSet.p[0].strain0 = (int)((MA[0].output -SensorsetREF[0])/8);
		//SensorSet.p[0].strain0 = (int)((MA[0].output -SensorsetREF[0]));
		//SensorSet.p[0].strain0 = (int)((MA[0].input -SensorsetREF[0]));
		//SensorSet.p[0].strain0 = (int)((uint16_t)KM[0].X_Est -SensorsetREF[0]);
		//SensorSet.p[0].strain0 = (int)(adc_result -SensorsetREF[0]);
		//SensorSet.p[0].strain45 = SensorSet.p[0].strain0 ;
		//SensorSet.p[0].strain90 = SensorSet.p[0].strain0 ;
		
		SensorSet.p[0].strain0 = (int)((uint16_t)KM[1].X_Est -SensorsetREF[1]);
		SensorSet.p[0].strain45 = (int)((uint16_t)KM[2].X_Est -SensorsetREF[2]);
		SensorSet.p[0].strain90 = (int)((uint16_t)KM[0].X_Est -SensorsetREF[0]);
		//SensorSet.p[0].strain0 = (int)((uint16_t)MA[1].output -SensorsetREF[1]);
		//SensorSet.p[0].strain45 = (int)((uint16_t)MA[2].output -SensorsetREF[2]);
		//SensorSet.p[0].strain90 =4*(int)((uint16_t)MA[0].output -SensorsetREF[0]);
		
		
		//@ strain Analysis
		//SensorSet.p[0].strain45 = (int) adc_result;
		PrinpicalStrainAll(&SensorSet);
		
		//@ send report
		SensorReport(&SensorSet, 0);

		//@ Send the resulting DATA to the DATA ANALYZER thought the SPI
		//uint16_t data = (uint16_t)(SensorSet.p[0].strain0);
		uint16_t data = (uint16_t)(SensorSet.p[0].strain45 + 128) ;
		DGI_SPI_send(data);
		
		//DGI_SPI_send(adc_result0 >> 4);
		//DGI_SPI_send(adc_result0 >> 8);
		//DGI_SPI_send(adc_result);
		//DGI_SPI_send(SensorValue>> 4);
		//DGI_SPI_send(MA[0].output>> 4);
		
		
	}
}

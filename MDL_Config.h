/*
 * MDL_cofiguraction.h
 *
 * Created: 2015/9/18 上午 10:08:55
 *  Author: TomCCChang
 */ 


#ifndef MDL_COFIGURACTION_H_
#define MDL_COFIGURACTION_H_

/*				
				INCLUDE
											*/
#include <asf.h>
#include <L21_DGI_SPI.h>

/*				
				STRUCT
											*/
struct dac_module dac_instance;
//struct tc_module tc_instance;//<--dont need for now
struct port_config pin_conf;
struct adc_module adc_instance;
struct adc_module adc_instance_3ch[3];
struct usart_module usart_instance;

/*				
				PROTOTYPE
											*/

/* DAC configuration */
void configure_dac(void);

/* DAC Channel configuration */
void configure_dac_channel(void);

/* ADC Configuration */
void configure_adc(void);
void configure_adc_3ch(void);
void adc_set(int index);
/* Application Initialization function Implementation */
void App_Init(void);

/* Configuring Instrument AMP */
void configure_Instrument_AMP_v2(void);

//@ Configure USART @//
void usart_read_callback(const struct usart_module *const usart_module);
void usart_write_callback(const struct usart_module *const usart_module);
void configure_usart(void);
void configure_usart_callbacks(void);

//@ Configure GPIO @//
void configure_port_pins(void);

//! [rx_buffer_var]
#define MAX_RX_BUFFER_LENGTH   5

volatile uint8_t rx_buffer[MAX_RX_BUFFER_LENGTH];

#endif /* MDL_COFIGURACTION_H_ */

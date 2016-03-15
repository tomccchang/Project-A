/*
* MDL_Config.c
*
* Created: 2015/9/18 上午 10:25:44
*  Author: TomCCChang
*/

#include "MDL_Config.h"

/* ADC Configuration function Implementation */

void configure_adc(void)
{
struct adc_config config_adc;
adc_get_config_defaults(&config_adc);

config_adc.clock_source                  = GCLK_GENERATOR_0;
config_adc.reference                     = ADC_REFERENCE_INTVCC2;		//VDDANA
config_adc.clock_prescaler               = ADC_CLOCK_PRESCALER_DIV2;
//config_adc.resolution                    = ADC_RESOLUTION_12BIT;
//config_adc.resolution                    = ADC_RESOLUTION_16BIT;
config_adc.resolution                    = ADC_RESOLUTION_CUSTOM;
config_adc.window.window_mode            = ADC_WINDOW_MODE_DISABLE;
config_adc.window.window_upper_value     = 0;
config_adc.window.window_lower_value     = 0;
//config_adc.positive_input                = ADC_POSITIVE_INPUT_OPAMP01;//original
//config_adc.positive_input                = ADC_POSITIVE_INPUT_OPAMP2;// for instrument AMP
config_adc.positive_input                = ADC_POSITIVE_INPUT_PIN18;//PA10 / for test
config_adc.negative_input                = ADC_NEGATIVE_INPUT_GND;
//config_adc.accumulate_samples            = ADC_ACCUMULATE_DISABLE;//original
config_adc.accumulate_samples            = ADC_ACCUMULATE_SAMPLES_256;
//config_adc.divide_result                 = ADC_DIVIDE_RESULT_DISABLE;
config_adc.left_adjust                   = false;
config_adc.differential_mode             = false;
config_adc.freerunning                   = true;
config_adc.event_action                  = ADC_EVENT_ACTION_DISABLED;
config_adc.run_in_standby                = false;
config_adc.on_demand                     = false;
config_adc.sampling_time_compensation_enable  = false;
config_adc.positive_input_sequence_mask_enable = 0;
config_adc.reference_compensation_enable = false;
config_adc.correction.correction_enable  = false;
config_adc.correction.gain_correction    = ADC_GAINCORR_RESETVALUE;
config_adc.correction.offset_correction  = ADC_OFFSETCORR_RESETVALUE;
config_adc.sample_length                 = 0;

adc_init(&adc_instance, ADC, &config_adc);
adc_enable(&adc_instance);
}

void configure_adc_3ch(void){
	struct adc_config config_adc;
	adc_get_config_defaults(&config_adc);
	
	config_adc.clock_source                  = GCLK_GENERATOR_0;
	config_adc.reference                     = ADC_REFERENCE_INTVCC2;		//VDDANA
	config_adc.clock_prescaler               = ADC_CLOCK_PRESCALER_DIV2;
	//config_adc.resolution                    = ADC_RESOLUTION_12BIT;
	//config_adc.resolution                    = ADC_RESOLUTION_16BIT;
	config_adc.resolution                    = ADC_RESOLUTION_CUSTOM;
	config_adc.window.window_mode            = ADC_WINDOW_MODE_DISABLE;
	config_adc.window.window_upper_value     = 0;
	config_adc.window.window_lower_value     = 0;
	config_adc.positive_input                = ADC_POSITIVE_INPUT_PIN18;//PA10 / test ok
	config_adc.negative_input                = ADC_NEGATIVE_INPUT_GND;
	config_adc.accumulate_samples            = ADC_ACCUMULATE_DISABLE;//original
	//config_adc.accumulate_samples            = ADC_ACCUMULATE_SAMPLES_1024;
	config_adc.divide_result                 = ADC_DIVIDE_RESULT_DISABLE;
	config_adc.left_adjust                   = false;
	config_adc.differential_mode             = false;
	config_adc.freerunning                   = true;
	config_adc.event_action                  = ADC_EVENT_ACTION_DISABLED;
	config_adc.run_in_standby                = false;
	config_adc.on_demand                     = false;
	config_adc.sampling_time_compensation_enable  = false;
	config_adc.positive_input_sequence_mask_enable = 0;
	config_adc.reference_compensation_enable = false;
	config_adc.correction.correction_enable  = false;
	config_adc.correction.gain_correction    = ADC_GAINCORR_RESETVALUE;
	config_adc.correction.offset_correction  = ADC_OFFSETCORR_RESETVALUE;
	config_adc.sample_length                 = 0;
	
	//config_adc.positive_input                = ADC_POSITIVE_INPUT_PIN17;//PA09 / test NG
	//adc_init(&adc_instance_3ch[0], ADC, &config_adc);
	//adc_enable(&adc_instance_3ch[0]);

	//config_adc.positive_input                = ADC_POSITIVE_INPUT_PIN1;//PA03 / test ok
	//adc_init(&adc_instance_3ch[1], ADC, &config_adc);
	//adc_enable(&adc_instance_3ch[1]);
	
	config_adc.positive_input                = ADC_POSITIVE_INPUT_PIN18;;//PA10 / test ok
	adc_init(&adc_instance_3ch[0], ADC, &config_adc);
	adc_enable(&adc_instance_3ch[0]);
	
	//config_adc.positive_input                = ADC_POSITIVE_INPUT_PIN2;//PB08 / test ok
	//adc_init(&adc_instance_3ch[2], ADC, &config_adc);
	//adc_enable(&adc_instance_3ch[2]);
}

void adc_set(int index){
	struct adc_config config_adc;
	adc_get_config_defaults(&config_adc);
	
	config_adc.clock_source                  = GCLK_GENERATOR_0;
	config_adc.reference                     = ADC_REFERENCE_INTVCC2;		//VDDANA
	config_adc.clock_prescaler               = ADC_CLOCK_PRESCALER_DIV2;
	//config_adc.resolution                    = ADC_RESOLUTION_12BIT;
	//config_adc.resolution                    = ADC_RESOLUTION_16BIT;
	config_adc.resolution                    = ADC_RESOLUTION_CUSTOM;
	config_adc.window.window_mode            = ADC_WINDOW_MODE_DISABLE;
	config_adc.window.window_upper_value     = 0;
	config_adc.window.window_lower_value     = 0;
	config_adc.negative_input                = ADC_NEGATIVE_INPUT_GND;
	//config_adc.accumulate_samples            = ADC_ACCUMULATE_DISABLE;//original
	config_adc.accumulate_samples            = ADC_AVGCTRL_SAMPLENUM_256;
	config_adc.divide_result                 = ADC_DIVIDE_RESULT_DISABLE;
	config_adc.left_adjust                   = false;
	config_adc.differential_mode             = false;
	config_adc.freerunning                   = true;
	config_adc.event_action                  = ADC_EVENT_ACTION_DISABLED;
	config_adc.run_in_standby                = false;
	config_adc.on_demand                     = false;
	config_adc.sampling_time_compensation_enable  = false;
	config_adc.positive_input_sequence_mask_enable = 0;
	config_adc.reference_compensation_enable = false;
	config_adc.correction.correction_enable  = false;
	config_adc.correction.gain_correction    = ADC_GAINCORR_RESETVALUE;
	config_adc.correction.offset_correction  = ADC_OFFSETCORR_RESETVALUE;
	config_adc.sample_length                 = 0;
	
	// set channel
	switch(index){
		case 0:
		config_adc.positive_input = ADC_POSITIVE_INPUT_PIN18;//PA03 / test ok
		break;
		
		case 1:
		config_adc.positive_input = ADC_POSITIVE_INPUT_PIN1;//PA03 / test ok
		break;
		
		case 2:
		config_adc.positive_input = ADC_POSITIVE_INPUT_PIN2;//PB08 / test ok
		break;
	}
	// Enable
	adc_init(&adc_instance, ADC, &config_adc);
	adc_enable(&adc_instance);
}



/* DAC configuration function Implementation */
void configure_dac(void)
{
	struct dac_config config_dac;
	dac_get_config_defaults(&config_dac);
	config_dac.reference = DAC_REFERENCE_VDDANA;
	dac_init(&dac_instance, DAC, &config_dac);
}

/* DAC Channel configuration function Implementation */




void configure_dac_channel(void)
{
	struct dac_chan_config config_dac_chan;
	dac_chan_get_config_defaults(&config_dac_chan);
	config_dac_chan.left_adjust    = false;
	config_dac_chan.current        = DAC_CURRENT_10K;
	config_dac_chan.run_in_standby = false;
	config_dac_chan.dither_mode    = false;
	config_dac_chan.refresh_period = 0xF;
	// DAC 0
	dac_chan_set_config(&dac_instance, DAC_CHANNEL_0, &config_dac_chan);
	dac_chan_enable(&dac_instance, DAC_CHANNEL_0);
	// DAC 1
	dac_chan_set_config(&dac_instance, DAC_CHANNEL_1, &config_dac_chan);
	dac_chan_enable(&dac_instance, DAC_CHANNEL_1);
}

//@ Configure USART @//
void usart_read_callback(const struct usart_module *const usart_module)
{
	usart_write_buffer_job(&usart_instance,
	(uint8_t *)rx_buffer, MAX_RX_BUFFER_LENGTH);
}

void usart_write_callback(const struct usart_module *const usart_module)
{
	port_pin_toggle_output_level(LED_0_PIN);
}

void configure_usart(void)
{
	//! [setup_config]
	struct usart_config config_usart;
	//! [setup_config]
	//! [setup_config_defaults]
	usart_get_config_defaults(&config_usart);
	//! [setup_config_defaults]

	//! [setup_change_config]
	config_usart.baudrate    = 9600;
	config_usart.mux_setting = EDBG_CDC_SERCOM_MUX_SETTING;
	config_usart.pinmux_pad0 = EDBG_CDC_SERCOM_PINMUX_PAD0;
	config_usart.pinmux_pad1 = EDBG_CDC_SERCOM_PINMUX_PAD1;
	config_usart.pinmux_pad2 = EDBG_CDC_SERCOM_PINMUX_PAD2;
	config_usart.pinmux_pad3 = EDBG_CDC_SERCOM_PINMUX_PAD3;
	//! [setup_change_config]

	//! [setup_set_config]
	while (usart_init(&usart_instance,
	EDBG_CDC_MODULE, &config_usart) != STATUS_OK) {
	}
	//! [setup_set_config]

	//! [setup_enable]
	usart_enable(&usart_instance);
	//! [setup_enable]
}


void configure_usart_callbacks(void)
{
	//! [setup_register_callbacks]
	usart_register_callback(&usart_instance,
	usart_write_callback, USART_CALLBACK_BUFFER_TRANSMITTED);
	usart_register_callback(&usart_instance,
	usart_read_callback, USART_CALLBACK_BUFFER_RECEIVED);
	//! [setup_register_callbacks]

	//! [setup_enable_callbacks]
	usart_enable_callback(&usart_instance, USART_CALLBACK_BUFFER_TRANSMITTED);
	usart_enable_callback(&usart_instance, USART_CALLBACK_BUFFER_RECEIVED);
	//! [setup_enable_callbacks]
}


//@ Configure GPIO @//
void configure_port_pins(void)
{
	struct port_config config_port_pin;
	port_get_config_defaults(&config_port_pin);
	config_port_pin.direction  = PORT_PIN_DIR_INPUT;
	config_port_pin.input_pull = PORT_PIN_PULL_UP;
	port_pin_set_config(BUTTON_0_PIN, &config_port_pin);
	config_port_pin.direction = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(LED_0_PIN, &config_port_pin);
	port_pin_set_config(PIN_PA10, &config_port_pin);
}



/* Application Initialization function Implementation */
void App_Init(void)
{

	//@ Configure The DAC @//
	configure_dac();
	configure_dac_channel();
	dac_enable(&dac_instance);

	/* Configure The Timer Counter */
	//configure_tc();
	//configure_tc_callbacks();
	
	/* Configure The ADC */
	configure_adc();
	//adc_set(0);
	//configure_adc_3ch();
	//@ Configure USART @//
	configure_usart();
	configure_usart_callbacks();
	
	//@ delay service
	delay_init();
	
	/* Initialize the SPI interface for the DGI communication with the Data Analyzer*/
	DGI_SPI_init(0);
	
	/* Enable the Global Interrupt */
	system_interrupt_enable_global();
}

/* Configuring Instrument AMP */
void configure_Instrument_AMP_v2(void){

	/** Initializes OPAMP module. */
	opamp_module_init();

	/*
	*  OPAMP 0 voltage follower
	*/
	
	/** Creates a new configuration structure for the OPAMP0. */
	struct opamp0_config conf_OP0;
	
	/** Settings and fill with the default settings. */
	opamp0_get_config_defaults(&conf_OP0);
	
	/* Set the the OPAMP0 as "Voltage Follower" mode. */
	conf_OP0.negative_input = OPAMP0_NEG_MUX_OUT0;
	//conf_OP0.positive_input = OPAMP0_POS_MUX_DAC;
	conf_OP0.positive_input = OPAMP0_POS_MUX_PIN0;
	//conf_OP0.r1_connection = OPAMP0_RES1_MUX_GND;// voltage shift zero
	conf_OP0.r1_connection = OPAMP0_RES1_MUX_DAC;// voltage shift basing on DAC
	//conf_OP0.config_common.potentiometer_selection= OPAMP_POT_MUX_8R_8R;// unity gain
	//conf_OP0.config_common.potentiometer_selection= OPAMP_POT_MUX_12R_4R;// gain:3
	conf_OP0.config_common.potentiometer_selection= OPAMP_POT_MUX_14R_2R;// gain:7
	conf_OP0.config_common.r1_enable = true;
	conf_OP0.config_common.r2_vcc = false;
	conf_OP0.config_common.r2_out = true;
	conf_OP0.config_common.on_demand = false;
	conf_OP0.config_common.run_in_standby = false;
	conf_OP0.config_common.bias_value = OPAMP_BIAS_MODE_3;
	conf_OP0.config_common.analog_out = true;
	
	/* Setup  OA0POS pin. */
	struct system_pinmux_config opamp0_pos_pin_conf;
	system_pinmux_get_config_defaults(&opamp0_pos_pin_conf);
	opamp0_pos_pin_conf.direction = SYSTEM_PINMUX_PIN_DIR_INPUT;
	opamp0_pos_pin_conf.mux_position = MUX_PA06B_OPAMP_OAPOS0;
	system_pinmux_pin_set_config(PIN_PA06B_OPAMP_OAPOS0, &opamp0_pos_pin_conf);
	
	/* Setup  OA0OUT pin. */
	struct system_pinmux_config opamp0_out_pin_conf;
	system_pinmux_get_config_defaults(&opamp0_out_pin_conf);
	opamp0_out_pin_conf.direction    = SYSTEM_PINMUX_PIN_DIR_OUTPUT;
	opamp0_out_pin_conf.mux_position = MUX_PA07B_OPAMP_OAOUT0;
	system_pinmux_pin_set_config(PIN_PA07B_OPAMP_OAOUT0, &opamp0_out_pin_conf);

	/* Initialize and enable the OPAMP0 with the user settings. */
	opamp0_set_config(&conf_OP0);
	opamp_enable(OPAMP_0);

	/* Wait for the output ready. */
	while(!opamp_is_ready(OPAMP_0));
	
	/*
	*  OPAMP1 voltage follower
	*/
	/** Creates a new configuration structure for the OPAMP1. */
	struct opamp1_config conf_OP1;

	/** Settings and fill with the default settings. */
	opamp1_get_config_defaults(&conf_OP1);

	/* Set the the OPAMP1 as "Voltage Follower" mode. */
	conf_OP1.negative_input = OPAMP1_NEG_MUX_OUT1;
	conf_OP1.positive_input = OPAMP1_POS_MUX_PIN1;
	conf_OP1.r1_connection = OPAMP1_RES1_MUX_GND;
	//conf.config_common.potentiometer_selection= 無影響;
	conf_OP1.config_common.r1_enable = false;
	conf_OP1.config_common.r2_vcc = false;
	conf_OP1.config_common.r2_out = false;
	conf_OP1.config_common.on_demand = false;
	conf_OP1.config_common.run_in_standby = false;
	conf_OP1.config_common.bias_value = OPAMP_BIAS_MODE_3;
	conf_OP1.config_common.analog_out = true;
	
	/* Setup  OA1OUT pin. */
	struct system_pinmux_config opamp1_out_pin_conf;
	system_pinmux_get_config_defaults(&opamp1_out_pin_conf);
	opamp1_out_pin_conf.direction    = SYSTEM_PINMUX_PIN_DIR_OUTPUT;
	opamp1_out_pin_conf.mux_position = MUX_PB06B_OPAMP_OAOUT1;
	system_pinmux_pin_set_config(PIN_PB06B_OPAMP_OAOUT1, &opamp1_out_pin_conf);
	
	/* Setup  OA1POS pin. */
	struct system_pinmux_config opamp1_pos_pin_conf;
	system_pinmux_get_config_defaults(&opamp1_pos_pin_conf);
	opamp1_out_pin_conf.direction    = SYSTEM_PINMUX_PIN_DIR_INPUT;
	opamp1_out_pin_conf.mux_position = MUX_PB09B_OPAMP_OAPOS1;
	system_pinmux_pin_set_config(PIN_PB09B_OPAMP_OAPOS1, &opamp1_pos_pin_conf);

	/* Initialize and enable the OPAMP1 with the user settings. */
	opamp1_set_config(&conf_OP1);
	opamp_enable(OPAMP_1);

	/* Wait for the output ready. */
	while(!opamp_is_ready(OPAMP_1));
	
	/*
	*  OPAMP2 Subtracter
	*/
	/** Creates a new configuration structure for the OPAMP2. */
	struct opamp2_config conf_OP2;

	opamp2_get_config_defaults(&conf_OP2);
	// Set the the OPAMP0 as "Non-Inverting PGA" mode. //
	conf_OP2.negative_input = OPAMP2_NEG_MUX_TAP2;// OP2 negative feedback
	conf_OP2.positive_input = OPAMP2_POS_MUX_TAP0;// connect to OP0
	conf_OP2.r1_connection = OPAMP2_RES1_MUX_OUT1;// connect to OP1
	conf_OP2.config_common.r1_enable = true;
	conf_OP2.config_common.r2_vcc = false;
	conf_OP2.config_common.r2_out = true;
	conf_OP2.config_common.analog_out = true;
	//conf_OP2.config_common.potentiometer_selection= OPAMP_POT_MUX_8R_8R;// unity gain
	//conf_OP2.config_common.potentiometer_selection= OPAMP_POT_MUX_4R_12R;// gain:3
	conf_OP2.config_common.potentiometer_selection= OPAMP_POT_MUX_2R_14R;// gain:7
	// Setup OA2OUT pin. //
	struct system_pinmux_config opamp2_out_pin_conf;
	system_pinmux_get_config_defaults(&opamp2_out_pin_conf);
	opamp2_out_pin_conf.direction = SYSTEM_PINMUX_PIN_DIR_OUTPUT;
	opamp2_out_pin_conf.mux_position = MUX_PA04B_OPAMP_OAOUT2;
	system_pinmux_pin_set_config(PIN_PA04B_OPAMP_OAOUT2, &opamp2_out_pin_conf);
	opamp2_set_config(&conf_OP2);
	opamp_enable(OPAMP_2);
	// Wait for the output ready. //
	while(!opamp_is_ready(OPAMP_2));
}



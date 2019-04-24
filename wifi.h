/*
 * wifi.h
 *
 * Created: 1/17/2017 9:47:13 AM
 *  Author: Ilya
 */ 


#ifndef WIFI_H_
#define WIFI_H_

#include <asf.h>
#include <string.h>

#define WIFI_USART					USART0
#define WIFI_USART_ID				ID_USART0
#define WIFI_USART_BAUDRATE			115200
#define WIFI_USART_HANDLER			USART0_Handler
#define WIFI_USART_IRQn				USART0_IRQn
#define WIFI_USART_CHAR_LENGTH		US_MR_CHRL_8_BIT
#define WIFI_USART_PARITY			US_MR_PAR_NO
#define WIFI_USART_STOP_BITS		US_MR_NBSTOP_1_BIT
#define WIFI_USART_MODE				US_MR_CHMODE_NORMAL

/** USART0 pin RX */
#define PIN_USART0_RXD	  {PIO_PA5A_RXD0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
#define PIN_USART0_RXD_IDX        (PIO_PA5_IDX)
#define PIN_USART0_RXD_FLAGS      (PIO_PERIPH_A | PIO_PULLUP)
/** USART0 pin TX */
#define PIN_USART0_TXD    {PIO_PA6A_TXD0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
#define PIN_USART0_TXD_IDX        (PIO_PA6_IDX)
#define PIN_USART0_TXD_FLAGS      (PIO_PERIPH_A | PIO_PULLUP)
/** USART0 pin CTS */
#define PIN_USART0_CTS    {PIO_PA8A_CTS0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
#define PIN_USART0_CTS_IDX        (PIO_PA8_IDX)
#define PIN_USART0_CTS_FLAGS      (PIO_PERIPH_A | PIO_PULLUP)
/** USART0 pin RTS */
#define PIN_USART0_RTS    {PIO_PA7A_RTS0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
#define PIN_USART0_RTS_IDX        (PIO_PA7_IDX)
#define PIN_USART0_RTS_FLAGS      (PIO_PERIPH_A | PIO_PULLUP)

/** All interrupt mask. */
#define ALL_INTERRUPT_MASK  0xffffffff


#define WIFI_COMM_PIO				PIOB
#define WIFI_COMM_ID				ID_PIOB
#define WIFI_COMM_PIN_MSK				PIO_PB2
#define WIFI_COMM_ATTR				PIO_PULLUP |PIO_IT_RISE_EDGE



#define WIFI_SET_ID			ID_PIOB
#define WIFI_SET_PIO		PIOB
#define WIFI_SET_PIN_MSK		PIO_PB0
#define WIFI_SET_ATTR		PIO_PULLUP |PIO_IT_RISE_EDGE

#define MAX_INPUT_WIFI 1000
volatile char input_line_wifi[MAX_INPUT_WIFI];
volatile uint32_t received_byte_wifi;
volatile bool new_rx_wifi;
volatile unsigned int input_pos_wifi;
volatile bool wifi_comm_success;
volatile uint32_t setup_web;

volatile bool web_connected ;
volatile bool image_pass;

void wifi_web_setup_handler(uint32_t ul_id, uint32_t ul_mask);
void configure_usart_wifi(void);

void process_incoming_byte_wifi(uint8_t inByte);
void process_data_wifi();
void wifi_command_response_handler(uint32_t ul_id, uint32_t ul_mask);
void configure_wifi_comm_pin(void);

void configure_wifi_web_setup_pin(void);


void write_wifi_command(char* comm, int cnt);
void write_image_to_file(void);

#endif /* WIFI_H_ */
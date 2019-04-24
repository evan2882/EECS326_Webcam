#include <asf.h>
#include "conf_board.h"
#include "conf_clock.h"
#include "wifi.h"
#include "camera.h"
#include "timer_interface.h"



int main (void)
{
	sysclk_init();
	wdt_disable(WDT);
	board_init();
	configure_tc();
	
	
	
	
	
	
	
	gpio_set_pin_low(WIFI_RESET_PIN);
	delay_ms(50);
	gpio_set_pin_high(WIFI_RESET_PIN);
	
	configure_usart_wifi();
	configure_wifi_comm_pin();
	configure_wifi_web_setup_pin();
	
	while (ioport_get_pin_level(WIFI_SET)==0) {
		if (setup_web) {
		
		usart_write_line(WIFI_USART, "setup web\r\n");
		setup_web=false;
		}
	}

	capture_init();
	g_ul_vsync_flag = false;
	
	usart_write_line(WIFI_USART, "set sy c p off\r\n");
	usart_write_line(WIFI_USART, "set sy c e off\r\n");
	
	
	
	
	
	
	
	while(1) {
		web_connected=false;
		if (ioport_get_pin_level(WIFI_SET)==1){
		if (setup_web){
			usart_write_line(WIFI_USART, "setup web\r\n");
			setup_web=false;  }
		
		else {
				//usart_putchar(WIFI_USART, "\r\n");
				usart_write_line(WIFI_USART, "poll all\r\n");
				delay_ms(50);
				
				
				if(web_connected==false){
					delay_ms(1000);
					}
				else {
					start_capture();
					write_image_to_file();
				}
			}
		}
	
		else{
			gpio_set_pin_low(WIFI_RESET_PIN);
			delay_ms(50);
			gpio_set_pin_high(WIFI_RESET_PIN);}
		
		}
}
			


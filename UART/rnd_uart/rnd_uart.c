#include "uart.h"
#include <stdint.h>
#include "platform.h"
#include "pinmux.h"
#include "traps.h"
#include <stdio.h>
#include <utils.h>
void main()
{
    *pinmux_config_reg=0x55;
   //reference for pinmux config https://blogshakti.org.in/pinmux-in-shakti/
    uart_init();
    set_baud_rate(uart_instance[1], 9600);
    printf("Test uart !\r\n");
    flush_uart(uart_instance[1]);


    while(1){
        // uint8_t result;
        char temp1;
        write_uart_character(uart_instance[1], 10);      
       //for uart tx1 and tx2 value is available at io[1] and io[3] respectively
       read_uart_character(uart_instance[1], &temp1);
       //for uart rx1 and rx2 value is available at io[0] and io[2] respectively
       	printf("rec %d\n", temp1);
        
    }
}




#include <xc.h>
#include "config.h"
#include "UART.h"



void main(void){
    UART_Init(9600);
    
    UART_Write('C');
    UART_Write_Text("Hola todos :)\r\n");
    
    while(1){
        __delay_ms(10);
    }
    return;
}

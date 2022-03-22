#include "uart.h"


void uart_init(){
gpio_init();        //Initialiserer pins
GPIO0->PIN_CNF[6]=0; //vi setter UART_INTERNAL_RX(Reciever) til å være input 
GPIO1->PIN_CNF[8]=1;    //Setter UART_INTERNAL_TX(Transmitter) Til å være OUTPUT!!!!!!LEMONS!!!


}
void uart_send(char letter);
char uart_read();
#include "uart.h"
#include "gpio.h"


void uart_init(){
gpio_init();        //Initialiserer pins
GPIO0->PIN_CNF[6]=0; //vi setter UART_INTERNAL_RX(Reciever) til å være input 
GPIO1->PIN_CNF[8]=1;    //Setter UART_INTERNAL_TX(Transmitter) Til å være OUTPUT!!!!!!LEMONS!!!

UART->PSEL_TXD=6;      //setter PIN 8 til TXD
UART->PSEL_RXD=40;           //Setter PIN 6 til RXD
UART->BAUDRATE=0x00275000;  //setter baudrate lik 9600("IT IS OVER 9000!")"
UART->PSEL_CTS=(1<<31);     //setter registeret PSEL_CTS 6 RTS lik disconnected, 
UART->PSEL_RTS=(1<<31);

UART->ENABLE=4;         //skrur på UARTEN UARTIG Sjhøø.
UART->TASKS_STARTrX=1;


}
void uart_send(char letter){
    UART->TASKS_STARTTX=1;              //gjør klare til sending
    UART->TXD=letter;
    while(UART->EVENTS_TXDRDY==0){      //venter til TXDRDY er klar. 
    
    }
    UART->EVENTS_TXDRDY=0;
    UART->TASKS_STOPTX=1;       //stopper sending

}

char uart_read(){
        //Unnår pakketap
          //leser fra UART linjen
    if(UART->EVENTS_RXDRDY==1){
       
        char c = UART->RXD;
         UART->EVENTS_RXDRDY=0;
         return(c);           //returnerer avlest data om noe relevant har blitt sendt
    }return('\0');
}
#include "gpio.h"
#include "uart.h"
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>




ssize_t _write(int fd, const void *buf, size_t count_doku){
    char * latter = (char*)(buf);
    for (int i =0; i<count_doku; i++){
uart_send(*latter);
latter++;
    }
    return count_doku;
}
ssize_t _read(int fd, void *buf, size_t count){
    char *str=(char*)(buf);
    char letter;
    do{
        letter = uart_read();
    }while(letter == 
    '\0')
    ;
    *str = letter;
    return 1;


}
int main(){
    //int light_switch=0;
    uart_init();
    while(1){
        char str1[3];
                scanf("%2s", str1);
        printf("The number is %i\n", (int)str1[1]*(int)str1[2]);
    }
    

   /*
    while(1){
        
        if(((GPIO0->IN)&(1<<23))==0){  //knapp B
            iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235
            ,2019,2018,'C');       
        }else if(((GPIO0->IN)&(1<<14))==0){     //knapp A
            uart_send('A');
        
        }
     

       char c = uart_read();
       if(c!= '\0'){
           uart_send(c);
           if(light_switch==0){
               gpio_lights_on();
               light_switch=1;
           }else{
               gpio_lights_off();
               light_switch=0;
           }
       }

    

}*/
return 0;
}

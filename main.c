#include <stdint.h>

#define GPIO0 ((NRF_GPIO_REGS0*)0x50000000) //gpio 0 base adress ser på datablad s 144
#define GPIO1 ((NRF_GPIO_REGS1*)0x50000300) //gpio 1 base adress ser på datablad s 144

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_0[118];	//For offset tar vi avstand fra DETECTMODE til PIN_CNF[0] (altså fra 0x528 til 0x700)
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS0;

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_1[118]; //se linje 17, samme prosedyre 
	volatile uint32_t PIN_CNF[10];
} NRF_GPIO_REGS1;

int main(){

	// Configure leds (dere må sjekke selv hvilken GPIO modul de ulike knappene tilhører)
	GPIO0->PIN_CNF[21] = 1; //Row 1
	GPIO0->PIN_CNF[22] = 1; //Row 2
	GPIO0->PIN_CNF[15] = 1; //Row 3
	GPIO0->PIN_CNF[24] = 1; //Row 4
	GPIO0->PIN_CNF[19] = 1; //Row 5

	GPIO0->PIN_CNF[28] = 1; //Col 1
	GPIO0->PIN_CNF[11] = 1; //Col 2
	GPIO0->PIN_CNF[31] = 1; //Col 3
	GPIO1->PIN_CNF[5] = 1;  //Col 4
	GPIO0->PIN_CNF[30] = 1; //Col 5 
	//det stod i oppgaveteksten side 6(FIGURTEKST) hvilke GPIO ting det var
	
	// Configure buttons (dere må sjekke selv hvilken GPIO modul de ulike knappene tilhører)
	GPIO0->PIN_CNF[14] = 0; // button A p0.14
	GPIO0->PIN_CNF[23] = 0; // button B p0.23
	//fant dette dritet på target MCU ischematics
	
	int sleep = 0;
	while(1){
	
		/* Check if button B is pressed;
		 * turn on LED matrix if it is. */
			if(((GPIO0->IN)&(1<<23))==0){	//sjekker for om pinnen på knapp b er lav pga. aktivt lav
				GPIO0->OUT |= 0b00000001011010001000000000000000; //bitstrengen som for forcefedes til microbiten og tvinger den til å skru på alle radene med spenning(s.5 i oppgtxt)
			}
			if(((GPIO0->IN)&(1<<14))==0){ //samme som for knapp a
				GPIO0->OUT &= ~(0b00000001011010001000000000000000);				//skrur av lys
			}
		/* Check if button A is pressed;
		 * turn off LED matrix if it is. */

		sleep = 10000;
		while(--sleep);
	}
	return 0;
}

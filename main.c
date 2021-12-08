/*
 * ArgumentenTest.c
 *
 * Created: Oefening online les
 * voorbereiding op proefwerk AVR-C
 * Author : wim.baert
 */ 

#include "main.h"

int main(void)
{
	volatile uint8_t waarde = 0;
	uint8_t max = 5;
	uint8_t reset = 3;
	//volatile uint8_t reset = 3;
	
	DDRB=0x50; //0b01010000
	volatile uint8_t ddbrstate = initDataDirectionRegister(&DDRB, 0x0F);
	volatile uint8_t portbstate = updatePortRegister(&PORTB, 0x0A);

    while (1) 
    {
		testEnResetVariabele(&waarde,max,reset);		
    }
}

/*
 *	Functienaam : testEnResetVariabele
 *
 *	inputs : variabele, testwaarde, resetwaarde
 *	outputs : variabele,testresultaat
 *	actie : variabele >= testwaarde? variabele=resetwaarde, testresultaat=1
 */
uint8_t testEnResetVariabele(volatile uint8_t* variabele,uint8_t testwaarde,uint8_t resetwaarde)
{
	uint8_t testresultaat = 0;
	
	//De '*' operator is de dereferencing operator
	(*variabele)++;
	if (*variabele >= testwaarde )
	{
		*variabele=resetwaarde;
		testresultaat = 1;		
	}	
	return testresultaat;
}

/*
 *	Functienaam : updatePortRegister
 *
 *	inputs : pointer naar register, instelwaarde
 *	outputs : nieuwe toestand van het register
 *	actie : reg |= waarde 
 */
volatile uint8_t updatePortRegister(uint8_t* reg, uint8_t value)
{
	(*reg)|=value;
	 return (*reg);	
}

/*
 *	Functienaam : readPinRegister
 *
 *	inputs : pointer naar register
 *	outputs : inhoud van register
 *	actie : -
 *
 */
volatile uint8_t readPinRegister(uint8_t* reg)
{
	return *reg;
}

/*
 *	Functienaam : initDataDirectionRegister
 *
 *	inputs : pointer naar register, instelwaarde
 *	outputs : nieuwe toestand van het register
 *	actie : reg |= waarde
 *
 */
volatile uint8_t initDataDirectionRegister(uint8_t* reg, uint8_t value)
{
	(*reg)|=value;  // *reg = *reg | value
	 return (*reg);	
}




/*
 * main.h
 *
 * Created: 7/12/2021 10:24:49
 *  Author: wim.baert
 */ 
#define F_CPU 16000000
#include <avr/io.h>

uint8_t testEnResetVariabele(volatile uint8_t*,uint8_t,uint8_t);
volatile uint8_t updateDataDirectionRegister(uint8_t*, uint8_t);
volatile uint8_t initDataDirectionRegister(uint8_t*, uint8_t);
volatile uint8_t updatePortRegister(uint8_t*, uint8_t);
volatile uint8_t initPortRegister(uint8_t*, uint8_t);
volatile uint8_t readPinRegister(uint8_t*);

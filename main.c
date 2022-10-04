/*
 * File:   main.c
 * Author: Frederik Borregaard
 *
 * Created on 4. oktober 2022, 19:23
 */

#include "config.h" // Henter alle vores indstillinger fra en samlede fil
// Denne v�rdi bruges til at f� en timeren til at interrupt efter 1 millisekund
const uint8_t TMR0_TIME = 217; 

// Disse variabler bruges til at gemme hvor langt tid vi har k�rt vores program
uint16_t ms_time = 0;
int sec_time = 0;

// ------------------ Custom Funktioner ------------------
// Her definere vi vores referance 
// for vores egen funktioner

int eksempel_funktion(int a, int b);

// ------------------ Custom Funktioner ------------------


// ------------------- interrupt timer -------------------
// Timer0 er en 8-bit timer/t�ller med 8-bit prescaler
// __interrupt funktion kaldes n�r TMR0 bliver 0 og
// TMR0IF bliver sat til 1 af microcontrolleren. 
// Derefter rester vi TRM0IF til 0 og TRM0 til 
// vores konstant TRM0_TIME, som var 217.
// Denne funktion ville altid k�rer i baggrund 
// uden at p�virke andre dele af programmet.
// ------------------- interrupt timer -------------------
void __interrupt() ISR() {
    if (INTCONbits.TMR0IF == 1) {
        INTCONbits.TMR0IF = 0; //  Reset timer flaget

        ms_time++;
        if (ms_time == 1000) {
            ms_time = 0;
            sec_time++;
        }

        TMR0 = TMR0_TIME; // Geninds�t timerv�rdien
    }
}

// ----------------------- Setup -------------------------
// setup ops�tning af SFR
// Special Function Registre
// setup af vores porte 
// setup vores timer til at 
// k�rer med det �nskede interval
// ----------------------- Setup -------------------------
void setup() {
    TRISB = 0xff;
    TRISC = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;

    TMR0 = TMR0_TIME;

    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;

    OPTION_REGbits.T0CS = 0; //intern clock
    OPTION_REGbits.T0SE = 0; // lige gyldig
    OPTION_REGbits.PSA = 0; // timer ikke WDT
    OPTION_REGbits.PS2 = 1;
    OPTION_REGbits.PS1 = 0;
    OPTION_REGbits.PS0 = 1;
}


// ------------------- Main funktion ---------------------
// Main funktionen er der hvor vi �nsker at g�rer 
// St�rste delen af vores program for at 
// hele programmet s� organiseret som muligt
// ------------------- Main funktion ---------------------
void main(void) {
    setup();

    int a = 2;
    int b = 6;
    
    while(1) {
        int resultat = eksempel_funktion(a, b);
        PORTC = resultat;
    }
}

// Her har er der lavet et eksempel p� en 
// funktion som tager to integer som 
// input og returner summen af dem
int eksempel_funktion(int a, int b) {
    return a + b;
}
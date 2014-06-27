/* 
 * File:   main.c
 * Author: Diego Santinelli
 *
 * Created on 15 aprile 2014, 19.15
 */
#include <xc.h>
#include "LM35.h"

#define _XTAL_FREQ 8000000



// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Detect (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)



void init()
{

    //ALL INPUT //GP5 OUTPUT
    TRISIO = 0b011111;


    //ADC define
    ADCON0 = 0b00001101;
            ///0------- LEFT Giustified
            ///----11-- AN3 active
            ///------0- GODONE
            ///-------1 ADON

    CMCON0bits.CM = 0b111;

}


void main(void) {

     
    init();

    while(1)
    {

        if (switchOn())
        {

            GPIObits.GP5 = 1;
            //GPIO = 0b010000;

        }
        else
            GPIObits.GP5 = 0;
            

        //__delay_ms(5000);
    }
}



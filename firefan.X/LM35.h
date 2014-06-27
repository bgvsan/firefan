/* 
 * File:   LM35.h
 * Author: diego
 *
 * Created on 25 aprile 2014, 9.55
 */

#ifndef LM35_H
#define	LM35_H


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LM35_H */

#define maxTemperature 60
#define minTemperature 50

//calculate the temperature from the AN3 LM35 connected
float getTemperature(void);
int switchOn(void);

float getTemperature()

{
    float temperature;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO_nDONE)
    {
        ;
    }

    //unsigned int ADvalue = ADRESH;
    unsigned int ADvalue=ADRESL + (ADRESH << 8);
    int rawvoltage= (ADvalue>>6);
    float millivolts= (rawvoltage/1024.0) * 5000;
    float temperature= millivolts/10;

    return temperature;

}

int switchOn(void)
{
    float temperature ;
    temperature = getTemperature();

    if(GPIObits.GP5 == 0)
    {
        if (temperature > maxTemperature)
            return 1;
        else
            return 0;
    }
    else
    {
        if(temperature < minTemperature)
            return 0;
        else
            return 1;
    }

}

/*
 * File:   Lab3p2.c
 * Author: MiguelAnguel
 * Created on March 29, 2015, 11:36 AM
 */

#include "p24fj64ga002.h"
#include "lcd.h"
#include "timer.h"
#include "adc.h"
#include "pwm.h"
#include <stdio.h>

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

#define true 1   // define true to use with bool data type.
#define false 0  // define false for bool data type.

volatile int val;

int main(void) {

    char v[10];
    float voltage;
    initPWM();
    initADC();
    initLCD();
    clearLCD();

    while(1){
        clearLCD();
        voltage = 3.285* ((float) val)/1023;
        sprintf(v,"%.3f V",voltage);
        printStringLCD(v);
        delayMs(10);
    }
    return 1;
}

// ******************************************************************************************* //

void _ISR_ADC1Interrupt(void){
    IFS0bits.AD1IF = 0;


    val = ADC1BUF0;
}
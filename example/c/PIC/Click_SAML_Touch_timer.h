/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_SAML_Touch_types.h"

uint32_t timerCounter = 0;

static void samltouch_configTimer()
{
  T1CON         = 0x01;
  TMR1IF_bit         = 0;
  TMR1H         = 0xC1;
  TMR1L         = 0x80;
  TMR1IE_bit         = 1;
  INTCON         = 0xC0;
}

void Interrupt()
{
    if (TMR1IF_bit != 0)
    {
        TMR1IF_bit = 0;
        TMR1H         = 0xC1;
        TMR1L         = 0x80;
                
            samltouch_tick();
                timerCounter++;
    }
}
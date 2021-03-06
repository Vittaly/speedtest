/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1827
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "cos_tab.h"
#include <stdlib.h>

const int16_t START_ARROW_POSITION = 180 << 2; // degree * 4
const uint8_t DegreePerKm7 = 120; // degree per km * 128
    
    
int getArrowDegree4(uint32_t p_speed4) 
 
    { 
     uint32_t r1 = p_speed4 * DegreePerKm7;
     uint16_t r2 = r1 >> 7;
     return (r2 > START_ARROW_POSITION) ? (360 << 2) + START_ARROW_POSITION - r2 : START_ARROW_POSITION - r2;
    }

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    

    int16_t arrow_degree = START_ARROW_POSITION; // degree  * 4
    int16_t speed4 = 0;
    int16_t hor_pwm_duty;
    int16_t vert_pwm_duty;
    bool speed_up = true;
    
   

    while (1)
    {
      arrow_degree = getArrowDegree4(speed4);
     // hor_pwm_duty = cos15(360);
      hor_pwm_duty = cos15(arrow_degree);
      
      if (hor_pwm_duty < 0)  
          //Invert_hor_SetHigh();
          LATAbits.LATA1 = 1;
      else 
         // Invert_hor_SetLow();
          LATAbits.LATA1 = 0;
      PWM3_LoadDutyValue(abs(hor_pwm_duty)>>7);

      
      vert_pwm_duty = sin15(arrow_degree);
      if (vert_pwm_duty < 0)  
          Invert_vert_SetHigh();
      else 
          Invert_vert_SetLow();
      PWM4_LoadDutyValue(abs(vert_pwm_duty) >> 7);
      speed4 += (speed_up?1:-1);
      if (speed4 > 220 * 4) speed_up = false;
      else if (speed4 <=0 ) speed_up = true;
      __delay_ms(5);
      
    }
}
/**
 End of File
*/
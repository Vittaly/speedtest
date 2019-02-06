/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1827
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SpeedSens aliases
#define SpeedSens_TRIS                 TRISAbits.TRISA0
#define SpeedSens_LAT                  LATAbits.LATA0
#define SpeedSens_PORT                 PORTAbits.RA0
#define SpeedSens_ANS                  ANSELAbits.ANSA0
#define SpeedSens_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SpeedSens_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SpeedSens_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SpeedSens_GetValue()           PORTAbits.RA0
#define SpeedSens_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SpeedSens_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SpeedSens_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SpeedSens_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set Invert_hor aliases
#define Invert_hor_TRIS                 TRISAbits.TRISA1
#define Invert_hor_LAT                  LATAbits.LATA1
#define Invert_hor_PORT                 PORTAbits.RA1
#define Invert_hor_ANS                  ANSELAbits.ANSA1
#define Invert_hor_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define Invert_hor_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define Invert_hor_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define Invert_hor_GetValue()           PORTAbits.RA1
#define Invert_hor_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define Invert_hor_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define Invert_hor_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define Invert_hor_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set Invert_vert aliases
#define Invert_vert_TRIS                 TRISAbits.TRISA2
#define Invert_vert_LAT                  LATAbits.LATA2
#define Invert_vert_PORT                 PORTAbits.RA2
#define Invert_vert_ANS                  ANSELAbits.ANSA2
#define Invert_vert_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define Invert_vert_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define Invert_vert_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define Invert_vert_GetValue()           PORTAbits.RA2
#define Invert_vert_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define Invert_vert_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define Invert_vert_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define Invert_vert_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSA4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
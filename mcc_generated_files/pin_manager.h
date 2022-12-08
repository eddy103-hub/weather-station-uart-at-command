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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F57Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set adcIn aliases
#define adcIn_TRIS                 TRISAbits.TRISA1
#define adcIn_LAT                  LATAbits.LATA1
#define adcIn_PORT                 PORTAbits.RA1
#define adcIn_WPU                  WPUAbits.WPUA1
#define adcIn_OD                   ODCONAbits.ODCA1
#define adcIn_ANS                  ANSELAbits.ANSELA1
#define adcIn_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define adcIn_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define adcIn_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define adcIn_GetValue()           PORTAbits.RA1
#define adcIn_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define adcIn_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define adcIn_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define adcIn_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define adcIn_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define adcIn_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define adcIn_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define adcIn_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSELA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set SW0 aliases
#define SW0_TRIS                 TRISBbits.TRISB4
#define SW0_LAT                  LATBbits.LATB4
#define SW0_PORT                 PORTBbits.RB4
#define SW0_WPU                  WPUBbits.WPUB4
#define SW0_OD                   ODCONBbits.ODCB4
#define SW0_ANS                  ANSELBbits.ANSELB4
#define SW0_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SW0_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SW0_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SW0_GetValue()           PORTBbits.RB4
#define SW0_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SW0_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SW0_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SW0_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SW0_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SW0_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SW0_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SW0_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RF0 procedures
#define RF0_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define RF0_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define RF0_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define RF0_GetValue()              PORTFbits.RF0
#define RF0_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define RF0_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define RF0_SetPullup()             do { WPUFbits.WPUF0 = 1; } while(0)
#define RF0_ResetPullup()           do { WPUFbits.WPUF0 = 0; } while(0)
#define RF0_SetAnalogMode()         do { ANSELFbits.ANSELF0 = 1; } while(0)
#define RF0_SetDigitalMode()        do { ANSELFbits.ANSELF0 = 0; } while(0)

// get/set RF1 procedures
#define RF1_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define RF1_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define RF1_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define RF1_GetValue()              PORTFbits.RF1
#define RF1_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define RF1_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define RF1_SetPullup()             do { WPUFbits.WPUF1 = 1; } while(0)
#define RF1_ResetPullup()           do { WPUFbits.WPUF1 = 0; } while(0)
#define RF1_SetAnalogMode()         do { ANSELFbits.ANSELF1 = 1; } while(0)
#define RF1_SetDigitalMode()        do { ANSELFbits.ANSELF1 = 0; } while(0)

// get/set LED0 aliases
#define LED0_TRIS                 TRISFbits.TRISF3
#define LED0_LAT                  LATFbits.LATF3
#define LED0_PORT                 PORTFbits.RF3
#define LED0_WPU                  WPUFbits.WPUF3
#define LED0_OD                   ODCONFbits.ODCF3
#define LED0_ANS                  ANSELFbits.ANSELF3
#define LED0_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define LED0_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define LED0_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define LED0_GetValue()           PORTFbits.RF3
#define LED0_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define LED0_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define LED0_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define LED0_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define LED0_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define LED0_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

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
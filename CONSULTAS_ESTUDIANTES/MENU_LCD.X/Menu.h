/* 
 * File:   Menu.h
 * Author: iProf
 *
 * Created on 14 de octubre de 2023, 12:08 PM
 */

#ifndef MENU_H
#define	MENU_H

#include <xc.h>
#include "config.h"
#include "ADC.h"
#include "LCD_LIB.h"

#define L1_Dir         TRISAbits.TRISA2
#define L1_Ansel       ANSELAbits.ANSA2
#define L1_LAT         LATAbits.LATA2

#define L2_Dir         TRISAbits.TRISA3
#define L2_Ansel       ANSELAbits.ANSA3
#define L2_LAT         LATAbits.LATA3

#define L3_Dir         TRISAbits.TRISA4
#define L3_Ansel       ANSELAbits.ANSA4
#define L3_LAT         LATAbits.LATA4

#define BTN_UP_Dir     TRISBbits.TRISB0
#define BTN_UP_Ansel   ANSELBbits.ANSB0
#define BTN_UP_PORT    PORTBbits.RB0

#define BTN_DOWN_Dir   TRISBbits.TRISB1
#define BTN_DOWN_Ansel ANSELBbits.ANSB1
#define BTN_DOWN_PORT   PORTBbits.RB1

#define BTN_SEL_Dir    TRISBbits.TRISB2
#define BTN_SEL_Ansel  ANSELBbits.ANSB2
#define BTN_SEL_PORT   PORTBbits.RB2

#define MA1_Dir        TRISBbits.TRISB3
#define MA1_Ansel      ANSELBbits.ANSB3
#define MA1_LAT        LATBbits.LATB3

#define MA2_Dir        TRISBbits.TRISB4
#define MA2_Ansel      ANSELBbits.ANSB4
#define MA2_LAT        LATBbits.LATB4

#define MB1_Dir        TRISBbits.TRISB5
#define MB1_Ansel      ANSELBbits.ANSB2
#define MB1_LAT        LATBbits.LATB5

#define MB2_Dir        TRISBbits.TRISB6
#define MB2_LAT        LATBbits.LATB6

#define LM35_Dir       TRISAbits.TRISA0
#define LM35_Ansel     ANSELAbits.ANSA0
#define LM35_Ch        0

#define LDR_Dir        TRISAbits.TRISA1
#define LDR_Ansel      ANSELAbits.ANSA1
#define LDR_Ch         1

void SystemInit();

void MA_TurnR();
void MA_TurnL();
void MA_Off();
void MB_TurnR();
void MB_TurnL();
void MB_Off();
float getLM35_Value();
float getLDR_Value();

void MenuPPAL();
void MenuSensores();
void MenuMotores();
void MenuLeds();
void MenuL1();
void MenuL2();
void MenuL3();
void MenuMOTORA();
void MenuMOTORB();






#endif	/* MENU_H */


#include "Menu.h"
#include <stdio.h>


enum{
    MPPAL,
    MSENSORES,
    MLEDS,
    MMOTORES,
    ML1,
    ML2,
    ML3,
    MMOTORA,
    MMOTORB        
};

extern char cMenu;
char op=1;

char strLCD[20]=" ";
int conver;
float lm35, ldr;

void SystemInit(){
    OSCCON  = 0x38;
    OSCTUNE = 0x00;
    BORCON  = 0x00;
    
    L1_Ansel = 0;
    L2_Ansel = 0;
    L3_Ansel = 0;
    
    L1_Dir = 0;
    L2_Dir = 0;
    L3_Dir = 0;
    
    MA1_Ansel = 0; 
    MA2_Ansel = 0; 
    MB1_Ansel = 0; 
    
    MA1_Dir = 0;
    MA2_Dir = 0;
    MB1_Dir = 0;
    MB2_Dir = 0;
    
    LM35_Ansel = 1;
    LDR_Ansel = 1;
    
    LM35_Dir = 1;
    LDR_Dir  = 1;
    
    BTN_UP_Ansel = 0;
    BTN_DOWN_Ansel = 0;
    BTN_SEL_Ansel = 0;
    
    BTN_UP_Dir = 1;
    BTN_DOWN_Dir = 1;
    BTN_SEL_Dir = 1;
    
    L1_LAT = 0;
    L2_LAT = 0;
    L3_LAT = 0;
    
    MA1_LAT = 0;
    MA2_LAT = 0;
    MB1_LAT = 0;
    MB2_LAT = 0;
    
    LCD_Init();
    LCD_Cmd(_LCD_CURSOR_OFF);
    
    ADC_Init();
            
    
}

void MA_TurnR(){
    MA1_LAT = 1;
    MA2_LAT = 0;
}
void MA_TurnL(){
    MA1_LAT = 0;
    MA2_LAT = 1;
}
void MA_Off(){
    MA1_LAT = 0;
    MA2_LAT = 0;
}
void MB_TurnR(){
    MB1_LAT = 1;
    MB2_LAT = 0;
}
void MB_TurnL(){
    MB1_LAT = 0;
    MB2_LAT = 1;
}
void MB_Off(){
   MB1_LAT = 0;
   MB2_LAT = 0; 
}
float getLM35_Value(){
    
}
float getLDR_Value(){
    
}

void MenuPPAL(){
    //                  12345678901234567890
    LCD_Write_Text(1,1,"       MENU PPAL    ");
    LCD_Write_Text(2,1,"1.MOTORES   3.LEDS  ");
    LCD_Write_Text(3,1,"2.SENSORES          ");
    LCD_Write_Text(4,1,"OP:                 ");
    LCD_Write(4,4,op+48);
    
    switch(op){
        case 1: LCD_Write(2,10,'<');
                LCD_Write(3,11,' ');
                LCD_Write(2,19,' ');
                break;
        case 2: LCD_Write(2,10,' ');
                LCD_Write(3,11,'<');
                LCD_Write(2,19,' ');
                break;
        case 3: LCD_Write(2,10,' ');
                LCD_Write(3,11,' ');
                LCD_Write(2,19,'<');
                break;
    }
    
    if(BTN_UP_PORT == 1){
        while(BTN_UP_PORT == 1);
        op++;
        if(op>3)
            op=1;
    }
    if(BTN_DOWN_PORT == 1){
        while(BTN_DOWN_PORT == 1);
        op--;
        if(op<1)
            op=3;
    }
    if(BTN_SEL_PORT == 1){
        while(BTN_SEL_PORT == 1);
        switch(op){
            case 1: cMenu=MMOTORES;  op=1; break;
            case 2: cMenu=MSENSORES; op=1; break;
            case 3: cMenu=MLEDS;     op=1; break;
        }
        LCD_Cmd(_LCD_CLEAR);
    }
    
    
}
void MenuSensores(){
    
    
    //                  12345678901234567890
    LCD_Write_Text(1,1,"   MENU SENSORES    ");
    //LCD_Write_Text(2,1,"LM35:               ");
    //LCD_Write_Text(3,1,"LDR:                ");
    LCD_Write_Text(4,1,"SEL TO BACK         ");
    
    
    conver = ADC_Get_Value(LM35_Ch);
    lm35   = conver*150.0/306.9;
    sprintf(strLCD,"LM35: %6.1f",lm35);
    LCD_Write_Text(2,1,strLCD);
    
    conver = ADC_Get_Value(LDR_Ch);
    ldr   = (conver/1023.0)*100.0;
    sprintf(strLCD,"LDR: %6.1f",ldr);
    LCD_Write_Text(3,1,strLCD);
    
    
    
    if(BTN_SEL_PORT == 1){
        while(BTN_SEL_PORT == 1);
        cMenu = MPPAL;
        
    }
    __delay_ms(100);
    
}
void MenuMotores(){
    //                  12345678901234567890
    LCD_Write_Text(1,1,"   MENU MOTORES     ");
    LCD_Write_Text(2,1,"1.MOTORA    3.BACK  ");
    LCD_Write_Text(3,1,"2.MOTORB            ");
    LCD_Write_Text(4,1,"OP:                 ");
    
    LCD_Write(4,4,op+48);
    
    switch(op){
        case 1: LCD_Write(2,9,'<');
                LCD_Write(3,9,' ');
                LCD_Write(2,19,' ');
                break;
        case 2: LCD_Write(2,9,' ');
                LCD_Write(3,9,'<');
                LCD_Write(2,19,' ');
                break;
        case 3: LCD_Write(2,9,' ');
                LCD_Write(3,9,' ');
                LCD_Write(2,19,'<');
                break;
    }
    
    if(BTN_UP_PORT == 1){
        while(BTN_UP_PORT == 1);
        op++;
        if(op>3)
            op=1;
    }
    if(BTN_DOWN_PORT == 1){
        while(BTN_DOWN_PORT == 1);
        op--;
        if(op<1)
            op=3;
    }
    if(BTN_SEL_PORT == 1){
        while(BTN_SEL_PORT == 1);
        switch(op){
            case 1: cMenu=MMOTORA;   op=1; break;
            case 2: cMenu=MMOTORB;   op=1; break;
            case 3: cMenu=MPPAL;     op=1; break;
        }
        LCD_Cmd(_LCD_CLEAR);
    }
    
}
void MenuLeds(){
    //                  12345678901234567890
    LCD_Write_Text(1,1,"       MENU LEDS    ");
    LCD_Write_Text(2,1,"1.L1    3.L3        ");
    LCD_Write_Text(3,1,"2.L2    4.BACK      ");
    LCD_Write_Text(4,1,"OP:                 ");
    LCD_Write(4,4,op+48);
    
    switch(op){
        case 1: LCD_Write(2,5,'<');
                LCD_Write(3,5,' ');
                LCD_Write(2,13,' ');
                LCD_Write(3,15,' ');
                break;
        case 2: LCD_Write(2,5,' ');
                LCD_Write(3,5,'<');
                LCD_Write(2,13,' ');
                LCD_Write(3,15,' ');
                break;
        case 3: LCD_Write(2,5,' ');
                LCD_Write(3,5,' ');
                LCD_Write(2,13,'<');
                LCD_Write(3,15,' ');
                break;
        case 4: LCD_Write(2,5,' ');
                LCD_Write(3,5,' ');
                LCD_Write(2,13,' ');
                LCD_Write(3,15,'<');
                break;
    }
    
    if(BTN_UP_PORT == 1){
        while(BTN_UP_PORT == 1);
        op++;
        if(op>4)
            op=1;
    }
    if(BTN_DOWN_PORT == 1){
        while(BTN_DOWN_PORT == 1);
        op--;
        if(op<1)
            op=3;
    }
    if(BTN_SEL_PORT == 1){
        while(BTN_SEL_PORT == 1);
        switch(op){
            case 1: cMenu=ML1;   op=1; break;
            case 2: cMenu=ML2;   op=1; break;
            case 3: cMenu=ML3;   op=1; break;
            case 4: cMenu=MPPAL; op=1; break;
        }
        LCD_Cmd(_LCD_CLEAR);
    }
}

void MenuL1(){
    //                  12345678901234567890
    LCD_Write_Text(1,1,"       MENU LED1    ");
    LCD_Write_Text(2,1,"1.ON    3.BACK      ");
    LCD_Write_Text(3,1,"2.OFF               ");
    LCD_Write_Text(4,1,"OP:                 ");
    LCD_Write(4,4,op+48);
    
    switch(op){
        case 1: LCD_Write(2,5,'<');
                LCD_Write(3,6,' ');
                LCD_Write(2,15,' ');
                break;
        case 2: LCD_Write(2,5,' ');
                LCD_Write(3,6,'<');
                LCD_Write(2,15,' ');
                break;
        case 3: LCD_Write(2,5,' ');
                LCD_Write(3,6,' ');
                LCD_Write(2,15,'<');
                break;
    }
    
    if(BTN_UP_PORT == 1){
        while(BTN_UP_PORT == 1);
        op++;
        if(op>3)
            op=1;
    }
    if(BTN_DOWN_PORT == 1){
        while(BTN_DOWN_PORT == 1);
        op--;
        if(op<1)
            op=3;
    }
    if(BTN_SEL_PORT == 1){
        while(BTN_SEL_PORT == 1);
        switch(op){
            case 1: L1_LAT=1;    break;
            case 2: L1_LAT=0;    break;
            case 3: cMenu=MLEDS; op=1; break;
        }
        LCD_Cmd(_LCD_CLEAR);
    }
}
void MenuL2(){
    //                  12345678901234567890
    LCD_Write_Text(1,1,"       MENU LED2    ");
    LCD_Write_Text(2,1,"1.ON    3.BACK      ");
    LCD_Write_Text(3,1,"2.OFF               ");
    LCD_Write_Text(4,1,"OP:                 ");
    LCD_Write(4,4,op+48);
    
    switch(op){
        case 1: LCD_Write(2,5,'<');
                LCD_Write(3,6,' ');
                LCD_Write(2,15,' ');
                break;
        case 2: LCD_Write(2,5,' ');
                LCD_Write(3,6,'<');
                LCD_Write(2,15,' ');
                break;
        case 3: LCD_Write(2,5,' ');
                LCD_Write(3,6,' ');
                LCD_Write(2,15,'<');
                break;
    }
    
    if(BTN_UP_PORT == 1){
        while(BTN_UP_PORT == 1);
        op++;
        if(op>3)
            op=1;
    }
    if(BTN_DOWN_PORT == 1){
        while(BTN_DOWN_PORT == 1);
        op--;
        if(op<1)
            op=3;
    }
    if(BTN_SEL_PORT == 1){
        while(BTN_SEL_PORT == 1);
        switch(op){
            case 1: L2_LAT=1;    break;
            case 2: L2_LAT=0;    break;
            case 3: cMenu=MLEDS; op=1; break;
        }
        LCD_Cmd(_LCD_CLEAR);
    }
}
void MenuL3(){
    //                  12345678901234567890
    LCD_Write_Text(1,1,"       MENU LED3    ");
    LCD_Write_Text(2,1,"1.ON    3.BACK      ");
    LCD_Write_Text(3,1,"2.OFF               ");
    LCD_Write_Text(4,1,"OP:                 ");
    LCD_Write(4,4,op+48);
    
    switch(op){
        case 1: LCD_Write(2,5,'<');
                LCD_Write(3,6,' ');
                LCD_Write(2,15,' ');
                break;
        case 2: LCD_Write(2,5,' ');
                LCD_Write(3,6,'<');
                LCD_Write(2,15,' ');
                break;
        case 3: LCD_Write(2,5,' ');
                LCD_Write(3,6,' ');
                LCD_Write(2,15,'<');
                break;
    }
    
    if(BTN_UP_PORT == 1){
        while(BTN_UP_PORT == 1);
        op++;
        if(op>3)
            op=1;
    }
    if(BTN_DOWN_PORT == 1){
        while(BTN_DOWN_PORT == 1);
        op--;
        if(op<1)
            op=3;
    }
    if(BTN_SEL_PORT == 1){
        while(BTN_SEL_PORT == 1);
        switch(op){
            case 1: L3_LAT=1;    break;
            case 2: L3_LAT=0;    break;
            case 3: cMenu=MLEDS; op=1; break;
        }
        LCD_Cmd(_LCD_CLEAR);
    }
}
void MenuMOTORA(){
    //                  12345678901234567890
    LCD_Write_Text(1,1,"     MENU MOTORA    ");
    LCD_Write_Text(2,1,"1.TURNR    3.OFF    ");
    LCD_Write_Text(3,1,"2.TURNL    4.BACK   ");
    LCD_Write_Text(4,1,"OP:                 ");
    
    LCD_Write(4,4,op+48);
    
    switch(op){
        case 1: LCD_Write(2,8,'<');
                LCD_Write(3,8,' ');
                LCD_Write(2,17,' ');
                LCD_Write(3,18,' ');
                break;
        case 2: LCD_Write(2,8,' ');
                LCD_Write(3,8,'<');
                LCD_Write(2,17,' ');
                LCD_Write(3,18,' ');
                break;
        case 3: LCD_Write(2,8,' ');
                LCD_Write(3,8,' ');
                LCD_Write(2,17,'<');
                LCD_Write(3,18,' ');
                break;
        case 4: LCD_Write(2,8,' ');
                LCD_Write(3,8,' ');
                LCD_Write(2,17,' ');
                LCD_Write(3,18,'<');
                break;
    }
    
    if(BTN_UP_PORT == 1){
        while(BTN_UP_PORT == 1);
        op++;
        if(op>4)
            op=1;
    }
    if(BTN_DOWN_PORT == 1){
        while(BTN_DOWN_PORT == 1);
        op--;
        if(op<1)
            op=3;
    }
    if(BTN_SEL_PORT == 1){
        while(BTN_SEL_PORT == 1);
        switch(op){
            case 1: MA_TurnR();    break;
            case 2: MA_TurnL();    break;
            case 3: MA_Off();      break;
            case 4: cMenu=MMOTORES; 
                    op=1; 
                    LCD_Cmd(_LCD_CLEAR);
                    break;
        }
        
    }
    
}
void MenuMOTORB(){
    //                  12345678901234567890
    LCD_Write_Text(1,1,"     MENU MOTORB    ");
    LCD_Write_Text(2,1,"1.TURNR    3.OFF    ");
    LCD_Write_Text(3,1,"2.TURNL    4.BACK   ");
    LCD_Write_Text(4,1,"OP:                 ");
    
    LCD_Write(4,4,op+48);
    
    switch(op){
        case 1: LCD_Write(2,8,'<');
                LCD_Write(3,8,' ');
                LCD_Write(2,17,' ');
                LCD_Write(3,18,' ');
                break;
        case 2: LCD_Write(2,8,' ');
                LCD_Write(3,8,'<');
                LCD_Write(2,17,' ');
                LCD_Write(3,18,' ');
                break;
        case 3: LCD_Write(2,8,' ');
                LCD_Write(3,8,' ');
                LCD_Write(2,17,'<');
                LCD_Write(3,18,' ');
                break;
        case 4: LCD_Write(2,8,' ');
                LCD_Write(3,8,' ');
                LCD_Write(2,17,' ');
                LCD_Write(3,18,'<');
                break;
    }
    
    if(BTN_UP_PORT == 1){
        while(BTN_UP_PORT == 1);
        op++;
        if(op>4)
            op=1;
    }
    if(BTN_DOWN_PORT == 1){
        while(BTN_DOWN_PORT == 1);
        op--;
        if(op<1)
            op=3;
    }
    if(BTN_SEL_PORT == 1){
        while(BTN_SEL_PORT == 1);
        switch(op){
            case 1: MB_TurnR();    break;
            case 2: MB_TurnL();    break;
            case 3: MB_Off();      break;
            case 4: cMenu=MMOTORES; 
                    op=1; 
                    LCD_Cmd(_LCD_CLEAR);
                    break;
        }
        
    }
    
}
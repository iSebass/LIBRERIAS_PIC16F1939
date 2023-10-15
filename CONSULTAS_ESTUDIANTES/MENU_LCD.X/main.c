#include <xc.h>
#include "config.h"
#include "Menu.h"

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

char cMenu=MPPAL;

void main(void){
   
    SystemInit();
   
    while(1){
       
        switch(cMenu){
            case MPPAL:     MenuPPAL();     break;
            case MSENSORES: MenuSensores(); break;
            case MLEDS:     MenuLeds();     break;
            case MMOTORES:  MenuMotores();  break;
            case ML1:       MenuL1();       break;
            case ML2:       MenuL2();       break;
            case ML3:       MenuL3();       break;
            case MMOTORA:   MenuMOTORA();   break;
            case MMOTORB:   MenuMOTORB();   break;
        }
        
        __delay_ms(50);
        
    }
    
    return;
}
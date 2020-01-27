/*
 * File:   CARRERAS.c
 * Author: CHARLIE
 *
 * Created on 22 de enero de 2020, 14:41
 */

// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define LED_RED     RD2
#define LED_GREEN   RD4
#define LED_YELLOW  RD3
#define LED_GA1     RD0
#define LED_GA2     RD7
#define START_BOT   RE3
#define PLAYER_1BOT RE1
#define PLAYER_2BOT RE2
#define BUZZER      RD6
#define BOCINA      RD5 
#define _XTAL_FREQ  4000000
unsigned char DISPLAY[] = { 0x3F, 0x06, 0x5b,0x4F};
unsigned char CONTADORA[] = {0b00000000,0b00000001,0b00000011,0b00000111,0b00001111,0b00011111,0b00111111,0b01111111,0b11111111};
unsigned char CONTADORB[] = {0b00000000,0b00000001,0b00000011,0b00000111,0b00001111,0b00011111,0b00111111,0b01111111,0b11111111};
unsigned char locura[] = {0b00000001,0b00000010,0b01000000,0b00010000,0b00001000,0b00000100,0b01000000,0b00100000,0b00000001};
unsigned char i = 0;
unsigned char x = 0;
unsigned char y = 0;
unsigned char z = 0;
unsigned char antireboteA = 0;
unsigned char antireboteB = 0;
void JUEGO(void); 
void CARRERITA(void);




void main(void)
{
    OSCCON =0b110;
    
    ANSEL = 0b00000000;
    ANSELH = 0b00000000;
    TRISA = 0b00000000;
    TRISB = 0b00000000; 
    TRISC = 0b00000000;
    TRISD = 0b00000000;
    TRISE = 1;
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 1;
    
    char  i=3;
    char  x = 0;
    char y = 0;
    char z = 0;
    
    char antireboteA = 0;
    char antireboteB = 0;
    JUEGO();
    return;
    
}

void JUEGO(void){
while (1){
    
      
        if(START_BOT==1)
    {
           
            
            i = 3;
        LED_RED = 1;
        BUZZER  = 1;
        
        PORTC   = DISPLAY[i];
        __delay_ms(5);
        LED_RED = 0;
        BUZZER  = 0;
        i=i-1;
        __delay_ms(5);
        
        LED_YELLOW = 1;
        BUZZER  = 1;
        PORTC   = DISPLAY[i];
        __delay_ms(5);
        LED_YELLOW = 0;
        BUZZER  = 0;
        i=i-1;
        __delay_ms(5);
        
        LED_GREEN = 1;
        BUZZER  = 1;
        PORTC   = DISPLAY[i];
        __delay_ms(5);
        LED_GREEN = 0;
        BUZZER  = 0;
        i=i-1;
        __delay_ms(5);
        LED_GREEN = 1;
        LED_YELLOW = 1;
        LED_RED = 1;
        BUZZER  = 1;
        BOCINA = 1;
        PORTC   = DISPLAY[i];
        __delay_ms(5);
        LED_GREEN = 1;
        LED_YELLOW = 0;
        LED_RED = 0;
        BUZZER  = 0;
        BOCINA = 0;
        
        CARRERITA();
        return;
        
    }
        else
        {
            unsigned char i =0;
            unsigned char z = 0;
            unsigned char antireboteA = 0;
            unsigned char antireboteB = 0;
                 LED_RED    = 1;
                 LED_YELLOW = 0;
                 LED_GREEN  = 0;
                 BUZZER     = 0;
                 i = 0;
        }
    }
   
    
    
  
}
void CARRERITA(void){
    while(1){
        
        z=z+1;
        __delay_ms(0.35);
        PORTC=locura[z];
        if(z==9){
            z=0;
            PORTC= locura[1];
            
        }
        if(PLAYER_1BOT==1){
            antireboteA = 1;
        }
            if(PLAYER_1BOT!=1 && antireboteA==1){
                
                antireboteA=0;
            x= x+1;
                    PORTA=CONTADORA[x];
                    if(x==8){
                        __delay_ms(5);
                        x=0;
                        PORTA=CONTADORA[x];
                        __delay_ms(5);
                        i= 1;
                        PORTC = DISPLAY[i];          
                        __delay_ms(1);
                        BUZZER = 0;
                        LED_GA1=0;
                        __delay_ms(1);
                        BUZZER = 1;
                        LED_GA1=1;
                        __delay_ms(1);
                        BUZZER = 0;
                        LED_GA1=0;
                        __delay_ms(1);
                        BUZZER = 1;
                        LED_GA1=1;
                         __delay_ms(1);
                        BUZZER = 0;
                        LED_GA1=0;
                        __delay_ms(1);
                        BUZZER = 1;
                        LED_GA1=1;
                        __delay_ms(2);
                        LED_GA1 = 0;
                        BUZZER=0;
                        return;
                    }
            }
           
           
        
        if(PLAYER_2BOT==1){
            antireboteB=1;
        }
            if(PLAYER_2BOT!=1 && antireboteB == 1){
                
                antireboteB=0;
            y= y+1;
                    PORTB=CONTADORB[y];
                    if(y==8){
                        __delay_ms(5);
                        y=0;
                        PORTB=CONTADORB[y];
                        __delay_ms(5);
                        i= 2;
                        PORTC = DISPLAY[i];          
                        BOCINA = 1;
                        LED_GA2=1;
                        __delay_ms(1);
                        BOCINA = 0;
                        LED_GA2=0;
                        __delay_ms(1);
                        BOCINA = 1;
                        LED_GA2=1;
                        __delay_ms(1);
                        BOCINA = 0;
                        LED_GA2=0;
                        __delay_ms(1);
                        BOCINA = 1;
                        LED_GA2=1;
                        __delay_ms(2);
                        LED_GA2=0;
                        BOCINA = 0;
                        return;
                    }
            }
        
        
    }
}
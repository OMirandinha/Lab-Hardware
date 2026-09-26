//cabeçalho
//includes
//defines
//pragma
//identificação das variáveis
//protótipo da função
//main
//void

/* Projeto didático utilizando o uc PIC 18f4520 Microchip
   Vitor Hugo Miranda
   ADS Noturno 3°Semestre */

#include<xc.h>
#include<pic18f4520.h>

#define_XTAL_FREQ 4000000 // frequencia do oscilador cristal = 4MHz
#define LED PORTDbits.RD0

#pragma config OSC = HS
#pragma config WDT = OFF

//declaração de variáveis
unsigned char x;

//protótipo de função
void tempo_50ms(void);

// exercicío piscar LED em PORTD0 com f = 10Hz com timer0
void main()
{
    TRISD = 0b00000000; //port D saída

     while(1)
    {
        LED = 1;
        tempo_50ms();
        LED = 0;
        tempo_50ms();
    }

}

 void tempo_50ms(void)
    {
        TMR0 = 61; // 256-(50000/256)
        T0CON = 0b11000111;
        INTCONbits.TMR0IF = 0;
        while(TMR0IF == 0);
    }

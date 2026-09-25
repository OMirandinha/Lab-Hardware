/* Projeto didático usando lingaugem C
   Elaborado por Vito Hugo Miranda em 24/09/2026 */

#include <stdio.h>
#include <pic18f4520.h>

#define freqCristal 4000000
#define led PORTDbits.RD0
#define botao PORTBbits.RB0
#define HIGH 1
#define LOW 0
#define aquecedor PORTDbits.RD0

#pragma config OSC = HS
#pragma config WDT = OFF

//Definição de variáveis

unsigned char x, dezena, tb, unidade, apontador, valor_led, display;
unsigned char num_bin, n, contagen, temp_dg_int;
unsigned int y, temperatura_inteiro, roda, temp_int, temp_high;
float z, temperatura_float, temp_float;
unsigned char minuto_uni = 0, temperatura_display;
unsigned char minuto_dez = 0, cont_seg, cont_min, cont_hora;

//Protótipo de funções
void Tempo50(void);

// Exercício: Piscar Led no timer 0

int main(){
    int rep = 100000;
    while(rep > 0){
        led = 1;
        Tempo50();
        led = 0;
    }
}

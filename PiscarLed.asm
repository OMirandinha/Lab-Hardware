
; PIC18F4520 - Fosc = 4 MHz
; RB0 = chave; RD0 = LED

    CLRF    TRISD
    BSF     TRISB,0
    BCF     PORTD,0

Inicio:
    BTFSS   PORTB,0
    GOTO    Inicio

    BSF     PORTD,0
    CALL    Delay100us
    BCF     PORTD,0

EsperaSoltar:
    BTFSC   PORTB,0
    GOTO    EsperaSoltar
    GOTO    Inicio

Delay100us:
    MOVLW   206
    MOVWF   TMR0
    BCF     INTCON,TMR0IF
    MOVLW   b'11000000'
    MOVWF   T0CON

EsperaT0:
    BTFSS   INTCON,TMR0IF
    GOTO    EsperaT0

    BCF     T0CON,TMR0ON
    RETURN

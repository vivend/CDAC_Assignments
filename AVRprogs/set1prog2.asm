;
; *********************************
; *                               *
; *                               *
; *********************************
;
.NOLIST
.INCLUDE "M128DEF.INC" ; Define device ATmega128
.LIST
.MACRO LOADABLE
  LDI ZH , @0
  LDI ZL , @1
  LDI YH , @2
  LDI YL , @3
.ENDMACRO
.MACRO CLEARABLE
 CLR ZH
 CLR ZL
 CLR YH
 CLR YL
.ENDMACRO
.ORG 0X00
LDI R25 , HIGH(RAMEND)
OUT SPH , R25
LDI R25 , LOW(RAMEND)
OUT SPL , R25
LOADABLE 0X23 , 0X01 , 0X33 , 0X01
CALL UNSIGNED_ADD
LOADABLE 0XFF , 0XFF ,0XFF ,0XFF
CALL UNSIGNED_ADD
LOADABLE 0X37 ,0X98 , 0X4B , 0X9C
CALL UNSIGNED_SUBTRACT
.ORG 0X100
UNSIGNED_ADD:   ADD ZL , YL
                ADC ZH , YH
                CLEARABLE
                RET
.ORG 0X200
UNSIGNED_SUBTRACT: SUB ZL ,YL
                   SBC ZH , YH
                   CLEARABLE
                   RET
.EXIT

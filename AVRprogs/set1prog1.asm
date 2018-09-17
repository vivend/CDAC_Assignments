;
; *********************************
; *                               *
; *                               *
; *********************************
;
.NOLIST
.INCLUDE "M128DEF.INC" ; Define device ATmega128
.LIST
; Macro to initialize the callstack

.MACRO STACKINIT
LDI @0 , HIGH(@1)
OUT SPH , @0
LDI @0 , LOW(@1)
OUT SPL , @0
.ENDMACRO
;Macro to initialize any value Lower 15 registers
.MACRO STOREVAL
.EQU TEMPLOC = 0X200
LDI @0 , @1
STS TEMPLOC , @0
LDS @2 , TEMPLOC
PUSH @2
.ENDMACRO
; Macro to PUSH to the stack
.MACRO      STACKABLE
            MOV R25 , @0
            INC R25
            MOV @1, R25
            PUSH @1
.ENDMACRO
;MACRO TO PUSH STATUS REGISTER ONTO THE STACK
.MACRO      SREG_STACKABLE
            SEI
            SEZ
            SET
            SEC
            IN R25 , @0
            PUSH R25
.ENDMACRO
; Macro to POP from the stack
.MACRO     REMOVABLE_TO
           POP @0
.ENDMACRO
.CSEG
.ORG 0x0000
STACKINIT R20 , RAMEND
STOREVAL R25 ,1 , R0
; STACKING UP THE VALUES
STACKABLE R0 , R1
STACKABLE R1 , R2
STACKABLE R2 , R3
STACKABLE R3 , R4
STACKABLE R4 , R5
STACKABLE R5 , R6
STACKABLE R6 , R7
;STACKING THE STATUS REGISTER
SREG_STACKABLE SREG
REMOVABLE_TO R15
REMOVABLE_TO R16
REMOVABLE_TO R17
REMOVABLE_TO R18
REMOVABLE_TO R19
REMOVABLE_TO R20
REMOVABLE_TO R21
REMOVABLE_TO R22
REMOVABLE_TO R23
.EXIT

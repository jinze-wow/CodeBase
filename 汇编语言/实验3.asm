MYSTACK SEGMENT STACK
        DW  64  DUP(?)
MYSTACK ENDS
DATA    SEGMENT
        DW  ?
DATA    ENDS
        ASSUME  CS:CODE,SS:MYSTACK,CS:DATA
CODE    SEGMENT
START:  MOV AX, DATA
        MOV DS, AX      ;数据段就位
        MOV BL, 89      ;成绩存放在BL中
        CMP BL, 60
        JB  FAIL       ;低于60分，跳转到FAIL
        CMP BL, 85
        JAE GOOD       ;不低于85分，跳转到GOOD
        MOV AL, 'P'
        JMP PRINT
FAIL:   MOV AL, 'F'
        JMP PRINT
GOOD:   MOV AL, 'G'
PRINT:  MOV DL, AL
        MOV AH, 02H
        INT 21H
        INT 3H
        MOV AX, 4C00H
        INT 21H
CODE    ENDS
        END START


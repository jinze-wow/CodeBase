MYSTACK SEGMENT STACK
        DW  64  DUP(?)
MYSTACK ENDS
DATA    SEGMENT
        DW  ?
DATA    ENDS
        ASSUME  CS:CODE,SS:MYSTACK,CS:DATA
CODE    SEGMENT
START:  MOV AX, DATA
        MOV DS, AX      ;���ݶξ�λ
        MOV BL, 89      ;�ɼ������BL��
        CMP BL, 60
        JB  FAIL       ;����60�֣���ת��FAIL
        CMP BL, 85
        JAE GOOD       ;������85�֣���ת��GOOD
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


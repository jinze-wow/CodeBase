stack segment stack ; ��ջ�εĶ���
byte 64 dup(0)
STACK ENDS
DATA  SEGMENT
   LIST DB 65H,76H,78H,54H,90H,85H,68H,66H,77H,88H
   		DB 99H,89H,79H,69H,75H,85H,63H,73H,83H,93H
   SUM DW 0
   AVER DB 0
   BUF DB 100 DUP(?)
  DATA ENDS
CODE SEGMENT
	ASSUME CS:CODE,DS:DATA,SS:STACK
START: PUSH DS
	MOV AX,DATA
	MOV DS,AX
    MOV DI,OFFSET LIST
    MOV BX,19
LPO: MOV SI,DI
	MOV CX,BX
LP1: MOV AL,[SI]
	INC SI
	CMP AL,[SI]
	JNC LP2
	MOV DL,[SI]
	MOV [SI-1],DL
	MOV [SI],AL
LP2: LOOP LP1
	DEC BX
	JNZ LPO
LP3: MOV CX,20
	MOV BX,OFFSET LIST
	MOV SUM,0
	XOR	AX,AX
LP4: ADD AL,[BX]
	DAA
	ADC AH,0
	INC BX
	LOOP LP4
	MOV SUM,AX
	MOV BL,20H
	DIV BL
	ADD AL,0 
	DAA
	MOV AVER,AL 
	POP DS
	HLT
CODE ENDS
	END START



;����:�Ӽ�������1-4λʮ��������(����Ӧ�Ķ�������
;�ǲ����ʾ�Ĵ�������),��������תΪ������(+��-)
;�ķ�ѹ��BCD��,������Ļ����ʾ����.


DATA SEGMENT
PROMPT DB 0AH,0DH
DB 'Input Hexdecimal(4 DIGITS):','$'
HEXBUF DB 5,0,5 DUP(0)
DISP DB 0AH,0DH
BCDBUF DB 6 DUP(0),'$'
DATA ENDS

STACK1 SEGMENT PARA STACK
DW 20H DUP(0)
STACK1 ENDS

COSEG SEGMENT
ASSUME CS:COSEG,DS:DATA,SS:STACK1
HEXBCD:
MOV AX,DATA
MOV DS,AX
;���ܼ������������,��HEXBUF+2Ϊ��ַ��5���ֽڵ�Ԫ
; ����,HEXBUF+1��ԪΪ��������ݸ���
LEA DX,PROMPT ;��ʾ��ʾInput Hexdecimal(4 DIGITS):
MOV AH,09H
INT 21H
LEA DX,HEXBUF ;���ܼ�������
MOV AH,0AH
INT 21H
;��ASCII��ʾ��1-4λʮ��������תΪ16λ�������� ��BX
LEA SI,HEXBUF+2 ;ʮ������λ���׵�ַ
MOV BX,0 ;�����Ԫ����ֵ=0
MOV CH,HEXBUF+1 ;ʮ������λ��
HEX1:
MOV AL,[SI] ;ȡһλʮ��������
CMP AL,'9' ;��39H�Ƚ�
JBE NUMB ;С�ڵ���ת��������ת��
SUB AL,07H ;�������,-7������ĸ��
NUMB:
AND AL,0FH
MOV CL,04
SAL BX,CL
OR BL,AL
INC SI
DEC CH
JNE HEX1
;BCD�뵥Ԫ��'0'
MOV WORD PTR BCDBUF+0,0
MOV WORD PTR BCDBUF+2,0
MOV WORD PTR BCDBUF+4,0
;ȷ��ʮ��������BCD�룩�ķ���
MOV BCDBUF,'+'
TEST BX,8000H
JNS PLUS
MOV BCDBUF,'-'
NEG BX;ȡ��
PLUS:
;�Ӷ���������λ��,����15�μӺͳ�
MOV CH,0FH
LOP0:

CLC;��λ��־����Ϊ0
SHL BX,1;�߼�����
CALL ADDIT
CALL MULTI
DEC CH
JNE LOP0
SHL BX,1
CALL ADDIT
;�ѷ����BCD��ת��ΪASCII����ʽ
LEA DI,BCDBUF+1
MOV CX,5
LOP1:
OR BYTE PTR [DI],30H
INC DI
LOOP LOP1
;��ʾת�����
LEA DX,DISP
MOV AH,09H
INT 21H
;�������
MOV AH,4CH
INT 21H

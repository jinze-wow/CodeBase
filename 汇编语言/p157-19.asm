stack segment stack
dw 64 dup ( ?)
stack ends
data segment
	buff db 'Go to school'
	count equ $-buff
data ends
code segment
assume cs:code , ds :data
start:
	mov ax , data
	mov ds , ax
	mov cl, count;�ַ�������
	mov bx,0;����ַΪ0
	loop1:
	mov al , buff [bx]
	cmp al, 61h;<6lh 
	jl next;����Сд��ĸ
	cmp al, 7ah; >7ah ?
	jg next;����Сд��ĸ
	sub al,20h;��Сд��ĸ,��Ϊ��д
	mov buff[bx] ,al;����ԭλ��
next:
inc bx;��ַ��1
dec cl;�ַ����ȼ�һ
	jnz loop1
	mov ax,4c00h
int 21h
code ends
	end start


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
	mov cl, count;字符串长度
	mov bx,0;基地址为0
	loop1:
	mov al , buff [bx]
	cmp al, 61h;<6lh 
	jl next;不是小写字母
	cmp al, 7ah; >7ah ?
	jg next;不是小写字母
	sub al,20h;是小写字母,改为大写
	mov buff[bx] ,al;存入原位置
next:
inc bx;基址加1
dec cl;字符长度减一
	jnz loop1
	mov ax,4c00h
int 21h
code ends
	end start


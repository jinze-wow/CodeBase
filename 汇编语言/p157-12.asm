data segment
table db 0c0h,0f9h,0a4h, 0b0h,99h,92h,82h,0f8h ,80h , 90h
list db 'please input a number : ' , '$'
data ends ;¹²Ñô¼«
code segment
assume cs :code , ds :data
	start: mov ax , data
	mov ds, ax
	mov dx,offset list
	mov ah , 9h
	int 21h
	mov ah , 01h
	int 21h
	mov bx,offset table
	sub al, '0'
	and ah , 0
	add bx,ax
	mov dl,[bx]
	mov ax,4c00h
	int 21h
code ends
	end start


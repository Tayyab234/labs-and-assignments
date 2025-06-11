[org 0x0100]
jmp code
x: dw 150  ;initial x point
y: dw 20   ;initial y point
k: dw 40  ;size
c: dw 60   ;color
;___________________________________________________
clrscr : push ax
push es
push cx
push di
mov ax, 0xb800
mov es, ax
mov di, 0
mov ax, 0x0720
mov cx, 2000
cld
rep stosw

pop ax
pop es
pop cx
pop di
ret
;__________________________________________________
line1:mov di,[k]

h1:inc cx
inc dx
mov ah,0ch
int 10h
dec di
cmp di, 0
ja h1
ret
;___________________________________________________
line2:mov di,[k]
h2:dec cx
inc dx
mov ah,0ch
int 10h
dec di
cmp di,0
ja h2
ret
;______________________________________________________
code : call clrscr
mov ah, 0
mov al, 13h
int 10h
mov al,60
mov cx,[x]
mov dx,[y]
mov ah,0ch
int 10h
push cx
push dx
call line1
call line2
pop dx
pop cx
call line2
call line1

mov ax, 0x4c00
int 21h
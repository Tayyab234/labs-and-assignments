[org 0x0100]
jmp start
m1: db 'Hi! I am Tayyab'
m2: db 'I am from Lahore'
m3: db 'I study at FAST'
m4: db 'My Roll No is 21l-5641'
l1: dw 15
l2: dw 16
l3: dw 22
;___________________________________________________
clrscr:push ax
push es
push cx
push di
mov ax,0xb800
mov es,ax
mov di,0
mov ax,0x0720
mov cx,2000
cld
rep stosw

pop ax
pop es
pop cx
pop di
ret
;__________________________________________________
display:push bp
mov bp,sp
mov ah,0x13
mov al,1
mov bh,0
mov bl,7
mov dx,[bp+8]
mov cx,[bp+6]
push cs
pop es
mov bp,[bp+4]
int 0x10
pop bp
ret 4
;_________________________________________________
start:call clrscr
 mov ah,0
 int 0x16

 mov ax,0x00
 push ax
 mov ax,[l1]
 push ax
 mov ax,m1
 push ax

 call display

 mov ah,0
 int 0x16
 mov ax,0x0100
 push ax
 mov ax,[l2]
 push ax
 mov ax,m2
 push ax
 call display

 mov ah,0
 int 0x16
 mov ax,0x0200
 push ax
 mov ax,[l1]
 push ax
 mov ax,m3
 push ax
 call display

 mov ah,0
 int 0x16
 mov ax,0x0300
 push ax
 mov ax,[l3]
 push ax
 mov ax,m4
 push ax
 call display



mov ax,0x4c00
int 0x21
 
[org 0x0100]
jmp start
m1: db 'Hi, you pressed a'
m2: db 'Hi, you pressed b'
m3: db 'Hi, you entered wrong credentials'
l: dw 17
l1: dw 33
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
mov dx,0x0A03
mov cx,[bp+6]
push cs
pop es
mov bp,[bp+4]
int 0x10
pop bp
ret 4
;_________________________________________________
start:call clrscr
mov cx,0
 mov ah,0
 int 0x16
 add cx,1
mov ah,0
int 0x16
cmp al,0x61
jne l3
mov ax,[l]
push ax
mov ax,m1
push ax
call display
jmp finish

l3:cmp al,0x62
jne l4
mov ax,[l]
push ax
mov ax,m2
push ax
call display
jmp finish

l4:mov ax,[l1]
push ax
mov ax,m3
push ax
call display

finish:mov ax,0x4c00
int 0x21
 
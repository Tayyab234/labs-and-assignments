[org 0x0100]
jmp start
  n: dw 6
  s: dw 11
pyramid:push bp
   mov bp,sp
   push ax
push bx
push cx
push dx
mov bx,[bp+4]
sub bx,2
mov ax,2
mov dx,2
l1:add ax,dx
sub bx,1
add cx,1
cmp cx,2
je l2
cmp bx,0
je h1
l2: add dx,1
mov cx,0
jmp l1
h1: pop dx
 pop cx
pop bx
pop ax
ret 2
start:mov ax, word[s]
  push ax
 call  pyramid
mov ax, 0x4c00
 int 0x21
[org 0x0100]
jmp start
find1:push bp
mov bp,sp
push ax 
push cx
push dx
push bx
 mov ax,[bp+6]
  mov cx,[bp+4]
  mov dx,0
mov bx,0
l1: shr ax,1
jnc skip
add bx,1
skip: add dx,1
cmp dx,cx
jne l1
pop bx
pop dx
pop cx
pop ax
ret 4
start: mov ax,0x5643
push ax
  mov ax,16
push ax
call find1
mov ax,0x4c00
int 0x21
[org 0x0100]
mov ax,0xB25D
mov cx,4
l1:rol al,1
rol ah,1
sub cx,1
jnz l1

mov ax,0x4c00
int 0x21
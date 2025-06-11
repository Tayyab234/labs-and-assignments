[org 0x0100]
mov bx,0xb189
mov ax,bx
mov cx,0

l1:shr ax,1
 jnc skip
 add cx,1

skip: cmp ax,0
      jnz l1

mov ax,1

l2:xor bx,ax
shl ax,1
sub cx,1
cmp cx,0
jnz l2

mov ax,0x4c00
int 0x21
[org 0x0100]


start: mov ax,0x5641


mov bx, 1111000011110000b
mov dx, 0000111100001111b
and bx,ax
and dx,ax
shr bx,4
shl dx,4
or bx,dx
mov ax,bx


end:
mov ax, 0x4c00
int 21h

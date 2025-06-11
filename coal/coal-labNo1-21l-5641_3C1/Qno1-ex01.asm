[org 0x0100]
mov ax,0
mov bx,0
l1: add ax,3
   add bx,1
   cmp bx,5
   jne l1
mov ax, 0x4c00
int 0x21
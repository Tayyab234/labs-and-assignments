[org 0x0100]
jmp start
m1: dw  3,6   ;x1,x2
m2: dw 5,6    ; y1,y2

sub1:mov si,dx      ;multiplication subroutine
    mov cx,dx
h1:add dx,cx
   sub si,1
   cmp si,1
   jnbe h1

ret

sub2: mov cx,15      ;if number in (2 complement)negative form than convert in positive form again as square of number is always positive
      mov si,1
   l1:xor dx,si
      shl si,1
      sub cx,1
     jnbe l1
add dx,1

ret

start:mov ax,[m1]
mov dx,[m1+2]
sub dx,ax
js sub2
call sub1

mov di,dx   ;store answer (x2-x1)^2


mov ax,[m2]
mov dx,[m2+2]
sub dx,ax
js sub2

call sub1    ;dx store answer (y2-y1)^2

add di,dx    ; di store the final answer (x2-x1)^2+(y2-y1)^2
mov ax,di    ;copy answer into ax

mov ax,0x4c00
int 0x21




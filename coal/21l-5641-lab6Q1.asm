[org 0x0100]
jmp start
sub1:mov dx,ax  ;multiplication subroutiine
h1:add ax,dx
     sub bx,1
     cmp bx,1
     jne h1
                
    ret


sub2:push bp
mov bp,sp
push ax
push bx
push cx

mov ax,[bp+4]
mov bx,ax
sub bx,1
l1:mov cx,bx
   call sub1
   mov bx,cx
   sub bx,1
   cmp bx,1
   jnbe l1
pop cx
pop bx
pop ax

ret 

start: mov cx,5
push cx
call sub2

mov cx,6
push cx
call sub2


mov ax,0x4c00
int 0x21

                                    
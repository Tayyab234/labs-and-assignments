[org 0x0100]
mov ax,200h
mov bx,150h
mov word[200],25h
mov word[250],15h
mov cx,[250]
mov bx,200
mov ax,[bx]
mov [200],cx
mov [250],ax


mov di,0
mov dx,0
mov bx,0
mov ax,0
jmp l1
h1: mov dx,[num+bx]
   mov [num+di],dx
   mov [num+bx],ax
mov ax,[num+di]
   jmp l2

l1:mov ax,[num+di]
    mov bx,0
   l2:cmp ax,[num+bx]
      jl h1
      add bx,2
      cmp bx,di
      jnge l2
 add di,2
cmp di,12
jne l1

mov ax,0
mov di,0
c1: mov ax,[num+di]
    mov [temp+di],ax
    add di,2
    cmp di,12
    jne c1

mov ax,0x4c00
int 0x21

num: dw 2,1,0,0,1,3
temp: dw 0

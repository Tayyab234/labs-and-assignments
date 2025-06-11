[org 0x0100]
jmp start
array1: dw 1, 2, 3 ,4 ,5 ,6 , 7, 8, 9
array2: dw 0, 0, 0, 0, 0, 0, 0, 0, 0
len: dw 9
start:mov ax,0
mov bx,0
mov di,0
mov cx,0
mov dx,0
l1:mov ax,word[array1+di]
   mov dx,ax
   sum:add ax,dx
       add cx,1
       cmp cx,2
      jne sum
mov cx,0
mov word[array2+ di],ax
mov ax,0
mov dx,0
add di,1
add bx,1
cmp bx,word[len]
jne l1
mov ax,0x4c00
int 0x21
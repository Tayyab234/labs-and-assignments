[org 0x0100]
mov ax,10
mov bx,20
mov cx,30
mov dx,0
l1 : mov [num1],ax
mov [num2],cx
mov [num3],bx
mov ax,[num2]
mov bx,[num1]
mov cx,[num3]
add dx,1
cmp dx,2
jne l1
mov ax, 0x4c00
int 0x21
num1: dw 0
num2: dw 0
num3: dw 0

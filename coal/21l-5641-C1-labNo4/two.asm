[org 0x0100]
jmp start
f: dw 0
result : dw 0
start : 
mov di,0
mov si,1
mov ax,0x5641
mov word[f],ax
l1:
mov dx,[f+di]
mov bx,[f+si]
mov [result + di],bx
mov [result + si],dx
add di,2
add si,2
add cx,1
cmp cx,8
jne l1


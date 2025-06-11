[org 0x0100]
jmp start
f: dw 0
result: dw 0
start:mov ax,0x5641
 mov cx,0
 mov di,0
mov si,1
mov word[f] ,ax
l1: mov dl,[f+di]
    ror dl,1
mov bl,[f+si]
ror bl,1
mov [result+0],dl
mov [result+1],bl
mov ax,0x4c00
int 0x21


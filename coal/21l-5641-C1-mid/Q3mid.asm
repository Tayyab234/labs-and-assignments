[org 0x0100]
jmp start
n: dw 10
print:push bp
mov bp,sp
push es
push di
push dx
push ax
push bx
push cx
mov ax,[bp+4]         ;get  value
mov bx,ax
mov dl,0x65           ; print A
mov dh,0x04           ; attribute red color
mov ax,0xb800
mov es,ax
mov di,0
mov cx,0
l1:add di,160
    l2: mov word[es:di],dx
         dec ax
        cmp ax, 0
        jne l2
    mov ax,bx
    add cx,1
    cmp bx,cx
jne l1
pop cx
pop bx
pop ax
pop dx
pop di
pop es
pop bp
ret 2

start: mov ax,word[n]
push ax              
call print

mov ax,0x4c00
int 0x21
[org 0x0100]
jmp start
S1: dw -3, -1 , 2, 5, 6, 8, 9
S2: dw -2, 2, 6, 7, 9
size1: dw 5
size2: dw 7
different: dw 0
diff: mov cx, word[size1]
mov si,0
mov di,0
mov dx,0
l1: mov ax,[bx+si]
cmp  ax,word[S2+di]
    je skip
     add di,1
    cmp cx, di
    jne l1
    mov di,dx
    mov word[different+di],ax
skip: mov di,0
      add si,1
      add dx,1
      cmp si,word[size2]
      jne l1
      ret
start: mov bx, S1
     call diff
mov ax, 0x4c00
int 0x21
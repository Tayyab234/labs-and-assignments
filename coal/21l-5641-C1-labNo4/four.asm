[org 0x0100]
jmp start
f: dw 0
start: mov ax,5641
    mov bx,ax
    or bx,ax
     xor ax,0x1bcd
     mov word[f],bx
    and word[f],ax
  mov ax,0x4c00
int 0x21
 


     
   
    
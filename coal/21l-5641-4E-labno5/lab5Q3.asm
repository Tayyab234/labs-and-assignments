[org 0x0100]
jmp start
multiplicant: dd 0,0xABCDD4E1   ; 64 bit miltiplicant
multiplier:  dd  0xAB5C32   ; 32 bit space multiplier
result: dd  0,0           ; 64 bit space allocate

start: shr word[multiplier],1
  rcr word[multiplier+2],1
  jnc skip

mov ax,word[multiplicant]
add word[result],ax
mov ax,word[multiplicant+2]
add word[result+2],ax
mov ax,word[multiplicant+4]
add word[result+4],ax
mov ax,word[multiplicant+6]
add word[result+6],ax

skip: shl word[multiplicant+6],1
rcl word[multiplicant+4],1
rcl word[multiplicant+2],1
rcl word[multiplicant],1

cmp byte[multiplier+2],0
jne start

mov ax,0x4c00
int 0x21


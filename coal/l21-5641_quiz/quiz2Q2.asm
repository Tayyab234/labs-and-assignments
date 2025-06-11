[org 0x0100]
jmp start
m1: db 'He has food and drinks'
m2: db 'He has food dna drinks'
m3: db 'He sah food dna drinks'
l: dw 21
oldisr: dd 0
;___________________________________________________
clrscr:push ax
push es
push cx
push di
mov ax,0xb800
mov es,ax
mov di,0
mov ax,0x0720
mov cx,2000
cld
rep stosw

pop ax
pop es
pop cx
pop di
ret
;__________________________________________________
display:push bp
mov bp,sp
 mov ah,0x13
mov al,1
mov bh,0
mov bl,7
mov dx,0x0A03
mov cx,[bp+6]
push cs
pop es
mov bp,[bp+4]
int 0x10
pop bp
ret 4
;_________________________________________________

kbisr: push ax
 push es
 in al, 0x60 ; read a char from keyboard port

 cmp al, 0x2a ; has the left shift pressed
 jne nextcmp 
;________________________________________
mov edx,1

;____________________________________

 jmp exit 

nextcmp: cmp al, 0x36 ; has the right shift pressed
 jne nextcmp2 
;______________________________________________
mov edx,2
  
;______________________________________________

 jmp exit 

nextcmp2: cmp al, 0xaa ; has the left shift released
 jne nextcmp3 
  call clrscr
 jmp exit 

nextcmp3: cmp al, 0xb6 ;right shift released
 jne nomatch 
  call clrscr 
 jmp exit
nomatch: pop es
 pop ax
 jmp far [cs:oldisr] 

exit: mov al, 0x20
 out 0x20, al 

 ;__________________________
cmp edx,1
jne l8
 call clrscr
 mov ax,[l]
 mov ax,m2
 push ax
 call display
jmp h1

l8: cmp edx,2
jne h1
call clrscr
  mov ax,[l]
  push ax
 mov ax,m3
  push ax
  call display
;____________________________
 pop es
 pop ax
 iret

;__________________________________________
start: call clrscr
 mov ax,[l]
 push ax
 mov ax,m1
 push ax
 call display
xor ax, ax
 mov es, ax 
 mov ax, [es:9*4]
 mov [oldisr], ax 
 mov ax, [es:9*4+2]
 mov [oldisr+2], ax 
 cli 
 mov word [es:9*4], kbisr
 mov [es:9*4+2], cs 
 sti 

h1: mov dx, start
 add dx, 15
 mov cl, 4
 shr dx, cl 
 mov ax, 0x3100 
 int 0x21


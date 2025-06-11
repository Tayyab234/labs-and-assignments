[org 0x0100]
jmp start
m1: db 'He has food and drinks'
m2: db 'He has food dna drinks'
m3: db 'He sah food and drinks'
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

pop di
pop cx
pop es
pop ax
ret
;__________________________________________________

kbisr: push ax
 push es
mov ax,0xb800
mov es,ax
 in al, 0x60 ; read a char from keyboard port

 cmp al, 0x2a ; has the left shift pressed
 jne nextcmp 
;________________________________________
mov dh,0x07
mov dl,0x42
mov word[es:0],dx
;____________________________________

 jmp exit 

nextcmp: cmp al, 0x36 ; has the right shift pressed
 jne nextcmp2 
;______________________________________________
mov dh,0x07
mov dl,0x41
mov word[es:0],dx
;______________________________________________

 jmp exit 

nextcmp2: cmp al, 0xaa ; has the left shift released
 jne nextcmp3 
 mov dx,0x0720
mov word[es:0],dx

nextcmp3: cmp al, 0xb6 ;right shift released
jne nomatch
mov dx,0x0720
mov word[es:0],dx
 jmp exit

nomatch:pop es 
pop ax
jmp far[cs:oldisr]

exit: mov al, 0x20
 out 0x20, al 
pop es
pop ax
 iret

;__________________________________________
start: call clrscr
mov ax,0xb800
mov es,ax
mov si,m1
mov dh,0x07
mov di,0
mov cx,[l]
k6:mov dl,[si]
  mov word[es:di],dx
  add di,2
  add si,1
loop k6

 mov ax,0
 mov es,ax
mov ax,[es:9*4]
mov word[oldisr],ax
mov ax,[es:9*4+2]
mov word[oldisr+2],ax

cli 
mov word [es:9*4], kbisr
mov [es:9*4+2], cs 
sti 

mov dx,start
add dx,15
mov cl,4
shr dx,cl
mov ax,0x3100
int 0x21


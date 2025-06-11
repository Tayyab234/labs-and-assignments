[org 0x0100]
jmp start
arr: dw 5,6,3,15,12,1,2,9,4,17
m1: db 'Sum of number array is : $'
m2: db 'Array in assending order : $'
m3: db 'Original array : $'
m4: db 'Enter key : $'
m5: db 'found $'
m6: db 'failed $'
inn: db  2
db 0
times 2 db 0
swap: db 0
;_____________________________________
clrscr : push ax
push es
push cx
push di
mov ax, 0xb800
mov es, ax
mov di, 0
mov ax, 0x0720
mov cx, 2000
cld
rep stosw

pop ax
pop es
pop cx
pop di
ret
;__________________________________________________
num:push bp
mov bp,sp
push es
push ax
push bx
push cx
push dx
push di

mov ax,0xb800
mov es,ax
mov ax,[bp+4]
mov bx,10
mov cx,0

nextdigit: mov dx,0
div bx
add dl,0x30
push dx
inc cx
cmp ax,0
jnz nextdigit

prin:pop dx
mov dh,0x07
mov ah,2
int 21h
loop prin

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 2

;___________________________
Sum:push ax
push es
push bx
;------------------------
mov ah,2
mov bh,0
mov dx,0000h
int 10h

;-------------------------
mov dx,m1
mov ah,09
int 21h
mov ax,0xb800
mov es,ax
mov ax,0
mov cx,10
mov bx,arr
l1: add ax,[bx]
add bx,2
loop l1

push ax
call num


pop ax 
pop es
pop bx
ret

;_________________________________________________________________
space:push dx
push ax
mov dl,' '
mov ah,2
int 0x21
pop ax
pop dx
ret

;____________________________________________________________
arrprin:mov cx,10
mov bx,arr
l2:push word[bx]
add bx,2
call num
call space
loop l2
;______________________________________________________________________

ret
;-----------------------------------------------------------------
asenprin:mov ax,0

ini:mov bx,0
mov byte[swap],0
loop2: mov ax,[arr+bx]
cmp ax,[arr+bx+2]
jbe noswap

mov dx,[arr+bx+2]
mov [arr+bx+2],ax
mov [arr+bx],dx
mov byte[swap],1

noswap: add bx,2
cmp bx,18
jne loop2

cmp byte[swap],1
je ini

ret


;__________________________________________________________________
nextline:mov dl,10
mov ah,2
int 0x21
mov dl,13
mov ah,2
int 0x21
ret
;_______-------------------------------
input:call nextline
mov dx,m4
mov ah,09
int 21h
mov dx,inn
mov ah,0Ah
int 0x21
mov al,[inn+2]

mov cx,10
mov bx,arr
l3:mov dl,[bx]
add dl,0x30
add bx,2
cmp al,dl
jne h1
call nextline
mov dx,m5
mov ah,09
int 21h
ret
h1:loop l3

call nextline
mov dx,m6
mov ah,09
int 21h
ret

;____---------------------------------------------

start:call clrscr
call Sum
call nextline
mov dx,m3
mov ah,09
int 21h
call arrprin
call asenprin
call nextline
mov dx,m2
mov ah,09
int 21h
call arrprin
call input

mov ax,0x4c00
int 0x21














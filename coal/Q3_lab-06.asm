[org 0x0100]
jmp start
message: dd 'My Name is Mickael Jackson, my roll # is 16L-4195, I love praying five times a day.'; string to be printed
length: dw 83 ; length of the string

clrscr:

push es
push ax
push di
mov ax, 0xb800
mov es, ax 
mov di, 0 
nextloc: mov word [es:di], 0x0720 
add di, 2 
cmp di, 4000 
jne nextloc 
pop di
pop ax
pop es
ret

printstr:
push bp
mov bp, sp
push es
push ax
push cx
push si
push di
mov ax, 0xb800
mov es, ax 
mov di, 0 
mov bx , 0
mov si, [bp+6] ; message
mov cx, [bp+4] ; length
mov ah, 0x07 ; attribute

nextchar: 
mov al, [si] 
mov [es:di], ax 
add di, 4 
add si, 2 
sub cx , 1

jcxz nextchar 

pop di
pop si
pop cx
pop ax
pop es
pop bp
ret 4
start: 
call clrscr 
mov ax, message
push ax 
push word [length] 
call printstr 
mov ax, 0x4c00 ; terminate program
int 0x21h
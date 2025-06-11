.model small
.stack 100h
.data
.code
main proc
mov ah,06h
mov al,10h
mov bh,00010001b
mov ch,0
mov cl,0
mov bh,1
mov dh, 15
mov dl,15
int 10h
mov ah, 4ch
int 21

main endp
end main

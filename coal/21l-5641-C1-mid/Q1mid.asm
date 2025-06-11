[org 0x0100]
jmp start
string1: db 'hello_world'
string2: db 'world'
len1: dw 11
len2:  dw 5
start: mov dx,0
mov ax,0
mov bx,word[len1]
mov cx,word[len2]
mov di,0
mov si,0
l1: mov dl,[string2+di]         
     l2: cmp dl, [string1+si]         ; cmpare string2 character to string1 every character
         jne  skip                    ; if not equal jmp to skip
          add ax,1                    ; if equal add 1 to ax
          jmp h1                      ; to neglect same alphabet again
         skip: add si,1
         cmp bx,si                    ; until string1 length completed
        jne l2
 h1:  mov si,0
add di,1
cmp cx,di                              ; until string2 length completed
jne l1
 mov ax, 0x4c00
int 0x21      
[org 0x0100]
jmp start
arr1: dw  10,12,56,1,43,23,89,12,0,35    ;unsigned number
arr2: dw 9,-2,-4,6,-7,-9,1,-12,12        ;signed number
flag1: db 0          ; tell if signed or unsigned number
swap: db 0

;__________________________________________________
;  for signed or unsigned acending order
;____________________________________________________

bubblesortA: dec cx
          shl cx,1
mainloop: mov si,0
          mov byte[swap],0

          jmp innerloop
swapping: mov dx,[bx+si+2]
          mov [bx+si],dx
          mov [bx+si+2],ax
          mov byte[swap],1
          jmp noswap

innerloop:cmp byte[flag1],1       ;check if signed array or unsigned-  1 for sign and 0 for unsigned
           je l1
           
          mov ax,[bx+si]         ;assending order sorting
          cmp ax,[bx+si+2]       ;   for
          jnbe  swapping         ;unsigned number
          jmp noswap             

l1:       mov ax,[bx+si]         ;assending order sorting
          cmp ax,[bx+si+2]       ;   for
          jnl  swapping          ;signed number
  
noswap:       add si,2
          cmp si,cx
          jne innerloop

   cmp byte[swap],1
   je mainloop

   ret

;__________________________________________________
;  for signed or unsigned decending order
;____________________________________________________
bubblesortD: dec cx
          shl cx,1
mainloop1: mov si,0
          mov byte[swap],0

          jmp innerloop1
swapping1: mov dx,[bx+si+2]
          mov [bx+si],dx
          mov [bx+si+2],ax
          mov byte[swap],1
          jmp noswap1

innerloop1:cmp byte[flag1],1       ;check if signed array or unsigned 1 for sign and 0 for unsigned
           je l2
           
          mov ax,[bx+si]         ;decending order sorting
          cmp ax,[bx+si+2]       ;   for
          jnae  swapping1         ;unsigned number
          jmp noswap1             

l2:       mov ax,[bx+si]         ;decending order sorting
          cmp ax,[bx+si+2]       ;   for
          jng  swapping1          ;signed number
  
noswap1:  add si,2
          cmp si,cx
          jne innerloop1

   cmp byte[swap],1
   je mainloop1

   ret


start:mov bx,arr1     ;unsigned number
     mov byte[flag1],0  ;for unsigned number
     mov cx,10         ;length of array
     call bubblesortA  ;assending buublesort
      
     mov bx,arr2     ;signed number
     mov byte[flag1],1  ;for signed number
     mov cx,9         ;length of array
     call bubblesortD  ;desending buublesort

    mov ax,0x4c00
    int 0x21












    
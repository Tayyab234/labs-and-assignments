[org 0x0100]

mll:		mov cl,16
		mov dx,[mlpr]

chkbit:	shr dx,1
		jnc skp
		mov ax,[mlpc]
		add [sum],ax
		mov ax,[mlpc+2]
		adc [sum+2],ax

skp:		shl word [mlpc],1
		rcl word [mlpc+2],1
		dec cl
		jnz chkbit
		jmp strt

adk		mov si,0x6275
		mov di,si
		not di
		mov cl,16
		mov dx,1
check:	test dx,[sum]
		jz skip
		mov ax,[big]
		add [f],ax
		mov ax,[big+2]
		adc[f+2],ax
skip:	shl word [big],1
		rcl word [big+2],1
		shl dx,1
		jnz check
		add [f+2],si
		ret
strt:		mov ax,0x6275
		mov bx,1001110110001010b
		mov [mlpc],ax
		mov [mlpr],bx
		call mll
		mov word [f],ax
		mov word [f+2],bx
		call adk

		mov ax,0x4c00
		int 0x21

mlpc: dd 5
mlpr: dw 5
big: dd 0
sum: dd 0
f: dd 0
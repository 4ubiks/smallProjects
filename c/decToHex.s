org 0x7C00

mov si, output
mov ah, 0eh

msgloop:
	mov al, [si]
	cmp al, 0
	je readin
	int 0x10
	inc si
	mov di, 0
	jmp msgloop

readin:
	mov ah, 0x00 				; read character (0x00)
	int 0x16 					; keyboard interrupt (0x16)
	int 0x05 
	mov [0x4000 + di], al 		; move 'al' to 0xa5's memory address
	
 	mov ah, 0x0e				; teletype output
	int 0x10					; interrupt print (0x10)
	inc di

	xor si, si
	cmp al, 0x0D				; 0x0D is a return
	je print
	
	jmp readin


print:
	mov dx, 0x03f8
	mov al, [0x4000 + si]
	out dx, al

	mov bl, [0x4000 + si]
	cmp bl, 0
	je exit
	
	inc si
	jmp print

exit:
	xor dx, dx
	int 0x80
	
output db 'type number to convert to hex: ', 0x0D, 0x0A, 0

times 510-($-$$) db 0
dw 0xAA55

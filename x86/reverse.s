section .data
	output db 10, "reward issac deliver nametag stressed", 10, 0

section .text
	global _start

_start:
	mov rcx, output
	

print:
	mov al, [rcx]
	test al, al
	jz set
	mov rax, 4 				; number for a sys_write
	mov rbx, 1 				; stdout
	mov rdx, 1 				; write 1 byte
	int 0x80

	inc rcx
	jmp print

set:
	dec rcx

reverse:
	mov al, [rcx]
	test al, al
	jz exit
	mov rax, 4
	mov rbx, 1
	mov rdx, 1
	int 0x80

	dec rcx
	jmp reverse
	
exit:
	mov rax, 1
	xor rbx, rbx
	int 0x80

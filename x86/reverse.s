section .data
	output db "reverse this", 0

section .text
	global _start

_start:
	mov rax, 4
	mov rbx, 1
	mov rcx, output
	mov rdx, 12
	int 0x80

	mov rax, 1
	xor rbx, rbx
	int 0x80

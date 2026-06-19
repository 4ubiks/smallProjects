	section .data
	    head db "ghp_"
	    head_len equ $ - head

	    sectB db "xxxxxxxxx"
	    sectB_len equ $ - sectB

	    sectU db "xxxxxxxxx" 
	    sectU_len equ $ - sectU

	    sectK db "xxxxxxxxx"
	    sectK_len equ $ - sectK

	    sectI db "xxxxxxxxx", 0xA
	    sectI_len equ $ - sectI

	    key db "key", 10
	    key_len equ $ - key

	section .bss
	    buffer resb 16

	section .text
	    global _start

	_start:
	;; read in key
	    mov rax, 0
	    mov rdi, 0
	    mov rsi, buffer
	    mov rdx, 16 
	    syscall
	    
	    mov rcx, key

	.compare:

	;; compare string char X
	    mov rax, [rcx]
	    cmp [rsi], al
	    jne .exit

	;; go to next char of both
	    inc rsi
	    inc rcx

	;; if rsi is empty, jump to print
	    cmp byte [rsi], 0
	    je .print
	    jmp .compare
	
	.print:
	    mov rax, 1          ; sys_write
	    mov rdi, 1          ; stdout
	    mov rsi, head
	    mov rdx, head_len
	    syscall

	    mov rax, 1
	    mov rdi, 1
	    mov rsi, sectU
	    mov rdx, sectU_len
	    syscall

	    mov rax, 1
	    mov rdi, 1
	    mov rsi, sectB
	    mov rdx, sectB_len
	    syscall

	    mov rax, 1
	    mov rdi, 1
	    mov rsi, sectI
	    mov rdx, sectI_len
	    syscall

	    mov rax, 1
	    mov rdi, 1
	    mov rsi, sectK
	    mov rdx, sectK_len
	    syscall

	.exit:
	    mov rax, 60         ; sys_exit
	    xor rdi, rdi
	    syscall

section .text
global _start

section .data
dict db 'a', 10, 'b', 20, 'c', 30  ; Keys: 'a', 10, 'b', 20, 'c', 30

_start:
    lea rsi, [dict]      ; Load address of dict
    mov al, [rsi]        ; Access first byte ('a')
    mov eax, 60          ; sys_exit
    xor edi, edi         ; Exit with code 0
    syscall

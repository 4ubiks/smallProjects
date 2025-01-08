section .data
    msg db 'hello', 0    ; Null-terminated string

section .text
    global _start

_start:
    ; sys_write (file descriptor 1 = stdout)
    mov eax, 4          ; sys_write system call number (4)
    mov ebx, 1          ; file descriptor 1 (stdout)
    lea ecx, [msg]      ; pointer to the message
    mov edx, 5          ; length of the message (5 characters)
    int 0x80            ; invoke system call

    ; sys_exit (exit code 0)
    mov eax, 1          ; sys_exit system call number (1)
    xor ebx, ebx        ; return code 0
    int 0x80            ; invoke system call

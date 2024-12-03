section .text
    global _start

section .data
;dict db '0', 0, '1', 1, '2', 2, '3', 3, '4', 4, '5', 5, '6', 6, '7', 7, '8', 8, '9', 9, '10', 'a', '11', 'b', '12', 'c', '13', 'd', '14', 'e', '15', 'f'  
dict db 'a', 10, 'b', 20, 'c', 30  ; Keys: 'a', 'b', 'c', Values: 10, 20, 30
dict_len equ ($ - dict) / 2 

_start:
    mov al, 'b'
    lea rsi, [dict]
    mov ecx, dict_len

search:
    cmp ecx, 0
    je not_found

    mov dl, [rsi]
    cmp dl, al
    je found

    add rsi, 2
    dec ecx
    jmp search

not_found:
    mov eax, 60
    xor edi, edi
    syscall

found:
    mov al, [rsi + 1]
    mov eax, 60
    xor edi, edi
    syscall

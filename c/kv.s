section .data
dict db 'a', 10, 'b', 20, 'c', 30
dict_len equ ($ - dict) / 2

msg db ' ', 0

section .text
global _start

_start:    
    mov al, 'a'
    lea esi, [dict]
    mov ecx, dict_len

search:
    cmp ecx, 0
    je not_found

    mov dl, [esi]
    cmp dl, al
    je found

    add esi, 2
    dec ecx
    jmp search

found:
    mov al, [esi + 1]
    mov bl, 10
    xor edx, edx

convert:
    ;div bl             ; Divide AL by 10, quotient in AL, remainder in DL
    add dl, '1'        ; Convert to ASCII by adding '0' to the remainder
    mov [msg], dl      

    mov eax, 4         ; sys_write
    mov ebx, 1         
    lea ecx, [msg]     
    mov edx, 1         
    int 0x80           

    mov eax, 1         ; sys_exit
    xor edi, edi       
    int 0x80

not_found:
    mov eax, 1         
    mov edi, 1         
    int 0x80

section .data
  head db "ghp_"
  head_len equ $ - head

  sectB db "xxxxxxxxx"
  sectB_len equ $ - sectB

  sectU db "xxxxxxxxx"
  sectB_len equ $ - sectU

  sectK db "xxxxxxxxx"
  sectK_len equ $ - sectK

  sectI db "xxxxxxxxx"
  sectI_len equ $ - sectI

section .text
  global _start

_start:
  mov rax, 1    ; sys_write
  mov rdi, 1    ; stdout
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

  mov rax, 60
  xor rdi, rdi
  syscall

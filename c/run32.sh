#!/bin/bash

nasm -f elf32 -o kv.o kv.s
ld -m elf_i386 -s -o kv kv.o
echo 'kv output: ' $(./kv)

printf "\n\n\n"
echo "echo" $?

.section .data
hello:
.string "Hello world!\n"

.section .text
.globl _start
_start:
movq $1, %rax
movq $1, %rdi
movq $hello, %rsi
movq $13, %rdx
syscall

movq $60, %rax
movq $2, %rdi
syscall

section .data
	nam_fmt db "Sully_%d", 0
	file_fmt db "%s.s", 0
	nasm_fmt db "nasm -f elf64 %s.s", 0
	gcc_fmt db "gcc -Wall -Wextra -Werror %1$s.o -o %1$s", 0
	code db "; Grace in x86_64 assembly%1$c%1$c%3$cdefine FILE %2$cGrace_kid.s%2$c%1$c%3$cdefine CODE %2$c%4$s%2$c%1$c%3$cmacro MACRO 2%1$csection .data%1$c	Grace_kid db %3$c1, 0%1$c	code db %3$c2, 0%1$c%1$csection .text%1$c	global main%1$c	extern dprintf%1$c%1$c	main:%1$c		push rbp%1$c		mov rbp, rsp%1$c		sub rsp, 0x10%1$c%1$c		mov rax, 2%1$c		lea rdi, [rel Grace_kid]%1$c		mov rsi, 0x241%1$c		mov rdx, 0644o%1$c		syscall%1$c%1$c		test rax, -1%1$c		js _error%1$c%1$c		mov [rbp-0x8], rax%1$c%1$c		mov rdi, rax%1$c		lea rsi, [rel code]%1$c		mov rdx, 0xa%1$c		mov rcx, 0x22%1$c		mov r8, 0x25%1$c		mov r9, rsi%1$c		xor rax, rax%1$c		call dprintf wrt ..plt%1$c%1$c		mov rdi, [rbp-0x8]%1$c%1$c		test rax, -1%1$c		js _error%1$c%1$c		mov rax, 3%1$c		syscall%1$c%1$c		mov rsp, rbp%1$c		pop rbp%1$c%1$c		mov rax, 60%1$c		xor rdi, rdi%1$c		syscall%1$c%1$c	_error:%1$c		mov rsp, rbp%1$c		pop rbp%1$c%1$c		mov rax, 60%1$c		mov rdi, 1%1$c		syscall%1$c%3$cendmacro%1$c%1$cMACRO FILE, CODE%1$c", 0

section .bss
	nam resb 18
	file resb 20
	nasm resb 35
	gcc resb 67
	i resq 1

section .text
	global main
	extern dprintf
	extern sprintf
	extern system
	extern execl

	main:
		push rbp
		mov rbp, rsp
		sub rsp, 0x10

		mov dword [rel i], 5

		lea rdi, [rel nam]
		lea rsi, [rel nam_fmt]
		mov rdx, [rel i]
		xor rax, rax
		call sprintf wrt ..plt

		lea rdi, [rel file]
		lea rsi, [rel file_fmt]
		lea rdx, [rel nam]
		xor rax, rax
		call sprintf wrt ..plt

		lea rdi, [rel nasm]
		lea rsi, [rel nasm_fmt]
		lea rdx, [rel nam]
		xor rax, rax
		call sprintf wrt ..plt

		lea rdi, [rel gcc]
		lea rsi, [rel gcc_fmt]
		lea rdx, [rel nam]
		xor rax, rax
		call sprintf wrt ..plt

		mov rax, 2
		lea rdi, [rel file]
		mov rsi, 0x241
		mov rdx, 0644o
		syscall

		test rax, -1
		js _error

		mov [rbp-0x8], rax

		mov rdi, rax
		lea rsi, [rel code]
		mov rdx, 0xa
		mov rcx, 0x22
		lea r8, 0x25
		mov r9, rsi
		mov r10, [rel i]
		mov [rbp-0x10], r10
		call dprintf wrt ..plt

		mov rdi, [rbp-0x8]

		mov rax, 3
		syscall

		lea rdi, [rel nasm]
		call system wrt ..plt

		test rax, -1
		js _error

		lea rdi, [rel gcc]
		call system wrt ..plt

		test rax, -1
		js _error

		lea rdi, [rel nam]
		call execl wrt ..plt

		test rax, -1
		js _error

		mov rsp, rbp
		pop rbp

		mov rax, 60
		xor rdi, rdi
		syscall

	_error:
		mov rsp, rbp
		pop rbp

		mov rax, 60
		mov rdi, 1
		syscall

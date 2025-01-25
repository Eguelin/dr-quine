; Colleen in x86_64 assembly

%define FILE "Grace_kid.s"
%define CODE "; Colleen in x86_64 assembly%1$c%1$c%3$cdefine FILE %2$cGrace_kid.s%2$c%1$c%3$cdefine CODE %2$c%4$s%2$c%1$c%3$cmacro MACRO 2%1$csection .data%1$c	Grace_kid db %3$c1, 0%1$c	code db %3$c2, 0%1$c%1$csection .text%1$c	global main%1$c	extern dprintf%1$c%1$c	main:%1$c		mov rax, 2%1$c		lea rdi, [rel Grace_kid]%1$c		mov rsi, 0x241%1$c		mov rdx, 0644o%1$c		syscall%1$c%1$c		test rax, -1%1$c		js _error%1$c%1$c		push rax%1$c%1$c		mov rdi, rax%1$c		lea rsi, [rel code]%1$c		mov rdx, 0xa%1$c		mov rcx, 0x22%1$c		mov r8, 0x25%1$c		mov r9, rsi%1$c		call dprintf wrt ..plt%1$c%1$c		pop rdi%1$c%1$c		test rax, -1%1$c		js _error%1$c%1$c		mov rax, 3%1$c		syscall%1$c%1$c		jmp _end%1$c%1$c	_error:%1$c		mov rax, 60%1$c		mov rdi, 1%1$c		syscall%1$c%1$c	_end:%1$c		mov rax, 60%1$c		xor rdi, rdi%1$c		syscall%1$c%3$cendmacro%1$c%1$cMACRO FILE, CODE%1$c"
%macro MACRO 2
section .data
	Grace_kid db %1, 0
	code db %2, 0

section .text
	global main
	extern dprintf

	main:
		mov rax, 2
		lea rdi, [rel Grace_kid]
		mov rsi, 0x241
		mov rdx, 0644o
		syscall

		test rax, -1
		js _error

		push rax

		mov rdi, rax
		lea rsi, [rel code]
		mov rdx, 0xa
		mov rcx, 0x22
		mov r8, 0x25
		mov r9, rsi
		call dprintf wrt ..plt

		pop rdi

		test rax, -1
		js _error

		mov rax, 3
		syscall

		jmp _end

	_error:
		mov rax, 60
		mov rdi, 1
		syscall

	_end:
		mov rax, 60
		xor rdi, rdi
		syscall
%endmacro

MACRO FILE, CODE

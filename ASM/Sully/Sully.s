section .rodata
	source db __FILE__, 0
	cmp_str db "Sully.s", 0
	nam_fmt db "Sully_%d", 0
	file_fmt db "%s.s", 0
	nasm_fmt db "nasm -f elf64 %s.s", 0
	gcc_fmt db "gcc -Wall -Wextra -Werror %1$s.o -o %1$s", 0
	code db "section .rodata%1$c	source db __FILE__, 0%1$c	cmp_str db %2$cSully.s%2$c, 0%1$c	nam_fmt db %2$cSully_%3$cd%2$c, 0%1$c	file_fmt db %2$c%3$cs.s%2$c, 0%1$c	nasm_fmt db %2$cnasm -f elf64 %3$cs.s%2$c, 0%1$c	gcc_fmt db %2$cgcc -Wall -Wextra -Werror %3$c1$s.o -o %3$c1$s%2$c, 0%1$c	code db %2$c%4$s%2$c, 0%1$c%1$csection .data%1$c	i dd %5$d%1$c%1$csection .bss%1$c	nam resb 18%1$c	file resb 20%1$c	nasm resb 35%1$c	gcc resb 67%1$c%1$csection .text%1$c	global main%1$c	extern dprintf%1$c	extern printf%1$c	extern sprintf%1$c	extern system%1$c	extern execl%1$c	extern strcmp%1$c%1$c	main:%1$c		push rbp%1$c		mov rbp, rsp%1$c		sub rsp, 0x10%1$c%1$c		mov rdi, [rel i]%1$c		test rdi, rdi%1$c		jz _end%1$c%1$c		lea rdi, [rel source]%1$c		lea rsi, [rel cmp_str]%1$c		call strcmp wrt ..plt%1$c%1$c		test rax, rax%1$c		jz _skip_dec%1$c%1$c		dec dword [rel i]%1$c%1$c	_skip_dec:%1$c		lea rdi, [rel nam]%1$c		lea rsi, [rel nam_fmt]%1$c		mov rdx, [rel i]%1$c		xor rax, rax%1$c		call sprintf wrt ..plt%1$c%1$c		lea rdi, [rel file]%1$c		lea rsi, [rel file_fmt]%1$c		lea rdx, [rel nam]%1$c		xor rax, rax%1$c		call sprintf wrt ..plt%1$c%1$c		lea rdi, [rel nasm]%1$c		lea rsi, [rel nasm_fmt]%1$c		lea rdx, [rel nam]%1$c		xor rax, rax%1$c		call sprintf wrt ..plt%1$c%1$c		lea rdi, [rel gcc]%1$c		lea rsi, [rel gcc_fmt]%1$c		lea rdx, [rel nam]%1$c		xor rax, rax%1$c		call sprintf wrt ..plt%1$c%1$c		mov rax, 2%1$c		lea rdi, [rel file]%1$c		mov rsi, 0x241%1$c		mov rdx, 0644o%1$c		syscall%1$c%1$c		test rax, -1%1$c		js _error%1$c%1$c		mov [rbp-0x8], rax%1$c%1$c		mov rdi, rax%1$c		lea rsi, [rel code]%1$c		mov rdx, 0xa%1$c		mov rcx, 0x22%1$c		lea r8, 0x25%1$c		mov r9, rsi%1$c		mov r10, [rel i]%1$c		mov [rbp-0x10], r10%1$c		call dprintf wrt ..plt%1$c%1$c		mov rdi, [rbp-0x8]%1$c%1$c		mov rax, 3%1$c		syscall%1$c%1$c		lea rdi, [rel nasm]%1$c		call system wrt ..plt%1$c%1$c		test rax, rax%1$c		jnz _error%1$c%1$c		lea rdi, [rel gcc]%1$c		call system wrt ..plt%1$c%1$c		test rax, rax%1$c		jnz _error%1$c%1$c		mov rax, 57%1$c		syscall%1$c%1$c		cmp rax, 0%1$c		jg _end%1$c		jl _error%1$c%1$c		lea rdi, [rel nam]%1$c		call execl wrt ..plt%1$c%1$c		test rax, -1%1$c		js _error%1$c%1$c	_end:%1$c		mov rsp, rbp%1$c		pop rbp%1$c%1$c		mov rax, 60%1$c		xor rdi, rdi%1$c		syscall%1$c%1$c	_error:%1$c		mov rsp, rbp%1$c		pop rbp%1$c%1$c		mov rax, 60%1$c		mov rdi, 1%1$c		syscall%1$c", 0

section .data
	i dd 5

section .bss
	nam resb 18
	file resb 20
	nasm resb 35
	gcc resb 67

section .text
	global main
	extern dprintf
	extern printf
	extern sprintf
	extern system
	extern execl
	extern strcmp

	main:
		push rbp
		mov rbp, rsp
		sub rsp, 0x10

		mov rdi, [rel i]
		test rdi, rdi
		jz _end

		lea rdi, [rel source]
		lea rsi, [rel cmp_str]
		call strcmp wrt ..plt

		test rax, rax
		jz _skip_dec

		dec dword [rel i]

	_skip_dec:
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

		test rax, rax
		jnz _error

		lea rdi, [rel gcc]
		call system wrt ..plt

		test rax, rax
		jnz _error

		mov rax, 57
		syscall

		cmp rax, 0
		jg _end
		jl _error

		lea rdi, [rel nam]
		call execl wrt ..plt

		test rax, -1
		js _error

	_end:
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

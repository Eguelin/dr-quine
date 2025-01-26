;Colleen in x86_64 assembly

section .data
	tmp_Colleen db "tmp_Colleen", 0
	code db ";Colleen in x86_64 assembly%1$c%1$csection .data%1$c	tmp_Colleen db %2$ctmp_Colleen%2$c, 0%1$c	code db %2$c%3$s%2$c, 0%1$c%1$csection .text%1$c	global main%1$c	extern dprintf%1$c%1$c	main:%1$c		;main function%1$c		push rbp%1$c		mov rbp, rsp%1$c%1$c		call ft_create%1$c%1$c		pop rbp%1$c%1$c		test rax, -1%1$c		js _error%1$c%1$c	_end:%1$c		mov rax, 60%1$c		xor rdi, rdi%1$c		syscall%1$c%1$c	_error:%1$c		mov rax, 60%1$c		mov rdi, 1%1$c		syscall%1$c%1$c	ft_create:%1$c		push rbp%1$c		mov rbp, rsp%1$c		sub rsp, 0x10%1$c%1$c		mov rax, 2%1$c		lea rdi, [rel tmp_Colleen]%1$c		mov rsi, 0x241%1$c		mov rdx, 0644o%1$c		syscall%1$c%1$c		test rax, -1%1$c		js _error_ft_create%1$c%1$c		mov [rbp-0x8], rax%1$c%1$c		mov rdi, rax%1$c		lea rsi, [rel code]%1$c		mov rdx, 0xa%1$c		mov rcx, 0x22%1$c		mov r8, rsi%1$c		xor rax, rax%1$c		call dprintf wrt ..plt%1$c%1$c		mov rdi, [rbp-0x8]%1$c%1$c		test rax, -1%1$c		js _error_ft_create%1$c%1$c		mov rax, 3%1$c		syscall%1$c%1$c		jmp _end_ft_create%1$c%1$c	_error_ft_create:%1$c		xor rax, rax%1$c%1$c	_end_ft_create:%1$c		mov rsp, rbp%1$c		pop rbp%1$c		ret%1$c%1$c", 0

section .text
	global main
	extern dprintf

	main:
		;main function
		push rbp
		mov rbp, rsp

		call ft_create

		pop rbp

		test rax, -1
		js _error

	_end:
		mov rax, 60
		xor rdi, rdi
		syscall

	_error:
		mov rax, 60
		mov rdi, 1
		syscall

	ft_create:
		push rbp
		mov rbp, rsp
		sub rsp, 0x10

		mov rax, 2
		lea rdi, [rel tmp_Colleen]
		mov rsi, 0x241
		mov rdx, 0644o
		syscall

		test rax, -1
		js _error_ft_create

		mov [rbp-0x8], rax

		mov rdi, rax
		lea rsi, [rel code]
		mov rdx, 0xa
		mov rcx, 0x22
		mov r8, rsi
		xor rax, rax
		call dprintf wrt ..plt

		mov rdi, [rbp-0x8]

		test rax, -1
		js _error_ft_create

		mov rax, 3
		syscall

		jmp _end_ft_create

	_error_ft_create:
		xor rax, rax

	_end_ft_create:
		mov rsp, rbp
		pop rbp
		ret


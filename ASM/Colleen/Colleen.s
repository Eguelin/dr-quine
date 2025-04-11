;Colleen in x86_64 assembly

section .data
	code db ";Colleen in x86_64 assembly%1$c%1$csection .data%1$c	code db %2$c%3$s%2$c, 0%1$c%1$csection .text%1$c	global main%1$c	extern printf%1$c	extern fflush%1$c%1$c	main:%1$c		;main function%1$c		push rbp%1$c		mov rbp, rsp%1$c%1$c		call ft_print%1$c%1$c		mov rsp, rbp%1$c		pop rbp%1$c%1$c		test rax, -1%1$c		js _error%1$c%1$c	_end:%1$c		mov rax, 60%1$c		xor rdi, rdi%1$c		syscall%1$c%1$c	_error:%1$c		mov rax, 60%1$c		mov rdi, 1%1$c		syscall%1$c%1$c	ft_print:%1$c		push rbp%1$c		mov rbp, rsp%1$c%1$c		lea rdi, [rel code]%1$c		mov rsi, 0xa%1$c		mov rdx, 0x22%1$c		lea rcx, [rel code]%1$c		call printf wrt ..plt%1$c%1$c		test rax, -1%1$c		js _end_ft_print%1$c%1$c		xor rdi, rdi%1$c		call fflush wrt ..plt%1$c%1$c	_end_ft_print:%1$c		mov rsp, rbp%1$c		pop rbp%1$c		ret%1$c", 0

section .text
	global main
	extern printf
	extern fflush

	main:
		;main function
		push rbp
		mov rbp, rsp

		call ft_print

		mov rsp, rbp
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

	ft_print:
		push rbp
		mov rbp, rsp

		lea rdi, [rel code]
		mov rsi, 0xa
		mov rdx, 0x22
		lea rcx, [rel code]
		call printf wrt ..plt

		test rax, -1
		js _end_ft_print

		xor rdi, rdi
		call fflush wrt ..plt

	_end_ft_print:
		mov rsp, rbp
		pop rbp
		ret

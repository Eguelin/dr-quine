; Colleen in x86_64 assembly
section .data
	tmp_Colleen db "tmp_Colleen", 0
	code db "; Colleen in x86_64 assembly%1$csection .data%1$c	tmp_Colleen db %2$ctmp_Colleen%2$c, 0%1$c	code db %2$c%3$s%2$c, 0%1$c%1$csection .text%1$c	global main%1$c	extern dprintf%1$c%1$c	main:%1$c		; main%1$c		jmp _ft_creat%1$c%1$c	_ft_creat:%1$c		mov rax, 2%1$c		lea rdi, [rel tmp_Colleen]%1$c		mov rsi, 0x241%1$c		mov rdx, 0644o%1$c		syscall%1$c%1$c		test rax, -1%1$c		js _error%1$c%1$c		push rax%1$c%1$c		mov rdi, rax%1$c		lea rsi, [rel code]%1$c		mov rdx, 0xa%1$c		mov rcx, 0x22%1$c		mov r8, rsi%1$c		call dprintf wrt ..plt%1$c%1$c		pop rdi%1$c%1$c		test rax, -1%1$c		js _error%1$c%1$c		mov rax, 3%1$c		syscall%1$c%1$c		jmp _end%1$c%1$c	_error:%1$c		mov rax, 60%1$c		mov rdi, 1%1$c		syscall%1$c%1$c	_end:%1$c		mov rax, 60%1$c		xor rdi, rdi%1$c		syscall%1$c", 0

section .text
	global main
	extern dprintf

	main:
		; main
		jmp _ft_creat

	_ft_creat:
		mov rax, 2
		lea rdi, [rel tmp_Colleen]
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
		mov r8, rsi
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

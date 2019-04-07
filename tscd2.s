	.file	"tscd2.c"
	.text
	.globl	NUM_HEX_ROWS
	.data
	.align 8
NUM_HEX_ROWS:
	.quad	16
	.globl	NUM_BIN_ROWS
	.align 8
NUM_BIN_ROWS:
	.quad	6
	.globl	bintable_request
	.bss
bintable_request:
	.space 1
	.section .rdata,"dr"
.LC0:
	.ascii "\33[38;5;244m\0"
.LC1:
	.ascii "\33[38;5;208m\0"
.LC2:
	.ascii "\33[38;5;226m\0"
.LC3:
	.ascii "\33[1;31m\0"
.LC4:
	.ascii "\33[38;5;154m\0"
.LC5:
	.ascii "\33[38;5;164m\0"
.LC6:
	.ascii "\33[0;32m\0"
.LC7:
	.ascii "\33[1;35m\0"
	.text
	.globl	colorchar
	.def	colorchar;	.scl	2;	.type	32;	.endef
	.seh_proc	colorchar
colorchar:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	cmpb	$0, 16(%rbp)
	jne	.L2
	leaq	.LC0(%rip), %rcx
	call	printf
	jmp	.L10
.L2:
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	16(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$3, %eax
	testl	%eax, %eax
	je	.L4
	leaq	.LC1(%rip), %rcx
	call	printf
	jmp	.L10
.L4:
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	16(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$4, %eax
	testl	%eax, %eax
	je	.L5
	leaq	.LC2(%rip), %rcx
	call	printf
	jmp	.L10
.L5:
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	16(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$151, %eax
	testl	%eax, %eax
	jne	.L6
	leaq	.LC3(%rip), %rcx
	call	printf
	jmp	.L10
.L6:
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	16(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$8, %eax
	testl	%eax, %eax
	je	.L7
	leaq	.LC4(%rip), %rcx
	call	printf
	jmp	.L10
.L7:
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	16(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$16, %eax
	testl	%eax, %eax
	je	.L8
	leaq	.LC5(%rip), %rcx
	call	printf
	jmp	.L10
.L8:
	cmpb	$15, 16(%rbp)
	ja	.L9
	leaq	.LC6(%rip), %rcx
	call	printf
	jmp	.L10
.L9:
	cmpb	$15, 16(%rbp)
	jbe	.L10
	cmpb	$31, 16(%rbp)
	ja	.L10
	leaq	.LC7(%rip), %rcx
	call	printf
.L10:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC8:
	.ascii "\33[0m\0"
	.text
	.globl	resetcolor
	.def	resetcolor;	.scl	2;	.type	32;	.endef
	.seh_proc	resetcolor
resetcolor:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC8(%rip), %rcx
	call	printf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	reverse
	.def	reverse;	.scl	2;	.type	32;	.endef
	.seh_proc	reverse
reverse:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -4(%rbp)
	movq	16(%rbp), %rcx
	call	strlen
	subl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.L13
.L14:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -9(%rbp)
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rcx
	movq	16(%rbp), %rdx
	addq	%rcx, %rdx
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-9(%rbp), %eax
	movb	%al, (%rdx)
	addl	$1, -4(%rbp)
	subl	$1, -8(%rbp)
.L13:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L14
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	print_binary
	.def	print_binary;	.scl	2;	.type	32;	.endef
	.seh_proc	print_binary
print_binary:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	leaq	s.3710(%rip), %rax
	movq	%rax, -8(%rbp)
	jmp	.L16
.L17:
	movzbl	16(%rbp), %eax
	andl	$1, %eax
	leal	48(%rax), %ecx
	movq	-8(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, -8(%rbp)
	movl	%ecx, %edx
	movb	%dl, (%rax)
	shrb	16(%rbp)
.L16:
	cmpb	$0, 16(%rbp)
	jne	.L17
	movq	-8(%rbp), %rax
	movb	$0, (%rax)
	leaq	s.3710(%rip), %rcx
	call	reverse
	leaq	s.3710(%rip), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC9:
	.ascii "%08x:%c\0"
.LC10:
	.ascii "\302\267\0"
.LC11:
	.ascii "\12%08x:%c\0"
.LC12:
	.ascii "%08s%c\0"
.LC13:
	.ascii "%*c\0"
	.text
	.globl	print_bintable2
	.def	print_bintable2;	.scl	2;	.type	32;	.endef
	.seh_proc	print_bintable2
print_bintable2:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	$0, -8(%rbp)
	movq	$0, -16(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -48(%rbp)
	movb	$0, -17(%rbp)
	jmp	.L20
.L29:
	movq	16(%rbp), %rcx
	call	fgetc
	movb	%al, -17(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L21
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	movq	-8(%rbp), %rax
	movl	$32, %r8d
	movq	%rax, %rdx
	leaq	.LC9(%rip), %rcx
	call	printf
	call	resetcolor
	jmp	.L22
.L21:
	movq	NUM_BIN_ROWS(%rip), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	testq	%rax, %rax
	jne	.L22
	call	__getreent
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movl	$32, %ecx
	call	fputc
	movq	NUM_BIN_ROWS(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jb	.L23
	movq	NUM_BIN_ROWS(%rip), %rax
	notq	%rax
	movl	$1, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	fseek
	jmp	.L24
.L23:
	movl	$0, %r8d
	movl	$0, %edx
	movq	16(%rbp), %rcx
	call	fseek
.L24:
	movq	$0, -16(%rbp)
	jmp	.L25
.L28:
	movq	16(%rbp), %rcx
	call	fgetc
	movb	%al, -17(%rbp)
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	-17(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$151, %eax
	testl	%eax, %eax
	je	.L26
	call	__getreent
	movq	16(%rax), %rdx
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	fputc
	jmp	.L27
.L26:
	leaq	.LC10(%rip), %rcx
	call	printf
.L27:
	addq	$1, -16(%rbp)
	call	resetcolor
.L25:
	movq	NUM_BIN_ROWS(%rip), %rax
	cmpq	%rax, -16(%rbp)
	jb	.L28
	movq	16(%rbp), %rcx
	call	fgetc
	movb	%al, -17(%rbp)
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	movq	-8(%rbp), %rax
	movl	$32, %r8d
	movq	%rax, %rdx
	leaq	.LC11(%rip), %rcx
	call	printf
	call	resetcolor
.L22:
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	print_binary
	movl	$32, %r8d
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rcx
	call	printf
	call	resetcolor
	addq	$1, -8(%rbp)
.L20:
	movq	-8(%rbp), %rax
	cmpq	32(%rbp), %rax
	jb	.L29
	movq	-8(%rbp), %rax
	cmpq	32(%rbp), %rax
	jne	.L30
	movq	-8(%rbp), %rax
	movq	%rax, -32(%rbp)
	jmp	.L31
.L34:
	movq	-32(%rbp), %rax
	andl	$1, %eax
	testq	%rax, %rax
	jne	.L32
	movl	$32, %r8d
	movl	$9, %edx
	leaq	.LC13(%rip), %rcx
	call	printf
	jmp	.L33
.L32:
	movl	$32, %r8d
	movl	$9, %edx
	leaq	.LC13(%rip), %rcx
	call	printf
.L33:
	addq	$1, -32(%rbp)
.L31:
	movq	NUM_BIN_ROWS(%rip), %rcx
	movq	-32(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	testq	%rax, %rax
	jne	.L34
	movq	NUM_BIN_ROWS(%rip), %rcx
	movq	-32(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	testq	%rax, %rax
	jne	.L30
	movl	$32, %ecx
	call	putchar
.L30:
	movq	-8(%rbp), %rax
	cmpq	32(%rbp), %rax
	jne	.L35
	movq	NUM_BIN_ROWS(%rip), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	testq	%rax, %rax
	je	.L35
	movq	-8(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	16(%rbp), %rcx
	call	ftell
	movq	%rax, -40(%rbp)
	movq	NUM_BIN_ROWS(%rip), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	negq	%rax
	movl	$1, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	fseek
	movq	$0, -16(%rbp)
	jmp	.L36
.L39:
	movq	16(%rbp), %rcx
	call	fgetc
	movb	%al, -17(%rbp)
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	-17(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$151, %eax
	testl	%eax, %eax
	je	.L37
	call	__getreent
	movq	16(%rax), %rdx
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	fputc
	jmp	.L38
.L37:
	leaq	.LC10(%rip), %rcx
	call	printf
.L38:
	addq	$1, -16(%rbp)
	call	resetcolor
.L36:
	movq	NUM_BIN_ROWS(%rip), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	cmpq	%rax, -16(%rbp)
	jb	.L39
	movq	-40(%rbp), %rax
	movl	$0, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	fseek
	jmp	.L40
.L35:
	movq	-8(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	16(%rbp), %rcx
	call	ftell
	movq	%rax, -40(%rbp)
	movq	NUM_BIN_ROWS(%rip), %rax
	negq	%rax
	movl	$1, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	fseek
	movq	$0, -16(%rbp)
	jmp	.L41
.L44:
	movq	16(%rbp), %rcx
	call	fgetc
	movb	%al, -17(%rbp)
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	-17(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$151, %eax
	testl	%eax, %eax
	je	.L42
	call	__getreent
	movq	16(%rax), %rdx
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	fputc
	jmp	.L43
.L42:
	leaq	.LC10(%rip), %rcx
	call	printf
.L43:
	addq	$1, -16(%rbp)
	call	resetcolor
.L41:
	movq	NUM_BIN_ROWS(%rip), %rax
	cmpq	%rax, -16(%rbp)
	jb	.L44
	movq	-40(%rbp), %rax
	movl	$0, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	fseek
.L40:
	nop
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC14:
	.ascii "%c%02x\0"
.LC15:
	.ascii "%c%c%c\0"
	.text
	.globl	print_hextable
	.def	print_hextable;	.scl	2;	.type	32;	.endef
	.seh_proc	print_hextable
print_hextable:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	$0, -8(%rbp)
	movq	$0, -16(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -48(%rbp)
	movb	$0, -17(%rbp)
	jmp	.L46
.L55:
	movq	16(%rbp), %rcx
	call	fgetc
	movb	%al, -17(%rbp)
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	cmpq	$0, -8(%rbp)
	jne	.L47
	movq	-8(%rbp), %rax
	movl	$32, %r8d
	movq	%rax, %rdx
	leaq	.LC9(%rip), %rcx
	call	printf
	jmp	.L48
.L47:
	movq	NUM_HEX_ROWS(%rip), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	testq	%rax, %rax
	jne	.L48
	call	__getreent
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movl	$32, %ecx
	call	fputc
	movq	NUM_HEX_ROWS(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jb	.L49
	movq	NUM_HEX_ROWS(%rip), %rax
	notq	%rax
	movl	$1, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	fseek
	jmp	.L50
.L49:
	movl	$0, %r8d
	movl	$0, %edx
	movq	16(%rbp), %rcx
	call	fseek
.L50:
	movq	$0, -16(%rbp)
	jmp	.L51
.L54:
	movq	16(%rbp), %rcx
	call	fgetc
	movb	%al, -17(%rbp)
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	-17(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$151, %eax
	testl	%eax, %eax
	je	.L52
	call	__getreent
	movq	16(%rax), %rdx
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	fputc
	jmp	.L53
.L52:
	leaq	.LC10(%rip), %rcx
	call	printf
.L53:
	addq	$1, -16(%rbp)
	call	resetcolor
.L51:
	movq	NUM_HEX_ROWS(%rip), %rax
	cmpq	%rax, -16(%rbp)
	jb	.L54
	movq	16(%rbp), %rcx
	call	fgetc
	movb	%al, -17(%rbp)
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	movq	-8(%rbp), %rax
	movl	$32, %r8d
	movq	%rax, %rdx
	leaq	.LC11(%rip), %rcx
	call	printf
	call	resetcolor
.L48:
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	movzbl	-17(%rbp), %eax
	movl	%eax, %r8d
	movl	$32, %edx
	leaq	.LC14(%rip), %rcx
	call	printf
	addq	$1, -8(%rbp)
	call	resetcolor
.L46:
	movq	-8(%rbp), %rax
	cmpq	32(%rbp), %rax
	jb	.L55
	movq	-8(%rbp), %rax
	cmpq	32(%rbp), %rax
	jne	.L56
	movq	-8(%rbp), %rax
	movq	%rax, -32(%rbp)
	jmp	.L57
.L60:
	movq	-32(%rbp), %rax
	andl	$1, %eax
	testq	%rax, %rax
	jne	.L58
	movl	$32, %r9d
	movl	$32, %r8d
	movl	$32, %edx
	leaq	.LC15(%rip), %rcx
	call	printf
	jmp	.L59
.L58:
	movl	$32, %r9d
	movl	$32, %r8d
	movl	$32, %edx
	leaq	.LC15(%rip), %rcx
	call	printf
.L59:
	addq	$1, -32(%rbp)
.L57:
	movq	NUM_HEX_ROWS(%rip), %rcx
	movq	-32(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	testq	%rax, %rax
	jne	.L60
	movq	NUM_HEX_ROWS(%rip), %rcx
	movq	-32(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	testq	%rax, %rax
	jne	.L56
	movl	$32, %ecx
	call	putchar
.L56:
	movq	-8(%rbp), %rax
	cmpq	32(%rbp), %rax
	jne	.L61
	movq	NUM_HEX_ROWS(%rip), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	testq	%rax, %rax
	je	.L61
	movq	-8(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	16(%rbp), %rcx
	call	ftell
	movq	%rax, -40(%rbp)
	movq	NUM_HEX_ROWS(%rip), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	negq	%rax
	movl	$1, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	fseek
	movq	$0, -16(%rbp)
	jmp	.L62
.L65:
	movq	16(%rbp), %rcx
	call	fgetc
	movb	%al, -17(%rbp)
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	-17(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$151, %eax
	testl	%eax, %eax
	je	.L63
	call	__getreent
	movq	16(%rax), %rdx
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	fputc
	jmp	.L64
.L63:
	leaq	.LC10(%rip), %rcx
	call	printf
.L64:
	addq	$1, -16(%rbp)
	call	resetcolor
.L62:
	movq	NUM_HEX_ROWS(%rip), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	cmpq	%rax, -16(%rbp)
	jb	.L65
	movq	-40(%rbp), %rax
	movl	$0, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	fseek
	jmp	.L66
.L61:
	movq	-8(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	16(%rbp), %rcx
	call	ftell
	movq	%rax, -40(%rbp)
	movq	NUM_HEX_ROWS(%rip), %rax
	negq	%rax
	movl	$1, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	fseek
	movq	$0, -16(%rbp)
	jmp	.L67
.L70:
	movq	16(%rbp), %rcx
	call	fgetc
	movb	%al, -17(%rbp)
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	colorchar
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movzbl	-17(%rbp), %eax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$151, %eax
	testl	%eax, %eax
	je	.L68
	call	__getreent
	movq	16(%rax), %rdx
	movzbl	-17(%rbp), %eax
	movl	%eax, %ecx
	call	fputc
	jmp	.L69
.L68:
	leaq	.LC10(%rip), %rcx
	call	printf
.L69:
	addq	$1, -16(%rbp)
	call	resetcolor
.L67:
	movq	NUM_HEX_ROWS(%rip), %rax
	cmpq	%rax, -16(%rbp)
	jb	.L70
	movq	-40(%rbp), %rax
	movl	$0, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	fseek
.L66:
	nop
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC16:
	.ascii "%llu: Less than two arguments!\12\0"
.LC17:
	.ascii "rb\0"
.LC18:
	.ascii "\33[1;31m\12\0\0"
.LC19:
	.ascii "%llu: Failed to open file!\12\0"
.LC20:
	.ascii "\33[0m\12\0\0"
	.align 8
.LC21:
	.ascii "%llu: Error! Column argument is not a type of unsigned integer!\12\0"
	.align 8
.LC22:
	.ascii "%llu: Error! Failed to open %s\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, -32(%rbp)
	movq	%rdx, -24(%rbp)
	call	__main
	movq	$0, -72(%rbp)
	cmpl	$1, -32(%rbp)
	jg	.L72
	movq	-72(%rbp), %rax
	movl	$594, %r8d
	leaq	.LC16(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	movl	$1, %eax
	jmp	.L73
.L72:
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	leaq	-8(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	leaq	.LC17(%rip), %rdx
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -72(%rbp)
	cmpq	$0, -72(%rbp)
	jne	.L74
	call	__getreent
	movq	24(%rax), %rax
	movq	%rax, %r9
	movl	$8, %r8d
	movl	$1, %edx
	leaq	.LC18(%rip), %rcx
	call	fwrite
	call	__getreent
	movq	16(%rax), %rax
	movl	$604, %r8d
	leaq	.LC19(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	call	__getreent
	movq	24(%rax), %rax
	movq	%rax, %r9
	movl	$5, %r8d
	movl	$1, %edx
	leaq	.LC20(%rip), %rcx
	call	fwrite
	movl	$1, %eax
	jmp	.L73
.L74:
	movq	-72(%rbp), %rax
	movl	$2, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	fseek
	movq	-72(%rbp), %rax
	movq	%rax, %rcx
	call	ftell
	movq	%rax, -80(%rbp)
	movq	NUM_HEX_ROWS(%rip), %rax
	addq	$1, %rax
	movl	$1, %edx
	movq	%rax, %rcx
	call	calloc
	movq	%rax, ascii_line.3777(%rip)
	movq	-72(%rbp), %rax
	movq	%rax, %rcx
	call	rewind
	jmp	.L75
.L84:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	cmpl	$99, %eax
	je	.L77
	cmpl	$100, %eax
	je	.L75
	cmpl	$98, %eax
	je	.L79
	jmp	.L88
.L77:
	addq	$8, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -88(%rbp)
	jmp	.L80
.L81:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
.L80:
	call	__locale_ctype_ptr
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	movsbq	%al, %rax
	addq	$1, %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	andl	$4, %eax
	testl	%eax, %eax
	jne	.L81
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L82
	call	__getreent
	movq	24(%rax), %rax
	movq	%rax, %r9
	movl	$8, %r8d
	movl	$1, %edx
	leaq	.LC18(%rip), %rcx
	call	fwrite
	call	__getreent
	movq	24(%rax), %rax
	movl	$652, %r8d
	leaq	.LC21(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	call	__getreent
	movq	24(%rax), %rax
	movq	%rax, %r9
	movl	$5, %r8d
	movl	$1, %edx
	leaq	.LC20(%rip), %rcx
	call	fwrite
	movl	$1, %eax
	jmp	.L73
.L82:
	movq	-88(%rbp), %rax
	movl	$10, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	strtol
	movq	%rax, NUM_HEX_ROWS(%rip)
	movq	ascii_line.3777(%rip), %rax
	movq	%rax, %rcx
	call	free
	movq	NUM_HEX_ROWS(%rip), %rax
	movl	$1, %edx
	movq	%rax, %rcx
	call	calloc
	movq	%rax, ascii_line.3777(%rip)
	movq	-88(%rbp), %rax
	movl	$10, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	strtol
	movq	%rax, NUM_BIN_ROWS(%rip)
	jmp	.L75
.L79:
	movb	$1, bintable_request(%rip)
	movq	ascii_line.3777(%rip), %rax
	movq	%rax, %rcx
	call	free
	movq	NUM_BIN_ROWS(%rip), %rax
	addq	$1, %rax
	movl	$1, %edx
	movq	%rax, %rcx
	call	calloc
	movq	%rax, ascii_line.3777(%rip)
	jmp	.L75
.L88:
	nop
.L75:
	addq	$8, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L83
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	cmpb	$45, %al
	je	.L84
.L83:
	movzbl	bintable_request(%rip), %eax
	testb	%al, %al
	je	.L85
	movq	ascii_line.3777(%rip), %rdx
	movq	-80(%rbp), %rcx
	movq	-72(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	print_bintable2
	jmp	.L86
.L85:
	movq	ascii_line.3777(%rip), %rdx
	movq	-80(%rbp), %rcx
	movq	-72(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	print_hextable
.L86:
	movq	-72(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	cmpl	$-1, %eax
	jne	.L87
	call	__getreent
	movq	24(%rax), %rax
	movq	%rax, %r9
	movl	$8, %r8d
	movl	$1, %edx
	leaq	.LC18(%rip), %rcx
	call	fwrite
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	leaq	-8(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rbx
	call	__getreent
	movq	24(%rax), %rax
	movq	%rbx, %r9
	movl	$708, %r8d
	leaq	.LC22(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	call	__getreent
	movq	24(%rax), %rax
	movq	%rax, %r9
	movl	$5, %r8d
	movl	$1, %edx
	leaq	.LC20(%rip), %rcx
	call	fwrite
	movl	$1, %eax
	jmp	.L73
.L87:
	movl	$0, %eax
.L73:
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
.lcomm s.3710,10,8
.lcomm ascii_line.3777,8,8
	.ident	"GCC: (GNU) 7.4.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	__locale_ctype_ptr;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	fgetc;	.scl	2;	.type	32;	.endef
	.def	__getreent;	.scl	2;	.type	32;	.endef
	.def	fputc;	.scl	2;	.type	32;	.endef
	.def	fseek;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	ftell;	.scl	2;	.type	32;	.endef
	.def	fprintf;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	fwrite;	.scl	2;	.type	32;	.endef
	.def	calloc;	.scl	2;	.type	32;	.endef
	.def	rewind;	.scl	2;	.type	32;	.endef
	.def	strtol;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef

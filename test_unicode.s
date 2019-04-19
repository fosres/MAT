	.file	"test_unicode.c"
	.text
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
	jmp	.L2
.L3:
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
.L2:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L3
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "\0"
.LC1:
	.ascii "%s\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rdx
	movl	$0, %ecx
	call	setlocale
	movq	%rax, -8(%rbp)
	movl	$15573120, -12(%rbp)
	movl	$32, -16(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, s.3830(%rip)
	leaq	s.3830(%rip), %rcx
	call	reverse
	leaq	s.3830(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	movl	-16(%rbp), %eax
	movl	%eax, s.3830(%rip)
	leaq	s.3830(%rip), %rcx
	call	reverse
	movl	-12(%rbp), %eax
	movl	%eax, s.3830(%rip)
	leaq	s.3830(%rip), %rcx
	call	reverse
	leaq	s.3830(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	leaq	s.3830(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	leaq	s.3830(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	leaq	s.3830(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	leaq	s.3830(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
.lcomm s.3830,5,1
	.ident	"GCC: (GNU) 7.4.0"
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	setlocale;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef

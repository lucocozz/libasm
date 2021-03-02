bits 64

section .text
	global ft_strcmp

ft_strcmp:
	xor	rcx, rcx
	jmp	compare

compare:
	mov	al, byte [rdi + rcx]
	mov	bl, byte [rsi + rcx]
	cmp	al, 0
	je return
	cmp	bl, 0
	je return
	cmp al, bl
	jne return
	inc	rcx
	jmp compare

return:
	movzx	rax, al
	movzx	rbx, bl
	sub rax, rbx
	ret
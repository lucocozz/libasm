bits 64

section .text
	global ft_strcpy

ft_strcpy:
	xor	rcx, rcx
	jmp	copy

copy:
	cmp	byte [rsi + rcx], 0
	je	return
	mov al, byte [rsi + rcx]
	mov byte [rdi + rcx], al
	inc rcx
	jmp copy

return:
	mov	byte [rdi + rcx], 0
	mov	rax, rdi
	ret
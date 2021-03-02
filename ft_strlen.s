bits 64

section .text
	global	ft_strlen
	
ft_strlen:
	xor	rcx, rcx
	jmp	count

count:
	cmp byte [rdi + rcx], 0
	je	return
	inc	rcx
	jmp	count

return:
	mov	rax, rcx
	ret

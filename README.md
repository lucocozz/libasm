# libasm
![100](https://i.imgur.com/iU05a2f.png)
### variables:
```
rax = returned variable
rcx = counter variable
rbx = variable
rdi = 1st argument function
rsi = 2nd argument function
rdx = 3th argument function
al, bl, cl, dl = char (8bits var)
```

### instructions:
```asm
mov	rcx, 0			; i = 0
xor	rcx, rcx		; i = 0	// fast
inc	rcx			; i++
dec 	rcx			; i--
cmp	byte [rdi + rcx], 0	; *(str + i) == '\0'	// str = rdi = 1st function arg
call	function		; function() // function extern of the file
jmp	label			; function() // label = function in same file
je	label			; if (True) function()
jne	label			; if (False) function()
jl	label			; if (value1 < value2) function()
ret				; return (var)	// var = rax
movzx	rbx, al			; str = (char *)c // (approximately) cast 8bits var to 64bits
syscall				; syscall ¯\_(ツ)_/¯ (after move rax, syscall_id)
```

### Handling errors:
```asm
section .text
	extern __errno_location

main:
	mov	rax, syscall_id
	syscall
	cmp	rax, 0
	jl	error
	ret

error:
	neg	rax
	mov	rbx, rax
	call	__errno_location
	mov	[rax], rbx
	mov	rax, -1
	ret
```

### sources:
https://syscalls.w3challs.com/?arch=x86_64

https://www.lacl.fr/tan/asm

https://www.fil.univ-lille1.fr/portail/archive19-20/~meftali/PdM/Theme1.pdf

https://www.youtube.com/watch?v=yxzUi8MdOAA&list=PLcT0DaY68xGzzmj47WSbb8XaIwWFjVlKz&index=1

https://www.youtube.com/watch?v=fvtd2Ut3MHw&list=PLrSOXFDHBtfEs7PCC6r44iXiX5gMlbjcR&index=1

⭐ https://github.com/Emmabrdt/Libasm-Linux

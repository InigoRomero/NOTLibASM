section .text
	global _ft_strcmp
_ft_strcmp:
	mov rcx, -1
while:
	inc rcx
	mov dl, byte[rdi + rcx]
	mov bl, byte[rsi + rcx]
	cmp  byte[rdi + rcx] , 0
	je while
	cmp  rbx, 0
	jl neg
	cmp rbx, 0
	je finish
	sub rdx, rbx
	mov rax, rdx
	ret
neg:
	sub rbx, rdx
	neg rbx
	mov rax, rbx
	ret

finish:
	mov rax, 0
	ret
section .text
	global _ft_strcpy

_ft_strcpy:
	mov rcx, -1
while:
	inc rcx
	mov  dl ,byte [rsi + rcx]
	mov byte [rdi + rcx], dl
	cmp byte [rdi + rcx], 0
	jne while
	mov rax, rdi
	ret
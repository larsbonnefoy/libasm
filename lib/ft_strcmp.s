;strcmp(const char *s1, const char *s2)
;s1 loaded in rdi, s2 loaded in rsi

section .text

global _ft_strcmp

_ft_strcmp:
	mov rcx, -1

.loop:
	inc rcx
	mov al, byte [rdi + rcx] 		;mov s1[i] into al
	cmp al, 0						;check for null terminating byte
	je .end
	cmp byte [rsi + rcx], al		;cmp  s2[i] with al
	je .loop						;if s1[i] == s2[i] loop
									;-> should check if s1[i] == 0 || s2[i] == 0
.end:
	sub al, byte [rsi + rcx]		;s1[i] - s2[i]
	movsx eax, al					;sign extend al to eax to return 32 bit value
	ret

section .text

global __ft_strlen              ;global defines symbols

__ft_strlen:
    xor rax, rax
    jmp .loop

.incr:
    inc rax

.loop:                          ;counting loop 
    cmp byte [rdi + rax], 0         ;checks if rax byte = 0
    jne .incr                       ;if cmp not equal to 1 loop back

	ret                             ;return value contained in rax

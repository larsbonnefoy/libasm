section .text

global __ft_strlen              ;global defines symbols

__ft_strlen:

mov rax, -1

.loop:                          ;counting loop 
inc rax                         ;inc rax counter by 1
cmp byte [rdi + rax], 0         ;checks if rax byte = 0
jne .loop                       ;if cmp not equal to 1 loop back

ret                             ;return value contained in rax

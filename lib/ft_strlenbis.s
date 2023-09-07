
section .text

global __ft_strlen              ;global defines symbols

__ft_strlen:

xor rax, rax                    ;setting rax to 0

.loop:                          ;counting loop 
cmp byte [rdi + rax], 0         ;checks if rax byte = 0
inc rax                         ;inc rax counter by 1
jne .loop                       ;if cmp not equal to 1 loop back

ret                             ;return value contained in rax

extern _ft_strlen
extern _malloc
extern _ft_strcpy

;rdi: contains str
;strlen needs len in rdi                        | returns in rax
;malloc needs len in rdi                        | returns in rax
;strcpy needs malloc space in rdi, str in rsi   | returns in rax

section .text

global _ft_strdup

_ft_strdup:
    call _ft_strlen         ;ret val of _ft_strlen is in rax
    push rdi                ;save string;
    mov rdi, rax            ;move len to malloc into rdi
    inc rdi                 ;+1 for null terminating byte
    call _malloc
    mov rdi, rax            ;move malloc address for strcpy
    pop rsi
    call _ft_strcpy
    ret

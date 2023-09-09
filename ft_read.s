%define MACH_SYSCALL(nb) 0x2000000 | nb
%define READ 3
extern ___error

;read(fd, *buff, buff_length)
;fd -> rdi
;buff -> rsi
;buff_length -> rdx
;check for null buff_length or buf?

section .text

global _ft_read

_ft_read:
    mov rax, MACH_SYSCALL(READ)
    syscall                         ;writes nbr of bytes read to eax if success
    jc .error
    jnc .end                        ;writes errno nb to eax if fail

.error:
    mov rdx, rax                    ;save ret value to rdx
    call ___error 
    mov [rax], rdx   
    mov rax, -1

.end:
    ret

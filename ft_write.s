%define MACH_SYSCALL(nb) 0x2000000 | nb
%define WRITE 4
extern ___error

;write(fd, buff, buff_length)
;fd -> rdi
;buff -> rsi
;buff_length -> rdx
;check for null buff_length or buf?

section .text

global _ft_write

_ft_write:
    mov rax, MACH_SYSCALL(WRITE)
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

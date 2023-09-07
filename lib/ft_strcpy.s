;dst is passed in rdi, src is passed in rsi

section .text

global __ft_strcpy

__ft_strcpy:

;xor rdi, rdi                ;clean dst
mov rcx, -1

cmp byte [rsi], 0           ;check first if not empty string
je .end              

.start:                      ;start of loop
inc rcx
mov al, byte [rsi + rcx]    ;move ithe byte from src into al
mov byte [rdi + rcx], al    ;move ithe byte from al to dst
cmp byte [rsi + rcx], 0     ;check if we are at end of string
jne .start                  ;if last byte is not reached we continue

.end:
mov rax, rdi                ;have to return dest*
ret

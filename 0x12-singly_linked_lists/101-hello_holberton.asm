global main
extern printf
extern exit

section .data
    message db "Hello, Holberton", 10, 0

section .text
main:
    push rdi
    mov rdi, message
    call printf
    pop rdi

    ; check the return value from printf
    cmp rax, -1
    je .error_handler ; error occured, handle it

    ; exit the program gracefully with code 0
    mov rdi, 0
    call exit

.error_handler:
    ; handle errors that occured during the call to printf

    ; exit with 1
    mov rdi, 1
    call exit

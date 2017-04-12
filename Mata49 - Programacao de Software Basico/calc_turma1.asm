; Using Linux and gcc:
; nasm -f elf calc_turma1.asm
; gcc -o calc_turma1 calc_turma1.o driver.c asm_io.o
%include "asm_io.inc"


segment .data
;
; These labels refer to strings used for output
;
;
prompt1 db    "Escolha uma operação(1: add, 2: sub, 3: mul, 4: div) ", 0       ; don't forget
prompt2 db    "Enter a first number: ", 0       ; don't forget nul terminator
prompt3 db    "Enter a second number: ", 0
prompt4 db    "O resultado eh: ", 0
prompt5 db    "O resto eh: ", 0

; uninitialized data is put in the .bss segment
;
segment .bss

number1 resd   1               ; 32bits reserve a double word

number2 resd   1               ; 32bits reserve a double word  

segment .text
        global  asm_main
asm_main:

        enter   0,0
        
        mov     eax, prompt1
        call    print_string 
        
        call    read_int          ; armazena no eax
        mov     [number1], eax    ; number1 = eax
        
        cmp eax, 1
        je adicionar                
                
        cmp eax, 2
        je subtracao


        cmp eax, 3
        je multiplicacao

        cmp eax, 4
        je divisao


        adicionar:
        mov     eax, prompt2
        call    print_string 
        
        call    read_int          ; armazena no eax
        mov     [number1], eax    ; number1 = eax
        
        mov     eax, prompt3
        call    print_string 
        
        call    read_int
        mov     [number2], eax
        
        mov     eax, prompt4
        call    print_string
        
        mov eax, [number1]
        add eax, [number2]
        
        call    print_int
        call    print_nl 
        
        jmp fim    
        
        subtracao:
        mov     eax, prompt2
        call    print_string 
        
        call    read_int          ; armazena no eax
        mov     [number1], eax    ; number1 = eax
        
        mov     eax, prompt3
        call    print_string 
        
        call    read_int
        mov     [number2], eax
        
        mov     eax, prompt4
        call    print_string
        
        mov eax, [number1]
        sub eax, [number2]
        
        call    print_int
        call    print_nl     
        
        jmp fim
        
        
        multiplicacao:
        mov     eax, prompt2
        call    print_string 
        
        call    read_int          ; armazena no eax
        mov     [number1], eax    ; number1 = eax
        
        mov     eax, prompt3
        call    print_string 
        
        call    read_int
        mov     [number2], eax
        
        mov     eax, prompt4
        call    print_string
        
        mov eax, [number1]
        imul eax, [number2]
        
        call    print_int
        call    print_nl 
        jmp fim

        divisao:
        mov     eax, prompt2
        call    print_string 
        
        call    read_int          ; armazena no eax
        mov     [number1], eax    ; number1 = eax
        
        mov     eax, prompt3
        call    print_string 
        
        call    read_int
        mov     [number2], eax
        
        mov     eax, prompt4
        call    print_string
        
        mov eax, [number1]
        cdq
        
        mov ebx, [number2] 
        idiv ebx
        
        call    print_int
        call    print_nl
        
        mov     eax, prompt5
        call    print_string
        
        mov eax, edx
        call    print_int
        call    print_nl  
        jmp fim
        
    fim:                        
        leave        
        ret  


;
; To create executable:
; Using djgpp:
; nasm -f coff first.asm
; gcc -o first first.o driver.c asm_io.o
;
; Using Linux and gcc:
; nasm -f elf first.asm
; gcc -o first first.o driver.c asm_io.o
;
; Using Borland C/C++
; nasm -f obj first.asm
; bcc32 first.obj driver.c asm_io.obj
;
; Using MS C/C++
; nasm -f win32 first.asm
; cl first.obj driver.c asm_io.obj
;
; Using Open Watcom
; nasm -f obj first.asm
; wcl386 first.obj driver.c asm_io.obj
%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data
;
; These labels refer to strings used for output
;
prompt1 db    "Enter a first number: ", 0       ; don't forget nul terminator
prompt2 db    "Enter a second number: ", 0
prompt3 db    "First number greater than second ", 0
prompt4 db    "First number less than second ", 0
prompt5 db    "Numbers equals ", 0

;
; uninitialized data is put in the .bss segment
;
segment .bss

number1 resd   1               ; 32bits reserve a double word
number2 resd   1               ; 32bits reserve a double word  


;
; code is put in the .text segment
;
segment .text
        global  asm_main
asm_main:

        enter   0,0               ; setup routine
        
        mov     eax, prompt1
        call    print_string        
        
        call    read_int          ; armazena no eax
        mov     [number1], eax    ; number1 = eax
        
        mov     eax, prompt2
        call    print_string
        
        call    read_int
        mov     [number2], eax
        
        cmp     [number1], eax  ; compare number1 com number2(eax)
        
        jz      equal           ; ZF=1 dá o salto
        jmp     else
        
        equal:
        mov     eax, prompt5
        call    print_string
        call    print_nl
        
        jmp     finish
        
        else:
        jg      greater
        
        less:
        mov     eax, prompt4
        call    print_string
        call    print_nl
        jmp     finish
        
        greater:
        mov     eax, prompt3
        call    print_string
        call    print_nl
       ; 
        finish:
            
        leave        
        ret

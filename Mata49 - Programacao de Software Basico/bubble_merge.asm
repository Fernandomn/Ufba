%include "asm_io.inc"

;______________________________________________________________________;
segment .data
	TAMVET dd 8
	prompt1 db "bubble"
	prompt2 db "merge"
;______________________________________________________________________;
segment .bss
	vetor1 resd 8
;______________________________________________________________________;
segment .text

global asm_main
asm_main:
	enter 0,0
		
	cld
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		
	mov edi, vetor1
	mov ecx, [TAMVET]
	
	pega_vetor:
		call read_int
		stosd
	loop pega_vetor
	
	call read_int ; limpa o buffer
	call read_char
	
	cmp eax, "b"
	je bubble_sort
	cmp eax, "m"
	je merge_sort
	
	jmp end_prog
		
	bubble_sort:
		mov eax, prompt1
		call print_string
		jmp end_prog
	merge_sort:
		mov eax, prompt2
		call print_string
		jmp end_prog
	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	end_prog:
		mov eax, 0
		leave
		ret

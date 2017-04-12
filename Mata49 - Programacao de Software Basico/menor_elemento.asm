%include "asm_io.inc"

;-----------------------------------------------

segment .data	; variaveis inicializadas

title1 db "MENOR ELEMENTO", 0
prompt1 db "insira os 7 elementos do vetor:", 0
output1 db "o menor valor e ", 0
output2 db " e sua posicao e ", 0

;-----------------------------------------------

segment .bss	; variaveis nao-inicializadas

vetor1 resd 7
menor1 resd 1
pos1 resd 1

;-----------------------------------------------

; programa principal:
segment .text
	global asm_main
asm_main:
	enter 0,0

	cld

	mov eax, title1
	call print_string
	call print_nl

	mov eax, prompt1
	call print_string
	call print_nl

	mov ecx, 7
	mov edi, vetor1
	laco1:
		call read_int
		stosd
		loop laco1

	mov eax, [vetor1]
	mov [menor1], eax

	mov ecx, 7
	mov esi, vetor1
	laco2:
		mov ebx, [menor1]
		lodsd
		cmp eax, ebx
		jge fim_laco
		mov [menor1], eax
		mov eax, 7
		sub eax, ecx
		mov [pos1], eax
		fim_laco:
			loop laco2

	mov eax, output1
	call print_string
	mov eax, [menor1]
	call print_int
	mov eax, output2
	call print_string
	mov eax, [pos1]
	call print_int
	call print_nl

	mov eax,0
	leave
	ret

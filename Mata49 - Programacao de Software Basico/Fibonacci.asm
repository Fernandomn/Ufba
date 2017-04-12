%include "asm_io.inc"

;-----------------------------------------------

segment .data

title1 db "FIBONACCI", 0
prompt1 db "digite um numero: ", 0
output1 db "o valor em Fibonacci e ", 0

;-----------------------------------------------

segment .bss

input1 resd 1
output2 resd 1
anterior1 resd 1
anterior2 resd 1

;-----------------------------------------------

segment .text
	global asm_main
asm_main:
	enter 0,0

	mov eax, 0
        mov [anterior1], eax
	mov eax, 1
	mov [anterior2], eax

	mov eax, title1
	call print_string
	call print_nl

	mov eax, prompt1
	call print_string

	call read_int
	mov [input1], eax

	mov eax, [input1]
	cmp eax, 0
	je caso_base
	mov ecx, eax
	laco:
		mov ebx, 0
		mov eax, [anterior1]
		add ebx, eax
		mov eax, [anterior2]
		add ebx, eax
		mov [output2], ebx
		mov [anterior1], eax
		mov [anterior2], ebx
		loop laco
		jmp final

	caso_base:
		mov eax, 1
		mov [output2], eax
		jmp final

	final:
		mov eax, output1
		call print_string
		mov eax, [output2]
		call print_int
		call print_nl
	

	mov eax,0
	leave
	ret

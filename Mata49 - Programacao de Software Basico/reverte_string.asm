%include "asm_io.inc"

;______________________________________________;
segment .data

prompt1 db "Digite a frase a ser codificada:"
MAXVET db 25
;______________________________________________;
segment .bss
vetorEntrada resb 25
vetorSaida resb 25

;______________________________________________;
segment .text

global asm_main

asm_main:
	enter 0, 0

	mov eax, prompt1
	call print_string
	call print_nl

	mov ecx, [MAXVET]
	mov edi, vetorEntrada
	laco1:
		call read_char
		stosb
	loop laco1

	mov ecx, [MAXVET]
	mov esi, vetorEntrada
	mov edi, vetorSaida
	mov ebx, 0
	laco2:
		lodsb
		cmp al, " "
		je move_contador
		movzx eax, al
		push eax
		inc ebx
		loop laco2
		jmp fim
		move_contador:
			mov ecx, ebx
			jmp lacoDes
		lacoDes:
			pop eax
			stosb
			loop lacoDes
		mov eax, " "
		stosb
		mov eax, [MAXVET]
		sub eax, ebx
		mov ecx, eax
		mov ebx, 0
		jmp laco2
		
fim:
	mov eax,0
	leave
	ret






%include "asm_io.inc"

;______________________________________________________________________;
segment .data
	TAMVET dd 8
	prompt1 db "bubble"
	prompt2 db "merge"
;______________________________________________________________________;
segment .bss
	vetor1 resd 8
	k_bubble resd 1
	i_bubble resd 1
	j_bubble resd 1
	p_bubble resd 1
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
	
	mov eax, 0
	call bubble_sort
		
	jmp end_prog
		
	bubble_sort:
	
		;void bubble (int V[], int n)
		;{
		;int k = n-1;
		mov eax, n
		dec eax
		mov [k], eax
		;int l; for (l = 0; l < n; l++) printf ("%d ", V[l]);
		mov esi, vetor1
		mov ecx, [TAMVET]
		print_bubble1:
			lodsd
			call print_int
			mov eax, " "
			call print_char
		loop print_bubble1
		call print_nl
		
		;int i;
		mov ecx, [TAMVET]
		;for (i = 0; i < n; i++)
		;{
		for_bubble1:
			;int j = 0;
			mov [j_bubble], 0
			;while (j <= k)
			;{
			mov eax, [j_bubble]
			cmp eax, [k_bubble]
			jg end_while_bubble1
				;if (V[j] > V[j+1])
				;{
				mov eax, [vetor1 + j*4]
				mov ebx, [vetor1 + (j+1)*4]
				cmp eax, ebx
				jge end_if_bubble1
					;int aux = V[j];
					;V[j] = V[j+1];
					;V[j+1] = aux;
					mov [vetor1 + j*4], ebx
					mov [vetor1 + (j+1)*4], eax
					;int l; for (l = 0; l < n; l++) printf ("%d ", V[l]);
					mov esi, vetor1
					mov ebx, ecx
					mov ecx, [TAMVET]
					print_bubble1:
						lodsd
						call print_int
						mov eax, " "
						call print_char
					loop print_bubble1
					call print_nl
					mov ecx, ebx
				;}
				end_if_bubble1:
			;j++;
			mov eax, [j_bubble]
			inc eax
			mov [j_bubble], eax
			;}
			end_while_bubble1:
		;}
		loop for_bubble1
		
		;}
	ret
	
	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	end_prog:
		mov eax, 0
		leave
		ret

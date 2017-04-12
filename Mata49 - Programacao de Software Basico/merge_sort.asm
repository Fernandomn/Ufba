%include "asm_io.inc"

;______________________________________________________________________;
segment .data
	TAMVET dd 8
	prompt1 db "bubble"
	prompt2 db "merge"
;______________________________________________________________________;
segment .bss
	vetor1 resd 8
	mid_merge resd 1
	i_merge resd 1
	j_merge resd 1
	k_merge resd 8
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
	
	call merge_sort
	jmp end_prog
	
	merge_sort:
	;void merge(int vec[], int vecSize) {
		;int mid;
		;int i, j, k;
		;int* tmp;

		;tmp = (int*) malloc(vecSize * sizeof(int));
		;if (tmp == NULL) {
			;exit(1);
		;}
 
		;mid = vecSize / 2;
		
 
		;i = 0;
		;j = mid;
		;k = 0;
		;while (i < mid && j < vecSize) {
			;if (vec[i] < vec[j]) {
				;tmp[k] = vec[i++];
			;}
			;else {
				;tmp[k] = vec[j++];
			;}
			;++k;
		;}
 
  ;if (i == mid) {
    ;while (j < vecSize) {
      ;tmp[k++] = vec[j++];
    ;}
  ;}
  ;else {
    ;while (i < mid) {
      ;tmp[k++] = vec[i++];
 
    ;}
  ;}
 
  ;for (i = 0; i < vecSize; ++i) {
    ;vec[i] = tmp[i];
  ;}
 
  ;free(tmp);
;}
 
;void mergeSort(int vec[], int vecSize) {
  ;int mid;
 
  ;if (vecSize > 1) {
    ;mid = vecSize / 2;
    ;mergeSort(vec, mid);
    ;mergeSort(vec + mid, vecSize - mid);
    ;merge(vec, vecSize);
  ;}
}
	ret	
	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	end_prog:
		mov eax, 0
		leave
		ret

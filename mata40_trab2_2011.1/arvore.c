/*
UNIVERSIDADE FEDERAL DA BAHIA
INSTITUTO DE MATEMÁTICA
DEPARTAMENTO DE CIENCIA DA COMPUTAÇÃO
2º trabalho para obtenção de nota na disciplina MATA40 - Estrutura de
Dados e Algoritmos, ministrada pelo professor Flávio Assis, do aluno 
Fernando Medeiros do Nascimento (2009.2), no período 2011.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*Definição das "cores". Neste trabalho, o valor da cor é um inteiro, 0 
 para preto, e 1 para vermelho*/
#define RED 1
#define BLACK 0

//estrutura da arvore
typedef struct noArvore {
	int chave;
	int cor;
	struct noArvore *esq, *dir, *pai;
	}noArvore, *Arvore;

//lista de prototipos
void insercao (Arvore *a, Arvore *sentinela);
void corrigeRedBlack(Arvore *a, Arvore *novoNo, Arvore *sentinela);
void rotEsq(Arvore *a, Arvore *no, Arvore *sentinela);
void rotDir(Arvore *a, Arvore *no, Arvore *sentinela);
void consulta (Arvore *a, Arvore *sentinela);
_Bool nucleoConsulta (Arvore *a, int valor, Arvore *sentinela);
void listaOrdem (Arvore *a, Arvore *sentinela);
void imprimeOrdemCrescente(Arvore *a, Arvore *sentinela);
void imprimeOrdemDecrescente(Arvore *a, Arvore *sentinela);
void imprimeNivel (Arvore *a, Arvore *sentinela);
void achaNivel (Arvore *a, Arvore *sentinela, int *nivel, int *contador);
void imprimeArvore (Arvore *a, Arvore *sentinela);
void visitaNo (Arvore *a, Arvore *sentinela);

void insercao (Arvore *a, Arvore *sentinela){
	/*funcao para insercao de novos nós na arvore. O no e gerado e sua 
	 * chave é obtida dentro desta função. A insercao segue a insercao 
	 * de uma arvore binaria comum. Ao final, corrigeRedBlack mantera
	 * as propriedades de uma arvore red-black*/
	Arvore novoNo;
	Arvore y, x;
	
	if ((novoNo =(noArvore*) malloc (sizeof(noArvore)))){
		scanf("%d", &(novoNo->chave));
		getchar();
		if (!(nucleoConsulta(a, (novoNo->chave), sentinela))){
			//nucleo consulta retornará true se o no com a chave indicada
			//já existir
			y = *sentinela;
			x = *a;
			while ((x != *sentinela)){
				y = x;
				if (novoNo->chave < x->chave)
					x = x->esq;
				else if	(novoNo->chave > x->chave)
					x = x->dir;
			}
			novoNo->pai = y;
			if (y == *sentinela)
				*a = novoNo;
			else if (novoNo->chave < y->chave)
					y->esq = novoNo;
				else
					y->dir = novoNo;
			novoNo->esq = *sentinela;
			novoNo->dir = *sentinela;
			novoNo->cor = RED;
			corrigeRedBlack(a, &novoNo, sentinela);
		}
	}else free(novoNo);
	//caso já exista o nó indicado, remove o que foi criado da memória
}

void corrigeRedBlack(Arvore *a, Arvore *novoNo, Arvore *sentinela){
	/*função que mantem as propriedades correta de uma red-black na 
	 * arvore. Funcoes de rotacao utilizadas serao descritas abaixo*/
	Arvore y, z = *novoNo;
	while((z->pai!=*sentinela)&&(z->pai->cor == RED)){
		if (z->pai == z->pai->pai->esq){
			y = z->pai->pai->dir;
			if (y->cor == RED){
				z->pai->cor = BLACK;
				y->cor = BLACK;
				z->pai->pai->cor = RED;
				z = z->pai->pai;
			}
			else{
				if (z == z->pai->dir){
					z = z->pai;
					rotEsq(a, &z, sentinela);
				}
				z->pai->cor = BLACK;
				z->pai->pai->cor = RED;
				rotDir(a, &(z->pai->pai), sentinela);
			}
		}
		else { //simetrico ao codigo acima
			y = z->pai->pai->esq;
			if (y->cor == RED){
				z->pai->cor = BLACK;
				y->cor = BLACK;
				z->pai->pai->cor = RED;
				z = z->pai->pai;
			}
			else{ 
				if (z == z->pai->esq){
					z = z->pai;
					rotDir(a, &z, sentinela);
				}
				z->pai->cor = BLACK;
				z->pai->pai->cor = RED;
				rotEsq(a, &(z->pai->pai), sentinela);
			}
		}	
	}
	(*a)->cor = BLACK;//garantindo que a raiz seja sempre preta
}

void rotEsq(Arvore *a, Arvore *no, Arvore *sentinela){
	/*Funcao que faz a rotacao de nos para a esquerda, sem que percam 
	 * suas sub-arvores*/
	Arvore y, x = (*no);
	
	y = x->dir;
	x->dir = y->esq;
	if ((y->esq->pai))
		y->esq->pai = x;
	y->pai = x->pai;
	if (x->pai == *sentinela)
		*a = y;
	else if (x == x->pai->esq)
			x->pai->esq = y;
		else
			x->pai->dir = y;
	y->esq = x;
	x->pai = y;		
	}
	
void rotDir(Arvore *a, Arvore *no, Arvore *sentinela){
	/*De forma simetrica a anterior, rotaciona os nos para a direita,
	 * sem que percam suas sub-arvores*/
	Arvore y, x = (*no);
	
	y = x->esq;
	x->esq = y->dir;
	if ((y->dir->pai))
		y->dir->pai = x;
	y->pai = x->pai;
	if (x->pai == *sentinela)
		*a = y;
	else if (x == x->pai->dir)
			x->pai->dir = y;
		else
			x->pai->esq = y;
	y->dir = x;
	x->pai = y;		
}

void consulta (Arvore *a, Arvore *sentinela){
	/*Funcao geral de consulta, que recebe o valor da entrada e gera a 
	 * saida da forma adequada. nucleoConsulta eh quem faz o trabalho 
	 * 'pesado'*/
	int valor;
	
	scanf ("%d", &valor);
	getchar();
	
	if (nucleoConsulta (a, valor, sentinela))
			printf("existe no com chave: %d\n", valor);
		else
			printf("nao existe no com chave: %d\n", valor);
		
}

_Bool nucleoConsulta (Arvore *a, int valor, Arvore *sentinela){
	/*Funcao booleana que faz a busca na arovre de maneira iterativa 
	 * (sem recursao) e retorna TRUE se o no indicado for encontrado, 
	 * e FALSE se o oposto ocorrer*/
	Arvore p = *a;
	while ((p)&&(p!=*sentinela)&&(valor != p->chave)){
		if (valor < p->chave)
			p = p->esq;
		else	
			p = p->dir;
		}
	if ((p)&&(p!=*sentinela))
		return true;
	return false;	
	}

void listaOrdem (Arvore *a, Arvore *sentinela){
	/*Funcao geral para a impressao de todos os nos. Chama as funcoes 
	 * imprimeOrdemCrescente ou imprimieOrdemDecrescente de acordo com o
	 *  valor inputado pelo usuario em 'direcao'*/
	char direcao;
	
	scanf("%c", &direcao);
	getchar();
	switch(direcao){
		case 'c':
			imprimeOrdemCrescente(a, sentinela);
			break;
		case 'd':
			imprimeOrdemDecrescente(a, sentinela);
			break;
		}
	}

void imprimeOrdemCrescente(Arvore *a, Arvore *sentinela){
	/*Funcao em ordem recursiva, que imprime todos os nos da arvore em 
	 * ordem crescente*/
	if((*a)!=(*sentinela)){
		imprimeOrdemCrescente(&((*a)->esq), sentinela);
		printf("%d\n", (*a)->chave);
		imprimeOrdemCrescente(&((*a)->dir), sentinela);
		}
	}
	
void imprimeOrdemDecrescente(Arvore *a, Arvore *sentinela){
	/*Simetrica aa anterior, imprime todos os nos da arvore em ordem 
	 * decrescente*/
	if((*a)!=(*sentinela)){
		imprimeOrdemDecrescente(&((*a)->dir), sentinela);
		printf("%d\n", (*a)->chave);
		imprimeOrdemDecrescente(&((*a)->esq), sentinela);
		}
	}

void imprimeNivel (Arvore *a, Arvore *sentinela){
	/*Funcao principal para imprimir um nivel da arvore. Seu nucleo é 
	 * 'achaNivel'*/
	int nivel, i = 0;
	
	scanf("%d", &nivel);
	getchar();
	achaNivel(a, sentinela, &nivel, &i);
	}

void achaNivel (Arvore *a, Arvore *sentinela, int *nivel, int *contador){
	/*Funcao prefixa que imprime os nos de um determinado nivel da 
	 * arvore. No inicio de cada "visita", ela acrescenta 1 ao contador,
	 * apos as recursoes, ela decrementa 1. Isso garante que o contador 
	 * sempre possua o valor equivalente ao nivel do no da arvore*/
	int i = *contador;
	if ((*a)&&((*a)!=(*sentinela))){
		i++;
		if (i == *nivel)
			printf("%d\n", (*a)->chave);
		achaNivel(&((*a)->esq), sentinela, nivel, &i);
		achaNivel(&((*a)->dir), sentinela, nivel, &i);
		i--;
		}
	}
	
void imprimeArvore (Arvore *a, Arvore *sentinela){
	/*Funcao de percurso em ordem simples. Chama a funcao 'visitaNo'
	 * (que tem esse nome por pura falta de criatividade), que fará 
	 * todas as impressoes em tela pedidas pela especificacao*/
	if((*a)&&((*a)!=(*sentinela))){
		imprimeArvore(&((*a)->esq), sentinela);
		visitaNo(a, sentinela);	
		imprimeArvore(&((*a)->dir), sentinela);
		}
	}	
	
void visitaNo (Arvore *a, Arvore *sentinela){
	/*Funcao que imprime as informacoes referentes aa cada no de acordo 
	 * com a especificacao*/
	
	//imprime a chave
	printf("chave: %d ", (*a)->chave);
	//imprime a cor
	if ((*a)->cor == RED)
		printf("cor: vermelho ");
	else
		printf("cor: preto ");
	//imprime a chave a esquerda
	if (((*a)->esq)&&((*a)->esq != *sentinela))
		printf("fesq: %d ", (*a)->esq->chave);
	else 
		printf("fesq: nil ");
	//imprime a chave a direita
	if (((*a)->dir)&&((*a)->dir != *sentinela))
		printf("fdir: %d\n", (*a)->dir->chave);
	else 
		printf("fdir: nil\n");
	}

int main (){
	Arvore a, sentinela;
	char opcao = ' ';
	//a = NULL;
	sentinela = (noArvore*)malloc(sizeof(noArvore));
	sentinela->pai = NULL;
	sentinela->esq = NULL;
	sentinela->dir = NULL;
	sentinela->cor = BLACK;
	a = sentinela;
	
	while (opcao != 'e'){
		scanf("%c", &opcao);
		getchar();
		switch (opcao){
			case 'i':
				insercao(&a, &sentinela);
				break;
			case 'c':
				consulta (&a, &sentinela);
				break;
			case 'p':
				listaOrdem(&a, &sentinela);
				break;
			case 'n':
				imprimeNivel(&a, &sentinela);
				break;
			case 'd':
				imprimeArvore(&a, &sentinela);
				break;
			case 'e':
				break;
			}
		}
	
	return 0;
	}

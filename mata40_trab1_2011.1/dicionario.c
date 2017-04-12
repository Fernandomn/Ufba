//1º trabalho para obtenção de nota na disciplina MATA40 - Estrutura de
//Dados e Algoritmos, ministrada pelo professor Flávio Assis, do aluno 
//Fernando Medeiros do Nascimento (2009.2), no período 2011.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//#include "funcoes.h"

#define MAXPALAVRA 30
#define NTABHASH 11
#define MAXTRADUCAO 50

typedef struct NoIdiomaOriginal{ // estrutura para a lista geral de palavras da lingua original
	char palavra[MAXPALAVRA];
	char classe;
	struct NoIdiomaOriginal *prox;
	struct ListaTraducoes *trad;
	}NoIdiomaOriginal, *IdOriginal;
	
typedef struct ListaTraducoes{ //estrutura dos nós da lista de traduções
	char traducao[MAXTRADUCAO];
	struct ListaTraducoes *prox;
	}ListaTraducoes, *Traducoes;
	
typedef struct ListaClasse{ // nós das listas de classes
	struct NoIdiomaOriginal *chave;
	struct ListaClasse *prox, *ant;
	}ListaClasse, *LClasse;

//lista de protótipos
int hash (char *p);
int ordc (char letra);
void inicializa (IdOriginal *l);
void insercao (IdOriginal *vetor, LClasse *lSubs, LClasse *lAdj, LClasse *lVerb, LClasse *lGeral);
void insereVetor (IdOriginal * vetor, IdOriginal *p);
void insereTraducoes (IdOriginal *p);
void insereListaClasse (LClasse *lSubs, LClasse *lAdj, LClasse *lVerb, IdOriginal *no);
void insereListaGeral (LClasse *lGeral, IdOriginal *no);
void descobrePosicao (LClasse * lista, LClasse * posicao, LClasse *noLista);
void insereListaSecundaria (LClasse * lista, LClasse * posicao, LClasse * noLista);
void ListaIdiomaOrigem (LClasse *lgeral);
void ListaOrdemAlfabetica (LClasse *lGeral);
void ImprimeOrdemCrescente (LClasse * lGeral, char *letra1, char *letra2);
void ImprimeOrdemDecrescente (LClasse * lGeral, char *letra1, char *letra2);
void achaPosicaoLista (LClasse *lista, char *letra, LClasse *pos);
void listaTraducoes (IdOriginal *vetor);
void convertePraMinuscula (char *palavraAConverter, char *convertida);
void achaPalavra (IdOriginal *lista, IdOriginal *noPalavra, char *palavra);
void achaUltimoElemento(LClasse *lGeral, LClasse *ultimo);
void ListaPalavrasClasse (LClasse *lSubs, LClasse *LAdj, LClasse *lVerb);
void ListaIndice(LClasse *lGeral);
void ConsultaClasse (IdOriginal *vetor);
void Remocao (IdOriginal *vetor, LClasse *lsubs, LClasse *ladj, LClasse *lverb, LClasse *lgeral);
void excluiTraducoes (IdOriginal *no);
void removeListaClasse(LClasse *lista, IdOriginal *no);
void descobrePosicaoSecundaria(LClasse *lista, IdOriginal *noAExcluir, LClasse *noExcClasse);
void removeListaSecundaria(LClasse *lista, LClasse *noExcClasse);
void achaPosicaoListaDec(LClasse *lista, char *letra, LClasse *pos);



int hash (char *p){ 
	// função hash, que retorna o indice do vetor/cabeçalho da lista a ser inserida a nova palavra do idioma original
	int i, m = strlen(p); //i é o inicio do somatório e contador; m é o limite superior do somatório. strlen é a função queretorna o tamanho de uma string
	int soma = 0; //soma dos valores de cada caracter
		
	for (i=0; i < m; i++){
		soma = soma + ordc(p[i]); //ordc é a função que informa o "valor" de cada caractere de acordo com a especificação. 
		}
	
	return soma % NTABHASH; //de acordo com a especificação, (somatorio de i até m de ordc) mod NTABHASH indica o indice do vetor, e é o retorno desta função
	}
	
int ordc (char letra){
	int posicao = 0; //valor retornado pela função
	
	/*Retorna o valor dos caracteres da palavra de acordo com sua posi
	 * ção no alfabeto, baseado na tabela ASCII*/
	
	if (((int)letra >= 'a')&&((int)letra <= 'z'))
		posicao = (int)letra - 96;
	else if (((int)letra >= 'A')&&((int)letra <= 'Z'))
		posicao = (int)letra - 64;
	else if (((int)letra >= '0')&&((int)letra <='9'))
		posicao = atoi(&letra);
	
	return posicao;
	}

void inicializa (IdOriginal *l){ //funcao de inicialização de listas
	*l = NULL;
	}

void insercao (IdOriginal *vetor, LClasse *lSubs, LClasse *lAdj, LClasse *lVerb, LClasse *lGeral){
	/*função usada para a criação de um novo nó de palavra original, que 
	vai receber uma lista de traduções, e vai ser inserida numa das 
	listas do vetor original, e vai ser ligada por uma das 3 listas de 
	classes, e pela lista geral.*/
	IdOriginal p; //p e o novo elemento da lista
	int i, numTraducoes;
	// numero de traduções (nós da lista de traduções) da palavra alocada em p
	
	if ((p = (NoIdiomaOriginal*) malloc (sizeof(NoIdiomaOriginal)))){ //criação do nó p, e teste para ver se ele existe
		p->trad = NULL;//inicializando a lista de traducoes
		/*pega a palavra, a classe, e o numero de traducoes, imputa as 
		 * 2 primeiras no novo nó, e o numero de traduções vai ser
		 * utilizada na insercao de traducoes*/
		scanf("%s", p->palavra);
		getchar();
		scanf("%c", &p->classe);
		getchar();
		scanf("%d", &numTraducoes);
		getchar();
		
		for (i = 0; i < numTraducoes; i++){
			insereTraducoes (&p);
		}	
		//inserção da nova palavra numa das listas do vetor. hash vai 
		//ser usada la dentro.
		insereVetor (vetor, &p);
		
		//inserção da palavra em uma das 3 listas de classe. qual das 3 é decidido la dentro
		insereListaClasse (lSubs, lAdj, lVerb, &p);
		
		//arrumação da palavra na lista geral
		insereListaGeral (lGeral, &p);
		
		}
	}
	
void insereVetor (IdOriginal * vetor, IdOriginal *p){
	int indice;
	
	indice = hash ((*p)->palavra);//descobrindo o indice do vetor
	
	if (*p){//conferencia por precaução. desnecessario
		//lembrando que vetor[indice] é o inicio de uma lista, não importa qual indice
		(*p)->prox = *(vetor+indice);
		*(vetor+indice) = (*p);
		//insereTraducoes (p, numTraducoes);//inserindo as traduções da palavra, uma lista que tem como inicio p->trad
		}
	}

void insereTraducoes (IdOriginal *p){ 
	//criação da lista de traduções de uma palavra, e a alocação de mais traduções
	 //int i, maxTraducoes = *numTraducoes;//pra facilitar a vida
	Traducoes novatraducao;
	
	if (*p){
		if ((novatraducao = (ListaTraducoes*)malloc(sizeof(ListaTraducoes)))){
			gets (novatraducao->traducao);
			novatraducao->prox = (*p)->trad;
			(*p)->trad = novatraducao;
			}
		}
	}

void insereListaClasse (LClasse *lSubs, LClasse *lAdj, LClasse *lVerb, IdOriginal *no){
	/*função que verifica qual classe cada nó pertence, e o insere numa 
	 * lista apropriada, já em ordem alfabética*/
	LClasse posicao; 
	/*ponteiro novo que descobre uma posição apropriada 
	na lista correta, para que seja inserido o nó*/
	LClasse noLista;
	IdOriginal noPalavra;

	noPalavra = *no; 
	// só pra ficar mais fácil pra trabalhar, é o nó da lista original
	if ((noLista = (ListaClasse*)malloc(sizeof(ListaClasse)))){ 
		/*criação de um novo nó, independente de qual das 3 listas ele 
		 * vai fazer parte, que aponta pra uma das palavras do idioma 
		 * original (no caso, *p)*/
		noLista->chave = noPalavra;
		noLista->prox = NULL;
		noLista->ant = NULL;
		switch (noLista->chave->classe){
			case 's': //se a classe for substantivo
				descobrePosicao(lSubs, &posicao, &noLista); 
				/*Função que descobre a posição apropriada para um nó em
				 * determinada lista. ao final, posicao será o nó da 
				 * lista anterior à posiçãbto correta de *p*/
				insereListaSecundaria(lSubs, &posicao, &noLista);
				// Função que, finalmente, insere o nó na lista correta
				break;
			case 'a':
				descobrePosicao(lAdj, &posicao, &noLista);
				insereListaSecundaria(lAdj, &posicao, &noLista);
				break;
			case 'v':
				descobrePosicao(lVerb, &posicao, &noLista);
				insereListaSecundaria(lVerb, &posicao, &noLista);
				break;
		}
	}
}

void insereListaGeral (LClasse *lGeral, IdOriginal *no){
	//copia descarada da função de inserção nas listas de classe
	LClasse posicao;
	LClasse noLista;
	IdOriginal noPalavra;
	
	noPalavra = *no; 

	if ((noLista = (ListaClasse*)malloc(sizeof(ListaClasse)))){
		noLista->chave = noPalavra;
		descobrePosicao(lGeral, &posicao, &noLista);
		insereListaSecundaria(lGeral, &posicao, &noLista);
		}
	
	}

void descobrePosicao (LClasse *lista, LClasse *posicao, LClasse *noLista){ 
	// conferir, acho que tá incompleta. retorna a posição do nó anterior à posição desejada
	LClasse p, q = *noLista, r;
	
	for (p = *lista, r = NULL; (p)&&(strcmp(p->chave->palavra, q->chave->palavra) < 0); r = p, p = p->prox);
	*posicao = r;
	}

void insereListaSecundaria (LClasse * lista, LClasse * posicao, LClasse * noLista){
	//função que recebe a lista de classe (não importa qual das 3 classes),
	//o nó que indique a posição correta, e o novo nó a ser inserido na lista
	if (*posicao != NULL){//colocando o nó da lista secundaria 
		(*noLista)->ant = (*posicao);
		(*noLista)->prox = (*posicao)->prox;//O ERRO ESTA AQUI
		if ((*posicao)->prox)
			(*posicao)->prox->ant = (*noLista);
		(*posicao)->prox = (*noLista);
	}
	else{
		(*noLista)->prox = *lista;
		*lista = (*noLista);
	}
}

void ListaIdiomaOrigem (LClasse *lgeral){
	char direcao;
	
	scanf ("%c", &direcao);
	getchar();
	
	switch (direcao){
		case 'c':
			ImprimeOrdemCrescente (lgeral, NULL, NULL);
			break;
		case 'd':
			ImprimeOrdemDecrescente (lgeral, NULL, NULL);
			break;
		}
	}

void ListaOrdemAlfabetica (LClasse *lGeral){
	char direcao, letra1, letra2;
	
	scanf("%c", &direcao);
	getchar();
	scanf("%c", &letra1);
	getchar();
	scanf("%c", &letra2);
	getchar();
	
	switch (direcao){
		case 'c':
			ImprimeOrdemCrescente (lGeral, &letra1, &letra2);
			break;
		case 'd':
			ImprimeOrdemDecrescente(lGeral, &letra1, &letra2);
			break;
		}
	}

void ImprimeOrdemCrescente (LClasse * lista, char *letra1, char *letra2){
	LClasse pos1, p;
	/*função que acha o primeiro nó que possua chave com a 'letra1' como
	 * letra inicial, dentro de 'lGeral', e retorna isso por 'pos'*/
	if((letra1)&&(letra2)){
		achaPosicaoLista (lista, letra1, &pos1);
		if (pos1){
			for (p = pos1; (p)&&((p->chave->palavra[0]) <= *letra2); p=p->prox){
				if (p)
					printf ("%s\n", p->chave->palavra);
				}
			}

		}	
	else{
		for (p = *lista; (p); p=p->prox){
			if (p)
				printf ("%s\n", p->chave->palavra);
		}
	}	
}

void ImprimeOrdemDecrescente (LClasse * lista, char *letra1, char *letra2){
	LClasse pos1, p, ultimo;
	/*função que acha o primeiro nó que possua chave com a 'letra1' como
	 * letra inicial, dentro de 'lGeral', e retorna isso por 'pos'*/
	if((letra1)&&(letra2)){
		achaPosicaoListaDec (lista, letra1, &pos1);
		if (pos1){
				for (p = pos1; (p)&&((p->chave->palavra[0]) >= *letra2); p=p->ant){
					if (p)
						printf ("%s\n", p->chave->palavra);
				}
		}
	}	
	else{
		achaUltimoElemento(lista, &ultimo);// devolve a ultima posição de uma lista
		if (ultimo){
			for (p = ultimo; (p); p=p->ant){
				if (p)
					printf ("%s\n", p->chave->palavra);
			}
		}		
	}	
}
	
void achaPosicaoLista (LClasse *lista, char *letra, LClasse *pos){
	LClasse p;
	for (p = *lista; (p)&&((p->chave->palavra[0]) < (*letra)); p = p->prox);
	if (p)

			*pos = p;
}

void achaPosicaoListaDec(LClasse *lista, char *letra, LClasse *pos){
	LClasse p;
	for (p = *lista; (p)&&(p->prox)&&((p->chave->palavra[0]) <= (*letra)); p = p->prox);
	if (p) {
		if (p->chave->palavra[0] > *letra)
			*pos = p->ant;
		else
			*pos = p;
	}
}
	
void achaUltimoElemento(LClasse *lGeral, LClasse *ultimo){
	LClasse p, q;
	for (p = *lGeral, q = NULL; (p); q = p, p = p->prox);
	if (q)
		*ultimo = q;
	}
	
void listaTraducoes (IdOriginal *vetor){
	char palavra[MAXPALAVRA]; //tradMinuscula[MAXTRADUCAO];
	IdOriginal noPalavra;
	Traducoes p;
	
	gets(palavra);
	//getchar();
	achaPalavra((vetor+(hash(palavra))), &noPalavra, palavra);
	if (noPalavra){
		for (p = noPalavra->trad; (p); (p = p->prox)){
			if (p){
				//convertePraMinuscula(p->traducao, tradMinuscula);
				printf("%s\n", p->traducao);
				}
			}
		}
	}
	
void convertePraMinuscula (char *palavraAConverter, char *convertida){
	int i;
	for (i = 0; i < strlen(palavraAConverter); i++){
		convertida[i] = tolower(palavraAConverter[i]);
		}
	}	

void achaPalavra (IdOriginal *lista, IdOriginal *noPalavra, char *palavra){
	//retorna o nó compativel com a palavra
	IdOriginal p;
	//for (p = *lista; (p)&&(strcmp(p->palavra, palavra)!=0); p=p->prox);
	p = *lista;
	 while ((p) && (strcmp(p->palavra,palavra) != 0)) {
               if (p->prox) {
                       p = p->prox;
               }
               else {
                       break;
               }

       }
	if (p)
		*noPalavra = p;
	else 	
		*noPalavra = NULL;	
	}

void ListaPalavrasClasse (LClasse *lSubs, LClasse *lAdj, LClasse *lVerb){
	char classe, direcao, letra1, letra2;
	
	scanf("%c", &classe);
	getchar();
	scanf("%c", &direcao);
	getchar();
	scanf("%c", &letra1);
	getchar();
	scanf("%c", &letra2);
	getchar();
	
	switch (classe){
		case 'a':
			if (direcao == 'c')
				ImprimeOrdemCrescente(lAdj, &letra1, &letra2);
			else if (direcao == 'd')
				ImprimeOrdemDecrescente(lAdj, &letra1, &letra2);
			break;
		case 's':
			if (direcao == 'c')
				ImprimeOrdemCrescente(lSubs, &letra1, &letra2);
			else if (direcao == 'd')
				ImprimeOrdemDecrescente(lSubs, &letra1, &letra2);
			break;
		case 'v':
			if (direcao == 'c')
				ImprimeOrdemCrescente(lVerb, &letra1, &letra2);
			else if (direcao == 'd')
				ImprimeOrdemDecrescente(lVerb, &letra1, &letra2);
			break;
		}
	}

void ListaIndice(LClasse *lGeral){
	LClasse p;
	int indice;
	
	scanf("%d", &indice);
	getchar();
	
	for (p = *lGeral; (p); p = p->prox){
		if (p){
			if (indice==hash((p->chave->palavra)))
				printf ("%s\n", p->chave->palavra);
			}
		}
	}

void ConsultaClasse (IdOriginal *vetor){
	
	char pEntrada[MAXPALAVRA];//palavra a ser consultada
	int indice;
	IdOriginal p;
	
	gets (pEntrada);
	indice = hash(pEntrada);
	achaPalavra((vetor+indice), &p, pEntrada);
	if (p){
		switch (p->classe){
			case 's': 
				printf ("substantivo\n"); 
				break;
			case 'a': 
				printf ("adjetivo\n"); 
				break;
			case 'v': 
				printf ("verbo\n"); 
				break;
			}
		}
	
	}

//remocao
void Remocao (IdOriginal *vetor, LClasse *lsubs, LClasse *ladj, LClasse *lverb, LClasse *lgeral){
	char palavraAExcluir[MAXPALAVRA];
	int indice;
	IdOriginal noAExcluir;
	
	scanf("%s", palavraAExcluir);
	getchar();
	indice = hash(palavraAExcluir);
	achaPalavra((vetor+indice), &noAExcluir, palavraAExcluir);
	if (noAExcluir){
		excluiTraducoes(&noAExcluir);//remove as traduções
		switch(noAExcluir->classe){//remove lista classe
			case 'a':
				removeListaClasse(ladj, &noAExcluir);
				break;
			case 's':
				removeListaClasse(lsubs, &noAExcluir);
				break;
			case 'v':
				removeListaClasse(lverb, &noAExcluir);
				break;
			}
		removeListaClasse(lgeral, &noAExcluir);//remove lista geral
		free(noAExcluir);//limpa a palavra de uma vez!!!
		}
	}
	
void excluiTraducoes (IdOriginal *no){
	Traducoes p;
	
	if (no){
		for (p = (*no)->trad;(p); p = (*no)->trad){
			if (p){
				(*no)->trad = p->prox;
				free(p);
				}
			}
		}
	}	

void removeListaClasse(LClasse *lista, IdOriginal *no){
	LClasse noExcClasse;
	
	descobrePosicaoSecundaria(lista, no, &noExcClasse);
	removeListaSecundaria(lista, &noExcClasse);
	}
	
void descobrePosicaoSecundaria(LClasse *lista, IdOriginal *noAExcluir, LClasse *noExcClasse){
	LClasse p;
	
	for (p = *lista; (p)&&(strcmp(p->chave->palavra, (*noAExcluir)->palavra)!=0); p=p->prox);
	if (p)
		*noExcClasse = p;
	}	

void removeListaSecundaria(LClasse *lista, LClasse *noExcClasse){
	LClasse p;
	
	p = *noExcClasse;
	if (p){
		if (p->ant){
			p->ant->prox = p->prox;
			if (p->prox)
				p->prox->ant = p->ant;
		}else{
			*lista = p->prox;
			if (p->prox)
				p->prox->ant = NULL;
		}
		free (p);
		}
	}

int main (){
	IdOriginal vetor[NTABHASH];//vetor de listas, chave do dicionário, que contem as listas de palavras na lingua original. Tem tamanho NTABHASH, como pedido na especificação
	LClasse lSubs = NULL, lAdj = NULL, lVerb = NULL, lGeral = NULL;//listas secundarias: listas de substantivos, adjetivos, verbos, e lista geral (que contem todas as palavras). todas devem ficar em ordem alfabética
	int i, numTraducoes;// contador, e numero de traduções primeira linha inserida pelo usuário
	char opcao = 'z';//primeiro caractere das entradas, dps da fase de inserção
	
	for (i = 0; i < NTABHASH; i++){ //inicialização de todos os indices do vetor de listas
		inicializa (&vetor[i]);
	}
	
	//fase de insercao
	scanf("%d", &numTraducoes);//primeiro numero obtido do usuário, que indica a quantidade de pal
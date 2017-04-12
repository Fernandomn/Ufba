#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

enum boolean {
    true = 1, false = 0
};
// Permitindo a sua declara??o como um tipo qualquer:
typedef  enum boolean  bool;

typedef struct  pilha
{
    //uma pilha s? precisa de um apontador, que ? o do proximo elemento
    struct pilha *prox;
    char chave;
}pilha;


void desempilha(pilha **p);
void empilha (pilha **p, char valor);
bool automato1(char *fitaEntrada);
bool automato2(char *fitaEntrada);

void desempilha(pilha **p)
{
    pilha * q;
    
    if (p != NULL){
		if ((*p)->prox)
		{
			q = *p;
	        *p = q->prox;
	        free(q);
        }
        else
        {
			q = *p;
			free(q);
			p = NULL;
		}
    }
}

void empilha (pilha **p, char valor)
{
    pilha *q;
    q = (pilha*)malloc(sizeof(pilha));
    q->chave = valor;
    q->prox = *p;
    *p=q;
}

bool automato1(char *fitaEntrada)
{
	int cabecote = 0;
	pilha *p = NULL;
    p = (pilha*)malloc(sizeof(pilha));
    p->prox = NULL;
    p->chave = 'Z';
    
	if (fitaEntrada[cabecote] == 'a') //q0
	{
		desempilha(&p);
		empilha(&p, 'Z');
		empilha(&p, 'C');
		empilha(&p, 'C');
		cabecote ++;
		while((fitaEntrada[cabecote] == 'a')&&(p)&&((p)->chave == 'C')) //q1
		{
			desempilha(&p);
			empilha(&p, 'C');
			empilha(&p, 'C');
			empilha(&p, 'C');
			cabecote ++;
		}
		if ((fitaEntrada[cabecote] == 'c')&&(p)&&((p)->chave == 'C')) //q3
		{
			desempilha(&p);
			cabecote++;
			while((fitaEntrada[cabecote] == 'c')&&(p)&&((p)->chave == 'C')) //q3
			{
				desempilha(&p);
				cabecote ++;
			}
			if ((fitaEntrada[cabecote] =='\0')&&(p)&&((p)->chave == 'Z'))//q4
			{
				return true;
			}
		}
	}
	return false;
}

bool automato2(char *fitaEntrada)
{
	int cabecote = 0;
	pilha *p = NULL;
    p = (pilha*)malloc(sizeof(pilha));
    p->prox = NULL;
    p->chave = 'Z';
	
	if (fitaEntrada[cabecote] == 'a') //q0
	{
		desempilha(&p);
		empilha(&p, 'Z');
		empilha(&p, 'C');
		cabecote ++;
		while((fitaEntrada[cabecote] == 'a')&&(p)&&((p)->chave == 'C')) //q2
		{
			desempilha(&p);
			empilha(&p, 'C');
			empilha(&p, 'C');
			cabecote ++;
		}
		if ((fitaEntrada[cabecote] == 'c')&&(p)&&((p)->chave == 'C')) //q3
		{
			desempilha(&p);
			cabecote++;
			while((fitaEntrada[cabecote] == 'c')&&(p)&&((p)->chave == 'C')) //q3
			{
				desempilha(&p);
				cabecote ++;
			}
			if ((fitaEntrada[cabecote] =='\0')&&(p)&&((p)->chave == 'Z')) //q4
			{
				return true;
			}
		}
	}
	return false;
}

int main ()
{
	char opc = 't'; //opcao, caso o usuario deseje inserir novas entradas
	char fitaDeEntrada[500];
	
	while (opc != 'n')
	{
		fitaDeEntrada[0] = '\0';
		printf("Por favor, insira a cadeia que deseja processar: \n");
		scanf("%s", fitaDeEntrada);
		getchar();
		
		if ((automato1(fitaDeEntrada) == false)&&(automato2(fitaDeEntrada) == false))
		{
			printf("A cadeia nao pertence a linguagem.\n");
		}
		else
		{
			printf("A cadeia pertence a linguagem.\n");
		}
		printf("Deseja verificar outra fita de entrada?(s/n)\n");
		scanf("%c", &opc);
	}
	
	return 0;
}

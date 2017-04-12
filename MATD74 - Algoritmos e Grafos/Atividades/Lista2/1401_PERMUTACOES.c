#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 10

void quick(char vet[], int esq, int dir){
  int pivo = esq, i,j;
  char ch;
  for(i=esq+1;i<=dir;i++){
    j = i;
    if((int)vet[j] < (int)vet[pivo]){
      ch = vet[j];
      while(j > pivo){
        vet[j] = vet[j-1];
        j--;
      }
      vet[j] = ch;
      pivo++;
    }
  }
  if(pivo-1 >= esq){
    quick(vet,esq,pivo-1);
  }
  if(pivo+1 <= dir){
    quick(vet,pivo+1,dir);
  }
}

void permutacoes(char * letras, char * permutacao)
{
  int tamEntrada;
  if((tamEntrada = strlen(letras)) > 0)
  {
    int i, j;
    int tamPermutacao = strlen(permutacao);
    char letraAtual[1] = "";
    char letrasRestantes[tamEntrada - 1], permutacaoAtual[tamPermutacao + 1];

    for(i = 0; i < tamEntrada; i++)
    {
      if(letras[i] != letraAtual[0])
      {
        strcpy(permutacaoAtual, permutacao);
        letraAtual[0] = letras[i];
        for (j = 0; j < i; j++){
          letrasRestantes[j] = letras[j];
        }
        for(j = i+1; j < tamEntrada; j++){
          letrasRestantes[j-1] = letras[j];
        }
        // permutacaoAtual[tamPermutacao] = letraAtual;
        strcat(permutacaoAtual, letraAtual);

        // printf("letrasRestantes: %s permutacaoAtual: %s\n", letrasRestantes, permutacaoAtual);
        // printf("letras: %s letrasRestantes: %s permutacaoOriginal %s permutacaoAtual %s\n", letras, letrasRestantes, permutacao, permutacaoAtual);
        permutacoes(letrasRestantes, permutacaoAtual);
        strcat(permutacaoAtual, "");
      }
    }
  }
  else
  {
    printf("%s\n", permutacao);
  }
}

int main ()
{
  char buffer[TAM], permutacao[1];
  int numEntradas, tamVetor;
  int i;
  scanf("%d", &numEntradas);
  for (i = 0; i < numEntradas; i++)
  {
    scanf("%s", buffer);
    getchar();
    tamVetor = strlen(buffer);
    char letras[tamVetor];
    strcpy(letras, buffer);
    strcpy(permutacao,"");
    
    quick(letras, 0, tamVetor-1);
    permutacoes(letras, permutacao);
    printf("\n");
  }
  return 0;
}

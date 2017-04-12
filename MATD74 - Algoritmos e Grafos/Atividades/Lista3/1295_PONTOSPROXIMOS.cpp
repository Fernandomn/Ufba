#include <bits/stdc++.h>
using namespace std;

#define MAX_DISTANCIA 40000
#define FOR(n) for(i=0; i < n; i++)

int tamanhoVetorEntrada = 0;
int i;
void merge (double vetorPontos[][2], int inicio, int final)
{
	if (inicio < final)
	{
		int meio = floor((inicio+final)/2);
		merge(vetorPontos, inicio, meio);
		merge(vetorPontos, meio+1, final);

		int i = 0, j = inicio, k = meio+1;
		double vetorTemp[final-inicio+1][2];

		while(j < meio+1 || k < final+1){
			if(j == meio+1){
				vetorTemp[i][0] = vetorPontos[k][0];
				vetorTemp[i][1] = vetorPontos[k][1];
				k++;
			}else if (k == final+1){
				vetorTemp[i][0] = vetorPontos[j][0];
				vetorTemp[i][1] = vetorPontos[j][1];
				j++;
			}
			else if(vetorPontos[j][0] < vetorPontos[k][0]){
				vetorTemp[i][0] = vetorPontos[j][0];
				vetorTemp[i][1] = vetorPontos[j][1];
				j++;
			}
			else{
				vetorTemp[i][0] = vetorPontos[k][0];
				vetorTemp[i][1] = vetorPontos[k][1];
				k++;
			}
			i++;
		}
		for(i = inicio; i <= final; i++){
			vetorPontos[i][0] = vetorTemp[i-inicio][0];
			vetorPontos[i][1] = vetorTemp[i-inicio][1];
		}
	}
}

void mergeInd (double vetorY[], int inicio, int final, int vetorNum[])
{
	if (inicio < final)
	{
		int meio = floor((inicio+final)/2);
		mergeInd(vetorY, inicio, meio, vetorNum);
		mergeInd(vetorY, meio+1, final, vetorNum);

		int i = 0, j = inicio, k = meio+1;
		double vetorTemp[final-inicio+1];
		int vetorPontosTemp[final-inicio+1];

		while(j < meio+1 || k < final+1){
			if(j == meio+1){
				vetorTemp[i] = vetorY[k];
				vetorPontosTemp[i] = vetorNum[k];
				k++;
			}else if (k == final+1){
				vetorTemp[i] = vetorY[j];
				vetorPontosTemp[i] = vetorNum[j];
				j++;
			}
			else if(vetorY[j] < vetorY[k]){
				vetorTemp[i] = vetorY[j];
				vetorPontosTemp[i] = vetorNum[j];
				j++;
			}
			else{
				vetorTemp[i] = vetorY[k];
				vetorPontosTemp[i] = vetorNum[k];
				k++;
			}
			i++;
		}
		for(i = inicio; i <= final; i++){
			vetorY[i] = vetorTemp[i-inicio];
			vetorNum[i] = vetorPontosTemp[i-inicio];
		}
	}
}

void candidatos(double vetorPontos[][2], int vetorNum[], int candidatos[], int inicio, int final, double distancia)
{
	int meio = floor((inicio+final)/2);
	int i, j = 0;
	for (i = inicio; i <= final; i++) {
		if((vetorPontos[vetorNum[i]][0] - vetorPontos[meio][0]) < distancia){
			candidatos[j] = vetorNum[i];
			j++;
		}
	}
	candidatos[j] = -1;
}

double combine (double vetorPontos[][2], int vetorNum[], int inicio, int final, double distEsq, double distDir)
{
	double menorDistancia = (distEsq < distDir) ? distEsq: distDir;
	double difX, difY, distancia;
	int i, j;
	int vetCandidatos[final+2];

	candidatos(vetorPontos, vetorNum, vetCandidatos, inicio, final, menorDistancia);
	for(i = 0; i <= final && vetCandidatos[i]!= -1; i++){
		j=i+1;
		while (vetCandidatos[j]!=-1 &&
			vetorPontos[vetCandidatos[j]][1] - vetorPontos[vetCandidatos[i]][1] < menorDistancia)
		{
			difX = vetorPontos[vetCandidatos[i]][0] - vetorPontos[vetCandidatos[j]][0];
			difY = vetorPontos[vetCandidatos[i]][1] - vetorPontos[vetCandidatos[j]][1];
			distancia = sqrt(pow(difX, 2)+pow(difY,2));
			if (distancia < menorDistancia)
				menorDistancia = distancia;
			j++;
		}
	}
	return menorDistancia;
}

void divida(double vetorPontos[][2],  int vetorNum[], int divisao[], int inicio, int final)
{
	int meio = floor((inicio+final)/2);
	int i = inicio, j = meio+1, k;

	for (k = inicio; k <= final; k++){
		if(vetorNum[k]<= meio){
			divisao[i] = vetorNum[k];
			i++;
		}
		else{
			divisao[j] = vetorNum[k];
			j++;
		}
	}
}

double distanciaRec(double vetorPontos[][2],  int vetorNum[], int inicio, int final)
{
	if (final <= inicio+2)
	{
		double menorDistancia = MAX_DISTANCIA, distancia;
		int i, j;
		double difX, difY;
		for(i = inicio+1; i <= final; i++){
			for(j = inicio; j < i; j++){
				difX = vetorPontos[inicio][0] - vetorPontos[inicio+1][0];
				difY = vetorPontos[inicio][1] - vetorPontos[inicio+1][1];
				distancia = sqrt(pow(difX, 2)+pow(difY,2));
				if (distancia < menorDistancia)
					menorDistancia = distancia;
			}
		}
		return menorDistancia;
	}
	else
	{
		int meio = floor((inicio+final)/2);
		int divisao[final+1];
		divida(vetorPontos, vetorNum, divisao, inicio, final);
		double distEsq = distanciaRec(vetorPontos, divisao, inicio, meio);
		double distDir = distanciaRec(vetorPontos, divisao, meio+1, final);
		return combine(vetorPontos, vetorNum, inicio, final, distEsq, distDir);
	}
}

double distanciaSH(double vetorPontos[][2], int n)
{
	merge(vetorPontos, 0, n-1);
	int vetorNum[n];
	int i;
	double vetorY[n];
	for(i = 0; i < n; i++){
		vetorNum[i] = i;
		vetorY[i] = vetorPontos[i][1];
	}
	mergeInd(vetorY, 0, n-1, vetorNum);
	return distanciaRec(vetorPontos, vetorNum, 0, n-1);
}

int main(int argc, char const *argv[])
{
	int numPontos;
	int i;
	double menorDistancia;
	while((scanf("%d", &numPontos)) && (numPontos != 0))
	{
		tamanhoVetorEntrada = numPontos;
		double vetorPontos[numPontos][2];
		FOR(numPontos)
		{
			scanf("%lf%lf", &vetorPontos[i][0], &vetorPontos[i][1]);
		}
		menorDistancia = distanciaSH(vetorPontos, numPontos);
		if(menorDistancia < 10000)
			printf("%.4lf\n", menorDistancia);
		else
			printf("%s\n", "INFINITY");
	}
	return 0;
}

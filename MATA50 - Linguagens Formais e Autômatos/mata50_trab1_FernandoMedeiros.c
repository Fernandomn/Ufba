//UNIVERSIDADE FEDERAL DA BAHIA
//Disciplina: MATA50 - Ling. Formais e Automatos
//Prof: Debora Abdalla
//Aluno: Fernando Medeiros do Nascimento

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main ()
{
	char automato[5][2][2];
	//q0 lendo x
	automato[0][0][0] = '1';
	automato[0][0][1] = 'x';
	//q0 lendo -
	automato[0][1][0] = 'e';
	automato[0][1][1] = 'e';
	//q1 lendo x
	automato[1][0][0] = '2';
	automato[1][0][1] = 'x';
	//q1 lendo -
	automato[1][1][0] = '0';
	automato[1][1][1] = '#';
	//q2 lendo x
	automato[2][0][0] = '3';
	automato[2][0][1] = 'x';
	//q2 lendo -
	automato[2][1][0] = '0';
	automato[2][1][1] = '#';
	//q3 lendo x
	automato[3][0][0] = '4';
	automato[3][0][1] = 'y';
	//q3 lendo -
	automato[3][1][0] = '0';
	automato[3][1][1] = '#';
	//q4 lendo x
	automato[4][0][0] = '4';
	automato[4][0][1] = ' ';
	//q4 lendo -
	automato[4][1][0] = '0';
	automato[4][1][1] = '#';

	char opc = 't';
	char fitaEntrada[500];
	char fitaSaida[500];

	while (opc != 'n')
	{
		int estado, lido, erro;
		int cabecote = 0;
		fitaEntrada[0] = '\0';
		fitaSaida[0] = '\0';
		estado = 0;
		erro = 0;

		printf("Por favor, insira a cadeia que deseja processar\n");
		scanf("%s", fitaEntrada);
		getchar();
		while ((fitaEntrada[cabecote] != '\0')&&(estado != (char)'e'))
		{
			char charLido = fitaEntrada[cabecote];
			switch (charLido)
			{
			case 'x':
				lido = 0;
				break;
			case '-':
				lido = 1;
				break;
			default:
				erro = 1;
				break;
			}
			//printf("Estou no estado %d, lendo o caractere %c(%d), e jogando na saida %c\n", estado, charLido, lido, automato[estado][lido][1]);
			if ((automato[estado][lido][1] != 'e')&&(automato[estado][lido][1] != ' ')){
                char temp[2];
                temp[0] = automato[estado][lido][1];
                temp[1] = '\0';
                strcat(fitaSaida, temp);
			}
            //printf("Fita de Saida: %s\n", fitaSaida);

            int aux = atoi(&automato[estado][lido][0]);
            estado = aux;
			cabecote ++;
		}

		if ((erro == 0) && (estado != (char)'e') && (estado != 0))
		{
			//printf("O resultado do processamento da cadeia foi: \n");
			printf("%s\n", fitaSaida);
		}
		else
		{
			printf("A cadeia não pertence a linguagem\n");
		}
		printf("Deseja verificar outra fita de entrada?(s/n)\n");
		scanf("%c", &opc);
	}
	return 0;
}

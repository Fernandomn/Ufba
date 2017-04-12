#include <stdio.h>
#include <string.h>

#define MAX_CASO_TESTE 1000

int main()
{
  char casoTeste[MAX_CASO_TESTE];
  int i, j, k;
  int contador = 0, numEntradas = 0;

  scanf("%d", &numEntradas);

  for (k = 0; k < numEntradas; k++)
  {
    scanf("%s", casoTeste);
    getchar();
    for (i = 0; i < MAX_CASO_TESTE || casoTeste[i] != '\0'; i++)
    {
      if (casoTeste[i] == '>')
      {
        for (j = i-1; j >= 0; j--)
        {
          if (casoTeste[j] == '<')
          {
            contador++;
            casoTeste[i] = 'D';
            casoTeste[j] = 'D';
            break;
          }
        }
      }
    }
    printf("%d\n", contador);
    contador = 0;
  }
  return 0;
}

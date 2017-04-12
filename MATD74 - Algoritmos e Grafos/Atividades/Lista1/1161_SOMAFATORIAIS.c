#include <stdio.h>
#include <stdlib.h>

long long int fatorial (int numero);
int main ()
{
  int numero1, numero2;
  while (scanf("%d %d", &numero1, &numero2) > 0)
  {
    printf("%lld\n", fatorial(numero1) + fatorial(numero2));
  }
  return 0;
}

long long int fatorial (int numero)
{
  return (numero == 0 || numero == 1) ? 1 : numero * fatorial(numero - 1);
}

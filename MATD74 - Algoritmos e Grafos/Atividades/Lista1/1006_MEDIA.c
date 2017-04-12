#include <stdio.h>
#include <stdlib.h>

int main ()
{
  double nota1, nota2, nota3;
  scanf("%lf", &nota1);
  scanf("%lf", &nota2);
  scanf("%lf", &nota3);
  printf("MEDIA = %.1f\n", nota1*0.2 + nota2*0.3 + nota3*0.5);
  return 0;
}

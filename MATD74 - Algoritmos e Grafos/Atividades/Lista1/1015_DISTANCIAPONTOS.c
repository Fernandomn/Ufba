#include <stdio.h>
#include <math.h>

int main ()
{
  double ponto1[2], ponto2[2];
  scanf("%lf %lf", &ponto1[0], &ponto1[1]);
  scanf("%lf %lf", &ponto2[0], &ponto2[1]);
  double difX = ponto1[0]-ponto2[0];
  double difY = ponto1[1]-ponto2[1];
  double distancia = sqrt(pow(difX, 2.0) + pow(difY, 2.0));
  printf("%.4lf\n", distancia);
  return 0;
}

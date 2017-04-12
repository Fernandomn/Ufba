#include <stdio.h>
#include <math.h>

int main ()
{
  int ponto1[2], ponto2[2];
  while(scanf("%d %d %d %d", &ponto1[0], &ponto1[1], &ponto2[0], &ponto2[1]))
  {
    if(ponto1[0] == 0 && ponto1[1] == 0 && ponto2[0] == 0 && ponto2[1] == 0)
      break;
    if (ponto1[0] == ponto2[0] && ponto1[1] == ponto2[1])
    	printf("0\n");
    else if  (ponto1[0] == ponto2[0] ||
      ponto1[1] == ponto2[1] ||
      fabs(ponto2[0] - ponto1[0]) == fabs(ponto2[1] - ponto1[1]))
    	 printf("1\n");
    else
    	printf("2\n");
  }
  return 0;
}

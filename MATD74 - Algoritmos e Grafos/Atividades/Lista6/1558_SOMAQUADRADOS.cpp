#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i = 0; i < n; i++)

string Naive(int numFatorar)
{
  bool ehValido = false;
  int i;
  int num1 = numFatorar;//abs(numFatorar);
  for(i = 0; i <= num1 && i*i <= num1; i++)
  {
    int num2 = num1 - (i*i);
    double raizNum2 = sqrt(num2);
    if(raizNum2 - int(raizNum2) == 0)
      ehValido = true;
  }
  return ehValido ? "YES" : "NO";
}

int main(int argc, char const *argv[]) {
  int numFatorar;
  while(scanf("%d\n", &numFatorar) != EOF)
  {
    string resposta;
    resposta = Naive(numFatorar);
    std::cout << resposta << std::endl;
  }
  return 0;
}

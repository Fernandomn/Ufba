#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i < int(n); i++)

int  memoizedTroco (int n, int k, int cedulas[], int memo[][7])
{
  if (k == n)
    return 1;
  if (k > n)
    return 0;
  int valorAtual;
  int contador = 0;
  FOR(j, 7)
  {
    valorAtual = k + cedulas[j];
    if(valorAtual < n)
      memo[k][j] = valorAtual;
      if(memoizedTroco(n, valorAtual, cedulas, memo) > 0)
        contador ++;
    if(valorAtual ==n){
      memo[k][j] = valorAtual;
      contador++;
    }    
  }
  return contador;
}

int troco(int n, int cedulas[])
{
  int i, j, contador;
  int memo[n][7];
  FOR(i, n)
    FOR(j, 7)
      memo[i][j] = 0;
  int q = memoizedTroco(n, 0, cedulas, memo);
}

int main(int argc, char const *argv[]) {
  int cedulas[] = {1, 2, 5, 10, 20, 50, 100};
  int n;
  std::cin >> n;
  int numFormas = troco(n, cedulas);
  std::cout << numFormas << std::endl;
  return 0;
}

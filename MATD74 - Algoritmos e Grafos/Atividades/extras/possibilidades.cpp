#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i = 0; i < n; i++)
enum Categorias{
  NAO_VERIF = -1,
  NAO,
  SIM
};

int possibilidades_increment(int n)
{
  if (n < 1) {
    return 0;
  }
  int i, j;
  int numeros[] = {1, 3, 4};
  int memo[n+1];
  FOR(i, n+1)
    memo[i] = 0;
  memo[0] = 1; memo[1] = 1;

  for(i = 2; i <= n; i++)
  {
    FOR(j, 3)
    {
      if(i-numeros[j] >= 0)
        memo[i] += memo[i-numeros[j]];
    }
  }
  return memo[n];
}
int possibilidades_memo(int n, int memo[])
{
  if (n < 0)
    return 0;
  if (n == 0 || n == 1)
    return 1;
  if (memo[n] > 0)
    return memo[n];
  int possib = possibilidades_memo(n-1, memo) + possibilidades_memo(n-3, memo) + possibilidades_memo(n-4, memo);
  memo[n] = possib;
  return possib;
}
int possibilidades_recursiva(int n)
{
  if (n < 1)
    return 0;
  int i;
  int memo[n+1];
  FOR(i, n+1)
    memo[i] = 0;
  memo[0] = 1; memo[1] = 1;
  return possibilidades_memo(n, memo);
}


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::cout << possibilidades_increment(n) << std::endl;
  std::cout << possibilidades_recursiva(n) << std::endl;
  return 0;
}

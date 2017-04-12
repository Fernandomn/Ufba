#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i = 0; i < n; i++)

int main(int argc, char const *argv[]) {
  int numPalavras;
  int maiorPalavra = 0;
  std::vector<string> palavras;
  string novaPalavra;
  int i, j;
  int qntEspacos;
  bool primeiro = true;
  while(scanf("%d\n", &numPalavras) && numPalavras != 0)
  {
    if(!primeiro) std::cout << std::endl;
    primeiro = false;
    maiorPalavra = 0;
    FOR(i, numPalavras)
    {
      std::cin >> novaPalavra;
      palavras.push_back(novaPalavra);
      maiorPalavra = max(maiorPalavra, int(novaPalavra.size()));
    }
    FOR(i, palavras.size())
    {
      qntEspacos = maiorPalavra - palavras[i].size();
      FOR(j, qntEspacos)
        std::cout << " ";
      std::cout << palavras[i] << std::endl;
    }
    // std::cout << std::endl;
    palavras.clear();
  }
  return 0;
}

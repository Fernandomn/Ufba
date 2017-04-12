#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i = 0; i < n; i++)

std::vector<int> filtraColunas(std::vector<std::vector<int> > caixaDoces, int linhas, int colunas)
{
  int i,j;
  int filtroDeLinha[colunas+2];
  std::vector<int> resultLinhas;

  FOR(i, linhas){
    // FOR(j, colunas){
    filtroDeLinha[colunas+1] = 0;
    filtroDeLinha[colunas] = 0;
    for (j = colunas-1; j >= 0; j--)
    {
      filtroDeLinha[j] = max(caixaDoces[i][j] + filtroDeLinha[j+2],
                            filtroDeLinha[j+1]);
    }
    resultLinhas.push_back(filtroDeLinha[0]);
  }
  // FOR(i, resultLinhas.size())
  //   std::cout << resultLinhas[i] << " " ;
  // std::cout << std::endl;
  return resultLinhas;
}

long long int filtraLinhas(std::vector<int> linhas)
{
  int i = 1;
  // long long int escolha = 0;
  int tamLinhas = linhas.size();
  int resultLinhas[tamLinhas+2];
  resultLinhas[tamLinhas] = 0;
  resultLinhas[tamLinhas+1] = 0;
  for(i = tamLinhas-1; i >= 0; i--)
  {
    resultLinhas[i] = max(linhas[i] + resultLinhas[i+2], resultLinhas[i+1]);
  }
  return resultLinhas[0];
}

int main(int argc, char const *argv[]) {
  /* code */
  int linhas, colunas;
  int i, j;
  while (scanf("%d%d\n", &linhas, &colunas) && (linhas + colunas))
  {
    std::vector<std::vector<int> > caixaDoces;
    FOR(i, linhas){
      std::vector<int> linha;
      FOR(j, colunas){
        int doce;
        scanf("%d", &doce);
        linha.push_back(doce);
      }
      caixaDoces.push_back(linha);
    }
    // FOR(i, linhas)
    // {
    //   FOR(j, colunas)
    //   {
    //     std::cout << caixaDoces[i][j] << " ";
    //   }
    //   std::cout << std::endl;
    // }
    // int linhasEscolhidas[linhas];
    std::vector<int> escolhaLinhas = filtraColunas(caixaDoces, linhas, colunas);
    long long int somaDoces = filtraLinhas(escolhaLinhas);
    std::cout << somaDoces << std::endl;
  }

  return 0;
}

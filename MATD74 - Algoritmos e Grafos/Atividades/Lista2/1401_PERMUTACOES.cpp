#include <bits/stdc++.h>
using namespace std;

// #define TAM 10
// #define FOR(n) for(int i=0; i < int(n); i++)

void permutacoes(string letras, string permutacao)
{
  int tamEntrada;
  if((tamEntrada = letras.size()) > 0)
  {
    int i;
    char letraAtual = ' ';
    string letrasRestantes, permutacaoAtual;

    for(i = 0; i < tamEntrada; i++)
    {
      if(letras[i] != letraAtual)
      {
        permutacaoAtual = permutacao;
        letraAtual = letras[i];
        letrasRestantes = letras.substr(0,i) + letras.substr(i+1, tamEntrada-i+1);
        permutacaoAtual += letraAtual;
        permutacoes(letrasRestantes, permutacaoAtual);
        permutacaoAtual = "";
      }
    }
  }
  else
  {
    cout << permutacao << "\n";
  }
}

int main ()
{
  string letras, permutacao;
  int numEntradas, tamVetor;
  int i;
  cin >> numEntradas;
  for (i = 0; i < numEntradas; i++)
  {
    cin >> letras;
    permutacao = "";
    sort(letras.begin(), letras.end());
    permutacoes(letras, permutacao);
    // printf("\n");
    cout << "\n";
  }
  return 0;
}

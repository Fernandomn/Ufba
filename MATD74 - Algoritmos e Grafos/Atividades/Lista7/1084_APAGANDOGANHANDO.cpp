#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i = 0; i < n; i++)

int main(int argc, char const *argv[]) {
  int n, d, i;
  int apagados;
  char numero;
  string pilha, entrada;
  while (scanf("%d%d\n", &n, &d) && (n + d))
  {
    pilha = "";
    apagados = 0;
    cin >> entrada;
    FOR(i, n)
    {
      numero = entrada[i];
      while((pilha.size() > 0)&&(pilha.at(pilha.size()-1) < numero ) && apagados < d)
      {
          pilha.erase(pilha.size()-1);
          apagados++;
      }
    if(pilha.size() < n-d)
      pilha.push_back(numero);

    }
    std::cout << pilha << std::endl;
  }
  return 0;
}

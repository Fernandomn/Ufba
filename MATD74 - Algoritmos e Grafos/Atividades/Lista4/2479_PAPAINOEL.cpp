#include <bits/stdc++.h>
using namespace std;

#define FOR(n) for(int i = 0; i < n; i++)

int main(int argc, char const *argv[]) {
  /* code */
  int bemComportada = 0, malComportada = 0;
  int qntCriancas;
  vector<string> lista;
  char comportamento;
  string nome;

  cin >> qntCriancas;
  FOR(qntCriancas)
  {
    cin >> comportamento >> nome;
    if(comportamento == '+')
      bemComportada++;
    else
      malComportada++;
    lista.push_back(nome);
  }
  sort(lista.begin(),lista.end());
  for(int i = 0; i < lista.size(); i++)
    cout << lista[i] << "\n";
  cout << "Se comportaram: " << bemComportada << " | Nao se comportaram: " << malComportada << "\n";
  return 0;
}

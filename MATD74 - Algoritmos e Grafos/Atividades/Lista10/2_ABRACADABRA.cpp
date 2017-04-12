#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i = 0; i < n; i++)

int main(int argc, char const *argv[]) {
  string palavra;
  string paraImprimir;
  int i, j;
  int letrasImprimir;

  while (getline(cin, palavra))
  {
    FOR(i, palavra.size()){
      FOR(j, i)
        std::cout << " ";
      letrasImprimir = palavra.size() - i;
      FOR(j, letrasImprimir){
        if(j < letrasImprimir-1)
          std::cout << palavra[j] << " ";
        else
          std::cout << palavra[j] << std::endl;
      }
    }
    std::cout << std::endl;
  }

  return 0;
}

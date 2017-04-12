#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i=0; i < n; i++)

int main(int argc, char const *argv[]) {
  string entrada1, entrada2;
  int i, j, iaux, jaux, n1, n2, maiorSubstring, tamSubstring;
  while(getline(cin, entrada1) && getline(cin, entrada2))
  {
    maiorSubstring = 0;
    tamSubstring = 0;
    n1 = entrada1.size(); n2 = entrada2.size();
    FOR(i, n1)
    {
      FOR(j, n2)
      {
        iaux = i;
        jaux = j;
        while(iaux < n1 && jaux < n2 && entrada1.at(iaux)==entrada2.at(jaux))
        {
          iaux++; jaux++;
          tamSubstring++;
        }
        maiorSubstring = max(tamSubstring, maiorSubstring);
        tamSubstring = 0;
      }
    }
    std::cout << maiorSubstring << std::endl;
    entrada1.clear(); entrada2.clear();
  }
  return 0;
}

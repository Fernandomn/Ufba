#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i=0; i < n; i++)

bool maiorCrianca(string c1, string c2)
{
  int n = min (c1.size(), c2.size());
  int i;
  FOR(i, n)
  {
    if (toupper(c1.at(i)) > toupper(c2.at(i)))
      return true;
    if (toupper(c1.at(i)) < toupper(c2.at(i)))
      return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  std::string ultimaCrianca = "";
  string crianca;
  while (getline(cin, crianca))
  {
    if (maiorCrianca(crianca, ultimaCrianca))
      ultimaCrianca = crianca;
  }
  std::cout << ultimaCrianca << std::endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i=0; i < n; i++)

int main(int argc, char const *argv[]) {
  std::vector<int> habitantes;
  int i, desejo;
  long long int n, trabalho;
  while (scanf("%lld", &n) && (n))
  {
    trabalho = 0;
    FOR(i, n){
      scanf("%d", &desejo);
      habitantes.push_back(desejo);
    }
    for (i = 1; i < n; i++)
    {
      if(habitantes[i-1] < 0)
        trabalho -= habitantes[i-1];
      else
        trabalho += habitantes[i-1];
      habitantes[i] += habitantes[i-1];
    }
    std::cout << trabalho << std::endl;
    habitantes.clear();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i = 0; i < n; i++)

void Fatoracao(int numFatorar, std::vector<int> & fatores){
  int num = numFatorar;
  int i;
  i = 2;
  while(i < numFatorar + 1){//floor(numFatorar/2)){
    if(num % i == 0){
      fatores.push_back(i);
      num = int(num / i);
    }
    else{
      i++;
    }
  }
}
int main(int argc, char const *argv[]) {
  std::vector<int> fatores;
  int i;
  int fatorar;
  std::cin >> fatorar;
  Fatoracao(fatorar, fatores);
  FOR(i, fatores.size())
    std::cout << fatores[i] << " ";
  std::cout << std::endl;
  return 0;
}

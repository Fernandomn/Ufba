#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i = 0; i < n; i++)

int main(int argc, char const *argv[]) {
  double a, b, c;
  string saida;
  std::cin >> a >> b >> c;
  double r1, r2;
  double delta = b * b - 4 * a * c;
  if (a != 0 && delta >= 0)
  {
    r1 = (-b + sqrt(delta))/(2 * a);
    r2 = (-b - sqrt(delta))/(2 * a);
    printf("R1 = %.5lf\n", r1);
    printf("R2 = %.5lf\n", r2);
  }
  else
  {
    std::cout << "Impossivel calcular" << std::endl;
  }
  return 0;
}

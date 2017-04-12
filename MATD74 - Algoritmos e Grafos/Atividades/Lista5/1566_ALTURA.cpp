#include <bits/stdc++.h>
using namespace std;

#define FOR(n) for(i = 0; i < n; i++)

void countingSort(std::vector<int> lista, std::vector<int> & resultado, long int tamLista, int numMax)
{
  std::vector<int> buffer;
  int i;
  FOR(numMax+1)
    buffer.push_back(0);

  FOR(tamLista)
    buffer[lista[i]]++;

  for(i = 1; i <= numMax; i++)
    buffer[i] += buffer[i-1];

  for(i = tamLista-1; i >= 0; i--){
    resultado[buffer[lista[i]]-1] = lista[i];
    buffer[lista[i]] --;
  }
}

int main(int argc, char const *argv[]) {
  int numCidades;
  long int numHabitantes;
  int i, j;
  scanf("%d", &numCidades);
  FOR(numCidades)
  {
    scanf("%ld", &numHabitantes);
    std::vector<int> habitantes, resultado;
    int habit;
    for(j = 0; j < numHabitantes; j++)
    {
      scanf("%d", &habit);
      habitantes.push_back(habit);
      resultado.push_back(0);
    }

    countingSort(habitantes, resultado, numHabitantes, 230);

    for(j = 0; j < numHabitantes - 1; j++)
      printf("%d ", resultado[j]);
    printf("%d\n", resultado[numHabitantes-1]);

  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i=0; i < n; i++)

bool ehMaiuscula(char letra)
{
  if (int(letra) >= int('A') && int(letra) <= int('Z'))
    return true;
  return false;
}

char decode (char entrada, string cifra)
{
  char saida = entrada;
  int i;
  int tamCifra = cifra.size();
  FOR(i, tamCifra)
  {
    if(tolower(entrada) == tolower(cifra.at(i)))
    {
      if (i < tamCifra / 2)
      {
        saida = cifra.at(i + floor(tamCifra/2));
      }
      else
      {
        saida = cifra.at(i - floor(tamCifra/2));
      }
    }
  }
  if (ehMaiuscula(entrada))
    saida = toupper(saida);

  return saida;
}

string pegaCifra(int tamCifra)
{
  char letra;
  int i;
  string saida;
  FOR(i, tamCifra)
  {
    scanf("%c", &letra);
    saida.push_back(tolower(letra));
  }
  getchar();
  return saida;
}

int main(int argc, char const *argv[]) {
  int tamCifra, numCasos;
  int i, j;
  while(scanf("%d%d\n", &tamCifra, &numCasos) != EOF)
  {
    string cod1, cod2, cifra, saida;

    cod1 = pegaCifra(tamCifra);
    cod2 = pegaCifra(tamCifra);
    cifra = cod1 + cod2;
    // std::cout << cifra << std::endl;
    FOR(i, numCasos)
    {
      string entrada;
      string saida;
      getline(cin, entrada);
      FOR(j, entrada.size())
      {
        saida.push_back(decode(entrada.at(j), cifra));
      }
      std::cout << saida << std::endl;
      entrada.clear();
      saida.clear();
    }
    std::cout << std::endl;
  }
  return 0;
}

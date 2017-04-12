#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i=0; i < n; i++)

int main(int argc, char const *argv[])
{
	int i, j, k;
	int numCasos;
	int numStrings;
	string entrada;

	cin >> numCasos;
	FOR(i, numCasos)
	{
		int soma = 0;
		cin >> numStrings;
		FOR(j, numStrings)
		{
			cin >> entrada;
			FOR(k, entrada.size())
			{
				soma += (int(entrada[k])-int('A')) + j + k;
			}
		}
		cout << soma << endl;
	}
	return 0;
}

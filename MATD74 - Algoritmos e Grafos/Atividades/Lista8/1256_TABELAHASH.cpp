#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i=0; i < n; i++)

int main(int argc, char const *argv[])
{
	int i, j, k;
	int numCasos;
	int base, qntChaves;
	int chave;
	std::vector< std::vector<int> > tabelaHash;

	cin >> numCasos;

	FOR (i, numCasos)
	{
		if (i > 0)
			cout << endl;
		cin >> base >> qntChaves;
		//prepara tabela
		FOR(j, base)
		{
			std::vector<int> v;
			tabelaHash.push_back(v);
		}
		//carrega tabela
		FOR(j, qntChaves)
		{
			scanf("%d", &chave);
			tabelaHash[chave % base].push_back(chave);
		}
		//imprime tabela
		FOR(j, tabelaHash.size())
		{
			cout << j << " ";
			for(k = 0; k <= tabelaHash[j].size(); k++)
			{
				if(k < tabelaHash[j].size())
					cout << "-> " << tabelaHash[j][k] << " ";
				else
					cout << "-> \\" << endl;
			}
		}
		if (i < numCasos-1)
			tabelaHash.clear();
	}
	return 0;
}

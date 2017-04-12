#include <bits/stdc++.h>
using namespace std;

#define FOR(n) for(i = 0; i < n; i++)
#define MAX_NUM 200

int main(int argc, char const *argv[])
{
	int numTelefones = 0;
	int i;
	string::size_type j;
	int economia;
	string novoNumero;
	while ((scanf("%d", &numTelefones))!= EOF)
	{
		economia = 0;
		vector<string> lista;
		FOR(numTelefones)
		{
			cin >> novoNumero;
			lista.push_back(novoNumero);
		}
		sort(lista.begin(),lista.end());
		for(i = 1; i < lista.size(); i++)
		{
			for(j = 0; j < lista[i].size(); j++)
			{
				if(lista[i-1][j] == lista[i][j])
					economia++;
				else
					break;
			}
		}
		cout << economia << "\n";
	}

	return 0;
}

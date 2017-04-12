#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(i = 0; i < n; i++)

struct Estrada {
	int x, y;
	int distancia;
};

bool ordenaDistancia(Estrada a, Estrada b){ return a.distancia < b.distancia; }

int Kruskal(std::vector<Estrada> listaEstradas, int vertices, int arestas, int totalEstradas)
{
	int lider[vertices];
	int i, j, v0, w0;
	std::vector<Estrada> estMin;
	FOR(i, vertices)
	{
		lider[i] = i;
	}
	sort(listaEstradas.begin(), listaEstradas.end(), ordenaDistancia);
	FOR(i, listaEstradas.size())
	{
		int u = listaEstradas[i].x;
		int v = listaEstradas[i].y;
		if(lider[u] != lider[v])
		{
			estMin.push_back(listaEstradas[i]);
			v0 = lider[u];
			w0 = lider[v];
      FOR(j, vertices)
			{
       if (lider[j] == w0)
          lider[j] = v0;
			}
			totalEstradas -= listaEstradas[i].distancia;
		}
	}
	return totalEstradas;
}

int main(int argc, char const *argv[])
{
	int i;
	int totalEstradas;
	int juncoes, estradas;
	std::vector<Estrada> listaEstradas;
	while(scanf("%d%d", &juncoes, &estradas) && (juncoes + estradas))
	{
		totalEstradas = 0;
		FOR(i, estradas)
		{
			Estrada est;
			cin >> est.x >> est.y >> est.distancia ;
			listaEstradas.push_back(est);
			totalEstradas += est.distancia;
		}

		int resultado = Kruskal(listaEstradas, juncoes, estradas, totalEstradas);
		std::cout << resultado << std::endl;
		listaEstradas.clear();
	}
	return 0;
}

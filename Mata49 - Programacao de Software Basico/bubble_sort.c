#include <stdio.h>

void bubble (int V[], int n)
{
	int k = n-1;
	int i;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		while (j <= k)
		{
			if (V[j] > V[j+1])
			{
				int aux = V[j];
				V[j] = V[j+1];
				V[j+1] = aux;
			}
			j++;
		}
	}
	int p = 0;
	while (p < n){
		printf("%d, ", V[p]);
		p++;
	}
}

int main (){
	int n = 5;
	int V[5] = {648, 6, 683, 168, 68};
	
	bubble(V, n);
	
	return 0;
	}

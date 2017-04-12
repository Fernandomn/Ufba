numEntradas = int(input())
contador = 0
while numEntradas > 0:
	casoTeste = input()
	casoTeste = list(casoTeste)
	for x in range(len(casoTeste)):
		if casoTeste[x] == '>':
			for y in reversed(range(len(casoTeste[:x]))):
				if casoTeste[y] == '<':
					contador += 1
					casoTeste[x] = 'D'
					casoTeste[y] = 'D'
					break
	print(contador)				
	contador = 0
	numEntradas -= 1

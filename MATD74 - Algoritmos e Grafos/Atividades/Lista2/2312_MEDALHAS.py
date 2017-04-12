from operator import itemgetter, attrgetter

numPaises = int(input())

paises = []

while (numPaises > 0):
	paisNovo = input().split()
	#pais = {'nome':paisNovo[0], 'ouro':paisNovo[1], 'prata':paisNovo[2], 'bronze':paisNovo[3]}
	pais = (paisNovo[0], int(paisNovo[1]), int(paisNovo[2]), int(paisNovo[3]))
	paises.append(pais)
	numPaises -= 1

ordemAlfabetica = sorted(paises, key = itemgetter(0))
resultado = sorted(ordemAlfabetica, key = itemgetter(1,2,3), reverse = True)

for pais in resultado:
	print('{0} {1} {2} {3}'.format(pais[0], pais[1], pais[2], pais[3]))
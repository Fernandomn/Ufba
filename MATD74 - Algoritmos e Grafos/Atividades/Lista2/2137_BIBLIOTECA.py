from operator import itemgetter, attrgetter

while True:
	try:
		numCasos = int(input())
	except EOFError:
		break

	vetorLivros = []
	for i in range(numCasos):
		codigoLivro = input()
		vetorLivros.append((int(codigoLivro), codigoLivro))
	vetorOrdenado = sorted(vetorLivros, key=itemgetter(0))
	for j in vetorOrdenado:
		print(j[1])
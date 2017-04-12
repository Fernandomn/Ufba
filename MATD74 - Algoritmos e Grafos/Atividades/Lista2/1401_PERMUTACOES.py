def permutacoes(vetor):
	n = len(vetor)
	perm = vetor[:]
	k = n
	m = 0
	# candidato = ''
	while True:
		if k >= n:
			# print(''.join(elem[1] for elem in vetor))
			print(''.join(elem[1] for elem in perm))
			m = n + 1
		while m < n and not valido(perm, k, m):
			m += 1
		if m < n:
			perm[k] = vetor[m]
			m = 0
			k += 1
		else:
			if k < 1:
				break
			m = perm[k - 1][0] + 1
			# candidato = perm[m]
			k -= 1


def valido(vetor, k, m):
	for i in range(k):
		if m == vetor[i][0]:
			return False
	return True


numEntradas = int(input())
for i in range(numEntradas):
	letras = input()
	vetorLetras = list(letras)
	vetorLetras.sort(key=str.lower)
	vetorOrdenado = list(enumerate(vetorLetras))
	permutacoes(vetorOrdenado)
	print()

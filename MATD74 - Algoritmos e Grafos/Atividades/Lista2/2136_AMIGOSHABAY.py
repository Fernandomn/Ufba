def InsereOrdenado (lista, nome, contador):
	novoItem = (nome, contador)
	if len(lista) < 1:
		lista.append(novoItem)
	else:
		inseriu = False
		for item in lista:
			if (nome == item[0]):
				return
			if (nome < item[0]):
				indice = lista.index(item)
				lista.insert(indice, novoItem)
				inseriu = True
				return
		if not inseriu:
			lista.append(novoItem)


listaSim = []
listaNao = []
contador = 0
maiorNome = 0
while True:
	entrada = input()
	if entrada == 'FIM':
		break
	alunoOpcao = entrada.split(' ')
	if alunoOpcao[1] == 'YES':
		if len(alunoOpcao[0]) > maiorNome:
			maiorNome = len(alunoOpcao[0])
		InsereOrdenado (listaSim, alunoOpcao[0], contador)
	else:
		InsereOrdenado (listaNao, alunoOpcao[0], contador)
	contador += 1

#resposta:
escolhido = ''
posicao = contador
for alunoSim in listaSim:
	if len(alunoSim[0]) == maiorNome and alunoSim[1] < posicao:
		escolhido = alunoSim[0]
		posicao = alunoSim[1]
	print(alunoSim[0])
for alunoNao in listaNao:
	print(alunoNao[0])
print('\nAmigo do Habay:\n'+escolhido)

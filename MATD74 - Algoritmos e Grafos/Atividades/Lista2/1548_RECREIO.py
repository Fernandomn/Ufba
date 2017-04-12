from operator import itemgetter, attrgetter

numEntradas = int(input())

for i in range(numEntradas):
    numAlunos = int(input())
    vetorAlunos = []
    vetor = input().split(' ')
    for j in range(numAlunos):
    	vetorAlunos.append((j, int(vetor[j])))
    #print(vetorAlunos)	
    vetorOrdenado = sorted(vetorAlunos, key = itemgetter(1), reverse = True)	
    #print(vetorOrdenado)
    contador = 0
    for k in range(len(vetorOrdenado)):
    	if (k == vetorOrdenado[k][0]):
    		contador += 1
    print (contador)
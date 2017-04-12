#UNIVERSIDADE FEDERAL DA BAHIA
#DEPARTAMENTO DE CIENCIA DA COMPUTACAO
#MATA53 - TEORIA DOS GRAFOS
#PROFESSOR - STEFFEN LEWITZKA
#ALUNOS:
#FERNANDO MEDEIROS DO NASCIMENTO	
#IGOR TEIXEIRA PAIM
import random
import math
import sys
import re

global tempo

class vertice:
	numero = 0
	peso = 0
	cor = 0
	
	def __init__(self, numero, peso, valor):
		this.numero = 0
		this.peso = 0
		this.cor = 0
		
class verticeSet:
	pai = 0
	rank = 0
########################################################################	
	

def criaGrafoMatrizNaoDirecional(vertices, arestas):
	#numVertices = len(vertices)
	grafo = [[0 for i in range(vertices)] for j in range (vertices)]
	for i in range(vertices):
		for j in range(vertices):
			if i == j:
				grafo[i][j] = 0
			elif [i, j] in arestas or [j,i] in arestas:
				grafo[i][j] = 1
				grafo[j][i] = 1
			else:
				grafo[i][j] = 0
				grafo[j][i] = 0
	printMatrix(grafo)
	return grafo

def criaGrafoMatrizNaoDirecionalComPeso(vertices, arestas, maxPeso):
	#numVertices = len(vertices)
	grafo = [[0 for i in range(vertices)] for j in range (vertices)]
	for i in range(vertices):
		for j in range(vertices):
			if i == j:
				grafo[i][j] = 0
			elif [i, j] in arestas or [j , i] in arestas:
				peso = random.randrange(1, maxPeso)
				grafo[i][j] = peso
				grafo[j][i] = peso
			else:
				grafo[i][j] = 0
				grafo[j][i] = 0
	printMatrix(grafo)
	return grafo
	
def criaGrafoMatrizDirecionalComPeso(vertices, arestas, maxPeso):
	#numVertices = len(vertices)
	grafo = [[0 for i in range(vertices)] for j in range (vertices)]
	for i in range(vertices):
		for j in range(vertices):
			if i == j:
				grafo[i][j] = 0
			elif [i, j] in arestas:
				peso = random.randrange(1, maxPeso)
				grafo[i][j] = peso
			else:
				grafo[i][j] = 0
	printMatrix(grafo)
	return grafo	
	
def criaGrafoMatrizNaoDirecionalComPesoFixo(vertices, arestas, pesos):
	#numVertices = len(vertices)
	grafo = [[0 for i in range(vertices)] for j in range (vertices)]
	for i in range(vertices):
		for j in range(vertices):
			if [i, j] in arestas:
				peso = pesos.pop(0)
				grafo[i][j] = peso
				grafo[j][i] = peso
	printMatrix(grafo)
	return grafo
	
def criaGrafoMatrizDirecionalComPesoFixo(vertices, arestas, pesos):
	#numVertices = len(vertices)
	grafo = [[0 for i in range(vertices)] for j in range (vertices)]
	for i in range(vertices):
		for j in range(vertices):
			if [i, j] in arestas:
				peso = pesos.pop(0)
				grafo[i][j] = peso
	printMatrix(grafo)
	return grafo	

def criaGrafoMatrizDirecional(vertices, arestas):
	#numVertices = len(vertices)
	grafo = [[0 for i in range(vertices)] for j in range (vertices)]
	for i in range(vertices):
		for j in range(vertices):
			if i == j:
				grafo[i][j] = 0
			elif [i, j] in arestas:
				grafo[i][j] = 1
#				grafo[j][i] = 1
			else:
				grafo[i][j] = 0
#				grafo[j][i] = 0
	printMatrix(grafo)
	return grafo
				
def criaGrafoListasNaoDirecional(vertices, arestas):
	
	grafo = []
	for i in range(vertices):
		grafo.append([])
		for j in range(vertices):
			if [i, j] in arestas or [j, i] in arestas:
				grafo[i].append(j)
	printMatrix(grafo)		
	return grafo		
				
def criaListaArestasAleatoriamente(vertices):
	arestas = []
	numMaxArestas = (float)((float)(vertices**2-vertices)/2)
	for i in range(vertices):
		for j in range(vertices):
			if (random.randrange(0,2) == 1) and (i != j):
				arestas.append([i,j])
	print (arestas)			
	return arestas			
########################################################################
def printMatrix(testMatrix):
	print("Grafo: ")
	print
	for i, element in enumerate(testMatrix):
		print (element)
	print()	
########################################################################
def buscaEmLargura (grafo, raiz):
	#usa lista de adjacencias
	#grafo é a estrutura de dados, raiz é o valor inteiro que representa
	#o vertice inicial da analise
	numVertices = len(grafo)
	cor = []
	distancia = []
	predecessor = []
	for vertice in range(numVertices):
		if vertice != raiz:
			cor.append("BRANCO")
			distancia.append(-1)
			predecessor.append(None)
			print ("O vertice "+ str(vertice)+ " está branco")
		else:
			cor.append("CINZA")
			print ("O vertice " + str(vertice) + " é a raiz, e está cinza")
			distancia.append(0)
			predecessor.append(None)
	fila = []
	fila.append(raiz)
	while len(fila) != 0:
		vertice = fila.pop(0)
		print("Vertice analizado: " + str(vertice))
		#vizinhosDoVertice = []
		#vizinhosDoVertice = vizinhosDoVertice(grafo, vertice)
		for vizinho in grafo[vertice]:
			print ("vizinho analizado: "+ str(vizinho))
			if cor[vizinho] == "BRANCO":
				print("o vizinho está branco, e agora é cinza")
				cor[vizinho] = "CINZA"
				distancia[vizinho] = distancia[vertice] + 1
				predecessor[vizinho] = vertice
				fila.append(vizinho)
			else:
				print("O vizinho não era branco, pular")	
		cor[vertice] = "PRETO"
		print ("O vertice " + str(vertice) + " agora é preto")

def buscaEmProfundidade(grafo):
	#usa lista de adjacencias
	print ("Iniciando Busca em Profundidade")
	numVertices = len(grafo)
	cor = []
	predecessor = []
	inicio = []
	final = []
	for vertice in range(numVertices):
		inicio.append(0)
		final.append(0)
		cor.append("BRANCO")
		print ("O vertice "+ str(vertice) +" esta branco")
		predecessor.append(None)
	#global tempo
	tempo = 0
	for vertice in range(numVertices):
		if cor[vertice] == "BRANCO":
			tempo, cor, predecessor, inicio, final = visitaBRP(vertice, grafo, tempo, cor, predecessor, inicio, final)

def visitaBRP(vertice, grafo, tempo, cor, predecessor, inicio, final):
	print ("Visitando o vertice "+str(vertice))
	cor[vertice] = "CINZA"
	print(str(vertice)+" esta cinza")
	#global tempo
	tempo += 1
	inicio[vertice] = tempo
	print ("Este vertice se iniciou no tempo "+ str(inicio[vertice]))
	for vizinho in grafo[vertice]:
		if cor[vizinho] == "BRANCO":
			print ("o vizinho "+str(vizinho)+" tem cor branca")
			predecessor[vizinho] = vertice
			tempo, cor, predecessor, inicio, final = visitaBRP(vizinho, grafo, tempo, cor, predecessor, inicio, final)
	cor[vertice] = "PRETO"
	print ("Agora o vertice "+str(vertice)+" é preto")
	final[vertice] = tempo
	print("A visita a ele foi concluida em "+str(final[vertice])+" unidades de tempo.")
	tempo += 1
	return tempo, cor, predecessor, inicio, final
	
	
def ordenacaoTopologica(grafo):
	#usa listas de adjacencias. Precisa de grafos aciclicos e direcionais
	print ("Iniciando Ordenacao Topologica")
	numVertices = len(grafo)
	cor = []
	predecessor = []
	inicio = []
	final = []
	ordem = []
	for vertice in range(numVertices):
		inicio.append(0)
		final.append(0)
		cor.append("BRANCO")
		print ("O vertice "+ str(vertice) +" esta branco")
		predecessor.append(None)
	tempo = 0
	for vertice in range(numVertices):
		if cor[vertice] == "BRANCO":
			tempo, cor, predecessor, inicio, final, ordem = visitaOrdTop(vertice, grafo, tempo, cor, predecessor, inicio, final, ordem)
	print ("A ordem ideal é: "+str(ordem))
	print()
	return ordem		
	
def visitaOrdTop(vertice, grafo, tempo, cor, predecessor, inicio, final, ordem):
	print ("Visitando o vertice "+str(vertice))
	cor[vertice] = "CINZA"
	print(str(vertice)+" esta cinza")
	#global tempo
	tempo += 1
	inicio[vertice] = tempo
	print ("Este vertice se iniciou no tempo "+ str(inicio[vertice]))
	for vizinho in grafo[vertice]:
		if cor[vizinho] == "BRANCO":
			print ("o vizinho "+str(vizinho)+" tem cor branca")
			predecessor[vizinho] = vertice
			tempo, cor, predecessor, inicio, final, ordem = visitaOrdTop(vizinho, grafo, tempo, cor, predecessor, inicio, final, ordem)
	cor[vertice] = "PRETO"
	print ("Agora o vertice "+str(vertice)+" é preto")
	final[vertice] = tempo
	ordem.append(vertice)
	print("A visita a ele foi concluida em "+str(final[vertice])+" unidades de tempo.")
	tempo += 1
	return tempo, cor, predecessor, inicio, final, ordem
	
def findSet(x, conjuntoDisjunto):
	#AQUI
	temp = conjuntoDisjunto[x]
	if x != temp[0]:
		conjuntoDisjunto[x][0] = findSet(conjuntoDisjunto[x][0], conjuntoDisjunto)
	return conjuntoDisjunto[x][0]
	
def uniao (x, y, conjuntoDisjunto):
	conjuntoDisjunto = link(findSet(x, conjuntoDisjunto), findSet(y, conjuntoDisjunto), conjuntoDisjunto)
	return conjuntoDisjunto

def link(x, y, conjuntoDisjunto):
	if conjuntoDisjunto[x][1] > conjuntoDisjunto[y][1]:
		conjuntoDisjunto[y][0] = x
	else:
		conjuntoDisjunto[x][0] = y
		if conjuntoDisjunto[x][1] == conjuntoDisjunto[y][1]:
			conjuntoDisjunto[y][1] += 1
	return conjuntoDisjunto		

def kruskal(grafo):
	#grafos não direcionais. Peso fixo
	A = []
	conjuntoDisjunto = []
	for vertice in range(len(grafo)):
		#Make-Set(x)
		#parent[x] = x
		#rank[x] = 0
		conjuntoDisjunto.append([vertice, 0])
		
	listaPesos = []
	for i in range(len(grafo)):
		for j in range(len(grafo)):
			if i != j and grafo[i][j] != 0:
				listaPesos.append([i,j,grafo[i][j]])	
				#vertices i, j, e o peso
	listaPesos.sort(key=lambda pesos:pesos[2]) #ordenando a lista pelos pesos das arestas
	
	for arestas in listaPesos:
		B = findSet(arestas[0], conjuntoDisjunto)
		C = findSet(arestas[1], conjuntoDisjunto)
		if B!= C:
			A.append((arestas[0],arestas[1]))
			conjuntoDisjunto = uniao(arestas[0],arestas[1], conjuntoDisjunto)
	return A		

def Dijkstra(grafo, verticeInicial):
	#usa matriz de adjacencia
	#grafos direcionais (ou nao) e com pesos
	print ("Iniciando o algoritmo de Dijkstra")
	distancia = []
	predecessor = []
	S = []
	Q = []
	#initialize-single-source
	for v in range(len(grafo)):
		distancia.append(2**30) #?
		predecessor.append(None)
		Q.append(v)
	distancia[verticeInicial] = 0
	while len(Q) > 0:
		indiceMinimo=distancia.index(min(distancia))
		u = Q.pop(indiceMinimo)#PAREI AQUI
		S.append(u)
		for v in range(len(grafo)):
			if  grafo[u][v] != 0 and distancia[v] > distancia[u]+grafo[u][v]:
				distancia[v] = distancia[u]+grafo[u][v]
				predecessor[v] = u
				print("Lista de predecessores: " + str(predecessor))
				print("Lista de distancias: "+str(distancia))
				print("Fila de vertices: " + str(Q))
				print("Vertices utilizados: "+str(S))
	print ()
	
def Warshall(grafo):
	#usa grafos direcionais ou não, com pesos
	numLinhas = len(grafo)
	dist = grafo
	pred = [[0 for i in range(numLinhas)] for j in range (numLinhas)]
	for i in range(numLinhas):
		for j in range(numLinhas):
			if dist[i][j] < 2**30:
				pred[i][j] = i
	
	for k in range(numLinhas):
		for i in range(numLinhas):
			for j in range(numLinhas):
				if dist[i][j] > dist[i][k] + dist[k][j]:
					dist[i][j] = dist[i][j] + dist[i][k]
					pred[i][j] = pred[k][j]
					printMatrix(dist)
	return dist				

########################################################################
def VerificaVerticesPeso(fita):
	primeiroVertice = 0
	segundoVertice = 0
	pesoVertice = 0
	primeiro = True
	segundo = False
	peso = False
	
	if (fita[i] >= int('0')) and (fita[i] <= int('9')):
		if (primeiro):
			primeiroVertice = primeiroVertice*10 + int(fita[i]);
		if (segundo):
			segundoVertice = segundoVertice*10 + int(fita[i]);
		if (peso):
			pesoVertice += pesoVertice*10 + int(fita[i])
	elif(fita[i] == '-'):
		if primeiro:
			primeiro = False
			segundo = True
		else:
			segundo = False
			peso = True	
	else:
		return None, None		
	return [primeiroVertice, segundoVertice], peso		
########################################################################
def KruskalPreDefinido():
	arestas = [[0,1],[0,7],[1,2],[1,7],[2,3],[2,5],[2,8],[3,4],[3,5],[4,5],[5,6],[6,7],[6,8],[7,8]]
	pesos =	[4, 8, 8, 11, 7, 4, 2, 9, 14, 10, 2, 1, 6, 7]
	grafo = []
	grafo = criaGrafoMatrizNaoDirecionalComPesoFixo(9, arestas, pesos)
	return grafo
	
def DijkstraPreDefinido():	
	arestas = [[0,1],[0,2],[1,2],[1,3],[1,4], [2,4], [3,4],[3,5],[4,5]]
	pesos = [8,12,1,3,7,4,5,21,15]
	grafo = criaGrafoMatrizNaoDirecionalComPesoFixo(6, arestas, pesos)
	return grafo 
	
def BuscaEmLarguraPreDefinido():
	vertices = 8
	arestas=[[0,1],[0,4],[1,5],[2,3],[2,5],[2,6],[3,6],[3,7],[5,6],[6,7]]
	grafo = criaGrafoListasNaoDirecional(vertices, arestas)
	return grafo
	
def BuscaEmProfundidadePreDefinido():
	vertices = 6
	arestas = [[0,1],[0,3],[1,3],[1,4],[2,4],[2,5],[3,4]]
	grafo = criaGrafoListasNaoDirecional(vertices, arestas)
	return grafo
	
def OrdTopologicaPreDefinido():
	vertices = 8
	arestas = [[0,1],[0,2],[0,7],[2,1],[3,2],[4,3],[4,5],[5,2],[6,0],[6,1],[6,5],[6,7]]
	grafo = criaGrafoMatrizDirecional(vertices, arestas)
	return grafo
	
def WarshallPreDefinido():
	vertices = 4
	arestas = [[1,0],[1,2],[1,3],[2,0],[2,3]]
	pesos = [4,3,-1,-2,2]
	grafo = criaGrafoMatrizDirecionalComPesoFixo(vertices, arestas, pesos)
	return grafo
########################################################################	
def main():
	
	grafo = []
	listaVertices = []
	listaArestas = []
	listaPesos = []
	opcAlgoritmo = ""
	
	while opcAlgoritmo != 'n':
		print("Digite o algoritmo que deseja executar:")
		print("Algoritmo de Krustal	- k")
		print("Algoritmo de Dijkstra - d")
		print("Busca em Largura	- l")
		print("Busca em profundidade - p")
		print("Ordenacao Topologica	- o")
		print("Algoritmo de Warshall - w")
		opcAlgoritmo = input()
		########## KRUSKAL 	########## 
		if opcAlgoritmo == 'k':
			print("Algoritmo de Kruskal")
			opcModo = input("Deseja inserir arestas, gerar um grafo aleatoriamente ou usar um grafo pré-definido? (i/a/p)\n")
			if opcModo == 'i':
				print("Digite o numero de vertices: ")
				numVertices = input()
				print("Grafo não-direcional (digite numeros para os vertices, qualquer letra para parar):")
				print("Digite as ligações dos vértices, da forma A-B-C, onde A é o vertice inicial, B o final, e C o peso")
				print("(Não seja redundante)")
				fita = input()
				while len(fita) > 0:
					if(fita[i] >= int('a')) and (fita[i] <= int('z'))and(fita[i] >= int('0')) and (fita[i] <= int('9')):
						vertice, peso = VerificaVerticesPeso(fita)
						listaArestas.append(vertice)
						listaPesos.append(peso)
				grafo = criaGrafoMatrizNaoDirecionalComPesoFixo(numVertices, listaArestas, listaPesos)
			elif opcModo == 'a':
				numVertices = input("Digite o numero de vertices")
				print("Gerando o grafo aleatoriamente")
				grafo = criaListaArestasAleatoriamente(numVertices)
			elif opcModo == 'p':
				grafo = KruskalPreDefinido()
			print("Resultado do algoritmo de Kruskal:")
			print(kruskal(grafo))
			
		########## DIJKSTRA ########## 	
		elif opcAlgoritmo == 'd':
			print("Algoritmo de Dijkstra")
			opcModo = input("Deseja inserir arestas, gerar um grafo aleatoriamente ou usar um grafo pré-definido? (i/a/p)")
			if opcModo == 'i':
				print("Digite o numero de vertices: ")
				numVertices = input()
				print("Grafo direcional")
				print("Digite as ligações dos vértices, da forma A-B-C, onde A é o vertice inicial, B o final, e C o peso")
				print("(digite numeros para os vertices, qualquer letra para parar)")
				fita = input()
				while len(fita) > 0:
					if(fita[i] >= int('a')) and (fita[i] <= int('z'))and(fita[i] >= int('0')) and (fita[i] <= int('9')):
						vertice, peso = VerificaVerticesPeso(fita)
						listaArestas.append(vertice)
						listaPesos.append(peso)
				grafo = criaGrafoMatrizDirecionalComPesoFixo(numVertices, listaArestas, listaPesos)
			elif opcModo == 'a':
				numVertices = input("Digite o numero de vertices")
				print("Gerando o grafo aleatoriamente")
				arestas = criaListaArestasAleatoriamente(numVertices)
				grafo = criaGrafoMatrizNaoDirecionalComPeso(numVertices, arestas, 20)
			elif opcModo == 'p':
				grafo = DijkstraPreDefinido()
			print("Resultado do Algoritmo de Dijkstra:")
			Dijkstra(grafo, 0)
		
		########## BUSCA EM LARGURA ########## 			
		elif opcAlgoritmo == 'l':
			print("Algoritmo de Busca em Largura")
			opcModo = input("Deseja inserir arestas, gerar um grafo aleatoriamente ou usar um grafo pré-definido? (i/a/p)")
			if opcModo == 'i':
				print("Digite o numero de vertices: ")
				numVertices = input()
				print("Grafo não-direcional")
				print("Digite as ligações dos vértices, da forma A-B, onde A é o vertice inicial, B o final")
				print("(digite numeros para os vertices, qualquer letra para parar)")
				print("Nao seja redundante")
				fita = input()
				while len(fita) > 0:
					if(fita[i] >= int('a')) and (fita[i] <= int('z'))and(fita[i] >= int('0')) and (fita[i] <= int('9')):
						vertice, peso = VerificaVerticesPeso(fita)
						listaArestas.append(vertice)
						listaPesos.append(peso)
				grafo = criaGrafoListasNaoDirecional(numVertices, listaArestas)
			elif opcModo == 'a':
				numVertices = input("Digite o numero de vertices")
				print("Gerando o grafo aleatoriamente")
				arestas = criaListaArestasAleatoriamente(numVertices)
				grafo = criaGrafoListasNaoDirecional(numVertices, arestas)
			elif opcModo == 'p':
				grafo = BuscaEmLarguraPreDefinido()
			print("Resultado do Algoritmo de Busca Em Largura:")
			buscaEmLargura(grafo, 1)		
		
		########## BUSCA EM PROFUNDIDADE ########## 			
		elif opcAlgoritmo == 'p':
			print("Algoritmo de Busca em Profundidade")
			opcModo = input("Deseja inserir arestas, gerar um grafo aleatoriamente ou usar um grafo pré-definido? (i/a/p)")
			if opcModo == 'i':
				print("Digite o numero de vertices: ")
				numVertices = input()
				print("Grafo não-direcional")
				print("Digite as ligações dos vértices, da forma A-B, onde A é o vertice inicial, B o final")
				print("(digite numeros para os vertices, qualquer letra para parar)")
				print("Nao seja redundante")
				fita = input()
				while len(fita) > 0:
					if(fita[i] >= int('a')) and (fita[i] <= int('z'))and(fita[i] >= int('0')) and (fita[i] <= int('9')):
						vertice, peso = VerificaVerticesPeso(fita)
						listaArestas.append(vertice)
						listaPesos.append(peso)
				grafo = criaGrafoListasNaoDirecional(numVertices, listaArestas)
			elif opcModo == 'a':
				numVertices = input("Digite o numero de vertices")
				print("Gerando o grafo aleatoriamente")
				arestas = criaListaArestasAleatoriamente(numVertices)
				grafo = criaGrafoListasNaoDirecional(numVertices, arestas)
			elif opcModo == 'p':
				grafo = BuscaEmProfundidadePreDefinido()
			print("Resultado do Algoritmo de Busca Em Profundidade:")
			buscaEmProfundidade(grafo)
		
		########## ORDENACAO TOPOLOGICA ########## 			
		elif opcAlgoritmo == 'o':
			print("Algoritmo de Ordenação Topológica")
			opcModo = input("Deseja inserir arestas, gerar um grafo aleatoriamente ou usar um grafo pré-definido? (i/a/p)")
			if opcModo == 'i':
				print("Digite o numero de vertices: ")
				numVertices = input()
				print("Grafo direcional aciclico")
				print("Digite as ligações dos vértices, da forma A-B, onde A é o vertice inicial, B o final")
				print("(digite numeros para os vertices, qualquer letra para parar)")
				fita = input()
				while len(fita) > 0:
					if(fita[i] >= int('a')) and (fita[i] <= int('z'))and(fita[i] >= int('0')) and (fita[i] <= int('9')):
						vertice, peso = VerificaVerticesPeso(fita)
						listaArestas.append(vertice)
						listaPesos.append(peso)
				grafo = criaGrafoListasNaoDirecional(numVertices, listaArestas)
			elif opcModo == 'a':
				numVertices = input("Digite o numero de vertices")
				print("Gerando o grafo aleatoriamente")
				arestas = criaListaArestasAleatoriamente(numVertices)
				grafo = criaGrafoMatrizDirecional(numVertices, arestas)
			elif opcModo == 'p':
				grafo = OrdTopologicaPreDefinido()
			ordenacaoTopologica(grafo)	
			
		########## WARSHALL ########## 			
		elif opcAlgoritmo == 'w':
			print("Algoritmo de Warshall")
			opcModo = input("Deseja inserir arestas, gerar um grafo aleatoriamente ou usar um grafo pré-definido? (i/a/p)")
			if opcModo == 'i':
				print("Digite o numero de vertices: ")
				numVertices = input()
				print("Grafo direcional com pesos")
				print("Digite as ligações dos vértices, da forma A-B=C, onde A é o vertice inicial, B o final, e C é o peso")
				print("(digite numeros para os vertices, qualquer letra para parar)")
				fita = input()
				while len(fita) > 0:
					if(fita[i] >= int('a')) and (fita[i] <= int('z'))and(fita[i] >= int('0')) and (fita[i] <= int('9')):
						vertice, peso = VerificaVerticesPeso(fita)
						listaArestas.append(vertice)
						listaPesos.append(peso)
				grafo = criaGrafoListasNaoDirecionalComPesoFixo(numVertices, listaArestas)
			elif opcModo == 'a':
				numVertices = input("Digite o numero de vertices")
				print("Gerando o grafo aleatoriamente")
				arestas = criaListaArestasAleatoriamente(numVertices)
				grafo = criaGrafoListasNaoDirecionalComPesoFixo(numVertices, arestas)
			elif opcModo == 'p':
				grafo = WarshallPreDefinido()
			print("Resultado do Algoritmo de Warshall: ")
			printMatrix(Warshall(grafo))
		elif opcAlgoritmo == 'n':
			break
		print()
		opcAlgoritmo = input("Digite qualquer tecla para realizar uma nova operação. 'n' para encerrar\n")
					
	return 0

if __name__ == '__main__':
	main()


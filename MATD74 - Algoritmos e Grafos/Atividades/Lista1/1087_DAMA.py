import math

while True:
	entrada = input()
	if entrada == '0 0 0 0':
		break
	pontos = entrada.split(' ')
	ponto1 = [int(pontos[0]), int(pontos[1])]
	ponto2 = [int(pontos[2]), int(pontos[3])]

	if ponto1[0] == ponto2[0] and ponto1[1] == ponto2[1]:
		print('0')
	elif ponto1[0] == ponto2[0] or ponto1[1] == ponto2[1] or math.fabs(ponto2[0] - ponto1[0]) == math.fabs(ponto2[1] - ponto1[1]):
		print('1')
	else:
		print('2')	

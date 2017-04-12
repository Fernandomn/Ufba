import math

a = input()
b = input()
ponto1 = a.split(' ')
ponto2 = b.split(' ')
ponto1[0], ponto1[1] = float(ponto1[0]), float(ponto1[1])
ponto2[0], ponto2[1] = float(ponto2[0]), float(ponto2[1])
difX = ponto1[0]-ponto2[0]
difY = ponto1[1]-ponto2[1]
distancia = math.sqrt(math.pow(difX, 2) + math.pow(difY, 2))

print('{0:.4f}'.format(distancia))
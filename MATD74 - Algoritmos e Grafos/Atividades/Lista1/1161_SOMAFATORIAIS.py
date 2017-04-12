import math

while True:
	try:
		linha = input()
	except EOFError:
		break
	numbers = linha.split(' ')
	numbers[0], numbers[1] = float(numbers[0]), float(numbers[1])
	fac1 = math.factorial(numbers[0])
	fac2 = math.factorial(numbers[1])
	print(fac1 + fac2)

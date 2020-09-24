#1st method
def demo():
	a = -1234
	x = str(a)
	numbers = [int(i) for i in x[1:]]
	
	for num in numbers[0:1]:
		numbers[num-1] = num - (2*num)
	print(numbers)

demo()


#2nd method
def demo():
	a = -1234
	x = str(a)
	numbers = [int(i) for i in x[1:]]
	
	for num in numbers[0:1]:
		numbers[num-1] = num*(-1)
	print(numbers)

demo()
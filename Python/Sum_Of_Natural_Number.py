class SumOfNN:
	def _init__(self):
		pass
		
	def sum(self, x):
		if x != 0:
			return x + self.sum(x-1)
		else:
			return x
			
sonn = SumOfNN()

print('Enter a number:')
num = int(input())

result = sonn.sum(num)
print()
print('Sum is {}'.format(result))
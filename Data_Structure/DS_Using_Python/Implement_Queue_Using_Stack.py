class Queue:
	def __init__(self):
		self.s1 = Stack()
		self.s2 = Stack()
		
	def isEmpty(self):
		res = self.s1.isEmpty() and self.s2.isEmpty()
		return res
		
	def enQueue(self, item):
		res = self.s1.push(item)
		return res
		
	def deQueue(self):
		if self.s2.isEmpty():
			while not self.s1.isEmpty():
				x = self.s1.pop()
				self.s2.push(x)
		return self.s2.pop()
		
	def display(self):
		res1 = self.s1.stack
		for i in res1:
			print(i, end= ' ')
			
	def show(self):
		res = self.s2.stack
		for i in res[::-1]:
			print(i, end= ' ')
		
class Stack:
	def __init__(self):
		self.stack = []
		
	def isEmpty(self):
		return self.stack == []
		
	def push(self, item):
		self.stack.append(item)
		
	def pop(self):
		return self.stack.pop()
		
q = Queue()
q.enQueue(4)
q.enQueue(6)
q.enQueue(10)
q.enQueue(15)
q.enQueue(19)

print("Queue of elements is:")
q.display()

result = q.deQueue()
print("\n\nDeleted item is:", result)

print("\nAfter removing an element:")
q.show()
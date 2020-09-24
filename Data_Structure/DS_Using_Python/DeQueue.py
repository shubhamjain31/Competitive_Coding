class Dequeue:
	def __init__(self):
		self.queue = []
		
	def isEmpty(self):
		return self.queue == []
		
	def addFront(self, element):
		self.queue.insert(0, element)
		
	def addEnd(self, element):
		self.queue.append(element)
		
	def delFront(self):
		self.queue.pop(0)
		
	def delEnd(self):
		self.queue.pop()
		
	def display(self):
		for i in self.queue:
			print(i, end=' ')
			
	def size(self):
		print("\n\nLength of dequeue is {}".format(len(self.queue)))
		
dq = Dequeue()

dq.addFront(5)
dq.addFront(25)
dq.addFront(54)
print("Dequeue insertion of elements at front is:")
dq.display()

print()

print("\nDequeue insertion of elements at rear is:")
dq.addEnd(19)
dq.addEnd(10)
dq.display()

dq.delFront()
print()
print("\nDequeue after deleting element at front is:")
dq.display()


dq.delEnd()
print()
print("\nDequeue after deleting element at rear is:")
dq.display()

dq.size()
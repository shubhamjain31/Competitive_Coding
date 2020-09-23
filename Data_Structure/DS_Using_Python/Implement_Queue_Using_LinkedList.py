class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		
class Queue:
	def __init__(self):
		self.front = None
		self.rear = None
		
	def enQueue(self, item):
		ptr = Node(item)
		print(item, end=' ')
		if self.front is None:
			self.front = ptr
			self.rear = ptr
		else:
			self.rear.next = ptr
			self.rear = ptr
			
	def deQueue(self):
		if self.front is None:
			print('Queue Underflow !!')
			return
		temp = self.front
		print('\n\nDeleted item is {}'.format(temp.data))
		self.front = self.front.next
		if self.front is None:
			self.rear = None
			
		item = temp.data
		return item
		
	def peek(self):
		if self.front:
			print('\n\nFront element of queue is {}'.format(self.front.data))
		else:
			return
			
	def isEmpty(self):
		return self.front is None and self.rear is None
		
	def linkedListTraversal(self):
		temp = self.front
		while temp is not None:
			print(temp.data, end = ' ')
			temp = temp.next
			
		
q = Queue()

print('Queue is')
q.enQueue(61)
q.enQueue(11)
q.enQueue(52)
q.enQueue(45)
q.enQueue(9)

print("\n\nQueue before removing element is:")
q.linkedListTraversal()

q.deQueue()

print("\nQueue after removing element is:")
q.linkedListTraversal()

q.peek()

if(q.isEmpty()):
    print("\nQueue is empty")
else:
    print("\nQueue is not empty")
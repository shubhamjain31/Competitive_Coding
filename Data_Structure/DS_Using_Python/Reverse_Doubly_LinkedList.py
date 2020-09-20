class Node:
	def __init__(self, data):
		self.data = data
		self.prev = None
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None
		
	def traverseData(self):
		temp = self.head
		while temp is not None:
			print(temp.data, end = ' ')
			temp = temp.next
			
	def insertFirst(self, data):
					ptr = Node(data)
					if self.head is None:
						ptr.data = data
						ptr.prev = None
						ptr.next = None
						self.head = ptr
					else:
						ptr.data = data
						ptr.prev = None
						ptr.next = self.head
						self.head = ptr
			
	def push(self, data):
		newNode = Node(data)
		newNode.next = self.head
		if self.head is not None:
			self.head.prev = newNode
		self.head = newNode
		
	def reverse(self):
		prevNode = self.head
		nextNode = None
		while prevNode is not None:
			nextNode = prevNode.prev
			prevNode.prev = prevNode.next
			prevNode.next = nextNode
			prevNode = prevNode.prev
		if nextNode is not None:
			self.head = nextNode.prev
		
llist = LinkedList()

llist.push(56)
llist.push(10)
llist.push(27)
llist.push(39)
print("\nLinked List before reversing")
llist.traverseData()

llist.reverse()
print("\nLinked List after reversing")
llist.traverseData()
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class SinglyLinkedList:
	def __init__(self):
		self.head = None
			
	def push(self, data):
		newNode = Node(data)
		newNode.next = self.head
		self.head = newNode
		
	def printList(self):
		if self.head is None:
			print('List has no element')
			return
		else:
			temp = self.head
			while(temp):
				print(temp.data, end=' ')
				temp = temp.next
				
sllist = SinglyLinkedList()

sllist.push(78)
sllist.push(52)
sllist.push(13)

sllist.printList()
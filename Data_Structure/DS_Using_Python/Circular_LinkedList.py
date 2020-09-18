class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		
class CircularLinkedList:
	def __init__(self):
		self.head = None
		
	def printList(self):
		if self.head is None:
			print('List has no element')
			return
		else:
			temp = self.head
			while(temp):
				print(temp.data, end=' ')
				temp = temp.next
				if temp == self.head:
					break
	
	def push(self, data):
		newNode = Node(data)
		temp = self.head
		newNode.next = self.head
		if self.head is not None:
			while(temp.next != self.head):
				temp = temp.next
			temp.next = newNode
		else:
			newNode.next = newNode
		self.head = newNode
		
cllist = CircularLinkedList()

cllist.push(12) 
cllist.push(56) 
cllist.push(2) 
cllist.push(11) 

print('Linked list is')
cllist.printList()
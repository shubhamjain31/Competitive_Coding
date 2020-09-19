class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		
class SinglyLinkedList:
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
				
	def size(self):
		if self.head == None:
			return 0 
		else:
			temp = self.head
			c = 0
			while(temp is not None):
				c += 1
				temp = temp.next
			return c
		
	def insert(self, data):
		newNode = Node(data)
		newNode.next = self.head
		self.head = newNode
	 		
	def sortingAscendingOrder(self):
	 		prevNode = self.head
	 		nextNode = None
	 		while prevNode is not None:
	 			nextNode = prevNode.next
	 			while nextNode is not None:
	 				if prevNode.data > nextNode.data:
	 					temp = prevNode.data
	 					prevNode.data =  nextNode.data
	 					nextNode.data = temp
	 				nextNode = nextNode.next
	 			prevNode = prevNode.next
	 
	def sortingDescendingOrder(self):
	 		prevNode = self.head
	 		nextNode = None
	 		while prevNode is not None:
	 			nextNode = prevNode.next
	 			while nextNode is not None:
	 				if prevNode.data < nextNode.data:
	 					temp = prevNode.data
	 					prevNode.data =  nextNode.data
	 					nextNode.data = temp
	 				nextNode = nextNode.next
	 			prevNode = prevNode.next
				
llist = SinglyLinkedList()
llist.insert(35)
llist.insert(2)
llist.insert(97)
llist.insert(53)

print('Linked list before sorting')
llist.printList()

print('\n\nLinked list after sorting for ascending order')
llist.sortingAscendingOrder()
llist.printList()

print('\n\nLinked list after sorting for descending order')
llist.sortingDescendingOrder()
llist.printList()

if llist.size() == 0:
	print('\nNo element found')
else:
	print('\n\nTotal number of elements in linked list is',llist.size())
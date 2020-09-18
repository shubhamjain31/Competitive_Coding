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
	
	#Inserting at the Beginning of the Linked List
	def insertAtFirst(self, val):
		newNode = Node(val)
		newNode.next = self.head
		self.head = newNode
		
	#Inserting at the End of the Linked List
	def insertAtEnd(self, val):
		newNode = Node(val)
		if self.head is None:
			self.head = newNode
		else:
			temp = self.head
			while(temp.next is not None):
				temp = temp.next
			temp.next = newNode
			newNode.next = None   #Optional
			
	#Inserting in between two Data Nodes
	def insertAtIndex(self, prevNode, data):
		if prevNode is None:
			print('The mentioned node is absent')
			return
		else:
			newNode = Node(data)
			newNode.next = prevNode.next
			prevNode.next = newNode
			
	#Searching an element
	def searchElement(self, key):
		temp = self.head
		f = 0
		while(temp):
			if temp.data == key:
				f = 1
				break
			temp = temp.next
		if f == 1:
		  print("\n{} is found".format(key));
		else:
		  print("\n{} is not found".format(key));
		
sllist = SinglyLinkedList()

sllist.head = Node(1)
second = Node(2)
third =  Node(3)
fourth = Node(4)

sllist.head.next = second
second.next = third
third.next = fourth
print('Linked list before insertion')
sllist.printList()

#sllist.insertAtFirst(7)
#print('\nLinked list after insertion')
#sllist.printList()

#sllist.insertAtEnd(6)
#print('\nLinked list after insertion')
#sllist.printList()

sllist.insertAtIndex(sllist.head, 10)
print('\nLinked list after insertion')
sllist.printList()

sllist.searchElement(2)
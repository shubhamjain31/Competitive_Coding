class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		self.prev = None

class DoublyLinkedList:
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
	
	def linkedListLength(self):
				currNode = self.head
				length = 0
				while(currNode.next is not None):
					length += 1
					currNode = currNode.next
				return length
			
	#Insert a new node at the beginning	
	def push(self, data):
		newNode = Node(data)
		newNode.next = self.head
		if self.head is not None:
			self.head.prev = newNode
		self.head = newNode
				
	#Deletion at the Beginning of the Linked List
	def deleteAtFirst(self):
		if self.head is None:
			print('Linked list has no element')
			return
		else:
			self.head = self.head.next
			self.head.next.prev = None
			
	#Deletion at the End of the Linked List
	def deleteAtEnd(self):
			if self.head is None:
				print('Linked list has no element')
				return
			else:
				temp = self.head
				while(temp.next != None):
					temp = temp.next
				temp.prev.next = None
				
	#Deletion in between two Data Nodes
	def deleteAtIndex(self, position):
				if self.head is None:
					print('\nLinked list has no element')
					return
				elif position <= 0 or position >= self.linkedListLength():
					print("\nInvalid Position")
					return
				else:
					p = self.head
					q = self.head.next
					i = 0
					while(i < position-1):
						p = p.next
						q = q.next
						i += 1
					p.next = q.next
					q.next.prev = p
					
	#Deletion of element by value
	def delete_element_by_value(self, val):
					if self.head is None:
						print('Linked list has no element')
						return
					else:
						p = self.head
						q = self.head.next
						while(q.data != val and q.next != None):
							p = p.next
							q = q.next
						if q.data == val and q.next is not  None:
							p.next = q.next
							q.next.prev = q.prev
						elif self.head.data == val:
							self.head = self.head.next
							self.head.next.prev = None
						elif q.data == val and q.next is None:
							p.next = None
						else:
							print('\nItem not found')
						return
							
dllist = DoublyLinkedList()

dllist.push(12) 
dllist.push(56) 
dllist.push(2) 
dllist.push(11) 

print('Linked list before deletion')
dllist.printList()

#dllist.deleteAtFirst()
#print('\nLinked list after deletion')
#dllist.printList()

#dllist.deleteAtEnd()
#print('\nLinked list after deletion')
#dllist.printList()

dllist.deleteAtIndex(0)
#print('\nLinked list after deletion')
#dllist.printList()

#dllist.delete_element_by_value(6256)
print('\nLinked list after deletion')
dllist.printList()
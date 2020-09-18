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
				
	def linkedListLength(self):
				currNode = self.head
				length = 0
				while(currNode.next is not None):
					length += 1
					currNode = currNode.next
				return length
				
	#Deletion at the Beginning of the Linked List
	def deleteAtFirst(self):
		if self.head is None:
			print('Linked list has no element')
			return
		else:
			self.head = self.head.next
			
	#Deletion at the End of the Linked List
	def deleteAtEnd(self):
			if self.head is None:
				print('Linked list has no element')
				return
			else:
				temp = self.head
				while(temp.next.next is not None):
					temp = temp.next
				temp.next = None
				
	#Deletion in between two Data Nodes
	def deleteAtIndex(self, position):
				if self.head is None:
					print('Linked list has no element')
					return
				elif position < 0 or position >= self.linkedListLength():
					print("Invalid Position")
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
					
	#Deletion of element by value
	def delete_element_by_value(self, val):
					if self.head is None:
						print('Linked list has no element')
						return
					else:
						p = self.head
						q = self.head.next
						while(q.data != val and q.next != None ):
							p = p.next
							q = q.next
						if q.data == val:
							p.next = q.next
						if self.head.data == val:
							self.head = self.head.next
						return
							
sllist = SinglyLinkedList()

sllist.head = Node(62)
second = Node(79)
third = Node(44)
fourth = Node(21)

sllist.head.next = second
second.next = third
third.next = fourth
fourth.next = None

print('Linked list before deletion')
sllist.printList()

#sllist.deleteAtFirst()
#print('\nLinked list after deletion')
#sllist.printList()

#sllist.deleteAtEnd()
#print('\nLinked list after deletion')
#sllist.printList()

#sllist.deleteAtIndex(1)
#print('\nLinked list after deletion')
#sllist.printList()

sllist.delete_element_by_value(44)
print('\nLinked list after deletion')
sllist.printList()
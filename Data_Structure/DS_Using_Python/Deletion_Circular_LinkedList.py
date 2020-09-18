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
				
	def linkedListLength(self):
				currNode = self.head
				length = 0
				while(currNode.next is not None):
					length += 1
					currNode = currNode.next
					if currNode == self.head:
						break
				return length
	
	#Insert a new node at the beginning
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
				
	#Deletion at the Beginning of the Linked List
	def deleteAtFirst(self):
		if self.head is None:
			print('Linked list has no element')
			return
		else:
			temp = self.head
			while(temp.next != self.head):
				temp = temp.next
			temp.next = self.head.next
			self.head = self.head.next
			
	#Deletion at the End of the Linked List
	def deleteAtEnd(self):
			if self.head is None:
				print('Linked list has no element')
				return
			else:
				p = self.head
				q = self.head.next
				while(p.next.next != self.head):
					p = p.next
					q = q.next
				p.next = q.next
				
	#Deletion in between two Data Nodes
	def deleteAtIndex(self, position):
				if self.head is None:
					print('Linked list has no element')
					return
				elif position < 0 or position >= self.linkedListLength():
					print("Invalid Position")
					return
				else:
					pass
					p = self.head
					q = self.head.next
					i = 1
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
					elif self.head.data == val:
						temp = self.deleteAtFirst()
						return
					else:
						p = self.head
						q = self.head.next
						while(q.data != val and q.next != self.head ):
							p = p.next
							q = q.next
						if q.data == val:
							p.next = q.next
						if self.head.data == val:
							self.head = self.head.next
						return
							
cllist = CircularLinkedList()

cllist.push(12) 
cllist.push(56) 
cllist.push(2) 
cllist.push(11) 

print('Linked list before deletion')
cllist.printList()

#cllist.deleteAtFirst()
#print('\nLinked list after deletion')
#cllist.printList()

#cllist.deleteAtEnd()
#print('\nLinked list after deletion')
#cllist.printList()

#cllist.deleteAtIndex(0)
#print('\nLinked list after deletion')
#cllist.printList()

cllist.delete_element_by_value(12)
print('\nLinked list after deletion')
cllist.printList()
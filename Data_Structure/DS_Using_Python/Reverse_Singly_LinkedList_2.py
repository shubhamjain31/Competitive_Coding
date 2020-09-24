#Reverse a linked list without actually reversing

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
		
	def reverse(self, temp):
			if temp == None:
				return
			self.reverse(temp.next)
			print(temp.data,end=' ')
				
llist = SinglyLinkedList()
llist.insert(35)
llist.insert(2)
llist.insert(97)
llist.insert(53)

print('\nLinked list before reversing')
llist.printList()

print('\n\nLinked list after reversing')
llist.reverse(llist.head)

if llist.size() == 0:
	print('No element found')
else:
	print('\n\nTotal number of elements in linked list is',llist.size())
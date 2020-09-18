class Node:
	def __init__(self, data):
		#Creation the Node class
		self.data = data
		self.next = None
		
class LinkedList:
	def __init__(self):
		#Creation of linked list
		self.head = None
		print('Linked list has been created successfully !!')
		
	def printList( self ):
		#Traversing a linked list
		if self.head is None:
		      print("List has no element")
		      return
		else:
		 	temp = self .head
		 	while (temp):
		 		print (temp.data, end=' ')
		 		temp = temp. next

#Creation of object of linked list class
llist = LinkedList()

llist.head = Node(1)
second = Node(2)
third = Node(3)

llist.head.next = second
second.next = third
third.next  = None
llist.printList()